#include <stdio.h>
#include <vector>

#include "../Src/fill817.h"
#include "../Src/argstab.h"

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
	printf ("Open port %s\n",c.c_str());
	fill_buf b;
	b.setcmd(FT817_GET_FREQ);
      }
      break;
    default:
      printf ("Unknown command\n");
    };
}
