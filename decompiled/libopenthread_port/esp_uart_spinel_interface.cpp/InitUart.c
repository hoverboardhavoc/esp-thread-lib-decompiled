/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> InitUart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: uart_path */
/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: esp_err_t InitUart(UartSpinelInterface * this,
   esp_openthread_uart_config_t * radio_uart_config) */

esp_err_t __thiscall
esp::openthread::UartSpinelInterface::InitUart
          (UartSpinelInterface *this,esp_openthread_uart_config_t *radio_uart_config)

{
  uint8_t uVar1;
  undefined3 uVar2;
  int iVar3;
  uart_stop_bits_t uVar4;
  undefined4 uVar5;
  uart_hw_flowcontrol_t uVar6;
  anon_union_4_2_cef08224_for_13uart_config_t_7 aVar7;
  int iVar8;
  int iVar9;
  uart_parity_t uVar10;
  uart_word_length_t uVar11;
  char acStack_20 [4];
  char uart_path [16];
  
  iVar3 = (radio_uart_config->uart_config).baud_rate;
  uVar11 = (radio_uart_config->uart_config).data_bits;
  uVar10 = (radio_uart_config->uart_config).parity;
  uVar4 = (radio_uart_config->uart_config).stop_bits;
  uVar6 = (radio_uart_config->uart_config).flow_ctrl;
  uVar1 = (radio_uart_config->uart_config).rx_flow_ctrl_thresh;
  uVar2 = *(undefined3 *)&(radio_uart_config->uart_config).field_0x15;
  aVar7 = (radio_uart_config->uart_config).field_6;
  iVar8 = radio_uart_config->rx_pin;
  iVar9 = radio_uart_config->tx_pin;
  (this->m_uart_config).port = radio_uart_config->port;
  (this->m_uart_config).uart_config.baud_rate = iVar3;
  (this->m_uart_config).uart_config.data_bits = uVar11;
  (this->m_uart_config).uart_config.parity = uVar10;
  (this->m_uart_config).uart_config.stop_bits = uVar4;
  (this->m_uart_config).uart_config.flow_ctrl = uVar6;
  (this->m_uart_config).uart_config.rx_flow_ctrl_thresh = uVar1;
  *(undefined3 *)&(this->m_uart_config).uart_config.field_0x15 = uVar2;
  (this->m_uart_config).uart_config.field_6 = aVar7;
  (this->m_uart_config).rx_pin = iVar8;
  (this->m_uart_config).tx_pin = iVar9;
  iVar3 = esp_openthread_uart_init_port(radio_uart_config);
  if (iVar3 == 0) {
    esp_vfs_dev_uart_port_set_tx_line_endings((this->m_uart_config).port,2);
    esp_vfs_dev_uart_port_set_rx_line_endings((this->m_uart_config).port,2);
    snprintf(acStack_20,0x10,"/dev/uart/%d");
    iVar8 = open(acStack_20,0x4002);
    this->m_uart_fd = iVar8;
    if (iVar8 < 0) {
      iVar3 = -1;
    }
  }
  else {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC3,uVar5,"OPENTHREAD","InitUart",0x109);
  }
  return iVar3;
}

