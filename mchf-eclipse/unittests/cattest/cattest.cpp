#include "gtest/gtest.h"
#include <stdio.h>

//#define __GNUC__
//#define __CSMC__


#define ARM_MATH_CM4
#define _GNU_SOURCE 
#define CORTEX_M4 
#define STM32F407xx 
#define USE_HAL_DRIVER 
#define USE_FULL_ASSERT



uint32_t __builtin_bswap32(uint32_t val) // need to convert big / little endian!!
{
  return val; // tbd
}


int __SMUAD(int , int ) { return 0; }
int __SMLALD(int, int, int) { return 0; }

int __DSB() { return 0; }
int __NOP() { return 0; }
int __CLZ(int i) { return 0; }
int __SSAT(int i, int b) { return 0; }
int __QADD(int i, int b) { return 0; }
int __QSUB(int i, int b) { return 0; }

#if 1
static uint32_t total_transmitt_Len = 0;
 
uint8_t CDC_Transmit_FS(uint8_t* Buf,uint32_t Len) 
{
  total_transmitt_Len += Len;
  printf ("Transmitt %d : %d\n",Len,total_transmitt_Len);

  return 0; 
}

#include "../../drivers/cat/cat_driver.c"

void __cdecl UiDriver_ToggleVfoAB(void) {}
void __cdecl UiDriver_SetSplitMode(bool) {  }
void __cdecl UiDriver_UpdateDisplayAfterParamChange(void) {}
struct DialFrequency volatile df;
int __cdecl AudioDriver_GetTranslateFreq(void) { return 0; }
struct SWRMeter swrm;
void __cdecl RadioManagement_SetDemodMode(unsigned int) {}
struct SMeter volatile sm;
USBD_HandleTypeDef hUsbDeviceFS;

__IO CdcVcp_CtrlLines_t  cdcvcp_ctrllines;

struct TransceiverState volatile ts;
#endif

bool okt()
{
  return true;
}

TEST(SerialepromTest, addr) 
{ 
#if 0
  //   EXPECT_EQ (true, okt ());
  uint8_t devaddr;
  uint32_t Addr = 0x10000; /* example */
  uint8_t Mem_Type = 17;
  
  SerialEEPROM_24Cxx_AdjustAddrs(Mem_Type,&devaddr,&Addr);
  EXPECT_EQ (MEM_DEVICE_WRITE_ADDR + 8, devaddr); 
  
  /* NB! Addr have been changed ! */
  SerialEEPROM_24Cxx_AdjustAddrs(Mem_Type,&devaddr,&Addr);	
  EXPECT_EQ (MEM_DEVICE_WRITE_ADDR + 8, devaddr); 
  /*---------------------------------------------------*/
  /* devaddr will be set to (MEM_DEVICE_WRITE_ADDR ) ! */
  /*---------------------------------------------------*/
  
  uint16_t addr16 = Addr;
  uint16_t value;
  uint16_t val = SerialEEPROM_ReadVariable(addr16, &value); 

  uint8_t se = SerialEEPROM_24Cxx_Detect();
#endif
}


