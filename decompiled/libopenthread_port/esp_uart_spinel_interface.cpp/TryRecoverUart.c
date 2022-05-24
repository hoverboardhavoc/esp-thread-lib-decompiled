/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> TryRecoverUart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::TryRecoverUart() */

int __thiscall esp::openthread::UartSpinelInterface::TryRecoverUart(UartSpinelInterface *this)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 uVar4;
  
  iVar1 = DeinitUart(this);
  if (iVar1 == 0) {
    iVar1 = InitUart(this,(esp_openthread_uart_config_t *)(this + 0x24));
    if (iVar1 == 0) {
      return 0;
    }
    uVar2 = esp_log_timestamp();
    uVar4 = 0x121;
    puVar3 = &_LC7;
  }
  else {
    uVar2 = esp_log_timestamp();
    uVar4 = 0x120;
    puVar3 = &_LC6;
  }
  esp_log_write(1,"OPENTHREAD",puVar3,uVar2,"OPENTHREAD","TryRecoverUart",uVar4);
  return iVar1;
}

