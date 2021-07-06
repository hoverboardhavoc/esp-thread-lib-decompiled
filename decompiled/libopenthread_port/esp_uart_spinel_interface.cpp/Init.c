/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> Init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::Init(esp_openthread_uart_config_t const&) */

undefined4 __thiscall
esp::openthread::UartSpinelInterface::Init
          (UartSpinelInterface *this,esp_openthread_uart_config_t *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = heap_caps_malloc(0x400,4);
  *(int *)(this + 0x20) = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0x101;
  }
  else {
    uVar2 = InitUart(this,param_1);
  }
  return uVar2;
}

