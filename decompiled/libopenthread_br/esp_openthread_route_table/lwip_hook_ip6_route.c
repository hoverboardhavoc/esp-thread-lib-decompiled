/*
 * Last changed at upstream commit a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * https://github.com/espressif/esp-thread-lib/commit/a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * Upstream date: 2024-04-18 16:47:55 +0800
 * Upstream subject: feat(br): update border router lib           esp-openthread: 07f637d           openthread: be7d36e
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
  do {
    esp_openthread_get_instance();
    iVar3 = otNetDataGetNextOnMeshPrefix(&uStack_3c,auStack_38);
    if (iVar3 != 0) {
      piVar2 = &s_on_link_prefixes;
      while ((puVar1 = (undefined1 *)*piVar2, puVar1 == (undefined1 *)0x0 ||
             (iVar3 = memcmp(param_1,piVar2 + 1,(uint)(*(byte *)(piVar2 + 6) >> 3)), iVar3 != 0))) {
        piVar2 = piVar2 + 8;
        if (piVar2 == (int *)s_route_entries) {
          __s2 = s_route_entries;
          puVar1 = (undefined1 *)0x0;
          do {
            if (((*(int *)(__s2 + 0x34) != 0) &&
                (iVar3 = memcmp(param_1,__s2,(uint)((byte)__s2[0x14] >> 3)), iVar3 == 0)) &&
               (iVar3 = is_better_route(__s2,puVar1), iVar3 != 0)) {
              puVar1 = __s2;
            }
            __s2 = __s2 + 0x38;
          } while (__s2 != (undefined1 *)0x10a68);
          if (puVar1 != (undefined1 *)0x0) {
            puVar1 = *(undefined1 **)(puVar1 + 0x34);
          }
          return puVar1;
        }
      }
      return puVar1;
    }
  } while ((-1 < cStack_27) ||
          (iVar3 = memcmp(param_1,auStack_38,(uint)(bStack_28 >> 3)), iVar3 != 0));
  esp_openthread_get_netif();
  puVar1 = (undefined1 *)to_underlying_lwip_netif();
  return puVar1;
}

