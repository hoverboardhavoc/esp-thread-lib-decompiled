/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_port -> esp_openthread_cli.o -> esp_openthread_cli_create_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_cli_create_task(void)

{
  undefined4 uVar1;
  
  uVar1 = xTaskGetCurrentTaskHandle();
  xTaskCreatePinnedToCore(ot_cli_loop,"ot_cli",0x1000,uVar1,4,&s_cli_task,0x7fffffff);
  return;
}

