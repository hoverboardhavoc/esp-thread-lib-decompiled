/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> GetIeeeEui64
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::GetIeeeEui64(unsigned char*) */

undefined4 __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
GetIeeeEui64(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
             *this,uchar *param_1)

{
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar1;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar2;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar3;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar4;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar5;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar6;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar7;
  
  RVar1 = this[0x6f9];
  RVar2 = this[0x6fa];
  RVar3 = this[0x6fb];
  RVar4 = this[0x6fc];
  RVar5 = this[0x6fd];
  RVar6 = this[0x6fe];
  RVar7 = this[0x6ff];
  *param_1 = (uchar)this[0x6f8];
  *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
   (param_1 + 1) = RVar1;
  *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
   (param_1 + 2) = RVar2;
  *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
   (param_1 + 3) = RVar3;
  *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
   (param_1 + 4) = RVar4;
  *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
   (param_1 + 5) = RVar5;
  *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
   (param_1 + 6) = RVar6;
  *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
   (param_1 + 7) = RVar7;
  return 0;
}

