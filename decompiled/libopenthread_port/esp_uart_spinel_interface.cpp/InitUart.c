/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> InitUart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::InitUart(esp_openthread_uart_config_t const&) */

int __thiscall
esp::openthread::UartSpinelInterface::InitUart
          (UartSpinelInterface *this,esp_openthread_uart_config_t *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  char acStack_20 [16];
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar11 = *(undefined4 *)(param_1 + 8);
  uVar10 = *(undefined4 *)(param_1 + 0xc);
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  uVar5 = *(undefined4 *)(param_1 + 0x14);
  uVar6 = *(undefined4 *)(param_1 + 0x18);
  uVar7 = *(undefined4 *)(param_1 + 0x1c);
  uVar8 = *(undefined4 *)(param_1 + 0x20);
  uVar9 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x28) = uVar1;
  *(undefined4 *)(this + 0x2c) = uVar11;
  *(undefined4 *)(this + 0x30) = uVar10;
  *(undefined4 *)(this + 0x34) = uVar2;
  *(undefined4 *)(this + 0x38) = uVar5;
  *(undefined4 *)(this + 0x3c) = uVar6;
  *(undefined4 *)(this + 0x40) = uVar7;
  *(undefined4 *)(this + 0x44) = uVar8;
  *(undefined4 *)(this + 0x48) = uVar9;
  iVar3 = esp_openthread_uart_init_port(param_1);
  if (iVar3 == 0) {
    esp_vfs_dev_uart_port_set_tx_line_endings(*(undefined4 *)(this + 0x24),2);
    esp_vfs_dev_uart_port_set_rx_line_endings(*(undefined4 *)(this + 0x24),2);
    snprintf(acStack_20,0x10,"/dev/uart/%d");
    iVar4 = open(acStack_20,0x4002);
    *(int *)(this + 0x4c) = iVar4;
    if (iVar4 < 0) {
      iVar3 = -1;
    }
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC3,uVar1,"OPENTHREAD","InitUart",0x109);
  }
  return iVar3;
}

