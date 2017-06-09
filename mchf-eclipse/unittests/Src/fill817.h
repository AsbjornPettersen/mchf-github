#ifndef _FILL817_H_INCLUDED
#define _FILL817_H_INCLUDED

#ifdef WINDOWS_ONLY

#define ARM_MATH_CM4
#define _GNU_SOURCE 
#define CORTEX_M4 
#define STM32F407xx 
#define USE_HAL_DRIVER 
#define USE_FULL_ASSERT

extern int __SMUAD(int , int );
extern int __SMLALD(int, int, int) ;
extern int __DSB();
extern int __NOP();
extern int __CLZ(int i);
extern int __SSAT(int i, int b);
extern int __QADD(int i, int b);
extern int __QSUB(int i, int b);
extern uint32_t __builtin_bswap32(uint32_t val) ;
extern uint8_t CDC_Transmit_FS(uint8_t* Buf,uint32_t Len);

//extern int CatDriver_InterfaceBufferAddData(uint8_t c);
#include "../../drivers/cat/cat_driver.h"

typedef enum
{
    FT817_SET_FREQ      = 0x01,
    FT817_GET_FREQ      = 0x03,
    FT817_SPLIT_ON      = 0x02,
    FT817_SPLIT_OFF     = 0x82,
    FT817_PTT_ON        = 0x08,
    FT817_PTT_OFF       = 0x88,
    FT817_MODE_SET      = 0x07,
    FT817_PWR_ON        = 0x0f,
    FT817_TOGGLE_VFO    = 0x81,
    FT817_A7            = 0xa7,
    FT817_EEPROM_READ   = 0xbb,
    FT817_EEPROM_WRITE  = 0xbc,
    FT817_READ_TX_STATE = 0xbd,
    FT817_READ_RX_STATE = 0xe7,
    FT817_PTT_STATE     = 0xf7,
    FT817_NOOP          = 0xff
} Ft817_CatCmd_t;
#endif

class fill_buf
{
public:
  uint8_t buf[256];
  fill_buf()
  {
    clear();
  };
  void clear()
  {
    memset(buf, 0x00, sizeof(buf));
  };
  unsigned char *cbuf() const { return (unsigned char *)buf; };
  const char *cmd_cstr(const Ft817_CatCmd_t cmd) const;
  void show_ft817() const;
  Ft817_CatCmd_t getcmd() const
  {
    Ft817_CatCmd_t cmd = (Ft817_CatCmd_t) buf[4];
    return cmd;
  };
  bool setcmd(const Ft817_CatCmd_t cmd, const uint16_t ee_addr, unsigned int &response_len);
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
  bool m_verbose = false;
public:
  fill_ft817 ()
  {
    it = v.cbegin();
  };
  bool filldata(const Ft817_CatCmd_t cmd, const uint16_t ee_addr, unsigned int &response_len) const
  {
    fill_buf b;
    b.setcmd(cmd, ee_addr, response_len);
    b.add(5);
    if (m_verbose)
      printf ("filldata 0x%x\n",cmd);
    return true;
  };
  bool filldata_loop()
  {
    unsigned int response_len;
    bool ok = filldata(*it, 0x0000, response_len);
    it++;
    if (it == v.cend())
      it = v.cbegin();
    return ok;
  };
};
#endif
