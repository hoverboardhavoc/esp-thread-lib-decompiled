/*
 * Last changed at upstream commit b6b61e3d4891c01e9b44cc1a27e741288192b537
 * https://github.com/espressif/esp-thread-lib/commit/b6b61e3d4891c01e9b44cc1a27e741288192b537
 * Upstream date: 2022-06-20 16:22:56 +0800
 * Upstream subject: openthread: update OpenThread submodule
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_route_table_add_onlink_prefix
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_route_table_add_onlink_prefix(int *param_1,int param_2,int param_3)

{
  undefined4 *__dest;
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  
  iVar1 = *param_1;
  uVar4 = 0x102;
  if ((iVar1 != 0) && (uVar4 = 0x102, (char)param_1[6] == '@')) {
    piVar7 = &s_on_link_prefixes;
    piVar5 = &s_on_link_prefixes;
    iVar6 = 0;
    do {
      if ((iVar1 == *piVar5) && ((char)piVar5[6] == '@')) {
        iVar2 = memcmp(piVar5 + 1,param_1 + 1,8);
        if (iVar2 == 0) {
          __dest = &s_on_link_prefixes + iVar6 * 8;
          if ((&DAT_000105dc)[iVar6 * 8] != -1) {
            sys_untimeout(0x10000,__dest);
          }
          goto _L0;
        }
      }
      iVar6 = iVar6 + 1;
      piVar5 = piVar5 + 8;
    } while (iVar6 != 10);
    iVar6 = 0;
    do {
      if (*piVar7 == 0) {
        iVar2 = iVar6 * 0x20;
        __dest = &s_on_link_prefixes + iVar6 * 8;
        memcpy(__dest,param_1,0x20);
        if (((&DAT_000105c4)[iVar6 * 8] & 0xc0ff) == 0x80fe) {
          cVar3 = *(char *)(*param_1 + 0x18a) + '\x01';
        }
        else {
          cVar3 = '\0';
        }
        (&DAT_000105d4)[iVar2] = cVar3;
        if ((param_3 != 0) && (*(char *)(iVar1 + 0x18b) != '\0')) {
          (&DAT_000105cc)[iVar2] = *(byte *)(iVar1 + 0x180) ^ 2;
          (&DAT_000105cd)[iVar2] = *(undefined1 *)(iVar1 + 0x181);
          (&DAT_000105ce)[iVar6 * 0x10] = 0xf3ff;
          memcpy(&DAT_000105d0 + iVar2,(void *)(iVar1 + 0x182),4);
          iVar6 = netif_add_ip6_address(iVar1,&DAT_000105c4 + iVar6 * 8,0);
          if (iVar6 != 0) {
            uVar4 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD",&_LC1,uVar4,"OPENTHREAD");
            return 0xffffffff;
          }
        }
_L0:
        iVar6 = netif_get_ip6_addr_match(iVar1,__dest + 1);
        if (-1 < iVar6) {
          iVar2 = iVar6 * 4 + iVar1;
          *(int *)(iVar2 + 0x114) = param_1[7];
          if ((param_2 != 0) &&
             (*(int *)(iVar2 + 0x134) = param_2, *(char *)(iVar1 + iVar6 + 0x10c) == '\x10')) {
            netif_ip6_addr_set_state(iVar1,iVar6,0x30);
          }
        }
        if (param_1[7] == -1) {
          return 0;
        }
        sys_timeout(param_1[7] * 1000,0x10000,__dest);
        return 0;
      }
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 8;
    } while (iVar6 != 10);
    uVar4 = 0x101;
  }
  return uVar4;
}

