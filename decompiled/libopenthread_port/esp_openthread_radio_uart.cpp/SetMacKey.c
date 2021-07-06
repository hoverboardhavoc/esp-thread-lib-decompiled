/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SetMacKey
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::SetMacKey(unsigned char, unsigned char, otMacKey const&,
   otMacKey const&, otMacKey const&) */

void ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
     ::SetMacKey(uchar param_1,uchar param_2,otMacKey *param_3,otMacKey *param_4,otMacKey *param_5)

{
  undefined3 in_register_00002029;
  undefined3 in_register_0000202d;
  
  Set(CONCAT31(in_register_00002029,param_1),(char *)0x800,"CCddd",
      CONCAT31(in_register_0000202d,param_2),param_3,param_4,param_5);
  return;
}

