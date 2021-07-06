/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioAddSrcMatchExtEntry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioAddSrcMatchExtEntry(int param_1)

{
  uint uVar1;
  otExtAddress aoStack_18 [20];
  
  for (uVar1 = 0; uVar1 < 8; uVar1 = uVar1 + 1) {
    aoStack_18[uVar1] = *(otExtAddress *)((7 - uVar1) + param_1);
  }
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  AddSrcMatchExtEntry((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                       *)s_radio,aoStack_18);
  return;
}

