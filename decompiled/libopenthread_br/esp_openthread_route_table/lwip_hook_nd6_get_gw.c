/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
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
  } while (__s2 != (undefined1 *)0x105f4);
  if (puVar1 != (undefined1 *)0x0) {
    puVar1 = puVar1 + 0x18;
  }
  return puVar1;
}

