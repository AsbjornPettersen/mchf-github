#include "gtest/gtest.h"

//#define __GNUC__
//#define __CSMC__


#define ARM_MATH_CM4
#define _GNU_SOURCE 
#define CORTEX_M4 
#define STM32F407xx 
#define USE_HAL_DRIVER 
#define USE_FULL_ASSERT

int __CLZ(int i) { return 0; }
int __SSAT(int i, int b) { return 0; }
int __QADD(int i, int b) { return 0; }
int __QSUB(int i, int b) { return 0; }



#include "../../misc/serial_eeprom.c"

//#include "../../misc/config_storage.c"

//#include "../../basesw/mcHF/Src/i2c.c"
I2C_HandleTypeDef hi2c2;

unsigned short __cdecl MCHF_I2C_ReadBlock(I2C_TypeDef *,unsigned char,unsigned short,unsigned short,unsigned char *,unsigned int) {  return 0;}
unsigned short __cdecl MCHF_I2C_ReadRegister(I2C_TypeDef *,unsigned char,unsigned short,unsigned short,unsigned char *){  return 0;}
unsigned short __cdecl MCHF_I2C_WriteRegister(I2C_TypeDef *,unsigned char,unsigned short,unsigned short,unsigned char) {  return 0;}
unsigned short __cdecl MCHF_I2C_WriteBlock(I2C_TypeDef *,unsigned char,unsigned short,unsigned short,unsigned char *,unsigned int) {  return 0;}
HAL_StatusTypeDef HAL_I2C_IsDeviceReady(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint32_t Trials, uint32_t Timeout)
{
  HAL_StatusTypeDef s = HAL_OK;
  return s;
}
struct TransceiverState volatile ts;


bool okt()
{
  return true;
}

TEST(SerialepromTest, addr) 
{ 
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
}
 
 
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
