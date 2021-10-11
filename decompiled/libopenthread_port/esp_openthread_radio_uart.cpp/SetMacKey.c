/*
 * Last changed at upstream commit 06ac9b875d9791f909572a74898757410582e76c
 * https://github.com/espressif/esp-thread-lib/commit/06ac9b875d9791f909572a74898757410582e76c
 * Upstream date: 2021-10-11 18:13:07 +0800
 * Upstream subject: openthread: update openthread(eb1de3d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SetMacKey
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::SetMacKey(unsigned char, unsigned char, otMacKeyMaterial
   const*, otMacKeyMaterial const*, otMacKeyMaterial const*) */

undefined4
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
SetMacKey(uchar param_1,uchar param_2,otMacKeyMaterial *param_3,otMacKeyMaterial *param_4,
         otMacKeyMaterial *param_5)

{
  undefined3 in_register_00002029;
  undefined4 uVar1;
  int in_a5;
  
  if (((param_4 != (otMacKeyMaterial *)0x0) && (param_5 != (otMacKeyMaterial *)0x0)) && (in_a5 != 0)
     ) {
    uVar1 = Set(CONCAT31(in_register_00002029,param_1),(char *)0x800);
    return uVar1;
  }
  return 7;
}

