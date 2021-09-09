/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  
  RVar1 = this[0x462];
  uVar2 = (uint)(byte)RVar1;
  if (((int)(uint)*(ushort *)(this + 0x460) >> (uVar2 & 0x1f) & 1U) == 0) {
    RVar5 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)0x1
    ;
    if (uVar2 < 0xf) {
      RVar5 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
              ((char)RVar1 + 1);
    }
    this[0x462] = RVar5;
    *(ushort *)(this + 0x460) = (ushort)(1 << (uVar2 & 0x1f)) | *(ushort *)(this + 0x460);
    if (uVar2 != 0) {
      iVar4 = SendCommand(this,param_1,param_2,(uchar)RVar1,param_3,param_4);
      if (iVar4 != 0) {
        return iVar4;
      }
      if (param_2 == 0x71) {
        if (this[0x463] !=
            (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)0x0
           ) {
          __assert_func(0,0,0);
        }
        this[0x463] = RVar1;
        return iVar4;
      }
      *(ulong *)(this + 0x468) = param_2;
      this[0x464] = RVar1;
      uVar3 = otPlatTimeGet();
      uVar2 = (uint)(uVar3 + 2000000 < uVar3) + extraout_a1;
      do {
        uVar6 = otPlatTimeGet();
        if (extraout_a1_00 < uVar2) goto _L0;
        if ((uVar2 == extraout_a1_00) && (extraout_a0 < uVar3 + 2000000)) goto _L0;
        do {
          uVar6 = HandleRcpTimeout();
_L0:
          iVar4 = esp::openthread::UartSpinelInterface::WaitForFrame(uVar6);
        } while (iVar4 != 0);
      } while ((this[0x464] !=
                (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0) || ((*(uint *)(this + 0x704) >> 1 & 1) == 0));
      LogIfFail("Error waiting response",*(undefined4 *)(this + 0x478));
      *(undefined4 *)(this + 0x468) = 0;
      return *(int *)(this + 0x478);
    }
  }
  return 5;
}

