/*
 * Last changed at upstream commit 7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * https://github.com/espressif/esp-thread-lib/commit/7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * Upstream date: 2021-11-03 15:55:12 +0800
 * Upstream subject: openthread: mdns & RCP ota update(3571cf8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioSleep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioSleep(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (((DAT_000134c0 != 1) && (iVar1 = 0xd, DAT_000134c0 == 2)) &&
     (iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x12dc0,(char *)0x37), iVar1 == 0)) {
    DAT_000134c0 = 1;
  }
  return iVar1;
}

