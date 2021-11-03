/*
 * Last changed at upstream commit 7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * https://github.com/espressif/esp-thread-lib/commit/7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * Upstream date: 2021-11-03 15:55:12 +0800
 * Upstream subject: openthread: mdns & RCP ota update(3571cf8)
 * Source: libopenthread_port -> esp_openthread_cli.o -> cli_output_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int cli_output_callback(char *param_1,__gnuc_va_list param_2)

{
  int iVar1;
  char acStack_14 [4];
  
  vsnprintf(acStack_14,3,param_1,param_2);
  iVar1 = strcmp(acStack_14,"> ");
  if ((iVar1 == 0) && (s_cli_task != 0)) {
    xTaskGenericNotify(0,0,2,0);
    iVar1 = 0;
  }
  else {
    iVar1 = vprintf(param_1,param_2);
  }
  return iVar1;
}

