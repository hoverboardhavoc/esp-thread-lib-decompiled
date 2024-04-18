/*
 * Last changed at upstream commit a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * https://github.com/espressif/esp-thread-lib/commit/a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * Upstream date: 2024-04-18 16:47:55 +0800
 * Upstream subject: feat(br): update border router lib           esp-openthread: 07f637d           openthread: be7d36e
 * Source: libopenthread_br -> esp_openthread_meshcop_mdns.o -> esp_openthread_publish_meshcop_mdns
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_publish_meshcop_mdns(void)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 extraout_a1;
  undefined *puVar11;
  undefined1 uStack_133;
  undefined2 uStack_132;
  undefined4 uStack_130;
  undefined4 auStack_12c [2];
  undefined1 auStack_124 [8];
  undefined1 uStack_11c;
  undefined1 auStack_118 [16];
  undefined1 auStack_108 [16];
  byte bStack_f8;
  byte bStack_f4;
  undefined1 auStack_f3 [19];
  undefined *puStack_e0;
  undefined4 uStack_dc;
  undefined *puStack_d8;
  char *pcStack_d4;
  undefined *puStack_d0;
  undefined4 uStack_cc;
  undefined *puStack_c8;
  char *pcStack_c4;
  undefined *puStack_c0;
  char *pcStack_bc;
  undefined *puStack_b8;
  undefined *puStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  
  uVar2 = esp_openthread_get_instance();
  uVar3 = otThreadGetExtendedPanId();
  uVar4 = otLinkGetExtendedAddress(uVar2);
  esp_openthread_get_instance();
  uStack_b0 = 0;
  iVar5 = otBackboneRouterGetState();
  uVar6 = otThreadGetVersion();
  uStack_b0 = CONCAT22((ushort)(4 < uVar6) << 3 | iVar5 == 2 | 0x3100 | (ushort)(iVar5 != 0) << 0xf
                       | (ushort)((uint)uStack_b0 >> 0x10) & 0xf6,(undefined2)uStack_b0);
  uStack_130 = uStack_b0;
  otThreadGetPartitionId(uVar2);
  auStack_12c[0] = __bswapsi2();
  uStack_132 = 0xbff0;
  otBackboneRouterGetConfig(uVar2,auStack_124);
  uStack_133 = uStack_11c;
  iVar5 = otDatasetGetActive(uVar2,&uStack_b0);
  if (iVar5 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC6,uVar2,"OPENTHREAD","esp_openthread_publish_meshcop_mdns",0x90
                 );
    return -1;
  }
  uStack_b0 = __bswapdi2(uStack_b0,uStack_ac);
  uStack_ac = extraout_a1;
  uVar7 = otThreadGetDomainName(uVar2);
  uVar6 = otThreadGetVersion();
  if (uVar6 == 4) {
    pcVar1 = "1.3.0";
  }
  else if (uVar6 < 5) {
    if (uVar6 == 2) {
      pcVar1 = "1.1.1";
    }
    else {
      if (uVar6 != 3) goto _L0;
      pcVar1 = "1.2.0";
    }
  }
  else if (uVar6 == 5) {
    pcVar1 = "1.4.0";
  }
  else {
_L0:
    pcVar1 = "";
  }
  uVar8 = otThreadGetNetworkName(uVar2);
  iVar5 = otBorderRoutingGetOmrPrefix(uVar2,auStack_108);
  iVar9 = otBorderAgentGetId(uVar2,auStack_118);
  puStack_e0 = &_LC7;
  puStack_d8 = &_LC8;
  puStack_d0 = &_LC9;
  puStack_c8 = &_LC10;
  pcStack_c4 = "BorderRouter";
  puStack_c0 = &_LC12;
  pcStack_bc = "OpenThread";
  puStack_b8 = &_LC14;
  puStack_b4 = &_LC15;
  uStack_dc = uVar7;
  pcStack_d4 = pcVar1;
  uStack_cc = uVar8;
  if (s_service_published == '\0') {
    uVar2 = otBorderAgentGetUdpPort(uVar2);
    esp_openthread_task_switching_lock_release();
    iVar10 = mdns_service_add(0,"_meshcop",&_LC16,uVar2,0,0);
    if (iVar10 == 0) {
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      s_service_published = '\x01';
      goto _L0;
    }
    uVar3 = esp_log_timestamp();
    uVar2 = 0xa8;
    puVar11 = &_LC18;
  }
  else {
_L0:
    esp_openthread_task_switching_lock_release();
    iVar10 = mdns_service_txt_set("_meshcop",&_LC16,&puStack_e0,6);
    if (iVar10 == 0) {
      iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                         ("_meshcop",&_LC16,&_LC20,&uStack_132,2);
      if (iVar10 == 0) {
        iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                           ("_meshcop",&_LC16,&_LC22,&uStack_133,1);
        if (iVar10 == 0) {
          iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                             ("_meshcop",&_LC16,&_LC24,auStack_12c,4);
          if (iVar10 == 0) {
            iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                               ("_meshcop",&_LC16,&_LC26,&uStack_b0,8);
            if (iVar10 == 0) {
              iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                                 ("_meshcop",&_LC16,&_LC28,&uStack_130,4);
              if (iVar10 == 0) {
                iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                                   ("_meshcop",&_LC16,&_LC30,uVar4,8);
                if (iVar10 == 0) {
                  iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                                     ("_meshcop",&_LC16,&_LC32,uVar3,8);
                  if (iVar10 == 0) {
                    if (iVar5 == 0) {
                      bStack_f4 = bStack_f8;
                      memcpy(auStack_f3,auStack_108,(uint)(bStack_f8 >> 3));
                      iVar5 = mdns_service_txt_item_set_with_explicit_value_len
                                        ("_meshcop",&_LC16,&_LC34,&bStack_f4,(bStack_f8 >> 3) + 1);
                      if (iVar5 != 0) {
                        uVar2 = esp_log_timestamp();
                        esp_log_write(1,"OPENTHREAD",&_LC35,uVar2,"OPENTHREAD",
                                      "esp_openthread_publish_meshcop_mdns",0xd2);
                        iVar10 = iVar5;
                        goto _L0;
                      }
                    }
                    if ((iVar9 != 0) ||
                       (iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                                           ("_meshcop",&_LC16,&_LC36,auStack_118,0x10), iVar10 == 0)
                       ) goto _L0;
                    uVar3 = esp_log_timestamp();
                    uVar2 = 0xd9;
                    puVar11 = &_LC37;
                  }
                  else {
                    uVar3 = esp_log_timestamp();
                    uVar2 = 0xc9;
                    puVar11 = &_LC33;
                  }
                }
                else {
                  uVar3 = esp_log_timestamp();
                  uVar2 = 0xc5;
                  puVar11 = &_LC31;
                }
              }
              else {
                uVar3 = esp_log_timestamp();
                uVar2 = 0xc1;
                puVar11 = &_LC29;
              }
            }
            else {
              uVar3 = esp_log_timestamp();
              uVar2 = 0xbd;
              puVar11 = &_LC27;
            }
          }
          else {
            uVar3 = esp_log_timestamp();
            uVar2 = 0xb9;
            puVar11 = &_LC25;
          }
        }
        else {
          uVar3 = esp_log_timestamp();
          uVar2 = 0xb5;
          puVar11 = &_LC23;
        }
      }
      else {
        uVar3 = esp_log_timestamp();
        uVar2 = 0xb2;
        puVar11 = &_LC21;
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      uVar2 = 0xaf;
      puVar11 = &_LC19;
    }
  }
  esp_log_write(1,"OPENTHREAD",puVar11,uVar3,"OPENTHREAD","esp_openthread_publish_meshcop_mdns",
                uVar2);
_L0:
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  return iVar10;
}

