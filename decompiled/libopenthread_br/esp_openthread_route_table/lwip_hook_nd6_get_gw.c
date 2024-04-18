/*
 * Last changed at upstream commit a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * https://github.com/espressif/esp-thread-lib/commit/a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * Upstream date: 2024-04-18 16:47:55 +0800
 * Upstream subject: feat(br): update border router lib           esp-openthread: 07f637d           openthread: be7d36e
 * Source: libopenthread_br -> esp_openthread_route_table.o -> lwip_hook_nd6_get_gw
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * lwip_hook_nd6_get_gw(int param_1,undefined1 *param_2)

{
  int *piVar1;
  undefined1 *__s2;
  undefined1 *puVar2;
  int iVar3;
  
  piVar1 = &s_on_link_prefixes;
  while ((*piVar1 == 0 ||
         (iVar3 = memcmp(param_2,piVar1 + 1,(uint)(*(byte *)(piVar1 + 6) >> 3)), iVar3 != 0))) {
    piVar1 = piVar1 + 8;
    if (piVar1 == (int *)s_route_entries) {
      __s2 = s_route_entries;
      puVar2 = (undefined1 *)0x0;
      do {
        if ((((*(int *)(__s2 + 0x34) != 0) && (*(int *)(__s2 + 0x34) == param_1)) &&
            (iVar3 = memcmp(param_2,__s2,(uint)((byte)__s2[0x14] >> 3)), iVar3 == 0)) &&
           (iVar3 = is_better_route(__s2,puVar2), iVar3 != 0)) {
          puVar2 = __s2;
        }
        __s2 = __s2 + 0x38;
      } while (__s2 != (undefined1 *)0x10a68);
      if (puVar2 != (undefined1 *)0x0) {
        puVar2 = puVar2 + 0x18;
      }
      return puVar2;
    }
  }
  return param_2;
}

