/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> Process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::Process(esp_openthread_mainloop_context_t const&) */

void __thiscall
esp::openthread::UartSpinelInterface::Process
          (UartSpinelInterface *this,esp_openthread_mainloop_context_t *param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x4c);
  if ((uVar1 < 0x40) && ((1 << (uVar1 & 0x1f) & *(uint *)(param_1 + (uVar1 >> 5) * 4)) != 0)) {
    TryReadAndDecode(this);
    return;
  }
  return;
}

