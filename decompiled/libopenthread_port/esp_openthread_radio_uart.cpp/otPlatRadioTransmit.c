/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioTransmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioTransmit(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int extraout_a1;
  
  if (DAT_000134a8 != 2) {
    if (DAT_000134a8 != 1) {
      return 0xd;
    }
    if ((DAT_00013418 & 0x10) == 0) {
      return 0xd;
    }
  }
  DAT_00013408 = param_1;
  otPlatRadioTxStarted(s_radio);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Request(0x12da8,3,(char *)0x71);
  if (iVar1 == 0) {
    DAT_000134a8 = 3;
    uVar2 = otPlatTimeGet();
    DAT_000134b8 = uVar2 + 5000000;
    DAT_000134bc = (uint)(DAT_000134b8 < uVar2) + extraout_a1;
  }
  return iVar1;
}

