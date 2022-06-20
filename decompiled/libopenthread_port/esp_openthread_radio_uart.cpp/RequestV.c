/*
 * Last changed at upstream commit b6b61e3d4891c01e9b44cc1a27e741288192b537
 * https://github.com/espressif/esp-thread-lib/commit/b6b61e3d4891c01e9b44cc1a27e741288192b537
 * Upstream date: 2022-06-20 16:22:56 +0800
 * Upstream subject: openthread: update OpenThread submodule
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> RequestV
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::RequestV(unsigned long, unsigned long, char const*, void*) */

void * __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
RequestV(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this,
        ulong param_1,ulong param_2,char *param_3,void *param_4)

{
  uint extraout_a0;
  int iVar1;
  uint uVar2;
  uint uVar3;
  int extraout_a1;
  uint extraout_a1_00;
  ulong extraout_a1_01;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar4;
  uint uVar5;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar6;
  uint uVar7;
  ulonglong uVar8;
  
  uVar2 = (uint)(byte)this[0x466];
  uVar5 = (uint)*(ushort *)(this + 0x464);
  uVar7 = 0xe;
  uVar3 = uVar2;
  do {
    if (((int)uVar5 >> (uVar2 & 0x1f) & 1U) == 0) {
      *(ushort *)(this + 0x464) = (ushort)uVar5 | (ushort)(1 << (uVar2 & 0x1f));
      RVar4 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
              0x1;
      RVar6 = SUB41(uVar2,0);
      if (uVar2 < 0xf) {
        RVar4 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )((char)RVar6 + '\x01');
      }
      this[0x466] = RVar4;
      if (uVar2 == 0) {
        return (void *)0x5;
      }
      param_4 = (void *)SendCommand(this,param_1,param_2,(uchar)RVar6,param_3,param_4);
      if (param_4 != (void *)0x0) {
        return param_4;
      }
      if (param_2 != 0x71) {
        this[0x468] = RVar6;
        *(ulong *)(this + 0x46c) = param_2;
        uVar3 = otPlatTimeGet();
        uVar2 = (uint)(uVar3 + 2000000 < uVar3) + extraout_a1;
        otLogDebgPlat("Wait response: tid=%u key=%u",this[0x468],*(undefined4 *)(this + 0x46c));
        break;
      }
      if (this[0x467] ==
          (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)0x0)
      {
        this[0x467] = RVar6;
        return (void *)0x0;
      }
      param_3 = (char *)0x0;
      uVar5 = 0;
      uVar3 = __assert_func(0);
      param_1 = extraout_a1_01;
    }
    if (uVar7 < uVar2) {
      uVar2 = 1;
    }
    else {
      uVar2 = uVar2 + 1 & 0xff;
    }
    if (uVar3 == uVar2) {
      return (void *)0x5;
    }
  } while( true );
_L0:
  uVar8 = otPlatTimeGet();
  if (((uVar2 <= extraout_a1_00) && ((uVar2 != extraout_a1_00 || (uVar3 + 2000000 <= extraout_a0))))
     || (iVar1 = esp::openthread::UartSpinelInterface::WaitForFrame(uVar8), iVar1 != 0)) {
    otLogWarnPlat("Wait for response timeout");
    *(undefined4 *)(this + 0x47c) = 0;
    this[0x7a9] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   )((byte)this[0x7a9] | 0x40);
    goto _L0;
  }
  if ((this[0x468] ==
       (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)0x0) &&
     ((*(uint *)(this + 0x704) >> 1 & 1) != 0)) {
    LogIfFail("Error waiting response",*(undefined4 *)(this + 0x47c));
    *(undefined4 *)(this + 0x46c) = 0;
_L0:
    return *(void **)(this + 0x47c);
  }
  goto _L0;
}

