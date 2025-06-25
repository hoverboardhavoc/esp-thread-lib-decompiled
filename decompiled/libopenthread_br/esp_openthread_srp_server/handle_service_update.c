/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> handle_service_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_service_update(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  void *pvVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  size_t __n;
  undefined4 *puVar14;
  uint uVar15;
  size_t sVar16;
  undefined4 *puVar17;
  size_t __n_00;
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
  
  iVar11 = otSrpServerHostIsDeleted(param_2);
  if (iVar11 != 0) {
    uVar12 = esp_log_timestamp();
    esp_log(3,"OPENTHREAD","I (%lu) %s: Host delete\n",uVar12,"OPENTHREAD");
    otSrpServerHostGetFullName(param_2);
    split_hostname_constprop_0(auStack_54);
    uVar12 = esp_log_timestamp();
    esp_log(3,"OPENTHREAD","I (%lu) %s: delete host %s\n",uVar12,"OPENTHREAD",auStack_54);
    esp_openthread_task_switching_lock_release();
    iVar11 = mdns_delegate_hostname_remove(auStack_54);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    esp_openthread_get_instance();
    otSrpServerHandleServiceUpdateResult(param_1,iVar11 != 0);
    return;
  }
  uVar12 = esp_log_timestamp();
  esp_log(3,"OPENTHREAD","I (%lu) %s: Host update\n",uVar12,"OPENTHREAD");
  otSrpServerHostGetFullName(param_2);
  split_hostname_constprop_0(acStack_19c);
  uVar12 = esp_log_timestamp();
  esp_log(3,"OPENTHREAD","I (%lu) %s: update host %s\n",uVar12,"OPENTHREAD",acStack_19c);
  esp_openthread_task_switching_lock_release();
  iVar11 = mdns_hostname_get(acStack_158);
  iVar1 = mdns_hostname_exists(acStack_19c);
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  iVar2 = otSrpServerHostGetAddresses(param_2,&bStack_1b3);
  if (bStack_1b3 == 0) {
    if (iVar1 != 0) {
      uVar12 = esp_log_timestamp();
      esp_log(3,"OPENTHREAD","I (%lu) %s: Set addr of host to NULL\n",uVar12,"OPENTHREAD");
      pvVar3 = (void *)0x0;
      goto _L0;
    }
    uVar12 = esp_log_timestamp();
    esp_log(3,"OPENTHREAD","I (%lu) %s: Add a new host without an addr\n",uVar12,"OPENTHREAD");
    pvVar3 = (void *)0x0;
_L0:
    if (iVar11 == 0) {
      iVar1 = strcasecmp(acStack_158,acStack_19c);
      iVar11 = 0x1d;
      pvVar5 = pvVar3;
      if (iVar1 == 0) goto _L0;
    }
    esp_openthread_task_switching_lock_release();
    mdns_delegate_hostname_add(acStack_19c,pvVar3);
  }
  else {
    uVar15 = 0;
    pvVar5 = (void *)0x0;
    do {
      pvVar3 = malloc(0x1c);
      if (pvVar3 == (void *)0x0) {
        iVar11 = 3;
        goto _L0;
      }
      *(undefined1 *)((int)pvVar3 + 0x14) = 6;
      memcpy(pvVar3,(void *)(uVar15 * 0x10 + iVar2),0x10);
      uVar15 = uVar15 + 1;
      *(undefined1 *)((int)pvVar3 + 0x10) = 0;
      *(void **)((int)pvVar3 + 0x18) = pvVar5;
      pvVar5 = pvVar3;
    } while ((uVar15 & 0xff) < (uint)bStack_1b3);
    if (iVar1 == 0) {
      do {
        uVar12 = esp_log_timestamp();
        uVar4 = ip6addr_ntoa(pvVar5);
        esp_log(3,"OPENTHREAD","I (%lu) %s: Add a new host, addr %s\n",uVar12,"OPENTHREAD",uVar4);
        puVar14 = (undefined4 *)((int)pvVar5 + 0x18);
        pvVar5 = (void *)*puVar14;
      } while ((void *)*puVar14 != (void *)0x0);
      goto _L0;
    }
    do {
      uVar12 = esp_log_timestamp();
      uVar4 = ip6addr_ntoa(pvVar5);
      esp_log(3,"OPENTHREAD","I (%lu) %s: Set addr of host to %s\n",uVar12,"OPENTHREAD",uVar4);
      puVar14 = (undefined4 *)((int)pvVar5 + 0x18);
      pvVar5 = (void *)*puVar14;
    } while ((void *)*puVar14 != (void *)0x0);
_L0:
    if (iVar11 == 0) {
      iVar1 = strcasecmp(acStack_158,acStack_19c);
      iVar11 = 0x1d;
      pvVar5 = pvVar3;
      if (iVar1 == 0) goto _L0;
    }
    esp_openthread_task_switching_lock_release();
    mdns_delegate_hostname_set_address(acStack_19c,pvVar3);
  }
  iVar11 = convert_to_ot_srp_error_code();
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  pvVar5 = pvVar3;
_L0:
  while (pvVar5 != (void *)0x0) {
    pvVar3 = *(void **)((int)pvVar5 + 0x18);
    free(pvVar5);
    pvVar5 = pvVar3;
  }
  if (iVar11 == 0) {
    iVar1 = 0;
    do {
      while( true ) {
        iVar1 = otSrpServerHostGetNextService(param_2,iVar1);
        if (iVar1 == 0) goto _L0;
        pcVar6 = (char *)otSrpServerServiceGetInstanceName();
        memset(acStack_114,0,0x41);
        memset(acStack_d0,0,0x41);
        acStack_1b0[0] = '\0';
        acStack_1b0[1] = '\0';
        acStack_1b0[2] = '\0';
        acStack_1b0[3] = '\0';
        acStack_1b0[4] = '\0';
        acStack_1b0[5] = '\0';
        pcVar7 = strchr(pcVar6,0x2e);
        sVar16 = (int)pcVar7 - (int)pcVar6;
        if (0x40 < sVar16) {
          sVar16 = 0x40;
        }
        pcVar7 = pcVar7 + 1;
        pcVar8 = strchr(pcVar7,0x2e);
        __n = (int)pcVar8 - (int)pcVar7;
        if (0x40 < __n) {
          __n = 0x40;
        }
        pcVar8 = pcVar8 + 1;
        pcVar9 = strchr(pcVar8,0x2e);
        __n_00 = (int)pcVar9 - (int)pcVar8;
        if (5 < __n_00) {
          __n_00 = 5;
        }
        strncpy(acStack_114,pcVar6,sVar16);
        acStack_114[sVar16] = '\0';
        strncpy(acStack_d0,pcVar7,__n);
        acStack_d0[__n] = '\0';
        strncpy(acStack_1b0,pcVar8,__n_00);
        acStack_1b0[__n_00] = '\0';
        uVar12 = esp_log_timestamp();
        esp_log(3,"OPENTHREAD","I (%lu) %s: Service %s.%s.%s\n",uVar12,"OPENTHREAD",acStack_114,
                acStack_d0,acStack_1b0);
        esp_openthread_task_switching_lock_release();
        iVar2 = mdns_service_exists_with_instance(acStack_114,acStack_d0,acStack_1b0,acStack_19c);
        esp_openthread_task_switching_lock_acquire(0xffffffff);
        iVar10 = otSrpServerServiceIsDeleted(iVar1);
        if (iVar10 == 0) break;
        iVar2 = otSrpServerServiceIsDeleted(iVar1);
        if (iVar2 != 0) {
          esp_openthread_task_switching_lock_release();
          iVar2 = mdns_service_remove_for_host(acStack_114,acStack_d0,acStack_1b0,acStack_19c);
          esp_openthread_task_switching_lock_acquire(0xffffffff);
          if (iVar2 == 0x105) {
            uVar12 = esp_log_timestamp();
            esp_log(2,"OPENTHREAD","W (%lu) %s: Failed to find service: %s.%s.%s.%s\n",uVar12,
                    "OPENTHREAD",acStack_19c,acStack_114,acStack_1b0);
          }
          else if (iVar2 != 0) {
_L0:
            iVar11 = 1;
            goto _L0;
          }
        }
      }
      uStack_1b2 = 0;
      uVar12 = otSrpServerServiceGetTxtData(iVar1,&uStack_1b2);
      otDnsInitTxtEntryIterator(auStack_8c,uVar12,uStack_1b2);
      uVar15 = 0;
      while (iVar10 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1a8), iVar10 == 0) {
        uVar15 = uVar15 + 1 & 0xff;
      }
      if (uVar15 == 0) {
_L0:
        puVar14 = (undefined4 *)0x0;
        uVar13 = 0;
      }
      else {
        puVar14 = (undefined4 *)malloc(uVar15 << 3);
        if (puVar14 == (undefined4 *)0x0) {
          iVar11 = 3;
          goto _L0;
        }
        memset(puVar14,0,uVar15 << 3);
        otDnsInitTxtEntryIterator(auStack_8c,uVar12,uStack_1b2);
        uVar15 = 0;
        while (iVar10 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1a8), iVar10 == 0) {
          pcVar8 = (char *)malloc(0x41);
          pcVar9 = (char *)malloc(0x41);
          pcVar7 = pcStack_1a4;
          pcVar6 = pcStack_1a8;
          if (pcStack_1a8 == (char *)0x0) {
            uVar13 = (uint)uStack_1a0;
            sVar16 = 0;
            do {
              if (pcStack_1a4[sVar16] == '=') {
                if ((sVar16 - 1 & 0xffff) < 0x40) {
                  strncpy(pcVar8,pcStack_1a4,sVar16);
                  uVar13 = uVar13 - sVar16 & 0xffff;
                  pcVar8[sVar16] = '\0';
                  puVar14[uVar15 * 2] = pcVar8;
                  if ((uVar13 - 2 & 0xffff) < 0x40) {
                    uVar13 = uVar13 - 1 & 0xffff;
                    strncpy(pcVar9,pcVar7 + sVar16 + 1,uVar13);
                    pcVar9[uVar13] = '\0';
                    (puVar14 + uVar15 * 2)[1] = pcVar9;
                    goto _L0;
                  }
                }
                break;
              }
              sVar16 = sVar16 + 1 & 0xffff;
            } while (uVar13 != sVar16);
_L0:
            free(pcVar8);
            free(pcVar9);
          }
          else {
            if ((pcVar8 == (char *)0x0) || (sVar16 = strnlen(pcStack_1a8,0x41), 0x40 < sVar16))
            goto _L0;
            strncpy(pcVar8,pcVar6,0x40);
            pcVar8[0x40] = '\0';
            puVar14[uVar15 * 2] = pcVar8;
            if ((pcVar9 == (char *)0x0) || (uVar13 = (uint)uStack_1a0, 0x40 < uVar13)) goto _L0;
            strncpy(pcVar9,pcStack_1a4,uVar13);
            pcVar9[uVar13] = '\0';
            (puVar14 + uVar15 * 2)[1] = pcVar9;
_L0:
            uVar15 = uVar15 + 1;
          }
        }
        uVar13 = uVar15 & 0xff;
        if (uVar15 == 0) {
          free(puVar14);
          goto _L0;
        }
      }
      uVar12 = otSrpServerServiceGetPort(iVar1);
      esp_openthread_task_switching_lock_release();
      if (iVar2 == 0) {
        uVar4 = esp_log_timestamp();
        esp_log(3,"OPENTHREAD","I (%lu) %s: Add new service\n",uVar4,"OPENTHREAD");
        iVar2 = mdns_service_add_for_host
                          (acStack_114,acStack_d0,acStack_1b0,acStack_19c,uVar12,puVar14,uVar13);
      }
      else {
        uVar4 = esp_log_timestamp();
        esp_log(3,"OPENTHREAD","I (%lu) %s: Update service\n",uVar4,"OPENTHREAD");
        iVar2 = mdns_service_port_set_for_host
                          (acStack_114,acStack_d0,acStack_1b0,acStack_19c,uVar12);
        if (iVar2 == 0) {
          iVar2 = mdns_service_txt_set_for_host
                            (acStack_114,acStack_d0,acStack_1b0,acStack_19c,puVar14,uVar13);
          if (iVar2 == 0) goto _L0;
          uVar12 = esp_log_timestamp();
          pcVar6 = "E (%lu) %s: Failed to add or update service txt\n";
        }
        else {
          uVar12 = esp_log_timestamp();
          pcVar6 = "E (%lu) %s: Failed to add or update service port\n";
        }
        esp_log(1,"OPENTHREAD",pcVar6,uVar12,"OPENTHREAD");
      }
_L0:
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      if (puVar14 != (undefined4 *)0x0) {
        puVar17 = puVar14;
        for (uVar15 = 0; uVar15 < uVar13; uVar15 = uVar15 + 1) {
          if ((void *)*puVar17 != (void *)0x0) {
            free((void *)*puVar17);
          }
          if ((void *)puVar17[1] != (void *)0x0) {
            free((void *)puVar17[1]);
          }
          puVar17 = puVar17 + 2;
        }
        free(puVar14);
      }
      if (iVar2 != 0) {
        uVar12 = esp_log_timestamp();
        esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to add or update service\n",uVar12,"OPENTHREAD");
        goto _L0;
      }
      uVar15 = otSrpServerServiceGetNumberOfSubTypes(iVar1);
      pvVar3 = malloc(uVar15 << 2);
      memset(pvVar3,0,uVar15 << 2);
      for (uVar13 = 0; uVar13 < uVar15; uVar13 = uVar13 + 1 & 0xffff) {
        iVar2 = otSrpServerServiceGetSubTypeServiceNameAt(iVar1,uVar13);
        if (iVar2 == 0) {
          uVar4 = esp_log_timestamp();
          uVar12 = 0xe6;
          pcVar6 = "E (%lu) %s: %s(%d): Failed to get service subtype\n";
_L0:
          esp_log(1,"OPENTHREAD",pcVar6,uVar4,"OPENTHREAD","alloc_subtype_list",uVar12);
          free_subtype_list(pvVar3,uVar15);
          uVar12 = esp_log_timestamp();
          esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to allocate subtype list\n",uVar12,"OPENTHREAD"
                 );
          goto _L0;
        }
        pvVar5 = malloc(0x41);
        if (pvVar5 == (void *)0x0) {
          uVar4 = esp_log_timestamp();
          uVar12 = 0xe9;
          pcVar6 = "E (%lu) %s: %s(%d): No memory for a new subtype entry\n";
          goto _L0;
        }
        split_hostname_constprop_0(iVar2,pvVar5);
        *(void **)(uVar13 * 4 + (int)pvVar3) = pvVar5;
      }
      esp_openthread_task_switching_lock_release();
      iVar2 = mdns_service_subtype_update_multiple_items_for_host
                        (acStack_114,acStack_d0,acStack_1b0,acStack_19c,pvVar3,uVar15 & 0xff);
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      for (iVar10 = 0; iVar10 < (int)uVar15; iVar10 = iVar10 + 1) {
        uVar12 = esp_log_timestamp();
        esp_log(3,"OPENTHREAD","I (%lu) %s: Update subtype: %s\n",uVar12,"OPENTHREAD",
                *(undefined4 *)(iVar10 * 4 + (int)pvVar3));
      }
      free_subtype_list(pvVar3,uVar15);
    } while (iVar2 == 0);
    uVar12 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to update service subtype\n",uVar12,"OPENTHREAD");
_L0:
    iVar11 = convert_to_ot_srp_error_code(iVar2);
  }
_L0:
  esp_openthread_get_instance();
  otSrpServerHandleServiceUpdateResult(param_1,iVar11);
  return;
}

