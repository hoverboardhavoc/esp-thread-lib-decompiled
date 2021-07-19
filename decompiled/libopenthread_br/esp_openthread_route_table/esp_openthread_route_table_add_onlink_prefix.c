/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_route_table_add_onlink_prefix
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_route_table_add_onlink_prefix(int *param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char cVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  
  iVar14 = *param_1;
  if (iVar14 == 0) {
    uVar6 = 0x102;
  }
  else if (param_1 == (int *)0x0) {
    uVar6 = 0x102;
  }
  else if ((char)param_1[6] == '@') {
    piVar4 = (int *)find_on_link_prefix(iVar14,param_1 + 1,0x40);
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)find_empty_onlink_prefix();
      if (piVar4 == (int *)0x0) {
        return 0x101;
      }
      uVar12 = param_1[1];
      iVar13 = param_1[2];
      iVar5 = param_1[3];
      iVar7 = param_1[4];
      iVar8 = param_1[5];
      iVar9 = param_1[6];
      iVar10 = param_1[7];
      *piVar4 = iVar14;
      piVar4[1] = uVar12;
      piVar4[2] = iVar13;
      piVar4[3] = iVar5;
      piVar4[4] = iVar7;
      piVar4[5] = iVar8;
      piVar4[6] = iVar9;
      piVar4[7] = iVar10;
      if ((uVar12 & 0xc0ff) == 0x80fe) {
        cVar11 = *(char *)(*param_1 + 0x196) + '\x01';
      }
      else {
        cVar11 = '\0';
      }
      *(char *)(piVar4 + 5) = cVar11;
      if ((param_3 != 0) && (*(char *)(iVar14 + 0x197) != '\0')) {
        *(byte *)(piVar4 + 3) = *(byte *)(iVar14 + 0x18c) ^ 2;
        *(undefined1 *)((int)piVar4 + 0xd) = *(undefined1 *)(iVar14 + 0x18d);
        *(undefined1 *)((int)piVar4 + 0xe) = 0xff;
        *(undefined1 *)((int)piVar4 + 0xf) = 0xf3;
        uVar1 = *(undefined1 *)(iVar14 + 399);
        uVar2 = *(undefined1 *)(iVar14 + 400);
        uVar3 = *(undefined1 *)(iVar14 + 0x191);
        *(undefined1 *)(piVar4 + 4) = *(undefined1 *)(iVar14 + 0x18e);
        *(undefined1 *)((int)piVar4 + 0x11) = uVar1;
        *(undefined1 *)((int)piVar4 + 0x12) = uVar2;
        *(undefined1 *)((int)piVar4 + 0x13) = uVar3;
        iVar5 = netif_add_ip6_address(iVar14,piVar4 + 1,0);
        if (iVar5 != 0) {
          otLogCrit(0xc,"-PLAT----: ","Failed to add slaac address");
          return 0xffffffff;
        }
      }
    }
    else {
      sys_untimeout(esp_openthread_on_link_prefix_timeout_handler,piVar4);
    }
    iVar5 = netif_get_ip6_addr_match(iVar14,piVar4 + 1);
    if (((-1 < iVar5) && (*(int *)((iVar5 + 0x44) * 4 + iVar14 + 4) = param_1[7], param_2 != 0)) &&
       (*(int *)((iVar5 + 0x4c) * 4 + iVar14 + 4) = param_2,
       *(char *)(iVar14 + iVar5 + 0x10c) == '\x10')) {
      netif_ip6_addr_set_state(iVar14,iVar5,0x30);
    }
    sys_timeout(param_1[7] * 1000,esp_openthread_on_link_prefix_timeout_handler,piVar4);
    uVar6 = 0;
  }
  else {
    uVar6 = 0x102;
  }
  return uVar6;
}

