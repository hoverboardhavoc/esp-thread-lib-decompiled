/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> free_txt_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void free_txt_list(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (puVar1 = param_1; puVar1 != param_1 + param_2 * 2; puVar1 = puVar1 + 2) {
      if ((void *)*puVar1 != (void *)0x0) {
        free((void *)*puVar1);
      }
      if ((void *)puVar1[1] != (void *)0x0) {
        free((void *)puVar1[1]);
      }
    }
    free(param_1);
    return;
  }
  return;
}