#if 1
void CatDriver_ft817_HandleProtocol()
{
  uint8_t bc = 0;
  uint8_t resp[32];
          
  while (CatDriver_InterfaceBufferGetData(ft817.req,5))
    {
#ifdef DEBUG_FT817
      int debug_idx;
      for (debug_idx = 0; debug_idx < 5 && ft817.cmd_cntr < FT817_MAX_CMD; debug_idx++ )
	{
	  ft817.reqs[ft817.cmd_cntr*5+debug_idx] = ft817.req[debug_idx];
	}
      ft817.cmd_cntr++;
#endif
      
      switch((Ft817_CatCmd_t)ft817.req[4])
	{
	case FT817_SET_FREQ:
	  {
	    ulong f = 0;
	    ulong fdelta;
	    
	    if(ts.xlat == 0)
	      {
		fdelta = (ts.tx_audio_source == TX_AUDIO_DIGIQ)?AudioDriver_GetTranslateFreq()*4:0;
		// If we are in DIGITAL IQ Output mode, use real tune frequency frequency instead
		// translated RX frequency
	      }
	    else
	      {
		fdelta = 0;
	      }
	    
	    int fidx;
	    for (fidx = 0; fidx < 4; fidx++)
	      {
		f *= 100;
		f +=  (ft817.req[fidx] >> 4) * 10 + (ft817.req[fidx] & 0x0f);
	      }
	    f *= TUNE_MULT*10;
	    df.tune_new = f - fdelta;
	    
	    resp[0] = 0;
	    bc = 1;
	    if(ts.flags1 & FLAGS1_CAT_IN_SANDBOX)			// if running in sandbox store active band
	      {
		ts.cat_band_index = ts.band;
	      }
	  }
	  break;
	  
	case FT817_GET_FREQ:
	  {
	    ulong fdelta;
	    
	    if(ts.xlat == 0)
	      {
		fdelta = (ts.tx_audio_source == TX_AUDIO_DIGIQ)?AudioDriver_GetTranslateFreq()*TUNE_MULT:0;
		// If we are in DIGITAL IQ Output mode, send real tune frequency frequency instead
		// translated RX frequency
	      }
	    else
	      {
		fdelta = 0;
	      }
	    
	    ulong f = (df.tune_new + fdelta  + (TUNE_MULT*10/2))/ (TUNE_MULT*10);
	    ulong fbcd = 0;
	    int fidx;
	    for (fidx = 0; fidx < 8; fidx++)
	      {
		fbcd >>= 4;
		fbcd |= (f % 10) << 28;
		f = f / 10;
	      }
	    
	    resp[0] = (uint8_t)(fbcd >> 24);
	    resp[1] = (uint8_t)(fbcd >> 16);
	    resp[2] = (uint8_t)(fbcd >> 8);
	    resp[3] = (uint8_t)fbcd;
	  }
	  switch(ts.dmod_mode)
	    {
	    case DEMOD_LSB:
	      resp[4] = 0;
	      break;
	    case DEMOD_USB:
	      resp[4] = 1;
	      break;
	    case DEMOD_CW:
	      resp[4] = 2 + (ts.cw_lsb==true?1:0);
	      break;
	      // return 3 if CW in LSB aka CW-R
	    case DEMOD_SAM:
	    case DEMOD_AM:
	      resp[4] = 4;
	      break;
	    case DEMOD_FM:
	      resp[4] = 8;
	      break;
	    default:
	      resp[4] = 1;
	    }
	  bc = 5;
	  break;
	case 7: /* set mode */
	  {
	    uint32_t new_mode = ts.dmod_mode;
	    uint32_t new_lsb = ts.cw_lsb;
	    switch (ft817.req[0])
	      {
	      case 0: // LSB
		new_mode = DEMOD_LSB;
		break;
	      case 1: // USB
		new_mode = DEMOD_USB;
		break;
	      case 2: // CW
		new_lsb = false;
		new_mode = DEMOD_CW;
		break;
	      case 3: // CW-R
		new_lsb = true;
		new_mode = DEMOD_CW;
		break;
	      case 4: // AM
		new_mode = DEMOD_AM;
		break;
	      case 8: // FM
	      case 0x88: // FM-N
		new_mode = DEMOD_FM;
		break;
	      case 0x0a: // DIG - SSB, side band controlled by some menu configuration in ft817, we use USB here
		new_mode = DEMOD_USB;
		break;
	      case 0x0c: // PKT - FM, 9k6
		new_mode = DEMOD_FM;
		break;
	      }
	    if  (new_mode != ts.dmod_mode || new_lsb != ts.cw_lsb )
	      {
		if(ts.flags1 & FLAGS1_CAT_IN_SANDBOX)			// if running in sandbox store active band
		  {
		    ts.cat_band_index = ts.band;
		  }
		ts.cw_lsb = new_lsb;
		RadioManagement_SetDemodMode(new_mode);
		UiDriver_UpdateDisplayAfterParamChange();
	      }
	  }
	  break;
	case FT817_PTT_ON:
	  resp[0] = cat_driver.cat_ptt_active?0xF0:0x00;
	  /* 0xF0 if PTT was already on */
	  
	  if(RadioManagement_IsTxDisabled() == false)
	    {
	      ts.ptt_req = true;
	      cat_driver.cat_ptt_active = true;
	    }
	  
	  bc = 1;
	  break;
	case FT817_PWR_ON:
	  resp[0] = 0;
	  bc = 1;
	  break;
	case FT817_TOGGLE_VFO:
	  UiDriver_ToggleVfoAB();
	  resp[0] = 0;
	  bc = 1;
	  break;
	case FT817_SPLIT_ON:
	  UiDriver_SetSplitMode(true);
	  resp[0] = 0;
	  bc = 1;
	  break;
	case FT817_SPLIT_OFF:
	  UiDriver_SetSplitMode(false);
	  resp[0] = 0;
	  bc = 1;
	  break;
	case FT817_PTT_OFF:
	  resp[0] = cat_driver.cat_ptt_active?0x00:0xF0; /* 0xF0 if PTT was already off */
	  ts.ptt_req = false;
	  cat_driver.cat_ptt_active = false;
	  bc = 1;
	  break;
	case FT817_A7: /* A7 */
	  resp[0]=0xA7;
	  resp[1]=0x02;
	  resp[2]=0x00;
	  resp[3]=0x04;
	  resp[4]=0x67;
	  resp[5]=0xD8;
	  resp[6]=0xBF;
	  resp[7]=0xD8;
	  resp[8]=0xBF;
	  bc = 9;
	  break;
	case FT817_EEPROM_READ:
	  resp[0]=0x00;
	  bc = 1;
	  break;
	case FT817_EEPROM_WRITE:
	  resp[0] = 0;
	  bc = 1;
	  break;
	case FT817_READ_TX_STATE:
	  if(RadioManagement_IsTxDisabled()||(ts.txrx_mode != TRX_MODE_TX))
	    {
	      resp[0] = 0;
	    }
	  else
	    {
	      resp[0] =((uint8_t)round(swrm.fwd_pwr)<<4)+(uint8_t)round(swrm.vswr_dampened);
	    }
	  bc = 1;
	  break;
	case FT817_READ_RX_STATE: /* E7 */
	  resp[0] = (uint8_t)round(sm.s_count*0.5);	//S-Meter signal
	  bc = 1;
	  break;
	case FT817_PTT_STATE:
	  // FT-817 responds 0xFF if not TX and 0x00 if TX
	  // This differs from KA7OEI description but has been verified
	  // with the real thing.
	  resp[0]=ts.txrx_mode == TRX_MODE_TX?0x00:0xFF;
	  if(RadioManagement_IsTxDisabled())
	    {
	      resp[0] =0xFF;
	    }
	  bc = 1;
	  break;
	case 255: /* FF sent out by HRD */
	  break;
	  // default:
	  // while (1);
	}
    }
  CatDriver_InterfaceBufferPutData(resp,bc);
  /* Return data back */
}
#endif




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

