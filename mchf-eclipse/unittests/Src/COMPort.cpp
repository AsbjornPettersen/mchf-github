#include "COMPort.h"
//#include <commctrl.h>
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string>

int index2=-1,index3=-1,index4=-1,index5=-1,index6=-1,index7=-1;

#if 0
// Message handler for about box.
INT_PTR CALLBACK Port(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{	
SendDlgItemMessageA(hDlg, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"5");
SendDlgItemMessageA(hDlg, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"6");
SendDlgItemMessageA(hDlg, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"7");
SendDlgItemMessageA(hDlg, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)"8");
SendDlgItemMessageA(hDlg, IDC_COMBO3, CB_ADDSTRING, 0, (LPARAM)"Even");
SendDlgItemMessageA(hDlg, IDC_COMBO3, CB_ADDSTRING, 0, (LPARAM)"Odd");
SendDlgItemMessageA(hDlg, IDC_COMBO3, CB_ADDSTRING, 0, (LPARAM)"None");
SendDlgItemMessageA(hDlg, IDC_COMBO3, CB_ADDSTRING, 0, (LPARAM)"Mark");
SendDlgItemMessageA(hDlg, IDC_COMBO3, CB_ADDSTRING, 0, (LPARAM)"Space");
SendDlgItemMessageA(hDlg, IDC_COMBO4, CB_ADDSTRING, 0, (LPARAM)"1");
SendDlgItemMessageA(hDlg, IDC_COMBO4, CB_ADDSTRING, 0, (LPARAM)"2");
SendDlgItemMessageA(hDlg, IDC_COMBO5, CB_ADDSTRING, 0, (LPARAM)"Xon/Xoff");
SendDlgItemMessageA(hDlg, IDC_COMBO5, CB_ADDSTRING, 0, (LPARAM)"Hardware");
SendDlgItemMessageA(hDlg, IDC_COMBO5, CB_ADDSTRING, 0, (LPARAM)"None");

#endif

static LPVOID get_err_str(const DWORD dwerr)
{
  LPVOID lpMsgBuf;
  
  FormatMessage( 
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM | 
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dwerr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR) &lpMsgBuf,
		0,
		NULL 
		 );
  return(lpMsgBuf);
}
 
 static void show_err(const DWORD dwerr)
 {
   LPVOID lpe = get_err_str(dwerr);
   
   printf("err=%s",(const char *)lpe);
  LocalFree(lpe);
}

 void os_err_str(const DWORD dwerr, char *str, const int maxlen)
  {
  LPVOID lpe = get_err_str(dwerr);
  if (lpe)
    {
      if (maxlen > 200)
	memset (str,0x00,200);
      strncpy (str,(char *)lpe, maxlen);
      LocalFree(lpe);
    }
 }
 
class oserrinfo
{
  std::string errstr;
  DWORD dwerr;
  DWORD get_last_error()
  {
    DWORD le;
    le = GetLastError();
    return (le);
  };
public:
 oserrinfo() 
  {
    dwerr = 0;
  };
  const char *get_errstr() const { return errstr.c_str(); };
  DWORD getlasterr()
  {
    dwerr = get_last_error();
    char buf[500];
    os_err_str(dwerr, buf, sizeof(buf)-1);
    //    term_at_crlf(buf);
    errstr = buf;
    return dwerr;
  };
};

 int serialportc::baudrate_to_index(const std::string b) const
 { 
   if (b == "115200")
     return 0;
   else if (b == "57600")
     return 1;
   else if (b == "38400")
     return 2;
   else if (b == "19200")
     return 3;
   else if (b == "9600")
     return 4;
   else if (b == "4800")
     return 5;
   else if (b == "2400")
     return 6;

   return 0;
 }

