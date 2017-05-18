#include "gtest/gtest.h"

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
uint8_t CDC_Transmit_FS(uint8_t* Buf,uint32_t Len) { return 0; }

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
//I2C_HandleTypeDef hi2c2;


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
 
 
int main(int argc, char **argv) 
{
  bool ok = CatDriver_CloneInStart();
  hUsbDeviceFS.dev_state = USBD_STATE_CONFIGURED;

   for  (int i = 0; i < 6; i++)
     {
       uint8_t c = 1;
       int st = CatDriver_InterfaceBufferAddData(c);
     }
  CatDriver_HandleProtocol();
  CatDriver_HandleProtocol();
  CatDriver_HandleProtocol();
  CatDriver_HandleProtocol();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
