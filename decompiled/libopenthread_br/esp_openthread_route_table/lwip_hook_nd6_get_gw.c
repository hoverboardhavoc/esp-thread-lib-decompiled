/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_route_table.o -> lwip_hook_nd6_get_gw
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * lwip_hook_nd6_get_gw(int param_1,void *param_2)

{
  undefined1 *__s2;
  undefined1 *puVar1;
  int iVar2;
  
  __s2 = s_route_entries;
  puVar1 = (undefined1 *)0x0;
  do {
    if ((((*(int *)(__s2 + 0x34) == param_1) && (*(int *)(__s2 + 0x34) != 0)) &&
        (iVar2 = memcmp(param_2,__s2,(uint)((byte)__s2[0x14] >> 3)), iVar2 == 0)) &&
       (iVar2 = is_better_route(__s2,puVar1), iVar2 != 0)) {
      puVar1 = __s2;
    }
    __s2 = __s2 + 0x38;
  } while (__s2 != (undefined1 *)0x105f0);
  if (puVar1 != (undefined1 *)0x0) {
    puVar1 = puVar1 + 0x18;
  }
  return puVar1;
}

