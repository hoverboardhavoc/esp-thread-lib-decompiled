/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = *param_1;
  if (iVar6 == 0) {
    uVar3 = 0x102;
  }
  else {
    uVar3 = 0x102;
    if ((char)param_1[6] == '@') {
      piVar7 = &s_on_link_prefixes;
      piVar2 = &s_on_link_prefixes;
      iVar1 = 0;
      do {
        if (((iVar6 == *piVar2) && ((char)piVar2[6] == '@')) &&
           (iVar4 = memcmp(piVar2 + 1,param_1 + 1,8), iVar4 == 0)) {
          __dest = (undefined4 *)((int)&s_on_link_prefixes + iVar1);
          sys_untimeout(0x10000,__dest);
          goto _L0;
        }
        iVar1 = iVar1 + 0x20;
        piVar2 = piVar2 + 8;
      } while (iVar1 != 0x140);
      iVar1 = 0;
      do {
        if (*piVar7 == 0) {
          iVar4 = iVar1 * 0x20;
          __dest = &s_on_link_prefixes + iVar1 * 8;
          memcpy(__dest,param_1,0x20);
          if (((&DAT_00010598)[iVar1 * 8] & 0xc0ff) == 0x80fe) {
            cVar5 = *(char *)(*param_1 + 0x196) + '\x01';
          }
          else {
            cVar5 = '\0';
          }
          (&DAT_000105a8)[iVar4] = cVar5;
          if ((param_3 != 0) && (*(char *)(iVar6 + 0x197) != '\0')) {
            (&DAT_000105a0)[iVar4] = *(byte *)(iVar6 + 0x18c) ^ 2;
            (&DAT_000105a1)[iVar4] = *(undefined1 *)(iVar6 + 0x18d);
            (&DAT_000105a2)[iVar1 * 0x10] = 0xf3ff;
            memcpy(&DAT_000105a4 + iVar4,(void *)(iVar6 + 0x18e),4);
            iVar1 = netif_add_ip6_address(iVar6,&DAT_00010598 + iVar1 * 8,0);
            if (iVar1 != 0) {
              uVar3 = esp_log_timestamp();
              esp_log_write(1,"OPENTHREAD",&_LC1,uVar3,"OPENTHREAD");
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
          sys_timeout(param_1[7] * 1000,0x10000,__dest);
          return 0;
        }
        iVar1 = iVar1 + 1;
        piVar7 = piVar7 + 8;
      } while (iVar1 != 10);
      uVar3 = 0x101;
    }
  }
  return uVar3;
}

