/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioSetShortAddress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioSetShortAddress(ushort param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SetShortAddress((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                           *)s_radio,param_1);
  if (iVar1 == 0) {
    return;
  }
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SetShortAddress((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                           *)s_radio,param_1);
  if (iVar1 == 7) {
    uVar2 = 2;
  }
  else {
    uVar2 = 1;
  }
  uVar2 = otExitCodeToString(uVar2);
  otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","otPlatRadioSetShortAddress",
            "/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_radio_uart.cpp"
            ,0x4f,uVar2);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SetShortAddress((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                           *)s_radio,param_1);
  if (iVar1 == 7) {
    iVar1 = 2;
  }
  else {
    iVar1 = 1;
  }
                    /* WARNING: Subroutine does not return */
  exit(iVar1);
}

