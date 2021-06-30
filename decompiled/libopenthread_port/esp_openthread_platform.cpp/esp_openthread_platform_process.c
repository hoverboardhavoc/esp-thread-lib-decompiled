/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_platform.cpp.o -> esp_openthread_platform_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_openthread_platform_process
                    (otInstance *instance,esp_openthread_mainloop_context_t *mainloop)

{
  esp_err_t eVar1;
  undefined4 uVar2;
  
  if ((s_platform_config.host_config.host_connection_mode == HOST_CONNECTION_MODE_UART) &&
     (eVar1 = esp_openthread_uart_process(), eVar1 != 0)) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC8,uVar2,"OPENTHREAD","esp_openthread_platform_process",0x66);
  }
  else {
    esp_openthread_radio_process(instance,mainloop);
    esp_openthread_alarm_process(instance);
    esp_openthread_task_queue_process(instance,mainloop);
    eVar1 = esp_openthread_netif_glue_process(instance,mainloop);
  }
  return eVar1;
}

