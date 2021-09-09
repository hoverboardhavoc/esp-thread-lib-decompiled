/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  int local_14 [3];
  
  local_14[0] = 1;
  if ((CONCAT31(in_register_0000202d,param_1) == 0) ||
     (iVar1 = Get((ulong)this,(char *)0xb0,&_LC11,local_14), iVar1 == 0)) {
    otLogNote(0xc,"-PLAT----: ","RCP API Version: %u",local_14[0]);
    iVar1 = 0;
    if (2 < local_14[0] - 1U) {
      otLogCrit(0xc,"-PLAT----: ","RCP API Version %u is not in the supported range [%u-%u]",1,3);
      uVar2 = otExitCodeToString(3);
      otLogCrit(0xc,"-PLAT----: ","%s() at %s:%d: %s","CheckRcpApiVersion",
                "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x19e,
                uVar2);
                    /* WARNING: Subroutine does not return */
      exit(3);
    }
  }
  return iVar1;
}

