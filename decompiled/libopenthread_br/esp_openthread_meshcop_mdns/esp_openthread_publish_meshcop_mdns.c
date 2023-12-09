/*
 * Last changed at upstream commit b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * https://github.com/espressif/esp-thread-lib/commit/b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * Upstream date: 2023-12-09 16:01:37 +0800
 * Upstream subject: feat(br): update border router lib     esp-openthread: 8d18b44     openthread: 41ef807
 * Source: libopenthread_br -> esp_openthread_meshcop_mdns.o -> esp_openthread_publish_meshcop_mdns
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_publish_meshcop_mdns(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 extraout_a1;
  undefined1 uStack_113;
  undefined2 uStack_112;
  undefined4 uStack_110;
  undefined4 auStack_10c [2];
  undefined1 auStack_104 [8];
  undefined1 uStack_fc;
  undefined1 auStack_f8 [16];
  byte bStack_e8;
  byte bStack_e4;
  undefined1 auStack_e3 [19];
  undefined *puStack_d0;
  undefined4 uStack_cc;
  undefined *puStack_c8;
  undefined *puStack_c4;
  undefined *puStack_c0;
  undefined4 uStack_bc;
  undefined *puStack_b8;
  char *pcStack_b4;
  undefined *puStack_b0;
  char *pcStack_ac;
  undefined *puStack_a8;
  undefined *puStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  
  uVar2 = esp_openthread_get_instance();
  uVar3 = otThreadGetExtendedPanId();
  uVar4 = otLinkGetExtendedAddress(uVar2);
  esp_openthread_get_instance();
  uStack_a0 = 0;
  iVar5 = otBackboneRouterGetState();
  uStack_a0 = CONCAT22((ushort)(iVar5 != 0) << 0xf | iVar5 == 2 | 0x3100 |
                       (ushort)((uint)uStack_a0 >> 0x10) & 0xfe,(undefined2)uStack_a0);
  uStack_110 = uStack_a0;
  otThreadGetPartitionId(uVar2);
  auStack_10c[0] = __bswapsi2();
  uStack_112 = 0xbff0;
  otBackboneRouterGetConfig(uVar2,auStack_104);
  uStack_113 = uStack_fc;
  iVar5 = otDatasetGetActive(uVar2,&uStack_a0);
  if (iVar5 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC5,uVar2,"OPENTHREAD","esp_openthread_publish_meshcop_mdns",0x85
                 );
    return -1;
  }
  uStack_a0 = __bswapdi2(uStack_a0,uStack_9c);
  uStack_9c = extraout_a1;
  uVar6 = otThreadGetDomainName(uVar2);
  iVar5 = otThreadGetVersion();
  if (iVar5 == 3) {
    puVar1 = &_LC1;
  }
  else if (iVar5 == 4) {
    puVar1 = &_LC2;
  }
  else if (iVar5 == 2) {
    puVar1 = (undefined *)0x10000;
  }
  else {
    puVar1 = &_LC3;
  }
  uStack_bc = otThreadGetNetworkName(uVar2);
  puStack_d0 = &_LC6;
  puStack_c8 = &_LC7;
  puStack_c0 = &_LC8;
  puStack_b8 = &_LC9;
  pcStack_b4 = "BorderRouter";
  puStack_b0 = &_LC11;
  pcStack_ac = "OpenThread";
  puStack_a8 = &_LC13;
  puStack_a4 = &_LC14;
  uStack_cc = uVar6;
  puStack_c4 = puVar1;
  if (s_service_published == '\0') {
    uVar6 = otBorderAgentGetUdpPort(uVar2);
    iVar5 = mdns_service_add(0,"_meshcop",&_LC15,uVar6,0,0);
    if (iVar5 != 0) {
      uVar3 = esp_log_timestamp();
      uVar2 = 0x95;
      puVar1 = &_LC17;
      goto _L0;
    }
    s_service_published = '\x01';
  }
  iVar5 = mdns_service_txt_set("_meshcop",&_LC15,&puStack_d0,6);
  if (iVar5 == 0) {
    iVar5 = mdns_service_txt_item_set_with_explicit_value_len
                      ("_meshcop",&_LC15,&_LC19,&uStack_112,2);
    if (iVar5 == 0) {
      iVar5 = mdns_service_txt_item_set_with_explicit_value_len
                        ("_meshcop",&_LC15,&_LC21,&uStack_113,1);
      if (iVar5 == 0) {
        iVar5 = mdns_service_txt_item_set_with_explicit_value_len
                          ("_meshcop",&_LC15,&_LC23,auStack_10c,4);
        if (iVar5 == 0) {
          iVar5 = mdns_service_txt_item_set_with_explicit_value_len
                            ("_meshcop",&_LC15,&_LC25,&uStack_a0,8);
          if (iVar5 == 0) {
            iVar5 = mdns_service_txt_item_set_with_explicit_value_len
                              ("_meshcop",&_LC15,&_LC27,&uStack_110,4);
            if (iVar5 == 0) {
              iVar5 = mdns_service_txt_item_set_with_explicit_value_len
                                ("_meshcop",&_LC15,&_LC29,uVar4,8);
              if (iVar5 == 0) {
                iVar5 = mdns_service_txt_item_set_with_explicit_value_len
                                  ("_meshcop",&_LC15,&_LC31,uVar3,8);
                if (iVar5 == 0) {
                  iVar5 = otBorderRoutingGetOmrPrefix(uVar2,auStack_f8);
                  if (iVar5 == 0) {
                    bStack_e4 = bStack_e8;
                    memcpy(auStack_e3,auStack_f8,(uint)(bStack_e8 >> 3));
                    iVar5 = mdns_service_txt_item_set_with_explicit_value_len
                                      ("_meshcop",&_LC15,&_LC33,&bStack_e4,(bStack_e8 >> 3) + 1);
                    if (iVar5 != 0) {
                      uVar2 = esp_log_timestamp();
                      esp_log_write(1,"OPENTHREAD",&_LC34,uVar2,"OPENTHREAD",
                                    "esp_openthread_publish_meshcop_mdns",0xc0);
                      return iVar5;
                    }
                  }
                  iVar5 = otBorderAgentGetId(uVar2,&bStack_e4);
                  if (iVar5 != 0) {
                    return 0;
                  }
                  iVar5 = mdns_service_txt_item_set_with_explicit_value_len
                                    ("_meshcop",&_LC15,&_LC35,&bStack_e4,0x10);
                  if (iVar5 == 0) {
                    return 0;
                  }
                  uVar3 = esp_log_timestamp();
                  uVar2 = 200;
                  puVar1 = &_LC36;
                }
                else {
                  uVar3 = esp_log_timestamp();
                  uVar2 = 0xb6;
                  puVar1 = &_LC32;
                }
              }
              else {
                uVar3 = esp_log_timestamp();
                uVar2 = 0xb2;
                puVar1 = &_LC30;
              }
            }
            else {
              uVar3 = esp_log_timestamp();
              uVar2 = 0xae;
              puVar1 = &_LC28;
            }
          }
          else {
            uVar3 = esp_log_timestamp();
            uVar2 = 0xa9;
            puVar1 = &_LC26;
          }
        }
        else {
          uVar3 = esp_log_timestamp();
          uVar2 = 0xa5;
          puVar1 = &_LC24;
        }
      }
      else {
        uVar3 = esp_log_timestamp();
        uVar2 = 0xa1;
        puVar1 = &_LC22;
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      uVar2 = 0x9e;
      puVar1 = &_LC20;
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    uVar2 = 0x9b;
    puVar1 = &_LC18;
  }
_L0:
  esp_log_write(1,"OPENTHREAD",puVar1,uVar3,"OPENTHREAD","esp_openthread_publish_meshcop_mdns",uVar2
               );
  return iVar5;
}

