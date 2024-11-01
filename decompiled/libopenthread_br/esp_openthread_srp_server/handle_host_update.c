/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> handle_host_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_host_update(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  int iVar13;
  size_t __n;
  undefined4 *puVar14;
  uint uVar15;
  undefined4 *puVar16;
  size_t __n_00;
  size_t sVar17;
  byte bStack_1b3;
  undefined2 uStack_1b2;
  char acStack_1b0 [8];
  char *pcStack_1a8;
  char *pcStack_1a4;
  ushort uStack_1a0;
  char acStack_19c [68];
  char acStack_158 [68];
  char acStack_114 [68];
  char acStack_d0 [68];
  undefined1 auStack_8c [88];
  
  otSrpServerHostGetFullName(param_2);
  split_hostname_constprop_0(acStack_19c);
  uVar3 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD","I (%lu) %s: update host %s\n",uVar3,"OPENTHREAD",acStack_19c);
  esp_openthread_task_switching_lock_release();
  iVar4 = mdns_hostname_get(acStack_158);
  iVar5 = mdns_hostname_exists(acStack_19c);
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  iVar6 = otSrpServerHostGetAddresses(param_2,&bStack_1b3);
  if (bStack_1b3 == 0) {
    if (iVar5 != 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD","I (%lu) %s: Set addr of host to NULL\n",uVar3,"OPENTHREAD");
      pvVar7 = (void *)0x0;
      goto _L0;
    }
    uVar3 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD","I (%lu) %s: Add a new host without an addr\n",uVar3,"OPENTHREAD");
    pvVar7 = (void *)0x0;
_L0:
    if (iVar4 == 0) {
      iVar5 = strcasecmp(acStack_158,acStack_19c);
      iVar4 = 0x1d;
      pvVar1 = pvVar7;
      if (iVar5 == 0) goto _L0;
    }
    esp_openthread_task_switching_lock_release();
    mdns_delegate_hostname_add(acStack_19c,pvVar7);
  }
  else {
    uVar15 = 0;
    pvVar1 = (void *)0x0;
    do {
      pvVar7 = malloc(0x1c);
      if (pvVar7 == (void *)0x0) {
        iVar4 = 3;
        goto _L0;
      }
      *(undefined1 *)((int)pvVar7 + 0x14) = 6;
      memcpy(pvVar7,(void *)(uVar15 * 0x10 + iVar6),0x10);
      uVar15 = uVar15 + 1;
      *(undefined1 *)((int)pvVar7 + 0x10) = 0;
      *(void **)((int)pvVar7 + 0x18) = pvVar1;
      pvVar1 = pvVar7;
    } while ((uVar15 & 0xff) < (uint)bStack_1b3);
    if (iVar5 == 0) {
      do {
        uVar3 = esp_log_timestamp();
        uVar8 = ip6addr_ntoa(pvVar1);
        esp_log_write(3,"OPENTHREAD","I (%lu) %s: Add a new host, addr %s\n",uVar3,"OPENTHREAD",
                      uVar8);
        puVar14 = (undefined4 *)((int)pvVar1 + 0x18);
        pvVar1 = (void *)*puVar14;
      } while ((void *)*puVar14 != (void *)0x0);
      goto _L0;
    }
    do {
      uVar3 = esp_log_timestamp();
      uVar8 = ip6addr_ntoa(pvVar1);
      esp_log_write(3,"OPENTHREAD","I (%lu) %s: Set addr of host to %s\n",uVar3,"OPENTHREAD",uVar8);
      puVar14 = (undefined4 *)((int)pvVar1 + 0x18);
      pvVar1 = (void *)*puVar14;
    } while ((void *)*puVar14 != (void *)0x0);
_L0:
    if (iVar4 == 0) {
      iVar5 = strcasecmp(acStack_158,acStack_19c);
      iVar4 = 0x1d;
      pvVar1 = pvVar7;
      if (iVar5 == 0) goto _L0;
    }
    esp_openthread_task_switching_lock_release();
    mdns_delegate_hostname_set_address(acStack_19c,pvVar7);
  }
  iVar4 = convert_to_ot_srp_error_code();
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  pvVar1 = pvVar7;
_L0:
  while (pvVar1 != (void *)0x0) {
    pvVar7 = *(void **)((int)pvVar1 + 0x18);
    free(pvVar1);
    pvVar1 = pvVar7;
  }
  iVar5 = iVar4;
  if (iVar4 != 0) {
_L0:
    esp_openthread_get_instance();
    otSrpServerHandleServiceUpdateResult(param_1,iVar5);
    return;
  }
  iVar6 = 0;
  do {
    iVar6 = otSrpServerHostGetNextService(param_2,iVar6);
    iVar5 = iVar4;
    if (iVar6 == 0) goto _L0;
    pcVar9 = (char *)otSrpServerServiceGetInstanceName();
    memset(acStack_114,0,0x41);
    memset(acStack_d0,0,0x41);
    acStack_1b0[0] = '\0';
    acStack_1b0[1] = '\0';
    acStack_1b0[2] = '\0';
    acStack_1b0[3] = '\0';
    acStack_1b0[4] = '\0';
    acStack_1b0[5] = '\0';
    pcVar10 = strchr(pcVar9,0x2e);
    sVar17 = (int)pcVar10 - (int)pcVar9;
    if (0x40 < sVar17) {
      sVar17 = 0x40;
    }
    pcVar10 = pcVar10 + 1;
    pcVar11 = strchr(pcVar10,0x2e);
    __n = (int)pcVar11 - (int)pcVar10;
    if (0x40 < __n) {
      __n = 0x40;
    }
    pcVar11 = pcVar11 + 1;
    pcVar12 = strchr(pcVar11,0x2e);
    __n_00 = (int)pcVar12 - (int)pcVar11;
    if (5 < __n_00) {
      __n_00 = 5;
    }
    strncpy(acStack_114,pcVar9,sVar17);
    acStack_114[sVar17] = '\0';
    strncpy(acStack_d0,pcVar10,__n);
    acStack_d0[__n] = '\0';
    strncpy(acStack_1b0,pcVar11,__n_00);
    acStack_1b0[__n_00] = '\0';
    uVar3 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD","I (%lu) %s: Service %s.%s.%s\n",uVar3,"OPENTHREAD",acStack_114,
                  acStack_d0,acStack_1b0);
    esp_openthread_task_switching_lock_release();
    iVar5 = mdns_service_exists_with_instance(acStack_114,acStack_d0,acStack_1b0,acStack_19c);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    iVar13 = otSrpServerServiceIsDeleted(iVar6);
    if (iVar13 == 0) {
      uStack_1b2 = 0;
      uVar3 = otSrpServerServiceGetTxtData(iVar6,&uStack_1b2);
      otDnsInitTxtEntryIterator(auStack_8c,uVar3,uStack_1b2);
      uVar15 = 0;
      while (iVar13 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1a8), iVar13 == 0) {
        uVar15 = uVar15 + 1 & 0xff;
      }
      if (uVar15 == 0) {
_L0:
        puVar14 = (undefined4 *)0x0;
        uVar2 = 0;
      }
      else {
        puVar14 = (undefined4 *)malloc(uVar15 << 3);
        if (puVar14 == (undefined4 *)0x0) {
          iVar5 = 3;
          goto _L0;
        }
        memset(puVar14,0,uVar15 << 3);
        otDnsInitTxtEntryIterator(auStack_8c,uVar3,uStack_1b2);
        uVar15 = 0;
        while (iVar13 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1a8), iVar13 == 0) {
          pcVar11 = (char *)malloc(0x41);
          pcVar12 = (char *)malloc(0x41);
          pcVar10 = pcStack_1a4;
          pcVar9 = pcStack_1a8;
          if (pcStack_1a8 == (char *)0x0) {
            uVar2 = (uint)uStack_1a0;
            sVar17 = 0;
            do {
              if (pcStack_1a4[sVar17] == '=') {
                if ((sVar17 - 1 & 0xffff) < 0x40) {
                  strncpy(pcVar11,pcStack_1a4,sVar17);
                  uVar2 = uVar2 - sVar17 & 0xffff;
                  pcVar11[sVar17] = '\0';
                  puVar16 = puVar14 + uVar15 * 2;
                  *puVar16 = pcVar11;
                  if ((uVar2 - 2 & 0xffff) < 0x40) {
                    uVar2 = uVar2 - 1 & 0xffff;
                    strncpy(pcVar12,pcVar10 + sVar17 + 1,uVar2);
                    pcVar12[uVar2] = '\0';
                    goto _L0;
                  }
                }
                break;
              }
              sVar17 = sVar17 + 1 & 0xffff;
            } while (uVar2 != sVar17);
_L0:
            free(pcVar11);
            free(pcVar12);
          }
          else {
            if ((pcVar11 == (char *)0x0) || (sVar17 = strnlen(pcStack_1a8,0x41), 0x40 < sVar17))
            goto _L0;
            strncpy(pcVar11,pcVar9,0x40);
            puVar16 = puVar14 + uVar15 * 2;
            pcVar11[0x40] = '\0';
            *puVar16 = pcVar11;
            if ((pcVar12 == (char *)0x0) || (uVar2 = (uint)uStack_1a0, 0x40 < uVar2)) goto _L0;
            strncpy(pcVar12,pcStack_1a4,uVar2);
            pcVar12[uVar2] = '\0';
_L0:
            puVar16[1] = pcVar12;
            uVar15 = uVar15 + 1;
          }
        }
        uVar2 = uVar15 & 0xff;
        if (uVar15 == 0) {
          free(puVar14);
          goto _L0;
        }
      }
      uVar3 = otSrpServerServiceGetPort(iVar6);
      esp_openthread_task_switching_lock_release();
      if (iVar5 == 0) {
        uVar8 = esp_log_timestamp();
        esp_log_write(3,"OPENTHREAD","I (%lu) %s: Add new service\n",uVar8,"OPENTHREAD");
        iVar13 = mdns_service_add_for_host
                           (acStack_114,acStack_d0,acStack_1b0,acStack_19c,uVar3,puVar14,uVar2);
      }
      else {
        uVar8 = esp_log_timestamp();
        esp_log_write(3,"OPENTHREAD","I (%lu) %s: Update service\n",uVar8,"OPENTHREAD");
        iVar13 = mdns_service_port_set_for_host
                           (acStack_114,acStack_d0,acStack_1b0,acStack_19c,uVar3);
        if (iVar13 == 0) {
          iVar13 = mdns_service_txt_set_for_host
                             (acStack_114,acStack_d0,acStack_1b0,acStack_19c,puVar14,uVar2);
          if (iVar13 == 0) goto _L0;
          uVar3 = esp_log_timestamp();
          pcVar9 = "E (%lu) %s: Failed to add or update service txt\n";
        }
        else {
          uVar3 = esp_log_timestamp();
          pcVar9 = "E (%lu) %s: Failed to add or update service port\n";
        }
        esp_log_write(1,"OPENTHREAD",pcVar9,uVar3,"OPENTHREAD");
      }
