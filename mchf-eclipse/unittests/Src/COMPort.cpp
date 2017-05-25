#include "COMPort.h"
//#include <commctrl.h>
#include <windows.h>
#include <tchar.h>
#include <stdio.h>


int                SetupUart();
int                SetupUart2();
int                WriteUart(unsigned char *buf1, int len,HANDLE);
int                ReadUart(int len,HANDLE);
int                configure(),configuretimeout(),CloseUart(),CloseUart2();


HANDLE         LPort;
DCB            PortDCB; 
COMMTIMEOUTS   CommTimeouts; 
HANDLE         hPort2;
char           lastError[1024],buf1[100],buf2[100];
int            index1=-1,index2=-1,index3=-1,index4=-1,index5=-1,index6=-1,index7=-1;
char           buff;

class serialportc
{
public:
  HANDLE hPort1 = nullptr;
  serialportc()
  {
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
    CloseHandle(hPort1);
    hPort1 = nullptr;
    return true;
  };
};
serialportc h1;
serialportc h2;

#if 0
// Message handler for about box.
INT_PTR CALLBACK Port(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{	
SendDlgItemMessageA(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"9600");
SendDlgItemMessageA(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"19200");
SendDlgItemMessageA(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"38400");
SendDlgItemMessageA(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"57600");
SendDlgItemMessageA(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"115200");
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
SendDlgItemMessageA(hDlg, IDC_COMBO6, CB_ADDSTRING, 0, (LPARAM)"COM1");
SendDlgItemMessageA(hDlg, IDC_COMBO6, CB_ADDSTRING, 0, (LPARAM)"COM5");
SendDlgItemMessageA(hDlg, IDC_COMBO7, CB_ADDSTRING, 0, (LPARAM)"COM1");
SendDlgItemMessageA(hDlg, IDC_COMBO7, CB_ADDSTRING, 0, (LPARAM)"COM5");

 case WM_COMMAND:
   switch(LOWORD(wParam)) 
     {   
   if(LOWORD(wParam)== IDOK)
     {       
       if((index1==-1)||(index2==-1)||(index3==-1)||(index4==-1)||(index5==-1)||(index6==-1)||(index6==-1))
	 {
	   MessageBoxA(hDlg,(LPCSTR)"Select the property of COM Port",(LPCSTR)"Error", MB_OK);	   
	 }
       else
	 {	 
	   SetupUart();
	   return (INT_PTR)TRUE;
	 }       
     }
#endif

int SetupUart()
{
  int STOPBITS;
  
  if (!h1.create("COM5"))
    return 0;

  //Initialize the DCBlength member. 
  PortDCB.DCBlength = sizeof (DCB); 
  
  // Get the default port setting information.
  GetCommState (h1.hPort1, &PortDCB);
  configure();
  
  // Retrieve the time-out parameters for all read and write operations  
  GetCommTimeouts (h1.hPort1, &CommTimeouts); 
  configuretimeout();
    
  //Re-configure the port with the new DCB structure. 
  if (!SetCommState (h1.hPort1, &PortDCB)) 
    { 
      MessageBox (NULL, L"1.Could not create the read thread.(SetCommState Failed)" ,L"Error", MB_OK);
      h1.Close();   
      return 0; 
    } 
  
  // Set the time-out parameters for all read and write operations on the port. 
  if (!SetCommTimeouts (h1.hPort1, &CommTimeouts)) 
    { 
      MessageBox (NULL, L"Could not create the read thread.(SetCommTimeouts Failed)" ,L"Error", MB_OK);
      h1.Close(); 
      return 0; 
    } 
  
  // Clear the port of any existing data. 
  if(PurgeComm(h1.hPort1, PURGE_TXCLEAR | PURGE_RXCLEAR)==0) 
    {   MessageBox (NULL, L"Clearing The Port Failed" ,L"Message", MB_OK);
      
      h1.Close(); 
      return 0; 
    }   
  return 1;
}

int SetupUart2()
{
  int STOPBITS;

  if (!h2.create("COM1"))
    return 0;
  
  // Initialize the DCBlength member. 
  PortDCB.DCBlength = sizeof (DCB); 
  
  // Get the default port setting information.
  GetCommState (h2.hPort1, &PortDCB);
  configure();
  
  
  // Retrieve the time-out parameters for all read and write operations  
  GetCommTimeouts (h2.hPort1, &CommTimeouts);
  configuretimeout();
	
	//Re-configure the port with the new DCB structure. 
  if (!SetCommState (h2.hPort1, &PortDCB)) 
    { 
      MessageBox (NULL, L"1.Could not create the read thread.(SetCommState Failed)" ,L"Error", MB_OK);
      h2.Close();   
      return 0; 
    } 
  
  // Set the time-out parameters for all read and write operations on the port. 
  if (!SetCommTimeouts (hPort2, &CommTimeouts)) 
    { 
      MessageBox (NULL, L"Could not create the read thread.(SetCommTimeouts Failed)" ,L"Error", MB_OK);
      h2.Close();   
      return 0; 
    } 
  
  // Clear the port of any existing data. 
  if(PurgeComm(h2.hPort1, PURGE_TXCLEAR | PURGE_RXCLEAR)==0) 
    {   MessageBox (NULL, L"Clearing The Port Failed" ,L"Message", MB_OK);
      h2.Close();
      return 0; 
    } 
 
  return 1;
}

int configure()
{	
  // Change the DCB structure settings
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
      PortDCB.BaudRate = 19200;            
      break;
    case 2:
      PortDCB.BaudRate= 38400;            
      break;
    case 3:
      PortDCB.BaudRate = 57600;            
      break;
    case 4:
      PortDCB.BaudRate = 9600;            
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
  return 1;
}

int configuretimeout()
{
	//memset(&CommTimeouts, 0x00, sizeof(CommTimeouts)); 
  CommTimeouts.ReadIntervalTimeout = 50; 
  CommTimeouts.ReadTotalTimeoutConstant = 50; 
  CommTimeouts.ReadTotalTimeoutMultiplier=10;
  CommTimeouts.WriteTotalTimeoutMultiplier=10;
  CommTimeouts.WriteTotalTimeoutConstant = 50; 
  return 1;
}
int WriteUart(unsigned char *buf1, int len,HANDLE hPort)
{
  DWORD dwNumBytesWritten;
  
  WriteFile (hPort,buf1, len,&dwNumBytesWritten,NULL);			
  
  if(dwNumBytesWritten > 0)
    {
      //MessageBox (NULL, L"Transmission Success" ,L"Success", MB_OK);
      return 1;
    }
  
  else 
    {
      MessageBox (NULL, L"Transmission Failed" ,L"Error", MB_OK);
      return 0;	
    }
}

int ReadUart(int len,HANDLE hPort)
{
  BOOL ret;
  DWORD dwRead;
  BOOL fWaitingOnRead = FALSE;
  OVERLAPPED osReader = {0};
  unsigned long retlen=0;
  
  // Create the overlapped event. Must be closed before exiting to avoid a handle leak.
  
  osReader.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
  if (osReader.hEvent == NULL)
    MessageBox (NULL, L"Error in creating Overlapped event" ,L"Error", MB_OK);
  if (!fWaitingOnRead)
    {
      if (!ReadFile(hPort, buf2, len, &dwRead,  &osReader)) 	
	{	  
          FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                        NULL,
                        GetLastError(),
                        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                        (LPWSTR)lastError,
                        1024,
                        NULL);
	  MessageBox (NULL, (LPWSTR)lastError ,L"MESSAGE", MB_OK);
	  
	}
      else
	{
	  
	  // MessageBox (NULL, L"ReadFile Suceess" ,L"Success", MB_OK);
	}
      
    }
 	
  if(dwRead > 0)	
    {
      //MessageBox (NULL, L"Read DATA Success" ,L"Success", MB_OK);//If we have data
      return (int) retlen;
    }
  //return the length
  
  else return 0;     //else no data has been read
}

int CloseUart()
{
  h1.Close(); 
  return 1;
}
int CloseUart2()
{
  CloseHandle(hPort2);
  return 1;
}

