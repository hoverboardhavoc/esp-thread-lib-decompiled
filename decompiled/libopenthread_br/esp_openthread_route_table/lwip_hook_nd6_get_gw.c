/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
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
    if ((((*(int *)(__s2 + 0x34) != 0) && (*(int *)(__s2 + 0x34) == param_1)) &&
        (iVar2 = memcmp(param_2,__s2,(uint)((byte)__s2[0x14] >> 3)), iVar2 == 0)) &&
       (iVar2 = is_better_route(__s2,puVar1), iVar2 != 0)) {
      puVar1 = __s2;
    }
    __s2 = __s2 + 0x38;
  } while (__s2 != (undefined1 *)0x105f8);
  if (puVar1 != (undefined1 *)0x0) {
    puVar1 = puVar1 + 0x18;
  }
  return puVar1;
}

