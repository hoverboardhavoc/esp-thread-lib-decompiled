/*
 * Last changed at upstream commit a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * https://github.com/espressif/esp-thread-lib/commit/a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * Upstream date: 2024-04-18 16:47:55 +0800
 * Upstream subject: feat(br): update border router lib           esp-openthread: 07f637d           openthread: be7d36e
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
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    uVar3 = 0x102;
  }
  else {
    uVar3 = 0x102;
    if ((char)param_1[6] == '@') {
      piVar8 = &s_on_link_prefixes;
      piVar7 = &s_on_link_prefixes;
      iVar1 = 0;
      do {
        if (((iVar2 == *piVar7) && ((char)piVar7[6] == '@')) &&
           (iVar4 = memcmp(piVar7 + 1,param_1 + 1,8), iVar4 == 0)) {
          __dest = (undefined4 *)((int)&s_on_link_prefixes + iVar1);
          sys_untimeout(0x10000,__dest);
          goto _L0;
        }
        iVar1 = iVar1 + 0x20;
        piVar7 = piVar7 + 8;
      } while (iVar1 != 0x140);
      iVar1 = 0;
      do {
        if (*piVar8 == 0) {
          iVar4 = iVar1 * 0x20;
          __dest = &s_on_link_prefixes + iVar1 * 8;
          memcpy(__dest,param_1,0x20);
          if (((&DAT_000106fc)[iVar1 * 8] & 0xc0ff) == 0x80fe) {
            cVar5 = *(char *)(*param_1 + 0x18a) + '\x01';
          }
          else {
            cVar5 = '\0';
          }
          (&DAT_0001070c)[iVar4] = cVar5;
          if ((param_3 != 0) && (*(char *)(iVar2 + 0x18b) != '\0')) {
            (&DAT_00010704)[iVar4] = *(byte *)(iVar2 + 0x180) ^ 2;
            (&DAT_00010705)[iVar4] = *(undefined1 *)(iVar2 + 0x181);
            (&DAT_00010706)[iVar4] = *(undefined1 *)(iVar2 + 0x182);
            (&DAT_00010707)[iVar4] = 0xff;
            (&DAT_00010708)[iVar4] = 0xfe;
            memcpy(&DAT_00010709 + iVar4,(void *)(iVar2 + 0x183),3);
            iVar1 = netif_add_ip6_address(iVar2,&DAT_000106fc + iVar1 * 8,0);
            if (iVar1 != 0) {
              uVar3 = esp_log_timestamp();
              esp_log_write(1,"OPENTHREAD",&_LC1,uVar3,"OPENTHREAD");
              return 0xffffffff;
            }
          }
_L0:
          iVar1 = netif_get_ip6_addr_match(iVar2,__dest + 1);
          if (-1 < iVar1) {
            iVar4 = iVar1 * 4 + iVar2;
            *(int *)(iVar4 + 0x114) = param_1[7];
            if ((param_2 != 0) &&
               (*(int *)(iVar4 + 0x134) = param_2, *(char *)(iVar2 + iVar1 + 0x10c) == '\x10')) {
              netif_ip6_addr_set_state(iVar2,iVar1,0x30);
            }
          }
          uVar6 = param_1[7];
          if (uVar6 != 0xffffffff) {
            iVar2 = 0x3ffffcc8;
            if (uVar6 < 0x10624e) {
              iVar2 = uVar6 * 1000;
            }
            sys_timeout(iVar2,0x10000,__dest);
          }
          return 0;
        }
        iVar1 = iVar1 + 1;
        piVar8 = piVar8 + 8;
      } while (iVar1 != 10);
      uVar3 = 0x101;
    }
  }
  return uVar3;
}

