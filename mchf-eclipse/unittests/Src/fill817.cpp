#include <stdio.h>
#include <vector>

#define WINDOWS_ONLY


#ifdef WINDOWS_ONLY
#define ARM_MATH_CM4
#define _GNU_SOURCE 
#define CORTEX_M4 
#define STM32F407xx 
#define USE_HAL_DRIVER 
#define USE_FULL_ASSERT

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
#endif

//#include "../../drivers/cat/cat_driver.h"
#include "./fill817.h"

const char *fill_buf::cmd_cstr(const Ft817_CatCmd_t cmd) const
{ 
  switch (cmd)
    {
    case FT817_SET_FREQ:
      return "FT817_SET_FREQ";
    case FT817_GET_FREQ:
      return "FT817_GET_FREQ";
    case FT817_A7:
      return "FT817_A7";
    case FT817_SPLIT_ON:
      return "FT817_SPLIT_ON";
    case FT817_SPLIT_OFF:
      return "FT817_SPLIT_OFF";
    case FT817_PTT_ON:
      return "FT817_PTT_ON";
    case FT817_PTT_OFF:
      return "FT817_PTT_OFF";
    case FT817_MODE_SET:
      return "FT817_MODE_SET";
    case FT817_PWR_ON:
      return "FT817_PWR_ON";
    case FT817_TOGGLE_VFO:
      return "FT817_TOGGLE_VFO";
    case FT817_EEPROM_READ:
      return "FT817_EEPROM_READ";
    case FT817_EEPROM_WRITE:
      return "FT817_EEPROM_WRITE";
    case FT817_READ_TX_STATE:
      return "FT817_READ_TX_STATE";
    case FT817_READ_RX_STATE:
      return "FT817_READ_RX_STATE";
    case FT817_PTT_STATE:
      return "FT817_PTT_STATE";
    case FT817_NOOP:
      return "FT817_NOOP";
    default:
      return "FT817_????";
    };
} 


void fill_buf::show_ft817() const
{
  Ft817_CatCmd_t cmd = (Ft817_CatCmd_t) buf[4];
  printf ("cmd=%d->%s\n",cmd, cmd_cstr(cmd));
  switch (cmd)
    {
    case FT817_GET_FREQ:
      {
	ulong fbcd = 0;
	ulong v = 0;
	fbcd +=  ((ulong) buf[0]) << 24;
	fbcd +=  ((ulong) buf[1]) << 16;
	fbcd +=  ((ulong) buf[2]) << 8;
	fbcd +=  ((ulong) buf[3]);
	printf ("fbcd=%ld\n",fbcd);
      }
      break;
    default:;
    };
}

bool fill_buf::setcmd(const Ft817_CatCmd_t cmd, const uint16_t ee_addr, unsigned int &response_len)
{
  //    printf ("cmd=%d->%s\n",cmd, cmd_cstr(cmd));
  clear();
  
  response_len = 0;
  switch (cmd)
    {
    case FT817_SET_FREQ:
      response_len = 1;
      break;
    case FT817_GET_FREQ:
      response_len = 5;
      break;
    case FT817_A7:
      response_len = 9;
      break;
    case FT817_EEPROM_READ:
      {
	//	  uint16_t ee_addr = 0x1925; // max, illegal
	buf[0]  = (uint8_t) (ee_addr  >> 8);
	buf[1]  = (uint8_t) (ee_addr & 0xff);
	if (ee_addr < 0x1925)
	  response_len = 2;
	else
	  response_len = 1;
      }
      break;
    default:
      response_len = 1;
    };
  
  buf[4]  = (uint8_t) cmd;
  return true;
}

