/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
 * Source: libopenthread_br -> esp_openthread_route_table.o -> lwip_hook_ip6_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * lwip_hook_ip6_route(void *param_1)

{
  undefined1 *puVar1;
  int *piVar2;
  undefined1 *__s2;
  int iVar3;
  undefined4 uStack_3c;
  undefined1 auStack_38 [16];
  byte bStack_28;
  char cStack_27;
  
  uStack_3c = 0;
  while( true ) {
    esp_openthread_get_instance();
    iVar3 = otNetDataGetNextOnMeshPrefix(&uStack_3c,auStack_38);
    if (iVar3 != 0) break;
    if ((cStack_27 < '\0') &&
       (iVar3 = memcmp(param_1,auStack_38,(uint)(bStack_28 >> 3)), iVar3 == 0)) {
      esp_openthread_get_netif();
      puVar1 = (undefined1 *)to_underlying_lwip_netif();
      return puVar1;
    }
  }
  piVar2 = &s_on_link_prefixes;
  do {
    puVar1 = (undefined1 *)*piVar2;
    if (puVar1 == (undefined1 *)0x0) break;
    iVar3 = memcmp(param_1,piVar2 + 1,(uint)(*(byte *)(piVar2 + 6) >> 3));
    if (iVar3 == 0) {
      return puVar1;
    }
    piVar2 = piVar2 + 8;
  } while (piVar2 != (int *)s_route_entries);
  __s2 = s_route_entries;
  puVar1 = (undefined1 *)0x0;
  do {
    if (*(int *)(__s2 + 0x34) == 0) break;
    iVar3 = memcmp(param_1,__s2,(uint)((byte)__s2[0x14] >> 3));
    if ((iVar3 == 0) && (iVar3 = is_better_route(__s2,puVar1), iVar3 != 0)) {
      puVar1 = __s2;
    }
    __s2 = __s2 + 0x38;
  } while (__s2 != (undefined1 *)0x10a0c);
  if (puVar1 != (undefined1 *)0x0) {
    puVar1 = *(undefined1 **)(puVar1 + 0x34);
  }
  return puVar1;
}

