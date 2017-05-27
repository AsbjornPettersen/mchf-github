#include <stdio.h>
#include <vector>

#define WINDOWS_ONLY

#include "../Src/fill817.h"
#include "../Src/argstab.h"
#include "../Src/COMPort.h"

#if 0
uint8_t CDC_Transmit_FS(uint8_t* Buf,uint32_t Len) {  return 0; }
bool RadioManagement_FmDevIs5khz() {  return false; }
void RadioManagement_FmDevSet5khz(bool is5khz) {  return; }
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
struct TransceiverState volatile ts;
#endif

int main(int argc, char **argv) 
{
  if (argc <= 1)
    {
      printf ("%s\n",argv[0]);
      printf ("options :\n");
      printf (" 0 :  Display mcHF status -port <COM port>\n");
      return 0;
    }

  argstab args;
  args.get_arguments(argc, argv);
  args.dump();
  switch (args.get_ch0())
    {
    case '0':
      {
	std::string c = args.get_param("-port");
	std::string comname = "COM" + c;
	printf ("Open port %s\n",comname.c_str());
	serialportc h;
	if (!h.create(comname.c_str()))
	  {
	    printf ("can't open %s\n", comname.c_str());
	    return 0;
	  }
	//	const std::string baudrate = "115200";
		const std::string baudrate = "4800";
	h.configure(baudrate);
	h.configuretimeout();
	if (!h.set_configured())
	  {
	    printf ("can't configure %s\n", comname.c_str());
	    return 0;
	  }

	h.purge();
	
	fill_buf b;
	unsigned int response_len;
	b.setcmd(FT817_GET_FREQ, response_len);

	char buf[1000];
	memset (buf,0x00,sizeof(buf));
	
	int br = h.ReadUart(response_len, buf);
	printf ("b=%d %s\n",br,buf);
	//	bool ok = h.WriteUart(b.buf, 5);
	h.Close();
      }
      break;
    default:
      printf ("Unknown command\n");
    };
}
