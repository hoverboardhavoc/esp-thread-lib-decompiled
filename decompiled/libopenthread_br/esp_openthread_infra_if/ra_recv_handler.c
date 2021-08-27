/*
 * Last changed at upstream commit c9af7b259218417072614ad265e7e896db15b49a
 * https://github.com/espressif/esp-thread-lib/commit/c9af7b259218417072614ad265e7e896db15b49a
 * Upstream date: 2021-08-27 13:57:40 +0800
 * Upstream subject: openthread: support ESP32-H2 chip(00e1885)
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
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
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
  
  for (uVar9 = 0x10; (int)(uVar9 + 1) < param_2; uVar9 = uVar4 + uVar9 & 0xffff) {
    pcVar5 = (char *)(param_1 + uVar9);
    cVar1 = *pcVar5;
    uVar4 = ((byte)pcVar5[1] & 0x1f) * 8;
    if ((cVar1 == '\x18') && (iVar7 = is_self_address(param_3), iVar7 == 0)) {
      bVar2 = pcVar5[2];
      bVar3 = pcVar5[3];
      uVar8 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC3,uVar8,"OPENTHREAD");
      for (uVar10 = 8; uVar10 < uVar4; uVar10 = uVar10 + (bVar2 >> 3) & 0xffff) {
        uStack_7c = 0;
        uStack_78 = 0;
        uStack_74 = 0;
        uStack_70 = 0;
        uStack_6c = 0;
        memcpy(&uStack_7c,(void *)(uVar10 + uVar9 + param_1),(uint)(bVar2 >> 3));
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
        uVar8 = esp_log_timestamp();
        uVar6 = ip6addr_ntoa(&uStack_7c);
        esp_log_write(3,"OPENTHREAD",&_LC4,uVar8,"OPENTHREAD",uVar6,uStack_38);
        iVar7 = esp_openthread_route_table_add_route_entry(&uStack_68);
        if (iVar7 != 0) {
          uVar8 = esp_log_timestamp();
          esp_log_write(3,"OPENTHREAD",&_LC5,uVar8,"OPENTHREAD");
        }
      }
    }
    else if (cVar1 == '\x03') {
      uVar8 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC6,uVar8,"OPENTHREAD");
      if (pcVar5[3] < '\0') {
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
        uVar8 = lwip_htonl(*(undefined4 *)(pcVar5 + 8));
        iVar7 = esp_openthread_route_table_add_onlink_prefix
                          (&uStack_68,uVar8,(byte)pcVar5[3] >> 6 & 1);
        if (iVar7 != 0) {
          uVar8 = esp_log_timestamp();
          esp_log_write(1,"OPENTHREAD",&_LC7,uVar8,"OPENTHREAD");
        }
      }
    }
  }
  return;
}

