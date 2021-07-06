/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> DeinitUart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::DeinitUart() */

undefined4 __thiscall esp::openthread::UartSpinelInterface::DeinitUart(UartSpinelInterface *this)

{
  undefined4 uVar1;
  
  if (*(int *)(this + 0x4c) != -1) {
    close(*(int *)(this + 0x4c));
    *(undefined4 *)(this + 0x4c) = 0xffffffff;
    uVar1 = uart_driver_delete(*(undefined4 *)(this + 0x24));
    return uVar1;
  }
  return 0x103;
}

