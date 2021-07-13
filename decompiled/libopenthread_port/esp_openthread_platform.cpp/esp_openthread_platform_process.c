/*
 * Last changed at upstream commit d84f8967f8ce14490e19433b85c8c363d424f4c1
 * https://github.com/espressif/esp-thread-lib/commit/d84f8967f8ce14490e19433b85c8c363d424f4c1
 * Upstream date: 2021-07-13 21:21:08 +0800
 * Upstream subject: openthread: add ot library for esp32h2
 * Source: libopenthread_port -> esp_openthread_platform.cpp.o -> esp_openthread_platform_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int esp_openthread_platform_process(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((_DAT_000103b4 == 1) && (iVar1 = esp_openthread_uart_process(), iVar1 != 0)) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC9,uVar2,"OPENTHREAD","esp_openthread_platform_process",0x6f);
  }
  else {
    esp_openthread_radio_process(param_1,param_2);
    esp_openthread_alarm_process(param_1);
    esp_openthread_task_queue_process(param_1,param_2);
    iVar1 = esp_openthread_netif_glue_process(param_1,param_2);
  }
  return iVar1;
}

