/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> esp_openthread_radio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */
/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */

esp_err_t esp_openthread_radio_init(esp_openthread_platform_config_t *config)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = esp::openthread::UartSpinelInterface::Init
                    ((esp_openthread_uart_config_t *)&s_radio.mSpinelInterface);
  if (iVar1 == 0) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
    ::Init(&s_radio,true,false,false);
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC30,uVar2,"OPENTHREAD","esp_openthread_radio_init",0x22);
  }
  return iVar1;
}