_L0:
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      if (puVar14 != (undefined4 *)0x0) {
        puVar16 = puVar14;
        for (uVar15 = 0; uVar15 < uVar2; uVar15 = uVar15 + 1) {
          if ((void *)*puVar16 != (void *)0x0) {
            free((void *)*puVar16);
          }
          if ((void *)puVar16[1] != (void *)0x0) {
            free((void *)puVar16[1]);
          }
          puVar16 = puVar16 + 2;
        }
        free(puVar14);
      }
      if (iVar13 != 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD","E (%lu) %s: Failed to add or update service\n",uVar3,
                      "OPENTHREAD");
        iVar5 = convert_to_ot_srp_error_code(iVar13);
        goto _L0;
      }
      if (iVar5 == 0) {
        uVar15 = otSrpServerServiceGetNumberOfSubTypes(iVar6);
        for (uVar2 = 0; uVar2 != uVar15; uVar2 = uVar2 + 1 & 0xffff) {
          iVar5 = otSrpServerServiceGetSubTypeServiceNameAt(iVar6,uVar2);
          if (iVar5 == 0) {
            uVar3 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD","E (%lu) %s: Failed to get service subtype\n",uVar3,
                          "OPENTHREAD");
            goto _L0;
          }
          memset(auStack_8c,0,0x41);
          split_hostname_constprop_0(iVar5,auStack_8c);
          esp_openthread_task_switching_lock_release();
          iVar5 = mdns_service_subtype_add_for_host
                            (acStack_114,acStack_d0,acStack_1b0,acStack_19c,auStack_8c);
          esp_openthread_task_switching_lock_acquire(0xffffffff);
          uVar3 = esp_log_timestamp();
          esp_log_write(3,"OPENTHREAD","I (%lu) %s: Service subtype %s\n",uVar3,"OPENTHREAD",
                        auStack_8c);
          if (iVar5 != 0) {
            uVar3 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD","E (%lu) %s: Failed to add service subtype\n",uVar3,
                          "OPENTHREAD");
            iVar5 = convert_to_ot_srp_error_code(iVar5);
            if (iVar5 != 0) goto _L0;
            break;
          }
        }
      }
    }
    else {
      iVar5 = otSrpServerServiceIsDeleted(iVar6);
      if (iVar5 != 0) {
        esp_openthread_task_switching_lock_release();
        iVar5 = mdns_service_remove_for_host(acStack_114,acStack_d0,acStack_1b0,acStack_19c);
        esp_openthread_task_switching_lock_acquire(0xffffffff);
        if (iVar5 == 0x105) {
          uVar3 = esp_log_timestamp();
          esp_log_write(2,"OPENTHREAD","W (%lu) %s: Failed to find service: %s.%s.%s.%s\n",uVar3,
                        "OPENTHREAD",acStack_19c,acStack_114,acStack_1b0);
        }
        else if (iVar5 != 0) {
_L0:
          iVar5 = 1;
          goto _L0;
        }
      }
    }
  } while( true );
}

