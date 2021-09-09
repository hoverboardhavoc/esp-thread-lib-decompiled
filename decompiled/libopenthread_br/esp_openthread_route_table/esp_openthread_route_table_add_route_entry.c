/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_route_table_add_route_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * esp_openthread_route_table_add_route_entry(char *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined1 *__s1;
  int iVar5;
  undefined1 *puVar6;
  
  if (param_1 != (char *)0x0) {
    puVar6 = s_route_entries;
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
    } while (__s1 != "OPENTHREAD");
    iVar3 = 0;
    do {
      if (*(int *)(puVar6 + 0x34) == 0) {
        iVar2 = iVar3 * 0x38;
        iVar5 = *(int *)(param_1 + 0x34);
        __s1 = s_route_entries + iVar2;
        *(int *)(s_route_entries + iVar2 + 0x34) = iVar5;
        memcpy(s_route_entries + iVar2 + 0x18,param_1 + 0x18,0x14);
        if ((*(uint *)(s_route_entries + iVar2 + 0x18) & 0xc0ff) == 0x80fe) {
          cVar4 = *(char *)(iVar5 + 0x196) + '\x01';
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
        sys_timeout(iVar3 * 1000,route_timeout_handler,__s1);
        return __s1;
      }
      iVar3 = iVar3 + 1;
      puVar6 = puVar6 + 0x38;
    } while (iVar3 != 10);
    param_1 = (char *)0x0;
  }
  return param_1;
}

