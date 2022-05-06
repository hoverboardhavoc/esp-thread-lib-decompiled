/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
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
    puVar3 = &_LC5;
  }
  else {
    uVar2 = esp_log_timestamp();
    uVar4 = 0x120;
    puVar3 = &_LC4;
  }
  esp_log_write(1,"OPENTHREAD",puVar3,uVar2,"OPENTHREAD","TryRecoverUart",uVar4);
  return iVar1;
}

