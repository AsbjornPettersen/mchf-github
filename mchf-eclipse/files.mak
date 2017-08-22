SRC := \
src/uhsdr_main.c \
misc/v_eprom/eeprom.c \
misc/config_storage.c \
misc/TestCPlusPlusBuild.cpp \
misc/profiling.c \
misc/serial_eeprom.c \
hardware/uhsdr_board.c \
hardware/uhsdr_hw_i2c.c \
hardware/uhsdr_rtc.c \
drivers/usb/device/class/composite/usbd_composite.c \
drivers/usb/device/class/composite/usbd_composite_desc.c \
drivers/usb/device/class/CDC/Src/usbd_cdc.c \
drivers/usb/device/class/AUDIO/Src/usbd_audio_cdc_comp.c \
drivers/usb/app/usb_device.c \
drivers/usb/app/usbd_audio_if.c \
drivers/usb/app/usbd_cdc_if.c \
drivers/usb/app/usbd_desc.c \
drivers/ui/oscillator/soft_tcxo.c \
drivers/ui/oscillator/ui_si570.c \
drivers/ui/menu/ui_menu.c \
drivers/ui/menu/ui_menu_internal.c \
drivers/ui/menu/ui_menu_structure.c \
drivers/ui/lcd/ui_lcd_hy28.c \
drivers/ui/lcd/ui_lcd_hy28_fonts.c \
drivers/ui/lcd/ui_spectrum.c \
drivers/ui/encoder/ui_rotary.c \
drivers/ui/radio_management.c \
drivers/ui/ui_configuration.c \
drivers/ui/ui_driver.c \
drivers/freedv/codebook.c \
drivers/freedv/codebookd.c \
drivers/freedv/codebookdt.c \
drivers/freedv/codebookge.c \
drivers/freedv/codebookjnd.c \
drivers/freedv/codebookjvm.c \
drivers/freedv/codebooklspmelvq.c \
drivers/freedv/codebookmel.c \
drivers/freedv/codebookres.c \
drivers/freedv/codebookvq.c \
drivers/freedv/codebookvqanssi.c \
drivers/freedv/codec2.c \
drivers/freedv/codec2_fft.c \
drivers/freedv/cohpsk.c \
drivers/freedv/dump.c \
drivers/freedv/fdmdv.c \
drivers/freedv/fifo.c \
drivers/freedv/fm.c \
drivers/freedv/fmfsk.c \
drivers/freedv/freedv_api.c \
drivers/freedv/freedv_data_channel.c \
drivers/freedv/freedv_vhf_framing.c \
drivers/freedv/fsk.c \
drivers/freedv/golay23.c \
drivers/freedv/interp.c \
drivers/freedv/kiss_fft.c \
drivers/freedv/kiss_fftr.c \
drivers/freedv/linreg.c \
drivers/freedv/lpc.c \
drivers/freedv/lsp.c \
drivers/freedv/modem_stats.c \
drivers/freedv/nlp.c \
drivers/freedv/octave.c \
drivers/freedv/pack.c \
drivers/freedv/phase.c \
drivers/freedv/postfilter.c \
drivers/freedv/quantise.c \
drivers/freedv/sine.c \
drivers/freedv/varicode.c \
drivers/cat/cat_driver.c \
drivers/audio/softdds/dds_table.c \
drivers/audio/softdds/softdds.c \
drivers/audio/filters/fir_rx_decimate_4.c \
drivers/audio/filters/fir_rx_decimate_4_min_lpf.c \
drivers/audio/filters/fir_rx_interpolate_16.c \
drivers/audio/filters/fir_rx_interpolate_16_10kHz.c \
drivers/audio/filters/iir_10k.c \
drivers/audio/filters/iir_10k_neu.c \
drivers/audio/filters/iir_15k_hpf_fm_squelch.c \
drivers/audio/filters/iir_1_4k.c \
drivers/audio/filters/iir_1_6k.c \
drivers/audio/filters/iir_1_8k.c \
drivers/audio/filters/iir_2_1k.c \
drivers/audio/filters/iir_2_3k.c \
drivers/audio/filters/iir_2_5k.c \
drivers/audio/filters/iir_2_7k.c \
drivers/audio/filters/iir_2_9k.c \
drivers/audio/filters/iir_2k7_tx_bpf.c \
drivers/audio/filters/iir_2k7_tx_bpf_fm.c \
drivers/audio/filters/iir_300hz.c \
drivers/audio/filters/iir_3_2k.c \
drivers/audio/filters/iir_3_4k.c \
drivers/audio/filters/iir_3_6k.c \
drivers/audio/filters/iir_3_8k.c \
drivers/audio/filters/iir_3k.c \
drivers/audio/filters/iir_4_2k.c \
drivers/audio/filters/iir_4_4k.c \
drivers/audio/filters/iir_4_6k.c \
drivers/audio/filters/iir_4_8k.c \
drivers/audio/filters/iir_4k.c \
drivers/audio/filters/iir_500hz.c \
drivers/audio/filters/iir_5_5k.c \
drivers/audio/filters/iir_5k.c \
drivers/audio/filters/iir_6_5k.c \
drivers/audio/filters/iir_6k.c \
drivers/audio/filters/iir_7_5k.c \
drivers/audio/filters/iir_7k.c \
drivers/audio/filters/iir_8_5k.c \
drivers/audio/filters/iir_8k.c \
drivers/audio/filters/iir_8k5_hpf_fm_squelch.c \
drivers/audio/filters/iir_9_5k.c \
drivers/audio/filters/iir_9k.c \
drivers/audio/filters/iir_antialias.c \
drivers/audio/filters/iq_rx_filter.c \
drivers/audio/filters/iq_rx_filter_am.c \
drivers/audio/filters/iq_tx_filter.c \
drivers/audio/cw/cw_gen.c \
drivers/audio/codec/codec.c \
drivers/audio/codec/uhsdr_hw_i2s.c \
drivers/audio/audio_driver.c \
drivers/audio/audio_filter.c \
drivers/audio/audio_management.c \
drivers/audio/freedv_uhsdr.c \
drivers/audio/freedv_test_data.c \
drivers/audio/rtty.c \
basesw/mcHF/Src/adc.c \
basesw/mcHF/Src/dac.c \
basesw/mcHF/Src/dma.c \
basesw/mcHF/Src/fatfs.c \
basesw/mcHF/Src/fsmc.c \
basesw/mcHF/Src/gpio.c \
basesw/mcHF/Src/i2c.c \
basesw/mcHF/Src/i2s.c \
basesw/mcHF/Src/main.c \
basesw/mcHF/Src/rtc.c \
basesw/mcHF/Src/spi.c \
basesw/mcHF/Src/stm32f4xx_hal_msp.c \
basesw/mcHF/Src/stm32f4xx_it.c \
basesw/mcHF/Src/tim.c \
basesw/mcHF/Src/usb_host.c \
basesw/mcHF/Src/usbd_conf.c \
basesw/mcHF/Src/usbh_conf.c \
basesw/mcHF/Src/user_diskio.c \
basesw/mcHF/Middlewares/Third_Party/FatFs/src/option/syscall.c \
basesw/mcHF/Middlewares/Third_Party/FatFs/src/option/unicode.c \
basesw/mcHF/Middlewares/Third_Party/FatFs/src/drivers/usbh_diskio.c \
basesw/mcHF/Middlewares/Third_Party/FatFs/src/diskio.c \
basesw/mcHF/Middlewares/Third_Party/FatFs/src/ff.c \
basesw/mcHF/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_core.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ctlreq.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ioreq.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_pipes.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp_ptp.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/HID/Src/usbh_hid.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/HID/Src/usbh_hid_keybd.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/HID/Src/usbh_hid_mouse.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/HID/Src/usbh_hid_parser.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Src/usbh_cdc.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/AUDIO/Src/usbh_audio.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cec.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_can.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_crc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cryp.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cryp_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dac.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dac_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dcmi.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dcmi_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dfsdm.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dsi.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_eth.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_fmpi2c.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_fmpi2c_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hash.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hash_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hcd.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_irda.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_iwdg.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_lptim.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_nand.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_nor.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pccard.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_qspi.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rng.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sai.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sai_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sd.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sdram.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_smartcard.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spdifrx.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sram.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_usart.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_wwdg.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fsmc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_sdmmc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c \
basesw/mcHF/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc/startup_stm32f407xx.S \
basesw/mcHF/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_bitreversal.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_bitreversal2.S \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_radix2_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_radix2_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_radix2_init_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_radix2_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_radix2_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_radix2_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_radix4_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_radix4_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_radix4_init_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_radix4_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_radix4_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_radix4_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_cfft_radix8_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_dct4_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_dct4_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_dct4_init_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_dct4_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_dct4_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_rfft_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_dct4_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_rfft_fast_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_rfft_fast_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_rfft_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_rfft_init_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_rfft_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_rfft_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/arm_rfft_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_copy_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_copy_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_copy_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_copy_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_fill_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_fill_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_fill_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_fill_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_float_to_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_float_to_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_float_to_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_q15_to_float.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_q15_to_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_q15_to_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_q31_to_float.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_q31_to_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_q31_to_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_q7_to_float.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_q7_to_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/arm_q7_to_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_max_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_max_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_max_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_max_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_mean_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_mean_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_mean_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_mean_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_min_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_min_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_min_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_min_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_power_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_power_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_power_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_power_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_rms_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_rms_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_rms_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_std_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_std_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_std_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_var_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_var_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/arm_var_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_add_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_add_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_add_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_cmplx_mult_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_cmplx_mult_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_cmplx_mult_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_init_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_inverse_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_inverse_f64.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_mult_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_mult_fast_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_mult_fast_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_mult_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_mult_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_scale_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_scale_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_scale_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_sub_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_sub_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_sub_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_trans_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_trans_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/arm_mat_trans_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_df1_32x64_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_df1_32x64_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_df1_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_df1_fast_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_df1_fast_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_df1_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_df1_init_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_df1_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_df1_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_df1_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_df2T_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_df2T_f64.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_df2T_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_df2T_init_f64.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_stereo_df2T_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_biquad_cascade_stereo_df2T_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_fast_opt_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_fast_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_fast_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_opt_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_opt_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_partial_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_partial_fast_opt_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_partial_fast_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_partial_fast_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_partial_opt_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_partial_opt_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_partial_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_partial_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_partial_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_conv_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_correlate_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_correlate_fast_opt_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_correlate_fast_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_correlate_fast_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_correlate_opt_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_correlate_opt_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_correlate_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_correlate_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_correlate_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_decimate_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_decimate_fast_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_decimate_fast_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_decimate_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_decimate_init_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_decimate_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_decimate_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_decimate_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_fast_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_fast_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_init_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_init_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_interpolate_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_interpolate_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_interpolate_init_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_interpolate_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_interpolate_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_interpolate_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_lattice_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_lattice_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_lattice_init_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_lattice_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_lattice_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_lattice_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_sparse_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_sparse_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_sparse_init_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_sparse_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_sparse_init_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_sparse_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_sparse_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_fir_sparse_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_iir_lattice_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_iir_lattice_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_iir_lattice_init_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_iir_lattice_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_iir_lattice_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_iir_lattice_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_lms_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_lms_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_lms_init_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_lms_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_lms_norm_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_lms_norm_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_lms_norm_init_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_lms_norm_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_lms_norm_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_lms_norm_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_lms_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/arm_lms_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FastMathFunctions/arm_cos_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FastMathFunctions/arm_cos_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FastMathFunctions/arm_cos_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FastMathFunctions/arm_sin_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FastMathFunctions/arm_sin_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FastMathFunctions/arm_sin_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FastMathFunctions/arm_sqrt_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/FastMathFunctions/arm_sqrt_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_init_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_pid_reset_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_sin_cos_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ControllerFunctions/arm_sin_cos_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_conj_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_conj_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_conj_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/CommonTables/arm_common_tables.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/CommonTables/arm_const_structs.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_abs_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_abs_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_abs_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_abs_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_add_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_add_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_add_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_add_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_dot_prod_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_dot_prod_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_dot_prod_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_dot_prod_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_mult_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_mult_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_mult_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_mult_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_negate_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_negate_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_negate_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_negate_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_offset_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_offset_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_offset_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_offset_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_scale_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_scale_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_scale_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_scale_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_shift_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_shift_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_shift_q7.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_sub_f32.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_sub_q15.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_sub_q31.c \
basesw/mcHF/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/arm_sub_q7.c \
 

