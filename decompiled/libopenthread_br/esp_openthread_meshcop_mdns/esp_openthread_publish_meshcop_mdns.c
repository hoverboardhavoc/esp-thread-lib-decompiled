/*
 * Last changed at upstream commit e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * https://github.com/espressif/esp-thread-lib/commit/e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * Upstream date: 2023-06-02 12:00:23 +0800
 * Upstream subject: ot br lib: fix issues in certification esp-openthread: a158ca1 openthread:091f68e
 * Source: libopenthread_br -> esp_openthread_meshcop_mdns.o -> esp_openthread_publish_meshcop_mdns
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_publish_meshcop_mdns(void)

{
  uint __n;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  char *__s;
  undefined4 uVar5;
  size_t sVar6;
  undefined4 extraout_a1;
  undefined *puVar7;
  char *__s_00;
  undefined1 uStack_f3;
  undefined2 uStack_f2;
  undefined4 uStack_f0;
  undefined4 auStack_ec [2];
  undefined *puStack_e4;
  undefined4 uStack_e0;
  undefined1 auStack_dc [8];
  undefined1 uStack_d4;
  undefined1 auStack_d0 [16];
  byte bStack_c0;
  byte bStack_bc;
  undefined1 auStack_bb [19];
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  
  uVar1 = esp_openthread_get_instance();
  puStack_e4 = &_LC4;
  uStack_e0 = otThreadGetDomainName();
  uVar2 = otThreadGetExtendedPanId(uVar1);
  uVar3 = otLinkGetExtendedAddress(uVar1);
  esp_openthread_get_instance();
  uStack_a8 = 0;
  iVar4 = otBackboneRouterGetState();
  uStack_a8 = CONCAT22(iVar4 == 2 | 0x3100 | (ushort)(iVar4 != 0) << 0xf |
                       (ushort)((uint)uStack_a8 >> 0x10) & 0xfe,(undefined2)uStack_a8);
  uStack_f0 = uStack_a8;
  auStack_ec[0] = otThreadGetPartitionId(uVar1);
  uStack_f2 = 0xbff0;
  otBackboneRouterGetConfig(uVar1,auStack_dc);
  uStack_f3 = uStack_d4;
  iVar4 = otThreadGetVersion();
  if (iVar4 == 3) {
    __s_00 = "1.2.0";
  }
  else if (iVar4 == 4) {
    __s_00 = "1.3.0";
  }
  else if (iVar4 == 2) {
    __s_00 = "1.1.1";
  }
  else {
    __s_00 = "";
  }
  __s = (char *)otThreadGetNetworkName(uVar1);
  iVar4 = otDatasetGetActive(uVar1,&uStack_a8);
  if (iVar4 != 0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC6,uVar1,"OPENTHREAD","esp_openthread_publish_meshcop_mdns",0x8e
                 );
    return -1;
  }
  uStack_a8 = __bswapdi2(uStack_a8,uStack_a4);
  uStack_a4 = extraout_a1;
  if (s_service_published == '\0') {
    uVar5 = otBorderAgentGetUdpPort(uVar1);
    iVar4 = mdns_service_add(0,"_meshcop",&_LC7,uVar5,0,0);
    if (iVar4 != 0) {
      uVar2 = esp_log_timestamp();
      uVar1 = 0x92;
      puVar7 = &_LC9;
      goto _L0;
    }
    s_service_published = '\x01';
  }
  iVar4 = otBorderRoutingGetOmrPrefix(uVar1,auStack_d0);
  if (iVar4 != 0) {
    __n = (uint)bStack_c0;
    bStack_bc = bStack_c0;
    memcpy(auStack_bb,auStack_d0,__n);
    auStack_bb[__n] = 0;
    iVar4 = mdns_service_txt_item_set_with_explicit_value_len
                      ("_meshcop",&_LC7,&_LC10,&bStack_bc,__n + 1 & 0xff);
    if (iVar4 != 0) {
      uVar2 = esp_log_timestamp();
      uVar1 = 0x9e;
      puVar7 = &_LC11;
      goto _L0;
    }
  }
  iVar4 = mdns_service_txt_set("_meshcop",&_LC7,&puStack_e4,1);
  if (iVar4 == 0) {
    iVar4 = mdns_service_txt_item_set_with_explicit_value_len("_meshcop",&_LC7,&_LC13,&uStack_f2,2);
    if (iVar4 == 0) {
      iVar4 = mdns_service_txt_item_set_with_explicit_value_len
                        ("_meshcop",&_LC7,&_LC15,&uStack_f3,1);
      if (iVar4 == 0) {
        iVar4 = mdns_service_txt_item_set_with_explicit_value_len
                          ("_meshcop",&_LC7,&_LC17,auStack_ec,4);
        if (iVar4 == 0) {
          iVar4 = mdns_service_txt_item_set_with_explicit_value_len
                            ("_meshcop",&_LC7,&_LC19,&uStack_a8,8);
          if (iVar4 == 0) {
            iVar4 = mdns_service_txt_item_set_with_explicit_value_len
                              ("_meshcop",&_LC7,&_LC21,&uStack_f0,4);
            if (iVar4 == 0) {
              iVar4 = mdns_service_txt_item_set_with_explicit_value_len
                                ("_meshcop",&_LC7,&_LC23,uVar3,8);
              if (iVar4 == 0) {
                sVar6 = strlen(__s_00);
                iVar4 = mdns_service_txt_item_set_with_explicit_value_len
                                  ("_meshcop",&_LC7,&_LC25,__s_00,sVar6 & 0xff);
                if (iVar4 == 0) {
                  iVar4 = mdns_service_txt_item_set_with_explicit_value_len
                                    ("_meshcop",&_LC7,&_LC27,uVar2,8);
                  if (iVar4 == 0) {
                    sVar6 = strlen(__s);
                    iVar4 = mdns_service_txt_item_set_with_explicit_value_len
                                      ("_meshcop",&_LC7,&_LC29,__s,sVar6 & 0xff);
                    if (iVar4 == 0) {
                      iVar4 = mdns_service_txt_item_set_with_explicit_value_len
                                        ("_meshcop",&_LC7,&_LC32,"BorderRouter",0xc);
                      if (iVar4 == 0) {
                        iVar4 = mdns_service_txt_item_set_with_explicit_value_len
                                          ("_meshcop",&_LC7,&_LC35,"OpenThread",10);
                        if (iVar4 == 0) {
                          iVar4 = mdns_service_txt_item_set_with_explicit_value_len
                                            ("_meshcop",&_LC7,&_LC38,&_LC37,1);
                          if (iVar4 == 0) {
                            return 0;
                          }
                          uVar2 = esp_log_timestamp();
                          uVar1 = 0xd2;
                          puVar7 = &_LC39;
                        }
                        else {
                          uVar2 = esp_log_timestamp();
                          uVar1 = 0xce;
                          puVar7 = &_LC36;
                        }
                      }
                      else {
                        uVar2 = esp_log_timestamp();
                        uVar1 = 0xcb;
                        puVar7 = &_LC33;
                      }
                    }
                    else {
                      uVar2 = esp_log_timestamp();
                      uVar1 = 199;
                      puVar7 = &_LC30;
                    }
                  }
                  else {
                    uVar2 = esp_log_timestamp();
                    uVar1 = 0xc3;
                    puVar7 = &_LC28;
                  }
                }
                else {
                  uVar2 = esp_log_timestamp();
                  uVar1 = 0xbf;
                  puVar7 = &_LC26;
                }
              }
              else {
                uVar2 = esp_log_timestamp();
                uVar1 = 0xbb;
                puVar7 = &_LC24;
              }
            }
            else {
              uVar2 = esp_log_timestamp();
              uVar1 = 0xb7;
              puVar7 = &_LC22;
            }
          }
          else {
            uVar2 = esp_log_timestamp();
            uVar1 = 0xb2;
            puVar7 = &_LC20;
          }
        }
        else {
          uVar2 = esp_log_timestamp();
          uVar1 = 0xad;
          puVar7 = &_LC18;
        }
      }
      else {
        uVar2 = esp_log_timestamp();
        uVar1 = 0xa9;
        puVar7 = &_LC16;
      }
    }
    else {
      uVar2 = esp_log_timestamp();
      uVar1 = 0xa6;
      puVar7 = &_LC14;
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    uVar1 = 0xa3;
    puVar7 = &_LC12;
  }
_L0:
  esp_log_write(1,"OPENTHREAD",puVar7,uVar2,"OPENTHREAD","esp_openthread_publish_meshcop_mdns",uVar1
               );
  return iVar4;
}

