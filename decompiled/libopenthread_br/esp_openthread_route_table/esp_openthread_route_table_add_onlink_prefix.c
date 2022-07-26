/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
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
          if ((&DAT_000105e8)[iVar6 * 8] != -1) {
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
        if (((&DAT_000105d0)[iVar6 * 8] & 0xc0ff) == 0x80fe) {
          cVar3 = *(char *)(*param_1 + 0x18a) + '\x01';
        }
        else {
          cVar3 = '\0';
        }
        (&DAT_000105e0)[iVar2] = cVar3;
        if ((param_3 != 0) && (*(char *)(iVar1 + 0x18b) != '\0')) {
          (&DAT_000105d8)[iVar2] = *(byte *)(iVar1 + 0x180) ^ 2;
          (&DAT_000105d9)[iVar2] = *(undefined1 *)(iVar1 + 0x181);
          (&DAT_000105da)[iVar2] = *(undefined1 *)(iVar1 + 0x182);
          (&DAT_000105db)[iVar2] = 0xff;
          (&DAT_000105dc)[iVar2] = 0xfe;
          memcpy(&DAT_000105dd + iVar2,(void *)(iVar1 + 0x183),3);
          iVar6 = netif_add_ip6_address(iVar1,&DAT_000105d0 + iVar6 * 8,0);
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

