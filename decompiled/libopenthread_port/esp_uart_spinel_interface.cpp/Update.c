/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> Update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::Update(esp_openthread_mainloop_context_t&) */

void __thiscall
esp::openthread::UartSpinelInterface::Update
          (UartSpinelInterface *this,esp_openthread_mainloop_context_t *param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x4c);
  if (uVar1 < 0x40) {
    *(uint *)(param_1 + (uVar1 >> 5) * 4) =
         *(uint *)(param_1 + (uVar1 >> 5) * 4) | 1 << (uVar1 & 0x1f);
  }
  if (*(int *)(param_1 + 0x18) < (int)uVar1) {
    *(uint *)(param_1 + 0x18) = uVar1;
  }
  return;
}

