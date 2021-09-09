/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> Deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::Deinit() */

undefined4 __thiscall esp::openthread::UartSpinelInterface::Deinit(UartSpinelInterface *this)

{
  undefined4 uVar1;
  
  if (*(int *)(this + 0x20) != 0) {
    heap_caps_free();
  }
  *(undefined4 *)(this + 0x20) = 0;
  if (*(int *)(this + 0x4c) == -1) {
    return 0x103;
  }
  close(*(int *)(this + 0x4c));
  *(undefined4 *)(this + 0x4c) = 0xffffffff;
  uVar1 = uart_driver_delete(*(undefined4 *)(this + 0x24));
  return uVar1;
}

