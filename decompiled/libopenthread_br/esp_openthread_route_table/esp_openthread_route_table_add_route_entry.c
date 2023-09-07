/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
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
  undefined1 *__s1;
  undefined1 *puVar5;
  int iVar6;
  
  if (param_1 != (undefined1 *)0x0) {
    puVar5 = s_route_entries;
    __s1 = s_route_entries;
    do {
      if (*(int *)(__s1 + 0x34) == 0) break;
      if ((((*(int *)(__s1 + 0x34) == *(int *)(param_1 + 0x34)) &&
           (bVar1 = __s1[0x14], bVar1 == param_1[0x14])) &&
          (iVar3 = memcmp(__s1 + 0x18,param_1 + 0x18,0x10), iVar3 == 0)) &&
         (iVar3 = memcmp(__s1,param_1,(uint)(bVar1 >> 3)), iVar3 == 0)) {
        sys_untimeout(route_timeout_handler,__s1);
        goto _L0;
      }
      __s1 = __s1 + 0x38;
    } while (__s1 != (undefined1 *)0x10a0c);
    iVar3 = 0;
    do {
      if (*(int *)(puVar5 + 0x34) == 0) {
        iVar2 = iVar3 * 0x38;
        iVar6 = *(int *)(param_1 + 0x34);
        __s1 = s_route_entries + iVar2;
        *(int *)(s_route_entries + iVar2 + 0x34) = iVar6;
        memcpy(s_route_entries + iVar2 + 0x18,param_1 + 0x18,0x14);
        if ((*(uint *)(s_route_entries + iVar2 + 0x18) & 0xc0ff) == 0x80fe) {
          cVar4 = *(char *)(iVar6 + 0x18a) + '\x01';
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
        iVar3 = *(int *)(param_1 + 0x30);
        *(int *)(__s1 + 0x30) = iVar3;
        if (iVar3 == -1) {
          return __s1;
        }
        sys_timeout(iVar3 * 1000,route_timeout_handler,__s1);
        return __s1;
      }
      iVar3 = iVar3 + 1;
      puVar5 = puVar5 + 0x38;
    } while (iVar3 != 10);
    param_1 = (undefined1 *)0x0;
  }
  return param_1;
}

