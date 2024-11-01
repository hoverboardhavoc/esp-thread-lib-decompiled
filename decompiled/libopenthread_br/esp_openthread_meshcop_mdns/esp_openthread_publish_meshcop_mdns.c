/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> esp_openthread_meshcop_mdns.o -> esp_openthread_publish_meshcop_mdns
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_publish_meshcop_mdns(undefined4 param_1)

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
  undefined1 uStack_13b;
  undefined2 uStack_13a;
  undefined4 uStack_138;
  undefined4 auStack_134 [2];
  undefined1 auStack_12c [8];
  undefined1 uStack_124;
  undefined1 auStack_120 [16];
  undefined1 auStack_110 [16];
  byte bStack_100;
  byte bStack_fc;
  undefined1 auStack_fb [19];
  undefined *puStack_e8;
  undefined4 uStack_e4;
  undefined *puStack_e0;
  char *pcStack_dc;
  undefined *puStack_d8;
  undefined4 uStack_d4;
  undefined *puStack_d0;
  char *pcStack_cc;
  undefined *puStack_c8;
  char *pcStack_c4;
  undefined *puStack_c0;
  undefined *puStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  
  uVar2 = esp_openthread_get_instance();
  uVar3 = otThreadGetExtendedPanId();
  uVar4 = otLinkGetExtendedAddress(uVar2);
  esp_openthread_get_instance();
  uStack_b8 = 0;
  iVar5 = otBackboneRouterGetState();
  uVar6 = otThreadGetVersion();
  uStack_b8 = CONCAT22((ushort)(4 < uVar6) << 3 | iVar5 == 2 | 0x3100 | (ushort)(iVar5 != 0) << 0xf
                       | (ushort)((uint)uStack_b8 >> 0x10) & 0xf6,(undefined2)uStack_b8);
  uStack_138 = uStack_b8;
  otThreadGetPartitionId(uVar2);
  auStack_134[0] = __bswapsi2();
  uStack_13a = 0xbff0;
  otBackboneRouterGetConfig(uVar2,auStack_12c);
  uStack_13b = uStack_124;
  iVar5 = otDatasetGetActive(uVar2,&uStack_b8);
  if (iVar5 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD","E (%lu) %s: %s(%d): Failed to get OpenThread active dataset\n",
                  uVar2,"OPENTHREAD","esp_openthread_publish_meshcop_mdns",0x90);
    return -1;
  }
  uStack_b8 = __bswapdi2(uStack_b8,uStack_b4);
  uStack_b4 = extraout_a1;
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
  iVar5 = otBorderRoutingGetOmrPrefix(uVar2,auStack_110);
  iVar9 = otBorderAgentGetId(uVar2,auStack_120);
  puStack_e8 = &_LC7;
  puStack_e0 = &_LC8;
  puStack_d8 = &_LC9;
  puStack_d0 = &_LC10;
  pcStack_cc = "BorderRouter";
  puStack_c8 = &_LC12;
  pcStack_c4 = "OpenThread";
  puStack_c0 = &_LC14;
  puStack_bc = &_LC15;
  uStack_e4 = uVar7;
  pcStack_dc = pcVar1;
  uStack_d4 = uVar8;
  if (s_service_published == '\0') {
    uVar2 = otBorderAgentGetUdpPort(uVar2);
    esp_openthread_task_switching_lock_release();
    iVar10 = mdns_service_add(param_1,"_meshcop",&_LC16,uVar2,0,0);
    if (iVar10 == 0) {
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      s_service_published = '\x01';
      goto _L0;
    }
    uVar3 = esp_log_timestamp();
    uVar2 = 0xa8;
    pcVar1 = "E (%lu) %s: %s(%d): Failed to publish meshcop mdns service\n";
  }
  else {
_L0:
    esp_openthread_task_switching_lock_release();
    iVar10 = mdns_service_txt_set("_meshcop",&_LC16,&puStack_e8,6);
    if (iVar10 == 0) {
      iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                         ("_meshcop",&_LC16,&_LC20,&uStack_13a,2);
      if (iVar10 == 0) {
        iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                           ("_meshcop",&_LC16,&_LC22,&uStack_13b,1);
        if (iVar10 == 0) {
          iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                             ("_meshcop",&_LC16,&_LC24,auStack_134,4);
          if (iVar10 == 0) {
            iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                               ("_meshcop",&_LC16,&_LC26,&uStack_b8,8);
            if (iVar10 == 0) {
              iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                                 ("_meshcop",&_LC16,&_LC28,&uStack_138,4);
              if (iVar10 == 0) {
                iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                                   ("_meshcop",&_LC16,&_LC30,uVar4,8);
                if (iVar10 == 0) {
                  iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                                     ("_meshcop",&_LC16,&_LC32,uVar3,8);
                  if (iVar10 == 0) {
                    if (iVar5 == 0) {
                      bStack_fc = bStack_100;
                      memcpy(auStack_fb,auStack_110,(uint)(bStack_100 >> 3));
                      iVar5 = mdns_service_txt_item_set_with_explicit_value_len
                                        ("_meshcop",&_LC16,&_LC34,&bStack_fc,(bStack_100 >> 3) + 1);
                      if (iVar5 != 0) {
                        uVar2 = esp_log_timestamp();
                        esp_log_write(1,"OPENTHREAD",
                                      "E (%lu) %s: %s(%d): Failed to set Off-Mesh routable prefix in meshcop mdns service\n"
                                      ,uVar2,"OPENTHREAD","esp_openthread_publish_meshcop_mdns",0xd2
                                     );
                        iVar10 = iVar5;
                        goto _L0;
                      }
                    }
                    if ((iVar9 != 0) ||
                       (iVar10 = mdns_service_txt_item_set_with_explicit_value_len
                                           ("_meshcop",&_LC16,&_LC36,auStack_120,0x10), iVar10 == 0)
                       ) goto _L0;
                    uVar3 = esp_log_timestamp();
                    uVar2 = 0xd9;
                    pcVar1 = 
                    "E (%lu) %s: %s(%d): Failed to set border agent id in meshcop mdns service\n";
                  }
                  else {
                    uVar3 = esp_log_timestamp();
                    uVar2 = 0xc9;
                    pcVar1 = "E (%lu) %s: %s(%d): Failed to set extpanid in meshcop mdns service\n";
                  }
                }
                else {
                  uVar3 = esp_log_timestamp();
                  uVar2 = 0xc5;
                  pcVar1 = 
                  "E (%lu) %s: %s(%d): Failed to set device discriminator in meshcop mdns service\n"
                  ;
                }
              }
              else {
                uVar3 = esp_log_timestamp();
                uVar2 = 0xc1;
                pcVar1 = "E (%lu) %s: %s(%d): Failed to set state bitmap in meshcop mdns service\n";
              }
            }
            else {
              uVar3 = esp_log_timestamp();
              uVar2 = 0xbd;
              pcVar1 = 
              "E (%lu) %s: %s(%d): Failed to set active timestamp in meshcop mdns service\n";
            }
          }
          else {
            uVar3 = esp_log_timestamp();
            uVar2 = 0xb9;
            pcVar1 = "E (%lu) %s: %s(%d): Failed to set partition id in meshcop mdns service\n";
          }
        }
        else {
          uVar3 = esp_log_timestamp();
          uVar2 = 0xb5;
          pcVar1 = "E (%lu) %s: %s(%d): Failed to set sequence number in meshcop mdns service\n";
        }
      }
      else {
        uVar3 = esp_log_timestamp();
        uVar2 = 0xb2;
        pcVar1 = "E (%lu) %s: %s(%d): Failed to set bbr port number in meshcop mdns service\n";
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      uVar2 = 0xaf;
      pcVar1 = "E (%lu) %s: %s(%d): Failed to set txt items for meshcop mdns service\n";
    }
  }
  esp_log_write(1,"OPENTHREAD",pcVar1,uVar3,"OPENTHREAD","esp_openthread_publish_meshcop_mdns",uVar2
               );
_L0:
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  return iVar10;
}

