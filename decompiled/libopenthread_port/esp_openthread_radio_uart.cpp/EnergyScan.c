/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> EnergyScan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::EnergyScan(unsigned char, unsigned short) */

int __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
EnergyScan(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this
          ,uchar param_1,ushort param_2)

{
  int iVar1;
  
  if (((byte)this[0x670] & 2) == 0) {
    iVar1 = 0x1b;
  }
  else {
    this[0x7a2] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   )param_1;
    *(ushort *)(this + 0x7a4) = param_2;
    this[0x7a9] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   )((byte)this[0x7a9] | 0x80);
    iVar1 = Set((ulong)this,(char *)0x31);
    if (((iVar1 == 0) && (iVar1 = Set((ulong)this,(char *)0x32), iVar1 == 0)) &&
       (iVar1 = Set((ulong)this,(char *)0x30), iVar1 == 0)) {
      this[0x671] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )param_1;
    }
  }
  return iVar1;
}

