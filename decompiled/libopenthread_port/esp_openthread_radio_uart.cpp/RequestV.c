/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> RequestV
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::RequestV(unsigned long, unsigned long, char const*, void*) */

int __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
RequestV(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this,
        ulong param_1,ulong param_2,char *param_3,void *param_4)

{
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar1;
  uint uVar2;
  uint uVar3;
  uint extraout_a0;
  int iVar4;
  int extraout_a1;
  uint extraout_a1_00;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar5;
  ulonglong uVar6;
  
  RVar1 = this[0x466];
  uVar2 = (uint)(byte)RVar1;
  if (((int)(uint)*(ushort *)(this + 0x464) >> (uVar2 & 0x1f) & 1U) == 0) {
    RVar5 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)0x1
    ;
    if (uVar2 < 0xf) {
      RVar5 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
              ((char)RVar1 + 1);
    }
    this[0x466] = RVar5;
    *(ushort *)(this + 0x464) = (ushort)(1 << (uVar2 & 0x1f)) | *(ushort *)(this + 0x464);
    if (uVar2 != 0) {
      iVar4 = SendCommand(this,param_1,param_2,(uchar)RVar1,param_3,param_4);
      if (iVar4 != 0) {
        return iVar4;
      }
      if (param_2 == 0x71) {
        if (this[0x467] !=
            (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)0x0
           ) {
          __assert_func(0,0,0);
        }
        this[0x467] = RVar1;
        return iVar4;
      }
      *(ulong *)(this + 0x46c) = param_2;
      this[0x468] = RVar1;
      uVar3 = otPlatTimeGet();
      uVar2 = (uint)(uVar3 + 2000000 < uVar3) + extraout_a1;
      otLogDebgPlat("Wait response: tid=%u key=%u",this[0x468],*(undefined4 *)(this + 0x46c));
      while (((uVar6 = otPlatTimeGet(), extraout_a1_00 < uVar2 ||
              ((uVar2 == extraout_a1_00 && (extraout_a0 < uVar3 + 2000000)))) &&
             (iVar4 = esp::openthread::UartSpinelInterface::WaitForFrame(uVar6), iVar4 == 0))) {
        if ((this[0x468] ==
             (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
             0x0) && ((*(uint *)(this + 0x704) >> 1 & 1) != 0)) {
          LogIfFail("Error waiting response",*(undefined4 *)(this + 0x47c));
          *(undefined4 *)(this + 0x46c) = 0;
_L0:
          return *(int *)(this + 0x47c);
        }
      }
      *(undefined4 *)(this + 0x47c) = 0;
      this[0x7a9] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )((byte)this[0x7a9] | 0x40);
      goto _L0;
    }
  }
  return 5;
}

