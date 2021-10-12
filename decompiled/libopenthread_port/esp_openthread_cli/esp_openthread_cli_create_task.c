/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
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
  xTaskCreatePinnedToCore(ot_cli_loop,"ot_cli",0xc00,uVar1,4,0,0x7fffffff);
  return;
}

