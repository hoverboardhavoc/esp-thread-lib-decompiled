/*
 * Last changed at upstream commit b6b61e3d4891c01e9b44cc1a27e741288192b537
 * https://github.com/espressif/esp-thread-lib/commit/b6b61e3d4891c01e9b44cc1a27e741288192b537
 * Upstream date: 2022-06-20 16:22:56 +0800
 * Upstream subject: openthread: update OpenThread submodule
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
  undefined4 uStack_bc;
  undefined4 auStack_b8 [2];
  undefined *puStack_b0;
  undefined *puStack_ac;
  undefined *puStack_a8;
  undefined4 uStack_a4;
  undefined *puStack_a0;
  char *pcStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  
  uVar1 = esp_openthread_get_instance();
  puStack_b0 = &_LC3;
  puStack_ac = &_LC4;
  puStack_a8 = &_LC5;
  uStack_a4 = otThreadGetNetworkName();
  puStack_a0 = &_LC6;
  iVar2 = otThreadGetVersion();
  if (iVar2 == 2) {
    pcStack_9c = "1.1.1";
  }
  else if (iVar2 == 3) {
    pcStack_9c = "1.2.0";
  }
  else {
    pcStack_9c = "";
  }
  uVar3 = otThreadGetExtendedPanId(uVar1);
  uVar4 = otLinkGetExtendedAddress(uVar1);
  uStack_98 = 0x32000000;
  uStack_bc = 0x32000000;
  auStack_b8[0] = otThreadGetPartitionId(uVar1);
  iVar2 = otDatasetGetActive(uVar1,&uStack_98);
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
  iVar2 = mdns_service_txt_set("_meshcop",&_LC9,&puStack_b0,3);
  if (iVar2 == 0) {
    iVar2 = mdns_service_txt_item_set_with_explicit_value_len("_meshcop",&_LC9,&_LC13,uVar3,8);
    if (iVar2 == 0) {
      iVar2 = mdns_service_txt_item_set_with_explicit_value_len("_meshcop",&_LC9,&_LC15,uVar4,8);
      if (iVar2 == 0) {
        uStack_98 = __bswapdi2(uStack_98,uStack_94);
        uStack_94 = extraout_a1;
        iVar2 = mdns_service_txt_item_set_with_explicit_value_len
                          ("_meshcop",&_LC9,&_LC17,&uStack_98,8);
        if (iVar2 == 0) {
          iVar2 = mdns_service_txt_item_set_with_explicit_value_len
                            ("_meshcop",&_LC9,&_LC19,auStack_b8,4);
          if (iVar2 == 0) {
            iVar2 = mdns_service_txt_item_set_with_explicit_value_len
                              ("_meshcop",&_LC9,&_LC21,&uStack_bc,4);
            if (iVar2 == 0) {
              return 0;
            }
            uVar3 = esp_log_timestamp();
            uVar1 = 0x8b;
            puVar5 = &_LC22;
          }
          else {
            uVar3 = esp_log_timestamp();
            uVar1 = 0x87;
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

