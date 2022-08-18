/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_route_table_add_onlink_prefix
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_route_table_add_onlink_prefix(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *__dest;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = *param_1;
  uVar2 = 0x102;
  if ((iVar6 != 0) && (uVar2 = 0x102, (char)param_1[6] == '@')) {
    piVar7 = &s_on_link_prefixes;
    piVar3 = &s_on_link_prefixes;
    iVar1 = 0;
    do {
      if (((iVar6 == *piVar3) && ((char)piVar3[6] == '@')) &&
         (iVar4 = memcmp(piVar3 + 1,param_1 + 1,8), iVar4 == 0)) {
        __dest = (undefined4 *)((int)&s_on_link_prefixes + iVar1);
        sys_untimeout(0x10000,__dest);
        goto _L0;
      }
      iVar1 = iVar1 + 0x20;
      piVar3 = piVar3 + 8;
    } while (iVar1 != 0x140);
    iVar1 = 0;
    do {
      if (*piVar7 == 0) {
        iVar4 = iVar1 * 0x20;
        __dest = &s_on_link_prefixes + iVar1 * 8;
        memcpy(__dest,param_1,0x20);
        if (((&DAT_000105b8)[iVar1 * 8] & 0xc0ff) == 0x80fe) {
          cVar5 = *(char *)(*param_1 + 0x18a) + '\x01';
        }
        else {
          cVar5 = '\0';
        }
        (&DAT_000105c8)[iVar4] = cVar5;
        if ((param_3 != 0) && (*(char *)(iVar6 + 0x18b) != '\0')) {
          (&DAT_000105c0)[iVar4] = *(byte *)(iVar6 + 0x180) ^ 2;
          (&DAT_000105c1)[iVar4] = *(undefined1 *)(iVar6 + 0x181);
          (&DAT_000105c2)[iVar4] = *(undefined1 *)(iVar6 + 0x182);
          (&DAT_000105c3)[iVar4] = 0xff;
          (&DAT_000105c4)[iVar4] = 0xfe;
          memcpy(&DAT_000105c5 + iVar4,(void *)(iVar6 + 0x183),3);
          iVar1 = netif_add_ip6_address(iVar6,&DAT_000105b8 + iVar1 * 8,0);
          if (iVar1 != 0) {
            uVar2 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD",&_LC1,uVar2,"OPENTHREAD");
            return 0xffffffff;
          }
        }
_L0:
        iVar1 = netif_get_ip6_addr_match(iVar6,__dest + 1);
        if (-1 < iVar1) {
          iVar4 = iVar1 * 4 + iVar6;
          *(int *)(iVar4 + 0x114) = param_1[7];
          if ((param_2 != 0) &&
             (*(int *)(iVar4 + 0x134) = param_2, *(char *)(iVar6 + iVar1 + 0x10c) == '\x10')) {
            netif_ip6_addr_set_state(iVar6,iVar1,0x30);
          }
        }
        if (param_1[7] == -1) {
          return 0;
        }
        sys_timeout(param_1[7] * 1000,0x10000,__dest);
        return 0;
      }
      iVar1 = iVar1 + 1;
      piVar7 = piVar7 + 8;
    } while (iVar1 != 10);
    uVar2 = 0x101;
  }
  return uVar2;
}

