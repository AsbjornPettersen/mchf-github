#include "gtest/gtest.h"
#include <stdio.h>

#define ARM_MATH_CM4
#define _GNU_SOURCE 
#define CORTEX_M4 
#define STM32F407xx 
#define USE_HAL_DRIVER 
#define USE_FULL_ASSERT

bool is_vfo_b(void) { return false; }
int __SMUAD(int , int ) { return 0; }
int __SMLALD(int, int, int) { return 0; }
int __DSB() { return 0; }
int __NOP() { return 0; }
int __CLZ(int i) { return 0; }
int __SSAT(int i, int b) { return 0; }
int __QADD(int i, int b) { return 0; }
int __QSUB(int i, int b) { return 0; }

uint32_t __builtin_bswap32(uint32_t val) // need to convert big / little endian!!
{
  return val; // tbd
}

extern uint8_t CDC_Transmit_FS(uint8_t* Buf,uint32_t Len);


#include "../../drivers/cat/cat_driver.c"
#include "../Src/fill817.h"


#if 1
class tr_data
{
public:
  std::vector<uint8_t> tab; 
  void dump() const
  {
    unsigned int i = 0;
    for (auto it = tab.cbegin(); it != tab.cend(); ++it) 
      {       
	uint8_t c = *it;
	printf ("0x%02x,",c);
	i++;
      }
    printf ("\n");
  };
  void add(uint8_t* Buf,uint32_t Len) 
  {
    for (uint32_t i=0; i < Len; i++)
      {
	tab.push_back(*Buf);
	Buf++;
      }
  };
};

tr_data transdata; 
 
uint8_t CDC_Transmit_FS(uint8_t* Buf,uint32_t Len) 
{
  transdata.add(Buf, Len);
  //  printf ("Transmitt %d\n",Len);
  return 0; 
}
struct TransceiverState volatile ts;

#if 0
#include "../../drivers/ui/radio_management.c"
#else
bool RadioManagement_FmDevIs5khz()
{
    return (ts.flags2 & FLAGS2_FM_MODE_DEVIATION_5KHZ) != 0;
}

void RadioManagement_FmDevSet5khz(bool is5khz)
{
    if (is5khz)
    {
        ts.flags2 |= FLAGS2_FM_MODE_DEVIATION_5KHZ;
    }
    else
    {
        ts.flags2 &= ~FLAGS2_FM_MODE_DEVIATION_5KHZ;
    }
}
#endif



void __cdecl UiDriver_ToggleVfoAB(void) {}
void __cdecl UiDriver_SetSplitMode(bool) {  }
void __cdecl UiDriver_UpdateDisplayAfterParamChange(void) {}
int __cdecl AudioDriver_GetTranslateFreq(void) { return 0; }
void __cdecl RadioManagement_SetDemodMode(unsigned int) {}
struct DialFrequency volatile df;
struct SWRMeter swrm;
struct SMeter volatile sm;
USBD_HandleTypeDef hUsbDeviceFS;

__IO CdcVcp_CtrlLines_t  cdcvcp_ctrllines;

#endif

bool okt()
{
  return true;
}

class ft817c
{
  struct FT817 *ft817p;
public:
  ft817c(struct FT817 *p)
  {
    ft817p = p;
  };
  const char *state_cstr() const
  { 
    switch (ft817p->state)
      {
      case CAT_INIT:
	return "CAT_INIT";
      case CAT_CAT:
	return "CAT_CAT";
      case CAT_CLONEOUT:
	return "CAT_CLONEOUT";
      case CAT_CLONEIN:
	return "CAT_CLONEIN";
      default:
	return "CAT_????";
      };
  }; 

  const char *clonein_state_cstr() const
  { 
    switch (ft817p->clonein_state)
      {
      case CLONEIN_INIT:
	return "CLONEIN_INIT";
      case CLONEIN_BLOCK_RECV_START:
	return "CLONEIN_BLOCK_RECV_START";
      case CLONEIN_BLOCK_RECV:
	return "CLONEIN_BLOCK_RECV";
      case CLONEIN_FINAL_PROCESSING:
      return "CLONEIN_FINAL_PROCESSING";
      case CLONEIN_DONE:
	return "CLONEIN_DONE";
      default:
	return "CLONEIN_????";
      };
  };
  const char *cloneout_state_cstr() const
  { 
    switch (ft817p->cloneout_state)
      {
      case CLONEOUT_INIT:
	return "CLONEOUT_INIT";
      case CLONEOUT_BLOCK_SEND:
	return "CLONEOUT_BLOCK_SEND";
      case CLONEOUT_BLOCK_ACK_WAIT:
	  return "CLONEOUT_BLOCK_ACK_WAIT";
      case CLONEOUT_BLOCK_ACK_NACK:
	  return "CLONEOUT_BLOCK_ACK_NACK";
      case CLONEOUT_DONE:
	  return "CLONEOUT_DONE";
      default:
	return "CLONEOUT_????";
      };
  };        
    
};

class global_data
{
public:
  global_data()
  {
    reset_all();
  };
  size_t send_sz() const
  { 
    size_t sz = transdata.tab.size(); 
    return sz;
  };

  void reset_all()
  {
    cat_buffer_reset(); // input buffer
    transdata.tab.clear(); 
  };
};

