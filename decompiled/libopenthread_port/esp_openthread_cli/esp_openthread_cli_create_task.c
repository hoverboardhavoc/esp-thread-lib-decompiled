/*
 * Last changed at upstream commit 7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * https://github.com/espressif/esp-thread-lib/commit/7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * Upstream date: 2021-11-03 15:55:12 +0800
 * Upstream subject: openthread: mdns & RCP ota update(3571cf8)
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
  xTaskCreatePinnedToCore(ot_cli_loop,"ot_cli",0xc00,uVar1,4,&s_cli_task,0x7fffffff);
  return;
}

