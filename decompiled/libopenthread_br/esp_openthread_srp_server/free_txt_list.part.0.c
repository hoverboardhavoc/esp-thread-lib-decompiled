/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> free_txt_list.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void free_txt_list_part_0(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
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

