/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_route_table_add_route_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * esp_openthread_route_table_add_route_entry(void *param_1)

{
  byte bVar1;
  int iVar2;
  undefined1 *__s1;
  int iVar3;
  char cVar4;
  undefined1 *puVar5;
  int iVar6;
  
  if (param_1 != (void *)0x0) {
    puVar5 = s_route_entries;
    __s1 = s_route_entries;
    while (*(int *)(__s1 + 0x34) != 0) {
      if ((((*(int *)(__s1 + 0x34) == *(int *)((int)param_1 + 0x34)) &&
           (bVar1 = __s1[0x14], bVar1 == *(byte *)((int)param_1 + 0x14))) &&
          (iVar3 = memcmp(__s1 + 0x18,(void *)((int)param_1 + 0x18),0x10), iVar3 == 0)) &&
         (iVar3 = memcmp(__s1,param_1,(uint)(bVar1 >> 3)), iVar3 == 0)) {
        if (*(int *)(__s1 + 0x30) != -1) {
          sys_untimeout(route_timeout_handler,__s1);
        }
        goto _L0;
      }
      __s1 = __s1 + 0x38;
      if (__s1 == (undefined1 *)0x1093c) break;
    }
    iVar3 = 0;
    do {
      if (*(int *)(puVar5 + 0x34) == 0) {
        iVar2 = iVar3 * 0x38;
        iVar6 = *(int *)((int)param_1 + 0x34);
        __s1 = s_route_entries + iVar2;
        *(int *)(s_route_entries + iVar2 + 0x34) = iVar6;
        memcpy(s_route_entries + iVar2 + 0x18,(void *)((int)param_1 + 0x18),0x14);
        if ((*(uint *)(s_route_entries + iVar2 + 0x18) & 0xc0ff) == 0x80fe) {
          cVar4 = *(char *)(iVar6 + 0x18a) + '\x01';
        }
        else {
          cVar4 = '\0';
        }
        iVar3 = iVar3 * 0x38;
        s_route_entries[iVar3 + 0x28] = cVar4;
        memcpy(s_route_entries + iVar3,param_1,0x14);
        s_route_entries[iVar3 + 0x14] = *(undefined1 *)((int)param_1 + 0x14);
_L0:
        __s1[0x2c] = *(undefined1 *)((int)param_1 + 0x2c);
        iVar3 = *(int *)((int)param_1 + 0x30);
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
  }
  return (undefined1 *)0x0;
}

