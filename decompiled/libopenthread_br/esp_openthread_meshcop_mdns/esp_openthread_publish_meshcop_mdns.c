/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_meshcop_mdns.o -> esp_openthread_publish_meshcop_mdns
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_publish_meshcop_mdns(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_a1;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined *puStack_28;
  undefined *puStack_24;
  undefined *puStack_20;
  undefined4 uStack_1c;
  undefined *puStack_18;
  undefined4 uStack_14;
  
  uVar1 = esp_openthread_get_instance();
  puStack_28 = &_LC3;
  puStack_24 = &_LC4;
  puStack_20 = &_LC5;
  uStack_1c = otThreadGetNetworkName();
  puStack_18 = &_LC6;
  uStack_14 = get_thread_version_string();
  uVar2 = otThreadGetExtendedPanId(uVar1);
  uVar3 = otLinkGetExtendedAddress(uVar1);
  uStack_94 = get_thread_state_bitmap();
  uStack_98 = otThreadGetPartitionId(uVar1);
  iVar4 = otDatasetGetActive(uVar1,&uStack_90);
  if (iVar4 == 0) {
    if (s_service_published == '\0') {
      uVar1 = otBorderAgentGetUdpPort(uVar1);
      iVar4 = mdns_service_add(0,"_meshcop",&_LC9,uVar1,0,0);
      if (iVar4 != 0) {
        uVar1 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC11,uVar1,"OPENTHREAD","esp_openthread_publish_meshcop_mdns"
                      ,0x72);
        return iVar4;
      }
      s_service_published = '\x01';
    }
    iVar4 = mdns_service_txt_set("_meshcop",&_LC9,&puStack_28,3);
    if (iVar4 == 0) {
      iVar4 = mdns_service_txt_item_set_with_explicit_value_len("_meshcop",&_LC9,&_LC13,uVar2,8);
      if (iVar4 == 0) {
        iVar4 = mdns_service_txt_item_set_with_explicit_value_len("_meshcop",&_LC9,&_LC15,uVar3,8);
        if (iVar4 == 0) {
          uStack_90 = __bswapdi2(uStack_90,uStack_8c);
          uStack_8c = extraout_a1;
          iVar4 = mdns_service_txt_item_set_with_explicit_value_len
                            ("_meshcop",&_LC9,&_LC17,&uStack_90,8);
          if (iVar4 == 0) {
            iVar4 = mdns_service_txt_item_set_with_explicit_value_len
                              ("_meshcop",&_LC9,&_LC19,&uStack_98,4);
            if (iVar4 == 0) {
              iVar4 = mdns_service_txt_item_set_with_explicit_value_len
                                ("_meshcop",&_LC9,&_LC21,&uStack_94,4);
              if (iVar4 != 0) {
                uVar1 = esp_log_timestamp();
                esp_log_write(1,"OPENTHREAD",&_LC22,uVar1,"OPENTHREAD",
                              "esp_openthread_publish_meshcop_mdns",0x8d);
              }
            }
            else {
              uVar1 = esp_log_timestamp();
              esp_log_write(1,"OPENTHREAD",&_LC20,uVar1,"OPENTHREAD",
                            "esp_openthread_publish_meshcop_mdns",0x89);
            }
          }
          else {
            uVar1 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD",&_LC18,uVar1,"OPENTHREAD",
                          "esp_openthread_publish_meshcop_mdns",0x85);
          }
        }
        else {
          uVar1 = esp_log_timestamp();
          esp_log_write(1,"OPENTHREAD",&_LC16,uVar1,"OPENTHREAD",
                        "esp_openthread_publish_meshcop_mdns",0x80);
        }
      }
      else {
        uVar1 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC14,uVar1,"OPENTHREAD","esp_openthread_publish_meshcop_mdns"
                      ,0x7c);
      }
    }
    else {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC12,uVar1,"OPENTHREAD","esp_openthread_publish_meshcop_mdns",
                    0x78);
    }
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC8,uVar1,"OPENTHREAD","esp_openthread_publish_meshcop_mdns",0x6e
                 );
    iVar4 = -1;
  }
  return iVar4;
}

