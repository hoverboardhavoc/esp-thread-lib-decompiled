/*
 * Last changed at upstream commit 7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * https://github.com/espressif/esp-thread-lib/commit/7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * Upstream date: 2021-11-03 15:55:12 +0800
 * Upstream subject: openthread: mdns & RCP ota update(3571cf8)
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
  esp_log_write(1,"OPENTHREAD",&_LC3,uVar2,"OPENTHREAD","esp_openthread_cli_input",0x3c);
  return 0x101;
}

