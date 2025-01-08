/*
 * Last changed at upstream commit 3638c36b340b5976df2e1fcef8ff28160ef622c3
 * https://github.com/espressif/esp-thread-lib/commit/3638c36b340b5976df2e1fcef8ff28160ef622c3
 * Upstream date: 2025-01-08 16:16:11 +0800
 * Upstream subject: feat(br): add lib for release/v5.5 * esp-openthread: 278d4fc29 * openthread: 005c5cefc * esp-idf: a150b999b
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> free_subtype_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void free_subtype_list(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (puVar1 = param_1; puVar1 != param_1 + param_2; puVar1 = puVar1 + 1) {
      if ((void *)*puVar1 != (void *)0x0) {
        free((void *)*puVar1);
      }
    }
    free(param_1);
    return;
  }
  return;
}

