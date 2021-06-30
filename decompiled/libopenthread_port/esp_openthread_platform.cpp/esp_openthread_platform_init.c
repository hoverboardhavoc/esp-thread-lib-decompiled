/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_platform.cpp.o -> esp_openthread_platform_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_openthread_platform_init(esp_openthread_platform_config_t *config)

{
  undefined4 uVar1;
  uart_port_t uVar2;
  int iVar3;
  uart_word_length_t uVar4;
  esp_openthread_platform_config_t *peVar5;
  esp_openthread_platform_config_t *peVar6;
  uart_stop_bits_t uVar7;
  esp_openthread_platform_config_t *peVar8;
  esp_openthread_platform_config_t *peVar9;
  
  if ((config->radio_config).radio_mode == RADIO_MODE_UART_RCP) {
    if ((config->host_config).host_connection_mode < 2) {
      peVar6 = config;
      peVar9 = &s_platform_config;
      do {
        peVar8 = peVar9;
        peVar5 = peVar6;
        uVar2 = (peVar5->radio_config).radio_uart_config.port;
        iVar3 = (peVar5->radio_config).radio_uart_config.uart_config.baud_rate;
        uVar4 = (peVar5->radio_config).radio_uart_config.uart_config.data_bits;
        (peVar8->radio_config).radio_mode = (peVar5->radio_config).radio_mode;
        (peVar8->radio_config).radio_uart_config.port = uVar2;
        (peVar8->radio_config).radio_uart_config.uart_config.baud_rate = iVar3;
        (peVar8->radio_config).radio_uart_config.uart_config.data_bits = uVar4;
        peVar6 = (esp_openthread_platform_config_t *)
                 &(peVar5->radio_config).radio_uart_config.uart_config.parity;
        peVar9 = (esp_openthread_platform_config_t *)
                 &(peVar8->radio_config).radio_uart_config.uart_config.parity;
      } while (peVar6 != (esp_openthread_platform_config_t *)
                         &(config->host_config).host_uart_config.rx_pin);
      uVar7 = (peVar5->radio_config).radio_uart_config.uart_config.stop_bits;
      *(uart_parity_t *)peVar9 = *(uart_parity_t *)peVar6;
      (peVar8->radio_config).radio_uart_config.uart_config.stop_bits = uVar7;
      iVar3 = esp_openthread_lock_init();
      if (iVar3 == 0) {
        if (((config->host_config).host_connection_mode == HOST_CONNECTION_MODE_UART) &&
           (iVar3 = esp_openthread_uart_init(config), iVar3 != 0)) {
          uVar1 = esp_log_timestamp();
          esp_log_write(1,"OPENTHREAD",&_LC5,uVar1,"OPENTHREAD","esp_openthread_platform_init",0x37)
          ;
        }
        else {
          iVar3 = esp_openthread_task_queue_init();
          if (iVar3 == 0) {
            iVar3 = esp_openthread_radio_init(config);
            if (iVar3 == 0) {
              return 0;
            }
            uVar1 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD",&_LC7,uVar1,"OPENTHREAD","esp_openthread_platform_init",
                          0x3a);
          }
          else {
            uVar1 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD",&_LC6,uVar1,"OPENTHREAD","esp_openthread_platform_init",
                          0x39);
          }
        }
      }
      else {
        uVar1 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC4,uVar1,"OPENTHREAD","esp_openthread_platform_init",0x35);
      }
      if (iVar3 != 0) {
        esp_openthread_platform_deinit();
      }
    }
    else {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC3,uVar1,"OPENTHREAD","esp_openthread_platform_init",0x2e);
      iVar3 = 0x102;
    }
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC2,uVar1,"OPENTHREAD","esp_openthread_platform_init",0x2b);
    iVar3 = 0x102;
  }
  return iVar3;
}

