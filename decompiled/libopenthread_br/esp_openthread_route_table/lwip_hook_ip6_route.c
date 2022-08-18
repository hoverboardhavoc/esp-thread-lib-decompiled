/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_br -> esp_openthread_route_table.o -> lwip_hook_ip6_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * lwip_hook_ip6_route(void *param_1)

{
  int *piVar1;
  undefined1 *__s2;
  undefined1 *puVar2;
  int iVar3;
  
  piVar1 = &s_on_link_prefixes;
  do {
    puVar2 = (undefined1 *)*piVar1;
    if (puVar2 == (undefined1 *)0x0) break;
    iVar3 = memcmp(param_1,piVar1 + 1,(uint)(*(byte *)(piVar1 + 6) >> 3));
    if (iVar3 == 0) {
      return puVar2;
    }
    piVar1 = piVar1 + 8;
  } while (piVar1 != (int *)s_route_entries);
  __s2 = s_route_entries;
  puVar2 = (undefined1 *)0x0;
  do {
    if (*(int *)(__s2 + 0x34) == 0) break;
    iVar3 = memcmp(param_1,__s2,(uint)((byte)__s2[0x14] >> 3));
    if ((iVar3 == 0) && (iVar3 = is_better_route(__s2,puVar2), iVar3 != 0)) {
      puVar2 = __s2;
    }
    __s2 = __s2 + 0x38;
  } while (__s2 != (undefined1 *)0x10924);
  if (puVar2 != (undefined1 *)0x0) {
    puVar2 = *(undefined1 **)(puVar2 + 0x34);
  }
  return puVar2;
}

