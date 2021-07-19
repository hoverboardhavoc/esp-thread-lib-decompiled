/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> ra_recv_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ra_recv_handler(int param_1,int param_2,undefined4 *param_3)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  char cStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  for (uVar8 = 0x10; (int)(uVar8 + 1) < param_2; uVar8 = uVar4 + uVar8 & 0xffff) {
    pcVar5 = (char *)(param_1 + uVar8);
    cVar1 = *pcVar5;
    uVar4 = ((byte)pcVar5[1] & 0x1f) * 8;
    if ((cVar1 == '\x18') && (iVar7 = is_self_address(param_3), iVar7 == 0)) {
      bVar2 = pcVar5[2];
      bVar3 = pcVar5[3];
      otLogInfo(0xc,"-PLAT----: ","Received RIO");
      for (uVar9 = 8; uVar9 < uVar4; uVar9 = uVar9 + (bVar2 >> 3) & 0xffff) {
        uStack_7c = 0;
        uStack_78 = 0;
        uStack_74 = 0;
        uStack_70 = 0;
        uStack_6c = 0;
        memcpy(&uStack_7c,(void *)(uVar9 + uVar8 + param_1),(uint)(bVar2 >> 3));
        uStack_34 = s_netif;
        uStack_50 = *param_3;
        uStack_4c = param_3[1];
        uStack_48 = param_3[2];
        uStack_44 = param_3[3];
        uStack_40 = param_3[4];
        uStack_54 = CONCAT31(uStack_54._1_3_,pcVar5[2]);
        uStack_68 = uStack_7c;
        uStack_64 = uStack_78;
        uStack_60 = uStack_74;
        uStack_5c = uStack_70;
        uStack_58 = uStack_6c;
        cStack_3c = (bVar3 >> 3 & 1) + (bVar3 >> 4 & 1) * -2;
        uStack_38 = lwip_htonl(*(undefined4 *)(pcVar5 + 4));
        uVar6 = ip6addr_ntoa(&uStack_7c);
        otLogInfo(0xc,"-PLAT----: ","prefix %s lifetime %u\n",uVar6,uStack_38);
        iVar7 = esp_openthread_route_table_add_route_entry(&uStack_68);
        if (iVar7 != 0) {
          otLogCrit(0xc,"-PLAT----: ","Failed to add route table entry\n");
        }
      }
    }
    else if ((cVar1 == '\x03') && (otLogInfo(0xc,"-PLAT----: ","Received PIO"), pcVar5[3] < '\0')) {
      uStack_68 = 0;
      uStack_64 = 0;
      uStack_60 = 0;
      uStack_5c = 0;
      uStack_58 = 0;
      uStack_54 = 0;
      uStack_50 = 0;
      uStack_4c = 0;
      memcpy(&uStack_64,pcVar5 + 0x10,0x10);
      uStack_68 = s_netif;
      uStack_50 = CONCAT31(uStack_50._1_3_,pcVar5[2]);
      uVar6 = lwip_htonl(*(undefined4 *)(pcVar5 + 8));
      iVar7 = esp_openthread_route_table_add_onlink_prefix
                        (&uStack_68,uVar6,(byte)pcVar5[3] >> 6 & 1);
      if (iVar7 != 0) {
        otLogCrit(0xc,"-PLAT----: ","Failed to add on link prefix\n");
      }
    }
  }
  return;
}

