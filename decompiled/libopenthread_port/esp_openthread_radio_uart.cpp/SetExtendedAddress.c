/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SetExtendedAddress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::SetExtendedAddress(otExtAddress const&) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
SetExtendedAddress(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   *this,otExtAddress *param_1)

{
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar1;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar2;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar3;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar4;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar5;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar6;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar7;
  int iVar8;
  
  iVar8 = Set((ulong)this,(char *)0x34);
  if (iVar8 == 0) {
    RVar1 = *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             (param_1 + 1);
    RVar2 = *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             (param_1 + 2);
    RVar3 = *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             (param_1 + 3);
    RVar4 = *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             (param_1 + 4);
    RVar5 = *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             (param_1 + 5);
    RVar6 = *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             (param_1 + 6);
    RVar7 = *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             (param_1 + 7);
    this[0x664] = *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    *)param_1;
    this[0x665] = RVar1;
    this[0x666] = RVar2;
    this[0x667] = RVar3;
    this[0x668] = RVar4;
    this[0x669] = RVar5;
    this[0x66a] = RVar6;
    this[0x66b] = RVar7;
  }
  return;
}