class fill_buf
{
public:
  uint8_t buf[256];
  fill_buf()
  {
    memset(buf, 0x00, sizeof(buf));
  };
  bool add (const unsigned int len)
  {
     for (unsigned int i = 0; i < len; i++)
      {
	uint8_t c = buf[i];
	int st = CatDriver_InterfaceBufferAddData(c);
	if (st != 1)
	  return false;
      }
     return true;
  };
};

class fill_ft817 
{
  std::vector<Ft817_CatCmd_t>::const_iterator it;
public:
  std::vector<Ft817_CatCmd_t> v = 
    {
      FT817_SET_FREQ,
      FT817_GET_FREQ,
      FT817_SPLIT_ON,
      FT817_SPLIT_OFF,
      FT817_PTT_ON,
      FT817_PTT_OFF,
      FT817_MODE_SET,
      FT817_PWR_ON,
      FT817_TOGGLE_VFO,
      FT817_A7,
      FT817_EEPROM_READ,
      FT817_EEPROM_WRITE,
      FT817_READ_TX_STATE,
      FT817_READ_RX_STATE,
      FT817_PTT_STATE,
      FT817_NOOP
    };
public:
  fill_ft817 ()
  {
    it = v.cbegin();
  };
  bool filldata(const Ft817_CatCmd_t cmd) const
  {
    fill_buf b;   
    b.buf[4]  = (uint8_t) cmd;
    b.add(5);
    printf ("filldata 0x%x\n",cmd);
    return true;
  };
  bool filldata_loop()
  {
    bool ok = filldata(*it);
    it++;
    if (it == v.cend())
      it = v.cbegin();
    return ok;
  };
};

class global_data
{
public:
  global_data()
  {
    reset_all();
  };
  void reset_all()
  {
    cat_buffer_reset(); // input buffer
    total_transmitt_Len = 0;  // output sent
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

TEST(FillBuftest, allcommands) 
{
  global_data glb;

  fill_ft817 t;
  for (auto i = t.v.cbegin(); i != t.v.cend(); i++)
    {
      bool ok = t.filldata(*i);
      EXPECT_EQ (true, ok);
      uint32_t prev = total_transmitt_Len;
      // CatDriver_HandleProtocol();  have eat data!
      CatDriver_ft817_HandleProtocol();
      printf ("ts.tx_disable=0x%x  CatDriver_CatPttActive()=%d \n",ts.tx_disable, CatDriver_CatPttActive());
      uint32_t Len = total_transmitt_Len - prev; 
      if (*i == FT817_MODE_SET) // error !!
	continue;
      if (*i == FT817_NOOP) // well
	continue;
      EXPECT_GT(Len,0);
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
	  CatDriver_ft817_HandleProtocol();
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
