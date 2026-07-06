/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_net_utils.o -> free_txt_list_with_explicit_value_len
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void free_txt_list_with_explicit_value_len(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    uVar1 = 0;
    puVar2 = param_1;
    do {
      if ((void *)*puVar2 != (void *)0x0) {
        free((void *)*puVar2);
      }
      if ((void *)puVar2[1] != (void *)0x0) {
        free((void *)puVar2[1]);
      }
      uVar1 = uVar1 + 1 & 0xff;
      puVar2 = puVar2 + 3;
    } while (uVar1 < param_2);
    free(param_1);
    return;
  }
  return;
}