bool serialportc::configure(const std::string baudrate)
{	
  const int index1 = baudrate_to_index(baudrate);

  memset(&PortDCB, 0x00, sizeof(PortDCB)); 
  PortDCB.DCBlength = sizeof (DCB); 

  GetCommState (hPort1, &PortDCB);

  PortDCB.fBinary = TRUE;                         // Binary mode; no EOF check
  PortDCB.fParity = TRUE;                         // Enable parity checking 
  PortDCB.fDsrSensitivity = FALSE;                // DSR sensitivity 
  PortDCB.fErrorChar = FALSE;                     // Disable error replacement 
  PortDCB.fOutxDsrFlow = FALSE;                   // No DSR output flow control 
  PortDCB.fAbortOnError = FALSE;                  // Do not abort reads/writes on error
  PortDCB.fNull = FALSE;                          // Disable null stripping 
  PortDCB.fTXContinueOnXoff = TRUE;                // XOFF continues Tx 
  
  switch(index1)                                  // BAUD Rate
    {
    case 0:
      PortDCB.BaudRate= 115200;            
      break;
    case 1:
      PortDCB.BaudRate = 57600;            
      break;
    case 2:
      PortDCB.BaudRate = 38400;            
      break;
    case 3:
      PortDCB.BaudRate = 19200;            
      break;
    case 4:
      PortDCB.BaudRate = 9600;            
      break;
    case 5:
      PortDCB.BaudRate = 4800;            
      break;
    case 6:
      PortDCB.BaudRate = 2400;            
      break;
    default:
      break;
    }
  switch(index2)                                     // Number of bits/byte, 5-8 
    {
    case 0:
      PortDCB.ByteSize = 5;            
      break;
    case 1:
      PortDCB.ByteSize = 6;            
      break;
    case 2:
      PortDCB.ByteSize= 7;            
      break;
    case 3:
      PortDCB.ByteSize=8;            
      break;
    default:
      break;
    }
  switch(index3)                                     // 0-4=no,odd,even,mark,space 
    {
    case 0:
      PortDCB.Parity= EVENPARITY;                
      break;
    case 1:
      PortDCB.Parity = MARKPARITY;               
      break;
    case 2:
      PortDCB.Parity = NOPARITY;                   
      break;
    case 3:
      PortDCB.Parity = ODDPARITY;           
      break;
    case 4:
      PortDCB.Parity = SPACEPARITY;           
      break;
    default:
      break;
    }
  switch(index4)                       
    {
    case 0:
      PortDCB.StopBits =  ONESTOPBIT;          
      break;
    case 1:
      PortDCB.StopBits =  TWOSTOPBITS;        
      break;
      
    default:
      break;
    }
  switch(index5)                       
    {
    case 0:
      PortDCB.fOutxCtsFlow = TRUE;                        // CTS output flow control 
      PortDCB.fDtrControl = DTR_CONTROL_ENABLE;           // DTR flow control type 
      PortDCB.fOutX = FALSE;                              // No XON/XOFF out flow control 
      PortDCB.fInX = FALSE;                               // No XON/XOFF in flow control 
      PortDCB.fRtsControl = RTS_CONTROL_ENABLE;           // RTS flow control             
      break;
    case 1:
      PortDCB.fOutxCtsFlow = FALSE;                      // No CTS output flow control 
      PortDCB.fDtrControl = DTR_CONTROL_ENABLE;          // DTR flow control type 
      PortDCB.fOutX = FALSE;                             // No XON/XOFF out flow control 
      PortDCB.fInX = FALSE;                              // No XON/XOFF in flow control 
      PortDCB.fRtsControl = RTS_CONTROL_ENABLE;          // RTS flow control 
      break;
    case 2:
      PortDCB.fOutxCtsFlow = FALSE;                      // No CTS output flow control 
      PortDCB.fDtrControl = DTR_CONTROL_ENABLE;          // DTR flow control type 
      PortDCB.fOutX = TRUE;                              // Enable XON/XOFF out flow control 
      PortDCB.fInX = TRUE;                               // Enable XON/XOFF in flow control 
      PortDCB.fRtsControl = RTS_CONTROL_ENABLE;          // RTS flow control       
      break;      
    default:
      break;
    }
  return true;
}

bool serialportc::configuretimeout()
{
  GetCommTimeouts (hPort1, &CommTimeouts); 

  CommTimeouts.ReadIntervalTimeout = 50; 
  CommTimeouts.ReadTotalTimeoutConstant = 50; 
  CommTimeouts.ReadTotalTimeoutMultiplier=10;
  CommTimeouts.WriteTotalTimeoutMultiplier=10;
  CommTimeouts.WriteTotalTimeoutConstant = 50; 
  return true;
}

bool serialportc::purge()
{
  if(PurgeComm(hPort1, PURGE_TXCLEAR | PURGE_RXCLEAR)==0) 
    {       
      return false; 
    }   
  return true;
}

bool serialportc::set_configured()
{
  oserrinfo oerr;
  if (!SetCommState (hPort1, &PortDCB)) 
    { 
      DWORD dw = oerr.getlasterr();
      printf("%s\n",oerr.get_errstr());

      Close();   
      return false; 
    } 

  if (!SetCommTimeouts (hPort1, &CommTimeouts)) 
    { 
      Close();   
      return false; 
    } 
  return true;
}

bool serialportc::WriteUart(unsigned char *buf1, const int len)
{
  DWORD dwNumBytesWritten;
  
  WriteFile (hPort1,buf1, len,&dwNumBytesWritten,NULL);			
  
  if(dwNumBytesWritten > 0)
    {
      //MessageBox (NULL, L"Transmission Success" ,L"Success", MB_OK);
      return true;
    }  
  else 
    {
      //      MessageBox (NULL, L"Transmission Failed" ,L"Error", MB_OK);
      return false;	
    }
}

int serialportc::ReadUart(const unsigned int len, char *buf2)
{
  BOOL ret;
  DWORD dwRead;
  unsigned long retlen=0;
    
  if (!ReadFile(hPort1, buf2, len, &dwRead,  NULL)) 	
    {	  	  
    }
  else
    {	  
      // MessageBox (NULL, L"ReadFile Suceess" ,L"Success", MB_OK);
    }      
 	
  if(dwRead > 0)	
    {
      retlen = dwRead;
      return (int) retlen;
    }
  else 
    return 0;     //else no data has been read
}



