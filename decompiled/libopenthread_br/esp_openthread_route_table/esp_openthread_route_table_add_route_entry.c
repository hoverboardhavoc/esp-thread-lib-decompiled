/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_route_table_add_route_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * esp_openthread_route_table_add_route_entry(undefined1 *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  undefined1 *__s1;
  undefined1 *puVar6;
  int iVar7;
  
  if (param_1 != (undefined1 *)0x0) {
    puVar6 = s_route_entries;
    __s1 = s_route_entries;
    do {
      if ((((*(int *)(__s1 + 0x34) != 0) && (*(int *)(__s1 + 0x34) == *(int *)(param_1 + 0x34))) &&
          (bVar1 = __s1[0x14], bVar1 == param_1[0x14])) &&
         ((iVar3 = memcmp(__s1 + 0x18,param_1 + 0x18,0x10), iVar3 == 0 &&
          (iVar3 = memcmp(__s1,param_1,(uint)(bVar1 >> 3)), iVar3 == 0)))) {
        sys_untimeout(route_timeout_handler,__s1);
        goto _L0;
      }
      __s1 = __s1 + 0x38;
    } while (__s1 != (undefined1 *)0x105f8);
    iVar3 = 0;
    do {
      if (*(int *)(puVar6 + 0x34) == 0) {
        iVar2 = iVar3 * 0x38;
        iVar7 = *(int *)(param_1 + 0x34);
        __s1 = s_route_entries + iVar2;
        *(int *)(s_route_entries + iVar2 + 0x34) = iVar7;
        memcpy(s_route_entries + iVar2 + 0x18,param_1 + 0x18,0x14);
        if ((*(uint *)(s_route_entries + iVar2 + 0x18) & 0xc0ff) == 0x80fe) {
          cVar4 = *(char *)(iVar7 + 0x212) + '\x01';
        }
        else {
          cVar4 = '\0';
        }
        iVar3 = iVar3 * 0x38;
        s_route_entries[iVar3 + 0x28] = cVar4;
        memcpy(s_route_entries + iVar3,param_1,0x14);
        s_route_entries[iVar3 + 0x14] = param_1[0x14];
_L0:
        __s1[0x2c] = param_1[0x2c];
        uVar5 = *(uint *)(param_1 + 0x30);
        *(uint *)(__s1 + 0x30) = uVar5;
        if (uVar5 == 0xffffffff) {
          return __s1;
        }
        iVar3 = 0x3ffffcc8;
        if (uVar5 < 0x10624e) {
          iVar3 = uVar5 * 1000;
        }
        sys_timeout(iVar3,route_timeout_handler,__s1);
        return __s1;
      }
      iVar3 = iVar3 + 1;
      puVar6 = puVar6 + 0x38;
    } while (iVar3 != 10);
    param_1 = (undefined1 *)0x0;
  }
  return param_1;
}

