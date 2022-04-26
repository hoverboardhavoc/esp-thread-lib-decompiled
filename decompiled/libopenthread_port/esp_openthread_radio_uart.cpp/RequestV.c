/*
 * Last changed at upstream commit 90d32076b158280332a6f931440e2145c0d51b08
 * https://github.com/espressif/esp-thread-lib/commit/90d32076b158280332a6f931440e2145c0d51b08
 * Upstream date: 2022-04-26 15:33:17 +0800
 * Upstream subject: openthread: support esp32h2beta1 & esp32h2beta2
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
  uint uVar1;
  uint uVar2;
  uint extraout_a0;
  int iVar3;
  int extraout_a1;
  uint extraout_a1_00;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar4;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar5;
  ulonglong uVar6;
  
  uVar1 = (uint)(byte)this[0x462];
  while (((int)(uint)*(ushort *)(this + 0x460) >> (uVar1 & 0x1f) & 1U) != 0) {
    if (uVar1 < 0xf) {
      uVar1 = uVar1 + 1 & 0xff;
    }
    else {
      uVar1 = 1;
    }
    if ((byte)this[0x462] == uVar1) {
      return 5;
    }
  }
  *(ushort *)(this + 0x460) = (ushort)(1 << (uVar1 & 0x1f)) | *(ushort *)(this + 0x460);
  RVar5 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)0x1;
  RVar4 = SUB41(uVar1,0);
  if (uVar1 < 0xf) {
    RVar5 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
            ((char)RVar4 + '\x01');
  }
  this[0x462] = RVar5;
  if (uVar1 == 0) {
    return 5;
  }
  iVar3 = SendCommand(this,param_1,param_2,(uchar)RVar4,param_3,param_4);
  if (iVar3 != 0) {
    return iVar3;
  }
  if (param_2 != 0x71) {
    *(ulong *)(this + 0x468) = param_2;
    this[0x464] = RVar4;
    uVar2 = otPlatTimeGet();
    uVar1 = (uint)(uVar2 + 2000000 < uVar2) + extraout_a1;
    otLogDebgPlat("Wait response: tid=%u key=%u",this[0x464],*(undefined4 *)(this + 0x468));
    do {
      uVar6 = otPlatTimeGet();
      if (extraout_a1_00 < uVar1) goto _L0;
      if ((uVar1 == extraout_a1_00) && (extraout_a0 < uVar2 + 2000000)) goto _L0;
      do {
        uVar6 = HandleRcpTimeout();
_L0:
        iVar3 = esp::openthread::UartSpinelInterface::WaitForFrame(uVar6);
      } while (iVar3 != 0);
    } while ((this[0x464] !=
              (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
              0x0) || ((*(uint *)(this + 0x704) >> 1 & 1) == 0));
    LogIfFail("Error waiting response",*(undefined4 *)(this + 0x478));
    *(undefined4 *)(this + 0x468) = 0;
    return *(int *)(this + 0x478);
  }
  if (this[0x463] !=
      (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)0x0) {
    __assert_func(0,0,0);
  }
  this[0x463] = RVar4;
  return iVar3;
}

