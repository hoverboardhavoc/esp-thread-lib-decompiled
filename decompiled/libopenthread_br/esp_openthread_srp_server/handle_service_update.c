/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> handle_service_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_service_update(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
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
  undefined1 auStack_8c [56];
  undefined1 auStack_54 [32];
  
  iVar12 = otSrpServerHostIsDeleted(param_2);
  if (iVar12 != 0) {
    uVar13 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD","I (%lu) %s: Host delete\n",uVar13,"OPENTHREAD");
    otSrpServerHostGetFullName(param_2);
    split_hostname_constprop_0(auStack_54);
    uVar13 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD","I (%lu) %s: delete host %s\n",uVar13,"OPENTHREAD",auStack_54);
    esp_openthread_task_switching_lock_release();
    iVar12 = mdns_delegate_hostname_remove(auStack_54);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    esp_openthread_get_instance();
    otSrpServerHandleServiceUpdateResult(param_1,iVar12 != 0);
    return;
  }
  uVar13 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD","I (%lu) %s: Host update\n",uVar13,"OPENTHREAD");
  otSrpServerHostGetFullName(param_2);
  split_hostname_constprop_0(acStack_19c);
  uVar13 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD","I (%lu) %s: update host %s\n",uVar13,"OPENTHREAD",acStack_19c);
  esp_openthread_task_switching_lock_release();
  iVar12 = mdns_hostname_get(acStack_158);
  iVar3 = mdns_hostname_exists(acStack_19c);
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  iVar4 = otSrpServerHostGetAddresses(param_2,&bStack_1b3);
  if (bStack_1b3 == 0) {
    if (iVar3 != 0) {
      uVar13 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD","I (%lu) %s: Set addr of host to NULL\n",uVar13,"OPENTHREAD");
      pvVar5 = (void *)0x0;
      goto _L0;
    }
    uVar13 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD","I (%lu) %s: Add a new host without an addr\n",uVar13,"OPENTHREAD")
    ;
    pvVar5 = (void *)0x0;
_L0:
    if (iVar12 == 0) {
      iVar3 = strcasecmp(acStack_158,acStack_19c);
      iVar12 = 0x1d;
      pvVar1 = pvVar5;
      if (iVar3 == 0) goto _L0;
    }
    esp_openthread_task_switching_lock_release();
    mdns_delegate_hostname_add(acStack_19c,pvVar5);
  }
  else {
    uVar15 = 0;
    pvVar1 = (void *)0x0;
    do {
      pvVar5 = malloc(0x1c);
      if (pvVar5 == (void *)0x0) {
        iVar12 = 3;
        goto _L0;
      }
      *(undefined1 *)((int)pvVar5 + 0x14) = 6;
      memcpy(pvVar5,(void *)(uVar15 * 0x10 + iVar4),0x10);
      uVar15 = uVar15 + 1;
      *(undefined1 *)((int)pvVar5 + 0x10) = 0;
      *(void **)((int)pvVar5 + 0x18) = pvVar1;
      pvVar1 = pvVar5;
    } while ((uVar15 & 0xff) < (uint)bStack_1b3);
    if (iVar3 == 0) {
      do {
        uVar13 = esp_log_timestamp();
        uVar6 = ip6addr_ntoa(pvVar1);
        esp_log_write(3,"OPENTHREAD","I (%lu) %s: Add a new host, addr %s\n",uVar13,"OPENTHREAD",
                      uVar6);
        puVar14 = (undefined4 *)((int)pvVar1 + 0x18);
        pvVar1 = (void *)*puVar14;
      } while ((void *)*puVar14 != (void *)0x0);
      goto _L0;
    }
    do {
      uVar13 = esp_log_timestamp();
      uVar6 = ip6addr_ntoa(pvVar1);
      esp_log_write(3,"OPENTHREAD","I (%lu) %s: Set addr of host to %s\n",uVar13,"OPENTHREAD",uVar6)
      ;
      puVar14 = (undefined4 *)((int)pvVar1 + 0x18);
      pvVar1 = (void *)*puVar14;
    } while ((void *)*puVar14 != (void *)0x0);
_L0:
    if (iVar12 == 0) {
      iVar3 = strcasecmp(acStack_158,acStack_19c);
      iVar12 = 0x1d;
      pvVar1 = pvVar5;
      if (iVar3 == 0) goto _L0;
    }
    esp_openthread_task_switching_lock_release();
    mdns_delegate_hostname_set_address(acStack_19c,pvVar5);
  }
  iVar12 = convert_to_ot_srp_error_code();
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  pvVar1 = pvVar5;
_L0:
  while (pvVar1 != (void *)0x0) {
    pvVar5 = *(void **)((int)pvVar1 + 0x18);
    free(pvVar1);
    pvVar1 = pvVar5;
  }
  iVar3 = iVar12;
  if (iVar12 != 0) {
_L0:
    esp_openthread_get_instance();
    otSrpServerHandleServiceUpdateResult(param_1,iVar3);
    return;
  }
  iVar4 = 0;
  do {
    iVar4 = otSrpServerHostGetNextService(param_2,iVar4);
    iVar3 = iVar12;
    if (iVar4 == 0) goto _L0;
    pcVar7 = (char *)otSrpServerServiceGetInstanceName();
    memset(acStack_114,0,0x41);
    memset(acStack_d0,0,0x41);
    acStack_1b0[0] = '\0';
    acStack_1b0[1] = '\0';
    acStack_1b0[2] = '\0';
    acStack_1b0[3] = '\0';
    acStack_1b0[4] = '\0';
    acStack_1b0[5] = '\0';
    pcVar8 = strchr(pcVar7,0x2e);
    sVar17 = (int)pcVar8 - (int)pcVar7;
    if (0x40 < sVar17) {
      sVar17 = 0x40;
    }
    pcVar8 = pcVar8 + 1;
    pcVar9 = strchr(pcVar8,0x2e);
    __n = (int)pcVar9 - (int)pcVar8;
    if (0x40 < __n) {
      __n = 0x40;
    }
    pcVar9 = pcVar9 + 1;
    pcVar10 = strchr(pcVar9,0x2e);
    __n_00 = (int)pcVar10 - (int)pcVar9;
    if (5 < __n_00) {
      __n_00 = 5;
    }
    strncpy(acStack_114,pcVar7,sVar17);
    acStack_114[sVar17] = '\0';
    strncpy(acStack_d0,pcVar8,__n);
    acStack_d0[__n] = '\0';
    strncpy(acStack_1b0,pcVar9,__n_00);
    acStack_1b0[__n_00] = '\0';
    uVar13 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD","I (%lu) %s: Service %s.%s.%s\n",uVar13,"OPENTHREAD",acStack_114,
                  acStack_d0,acStack_1b0);
    esp_openthread_task_switching_lock_release();
    iVar3 = mdns_service_exists_with_instance(acStack_114,acStack_d0,acStack_1b0,acStack_19c);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    iVar11 = otSrpServerServiceIsDeleted(iVar4);
    if (iVar11 == 0) {
      uStack_1b2 = 0;
      uVar13 = otSrpServerServiceGetTxtData(iVar4,&uStack_1b2);
      otDnsInitTxtEntryIterator(auStack_8c,uVar13,uStack_1b2);
      uVar15 = 0;
      while (iVar11 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1a8), iVar11 == 0) {
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
          iVar3 = 3;
          goto _L0;
        }
        memset(puVar14,0,uVar15 << 3);
        otDnsInitTxtEntryIterator(auStack_8c,uVar13,uStack_1b2);
        uVar15 = 0;
        while (iVar11 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1a8), iVar11 == 0) {
          pcVar9 = (char *)malloc(0x41);
          pcVar10 = (char *)malloc(0x41);
          pcVar8 = pcStack_1a4;
          pcVar7 = pcStack_1a8;
          if (pcStack_1a8 == (char *)0x0) {
            uVar2 = (uint)uStack_1a0;
            sVar17 = 0;
            do {
              if (pcStack_1a4[sVar17] == '=') {
                if ((sVar17 - 1 & 0xffff) < 0x40) {
                  strncpy(pcVar9,pcStack_1a4,sVar17);
                  uVar2 = uVar2 - sVar17 & 0xffff;
                  pcVar9[sVar17] = '\0';
                  puVar16 = puVar14 + uVar15 * 2;
                  *puVar16 = pcVar9;
                  if ((uVar2 - 2 & 0xffff) < 0x40) {
                    uVar2 = uVar2 - 1 & 0xffff;
                    strncpy(pcVar10,pcVar8 + sVar17 + 1,uVar2);
                    pcVar10[uVar2] = '\0';
                    goto _L0;
                  }
                }
                break;
              }
              sVar17 = sVar17 + 1 & 0xffff;
            } while (uVar2 != sVar17);
_L0:
            free(pcVar9);
            free(pcVar10);
          }
          else {
            if ((pcVar9 == (char *)0x0) || (sVar17 = strnlen(pcStack_1a8,0x41), 0x40 < sVar17))
            goto _L0;
            strncpy(pcVar9,pcVar7,0x40);
            puVar16 = puVar14 + uVar15 * 2;
            pcVar9[0x40] = '\0';
            *puVar16 = pcVar9;
            if ((pcVar10 == (char *)0x0) || (uVar2 = (uint)uStack_1a0, 0x40 < uVar2)) goto _L0;
            strncpy(pcVar10,pcStack_1a4,uVar2);
            pcVar10[uVar2] = '\0';
_L0:
            puVar16[1] = pcVar10;
            uVar15 = uVar15 + 1;
          }
        }
        uVar2 = uVar15 & 0xff;
        if (uVar15 == 0) {
          free(puVar14);
          goto _L0;
        }
      }
      uVar13 = otSrpServerServiceGetPort(iVar4);
      esp_openthread_task_switching_lock_release();
      if (iVar3 == 0) {
        uVar6 = esp_log_timestamp();
        esp_log_write(3,"OPENTHREAD","I (%lu) %s: Add new service\n",uVar6,"OPENTHREAD");
        iVar11 = mdns_service_add_for_host
                           (acStack_114,acStack_d0,acStack_1b0,acStack_19c,uVar13,puVar14,uVar2);
      }
      else {
        uVar6 = esp_log_timestamp();
        esp_log_write(3,"OPENTHREAD","I (%lu) %s: Update service\n",uVar6,"OPENTHREAD");
        iVar11 = mdns_service_port_set_for_host
                           (acStack_114,acStack_d0,acStack_1b0,acStack_19c,uVar13);
        if (iVar11 == 0) {
          iVar11 = mdns_service_txt_set_for_host
                             (acStack_114,acStack_d0,acStack_1b0,acStack_19c,puVar14,uVar2);
          if (iVar11 == 0) goto _L0;
          uVar13 = esp_log_timestamp();
          pcVar7 = "E (%lu) %s: Failed to add or update service txt\n";
        }
        else {
          uVar13 = esp_log_timestamp();
          pcVar7 = "E (%lu) %s: Failed to add or update service port\n";
        }
        esp_log_write(1,"OPENTHREAD",pcVar7,uVar13,"OPENTHREAD");
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
      if (iVar11 != 0) {
        uVar13 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD","E (%lu) %s: Failed to add or update service\n",uVar13,
                      "OPENTHREAD");
        iVar3 = convert_to_ot_srp_error_code(iVar11);
        goto _L0;
      }
      if (iVar3 == 0) {
        uVar15 = otSrpServerServiceGetNumberOfSubTypes(iVar4);
        for (uVar2 = 0; uVar2 != uVar15; uVar2 = uVar2 + 1 & 0xffff) {
          iVar3 = otSrpServerServiceGetSubTypeServiceNameAt(iVar4,uVar2);
          if (iVar3 == 0) {
            uVar13 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD","E (%lu) %s: Failed to get service subtype\n",uVar13,
                          "OPENTHREAD");
            goto _L0;
          }
          memset(auStack_8c,0,0x41);
          split_hostname_constprop_0(iVar3,auStack_8c);
          esp_openthread_task_switching_lock_release();
          iVar3 = mdns_service_subtype_add_for_host
                            (acStack_114,acStack_d0,acStack_1b0,acStack_19c,auStack_8c);
          esp_openthread_task_switching_lock_acquire(0xffffffff);
          uVar13 = esp_log_timestamp();
          esp_log_write(3,"OPENTHREAD","I (%lu) %s: Service subtype %s\n",uVar13,"OPENTHREAD",
                        auStack_8c);
          if (iVar3 != 0) {
            uVar13 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD","E (%lu) %s: Failed to add service subtype\n",uVar13,
                          "OPENTHREAD");
            iVar3 = convert_to_ot_srp_error_code(iVar3);
            if (iVar3 != 0) goto _L0;
            break;
          }
        }
      }
    }
    else {
      iVar3 = otSrpServerServiceIsDeleted(iVar4);
      if (iVar3 != 0) {
        esp_openthread_task_switching_lock_release();
        iVar3 = mdns_service_remove_for_host(acStack_114,acStack_d0,acStack_1b0,acStack_19c);
        esp_openthread_task_switching_lock_acquire(0xffffffff);
        if (iVar3 == 0x105) {
          uVar13 = esp_log_timestamp();
          esp_log_write(2,"OPENTHREAD","W (%lu) %s: Failed to find service: %s.%s.%s.%s\n",uVar13,
                        "OPENTHREAD",acStack_19c,acStack_114,acStack_1b0);
        }
        else if (iVar3 != 0) {
_L0:
          iVar3 = 1;
          goto _L0;
        }
      }
    }
  } while( true );
}

