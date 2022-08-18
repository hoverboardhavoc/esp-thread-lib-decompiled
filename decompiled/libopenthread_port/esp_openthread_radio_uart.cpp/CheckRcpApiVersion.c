/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> CheckRcpApiVersion
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::CheckRcpApiVersion(bool) */

int __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
CheckRcpApiVersion(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   *this,bool param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined3 in_register_0000202d;
  int aiStack_14 [4];
  
  aiStack_14[0] = 1;
  if ((CONCAT31(in_register_0000202d,param_1) == 0) ||
     (iVar1 = Get((ulong)this,(char *)0xb0,&_LC51,aiStack_14), iVar1 == 0)) {
    otLogNotePlat("RCP API Version: %u",aiStack_14[0]);
    iVar1 = 0;
    if (2 < aiStack_14[0] - 4U) {
      otLogCritPlat("RCP API Version %u is not in the supported range [%u-%u]",4,6);
      uVar2 = otExitCodeToString(3);
      otLogCritPlat("%s() at %s:%d: %s","CheckRcpApiVersion",
                    "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                    0x1a6,uVar2);
                    /* WARNING: Subroutine does not return */
      exit(3);
    }
  }
  return iVar1;
}

