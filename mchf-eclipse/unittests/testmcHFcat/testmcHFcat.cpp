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

static void show_commands()
{
  printf ("Baudrates: 115200,57600,38400,19200,9600,4800,2400\n");

  printf ("Commands:\n");
  fill_ft817 t;
  fill_buf b;
  for (auto i = t.v.cbegin(); i != t.v.cend(); i++)
    {
      Ft817_CatCmd_t cmd = *i;
      printf ("cmd=%3d %s\n",cmd,b.cmd_cstr(cmd));
    }
}

int main(int argc, char **argv) 
{
  if (argc <= 1)
    {
      printf ("%s\n",argv[0]);
      printf ("options :\n");
      printf (" 0 :  Info\n");
      printf (" 1 :  Display mcHF status -port <COM port> -b <baudrate> -cmd <command>\n");

      return 0;
    }

  argstab args;
  args.get_arguments(argc, argv);
  args.dump();
  switch (args.get_ch0())   
    {
    case '0':
      {
	show_commands();
      };
      break;
    case '1':
      {
	Ft817_CatCmd_t cmd = FT817_GET_FREQ;
	unsigned int val;
	if (args.get_param_uint("-cmd", val))
	  {
	    cmd = (Ft817_CatCmd_t) val;
	    fill_buf b;
	    printf ("cmd=%3d %s\n",cmd,b.cmd_cstr(cmd));
	  }
	serialportc h;

	std::string c = args.get_param("-port");
	std::string comname;
	h.map_com_names(c, comname);
	printf ("Open port %s\n",comname.c_str());

	if (!h.create(comname.c_str()))
	  {
	    printf ("can't open %s\n", comname.c_str());
	    return 0;
	  }

	std::string baudrate = "4800";
	c = args.get_param("-b");
	if (c.length() > 0)
	  {
	    bool found;
	    int ind = h.baudrate_to_index(c, found);
	    if (found)
	      baudrate = c;
	  }
		
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
	b.setcmd(cmd, 0x0000,response_len);

	bool ok = h.WriteUart(b.buf, 5);

	fill_buf bread;
	int br = h.ReadUart(response_len, (char *)bread.buf);
	printf ("b=%d %s\n",br,bread.buf);
	if (br > 0)
	  bread.show_ft817();

	h.Close();
      }
      break;
    default:
      printf ("Unknown command\n");
    };
}
