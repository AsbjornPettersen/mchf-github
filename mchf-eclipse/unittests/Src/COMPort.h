#pragma once

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string>

class serialportc
{
public:
  DCB            PortDCB; 
  COMMTIMEOUTS   CommTimeouts; 
  HANDLE hPort1 = nullptr;
  serialportc()
  {
  };
   ~serialportc()
  {
    Close();
  };
  bool create(const char *comport)
  {
    hPort1 = CreateFileA (comport,		     // Name of the port 
			 GENERIC_READ | GENERIC_WRITE,     // Access (read-write) mode 
			 0,                                  
			 NULL,                             
			 OPEN_EXISTING,
			 FILE_ATTRIBUTE_NORMAL,                     
			 NULL);
    if ( hPort1 == INVALID_HANDLE_VALUE )
      {       
	return false;
      }   
    return true;
  };
  bool Close()
  {
    if (hPort1)
      CloseHandle(hPort1);
    hPort1 = nullptr;
    return true;
  };
  bool configure(const std::string baudrate);
  bool configuretimeout();
  bool set_configured();
  bool purge();
  bool WriteUart(unsigned char *buf1, const int len);
  int ReadUart(const unsigned int len, char *buf2);
  int baudrate_to_index(const std::string b) const;
};
