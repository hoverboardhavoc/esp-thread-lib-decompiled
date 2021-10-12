/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
 * Source: libopenthread_port -> esp_openthread_cli.o -> esp_openthread_cli_input
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_cli_input(char *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = strdup(param_1);
  if (pcVar1 != (char *)0x0) {
    uVar2 = esp_openthread_task_queue_post(line_handle_task,pcVar1);
    return uVar2;
  }
  uVar2 = esp_log_timestamp();
  esp_log_write(1,"OPENTHREAD",&_LC2,uVar2,"OPENTHREAD","esp_openthread_cli_input",0x31);
  return 0x101;
}

