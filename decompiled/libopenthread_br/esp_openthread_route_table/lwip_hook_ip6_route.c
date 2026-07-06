/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_route_table.o -> lwip_hook_ip6_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lwip_hook_ip6_route(void *param_1)

{
  undefined1 *__s2;
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_3c;
  undefined1 auStack_38 [16];
  byte bStack_28;
  char cStack_27;
  
  uStack_3c = 0;
  while( true ) {
    esp_openthread_get_instance();
    iVar2 = otNetDataGetNextOnMeshPrefix(&uStack_3c,auStack_38);
    if (iVar2 != 0) break;
    if ((cStack_27 < '\0') &&
       (iVar2 = memcmp(param_1,auStack_38,(uint)(bStack_28 >> 3)), iVar2 == 0)) {
      esp_openthread_get_netif();
      uVar3 = to_underlying_lwip_netif();
      return uVar3;
    }
  }
  __s2 = s_route_entries;
  puVar1 = (undefined1 *)0x0;
  do {
    if (((*(int *)(__s2 + 0x34) != 0) &&
        (iVar2 = memcmp(param_1,__s2,(uint)((byte)__s2[0x14] >> 3)), iVar2 == 0)) &&
       (iVar2 = is_better_route(__s2,puVar1), iVar2 != 0)) {
      puVar1 = __s2;
    }
    __s2 = __s2 + 0x38;
  } while (__s2 != (undefined1 *)0x105f0);
  if (puVar1 == (undefined1 *)0x0) {
    return 0;
  }
  return *(undefined4 *)(puVar1 + 0x34);
}