TEST(FillBuftest, fill_buf) 
{
  global_data glb;

  fill_buf t;
  EXPECT_EQ (true, t.add(1));
  uint32_t bufsz = CatDriver_InterfaceBufferHasData();
  EXPECT_EQ (1, bufsz);
  EXPECT_EQ (true, t.add(254));
  EXPECT_EQ (255, CatDriver_InterfaceBufferHasData());
  EXPECT_EQ (false, t.add(1));
  EXPECT_EQ (255, CatDriver_InterfaceBufferHasData());
  cat_buffer_reset();
  EXPECT_EQ (0, CatDriver_InterfaceBufferHasData());
  EXPECT_EQ (true, t.add(255));
  EXPECT_EQ (255, CatDriver_InterfaceBufferHasData());
  
  glb.reset_all();
}

TEST(CatDrivertest, blockAck) 
{
  global_data glb;

  bool ok = CatDriver_BlockAck();
  EXPECT_EQ (false, ok);

  fill_buf f;
  f.add(1); // zero val
  ok = CatDriver_BlockAck();
  EXPECT_EQ (false, ok);
  
  f.buf[0] = CLONE_CMD_ACK;
  f.add(1); // 
  ok = CatDriver_BlockAck();
  EXPECT_EQ (true, ok);

  glb.reset_all();
  CatDriver_CloneSendAck();
  EXPECT_EQ (1, glb.send_sz());
}

TEST(CatDrivertest, test_debug_flag) 
{
  bool debug = false;
#ifdef DEBUG_FT817
  debug = true;
#endif
  EXPECT_EQ (false, debug);
}

void check_one_cmd(const Ft817_CatCmd_t cmd, const uint16_t ee_addr, fill_ft817 &t)
{
  unsigned int response_len;
  bool ok = t.filldata(cmd, ee_addr, response_len);
  EXPECT_EQ (true, ok);
  EXPECT_GT(response_len,0);
  
  ts.sysclock  = cat_driver.lastbufferadd_time = CAT_DRIVER_TIMEOUT; // hack
  CatDriver_HandleCommands();
  size_t sz = transdata.tab.size(); 
#if 0
  printf ("ts.tx_disable=0x%x  CatDriver_CatPttActive()=%d \n",ts.tx_disable, CatDriver_CatPttActive());
  transdata.dump(); 
#endif
  transdata.tab.clear(); 
  if (cmd == FT817_NOOP) // well
    return;
  EXPECT_GT(sz,0);
  EXPECT_EQ(sz,response_len);
}

TEST(CatDrivertest, read_eeprom) 
{
  global_data glb;

  Ft817_CatCmd_t cmd = FT817_EEPROM_READ;
  fill_ft817 t;
  uint16_t ee_addr = 0x1925; // max, illegal
  check_one_cmd(cmd, ee_addr, t);
#if 0
  ee_addr = 0x1925 -1 ; // max, illegal
  check_one_cmd(cmd, ee_addr, t);
#endif
}

TEST(CatDrivertest, allcommands) 
{
  global_data glb;

  fill_ft817 t;
  uint16_t ee_addr = 0x1925; // max, illegal
  for (auto i = t.v.cbegin(); i != t.v.cend(); i++)
    {
      check_one_cmd(*i, ee_addr, t);
    }
}

class fillclone
{
public:
  unsigned int blockno = 0;
  unsigned int ind = 0;
  uint8_t count = 0;
public:
  bool filldata()
  {
    if (ind >= 11)
      return false;

    if (count == 0)
      count = cloneblock_len[ind].count; 
    unsigned int len = cloneblock_len[ind].len + 2;
    fill_buf b;      
    b.buf[0]  = (uint8_t) blockno;
    b.buf[len-1]  = CatDriver_Clone_Checksum(&b.buf[1],len-2);
    b.add(len);

    count --;
    if (count == 0)
      {
	ind ++;
      }
    blockno++;
    return true;
  };
};

int main(int argc, char **argv) 
{
  global_data glb;

  ft817c ftc(&ft817);
  printf ("sizeof(ft871_settings_t) =%d\n",sizeof(ft871_settings_t));
  printf ("ts.tx_disable=0x%x  CatDriver_CatPttActive()=%d \n",ts.tx_disable, CatDriver_CatPttActive());

  hUsbDeviceFS.dev_state = USBD_STATE_CONFIGURED;

  fill_ft817 f8;

#if 1
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
#endif
  
  //  bool ok = CatDriver_CloneInStart();

  fillclone fc;
  //  fc.filldata();
#if 1
  for  (int i = 0; i < 6000; i++)
    {
      if ((ft817.state == CAT_CAT) || (ft817.state == CAT_INIT))
	{
	  printf (" CAT_CAT in=%s fc.ind=%d count=%d\n",ftc.clonein_state_cstr(), fc.ind, fc.count);
	  //	  f8.filldata(FT817_SET_FREQ);
	  //	  f8.filldata(FT817_GET_FREQ);
	  f8.filldata_loop();
	  ts.sysclock  = cat_driver.lastbufferadd_time = CAT_DRIVER_TIMEOUT; 
	  CatDriver_HandleCommands();
	}
      //      CatDriver_HandleProtocol();
      uint8_t bytes = CatDriver_InterfaceBufferHasData();
      printf ("bytes =%d in=%s fc.ind=%d count=%d\n",bytes, ftc.clonein_state_cstr(), fc.ind, fc.count);
      if (ft817.state == CAT_CLONEIN)
	{
	  if (bytes == 0)
	    {
	      bool ok = fc.filldata();
	    }
	}
    }
#endif

  CatDriver_HandleProtocol();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
