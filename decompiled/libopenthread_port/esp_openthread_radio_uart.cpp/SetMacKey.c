/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SetMacKey
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::SetMacKey(unsigned char, unsigned char, otMacKeyMaterial
   const*, otMacKeyMaterial const*, otMacKeyMaterial const*) */

int __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
SetMacKey(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this,
         uchar param_1,uchar param_2,otMacKeyMaterial *param_3,otMacKeyMaterial *param_4,
         otMacKeyMaterial *param_5)

{
  int iVar1;
  
  iVar1 = 7;
  if (((param_3 != (otMacKeyMaterial *)0x0) && (param_4 != (otMacKeyMaterial *)0x0)) &&
     (param_5 != (otMacKeyMaterial *)0x0)) {
    iVar1 = Set((ulong)this,(char *)0x800);
    if (iVar1 == 0) {
      this[0x708] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )param_1;
      this[0x709] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )param_2;
      memcpy(this + 0x70a,param_3,0x10);
      memcpy(this + 0x71a,param_4,0x10);
      memcpy(this + 0x72a,param_5,0x10);
      this[0x7a9] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )((byte)this[0x7a9] | 2);
    }
  }
  return iVar1;
}

