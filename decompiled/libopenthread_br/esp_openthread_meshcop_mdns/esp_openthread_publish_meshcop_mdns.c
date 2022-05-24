/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_br -> esp_openthread_meshcop_mdns.o -> esp_openthread_publish_meshcop_mdns
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_publish_meshcop_mdns(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 extraout_a1;
  undefined *puVar5;
  undefined4 uStack_ac;
  undefined4 auStack_a8 [2];
  undefined *puStack_a0;
  undefined *puStack_9c;
  undefined *puStack_98;
  undefined4 uStack_94;
  undefined *puStack_90;
  char *pcStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  
  uVar1 = esp_openthread_get_instance();
  puStack_a0 = &_LC3;
  puStack_9c = &_LC4;
  puStack_98 = &_LC5;
  uStack_94 = otThreadGetNetworkName();
  puStack_90 = &_LC6;
  iVar2 = otThreadGetVersion();
  if (iVar2 == 2) {
    pcStack_8c = "1.1.1";
  }
  else if (iVar2 == 3) {
    pcStack_8c = "1.2.0";
  }
  else {
    pcStack_8c = "";
  }
  uVar3 = otThreadGetExtendedPanId(uVar1);
  uVar4 = otLinkGetExtendedAddress(uVar1);
  uStack_88 = 0x32000000;
  uStack_ac = 0x32000000;
  auStack_a8[0] = otThreadGetPartitionId(uVar1);
  iVar2 = otDatasetGetActive(uVar1,&uStack_88);
  if (iVar2 != 0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC8,uVar1,"OPENTHREAD","esp_openthread_publish_meshcop_mdns",0x6d
                 );
    return -1;
  }
  if (s_service_published == '\0') {
    uVar1 = otBorderAgentGetUdpPort(uVar1);
    iVar2 = mdns_service_add(0,"_meshcop",&_LC9,uVar1,0,0);
    if (iVar2 != 0) {
      uVar3 = esp_log_timestamp();
      uVar1 = 0x70;
      puVar5 = &_LC11;
      goto _L0;
    }
    s_service_published = '\x01';
  }
  iVar2 = mdns_service_txt_set("_meshcop",&_LC9,&puStack_a0,3);
  if (iVar2 == 0) {
    iVar2 = mdns_service_txt_item_set_with_explicit_value_len("_meshcop",&_LC9,&_LC13,uVar3,8);
    if (iVar2 == 0) {
      iVar2 = mdns_service_txt_item_set_with_explicit_value_len("_meshcop",&_LC9,&_LC15,uVar4,8);
      if (iVar2 == 0) {
        uStack_88 = __bswapdi2(uStack_88,uStack_84);
        uStack_84 = extraout_a1;
        iVar2 = mdns_service_txt_item_set_with_explicit_value_len
                          ("_meshcop",&_LC9,&_LC17,&uStack_88,8);
        if (iVar2 == 0) {
          iVar2 = mdns_service_txt_item_set_with_explicit_value_len
                            ("_meshcop",&_LC9,&_LC19,auStack_a8,4);
          if (iVar2 == 0) {
            iVar2 = mdns_service_txt_item_set_with_explicit_value_len
                              ("_meshcop",&_LC9,&_LC21,&uStack_ac,4);
            if (iVar2 == 0) {
              return 0;
            }
            uVar3 = esp_log_timestamp();
            uVar1 = 0x8a;
            puVar5 = &_LC22;
          }
          else {
            uVar3 = esp_log_timestamp();
            uVar1 = 0x86;
            puVar5 = &_LC20;
          }
        }
        else {
          uVar3 = esp_log_timestamp();
          uVar1 = 0x82;
          puVar5 = &_LC18;
        }
      }
      else {
        uVar3 = esp_log_timestamp();
        uVar1 = 0x7d;
        puVar5 = &_LC16;
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      uVar1 = 0x79;
      puVar5 = &_LC14;
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    uVar1 = 0x76;
    puVar5 = &_LC12;
  }
_L0:
  esp_log_write(1,"OPENTHREAD",puVar5,uVar3,"OPENTHREAD","esp_openthread_publish_meshcop_mdns",uVar1
               );
  return iVar2;
}

