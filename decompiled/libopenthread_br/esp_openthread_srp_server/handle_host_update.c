/*
 * Last changed at upstream commit baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * https://github.com/espressif/esp-thread-lib/commit/baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * Upstream date: 2025-10-23 04:21:23 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 36b14d3ef
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> handle_host_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_host_update(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  void *pvVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  int iVar12;
  undefined4 *puVar13;
  uint uVar14;
  size_t __n;
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
  undefined1 auStack_8c [88];
  
  otSrpServerHostGetFullName(param_2);
  split_hostname_constprop_0(acStack_19c);
  uVar1 = esp_log_timestamp();
  esp_log(3,"OPENTHREAD","I (%lu) %s: update host %s\n",uVar1,acStack_19c);
  esp_openthread_task_switching_lock_release();
  iVar2 = mdns_hostname_get(acStack_158);
  iVar3 = mdns_hostname_exists(acStack_19c);
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  iVar4 = otSrpServerHostGetAddresses(param_2,&bStack_1b3);
  if (bStack_1b3 == 0) {
    if (iVar3 != 0) {
      uVar1 = esp_log_timestamp();
      esp_log(3,"OPENTHREAD","I (%lu) %s: Set addr of host to NULL\n",uVar1);
      pvVar5 = (void *)0x0;
      goto _L25;
    }
    uVar1 = esp_log_timestamp();
    esp_log(3,"OPENTHREAD","I (%lu) %s: Add a new host without an addr\n",uVar1);
    pvVar5 = (void *)0x0;
_L27:
    if (iVar2 == 0) {
      iVar3 = strcasecmp(acStack_158,acStack_19c);
      iVar2 = 0x1d;
      pvVar7 = pvVar5;
      if (iVar3 == 0) goto _L30;
    }
    esp_openthread_task_switching_lock_release();
    mdns_delegate_hostname_add(acStack_19c,pvVar5);
  }
  else {
    uVar14 = 0;
    pvVar7 = (void *)0x0;
    do {
      pvVar5 = malloc(0x1c);
      if (pvVar5 == (void *)0x0) {
        iVar2 = 3;
        goto _L30;
      }
      *(undefined1 *)((int)pvVar5 + 0x14) = 6;
      memcpy(pvVar5,(void *)(uVar14 * 0x10 + iVar4),0x10);
      uVar14 = uVar14 + 1;
      *(undefined1 *)((int)pvVar5 + 0x10) = 0;
      *(void **)((int)pvVar5 + 0x18) = pvVar7;
      pvVar7 = pvVar5;
    } while ((uVar14 & 0xff) < (uint)bStack_1b3);
    if (iVar3 == 0) {
      do {
        uVar1 = esp_log_timestamp();
        uVar6 = ip6addr_ntoa(pvVar7);
        esp_log(3,"OPENTHREAD","I (%lu) %s: Add a new host, addr %s\n",uVar1,"OPENTHREAD",uVar6);
        puVar13 = (undefined4 *)((int)pvVar7 + 0x18);
        pvVar7 = (void *)*puVar13;
      } while ((void *)*puVar13 != (void *)0x0);
      goto _L27;
    }
    do {
      uVar1 = esp_log_timestamp();
      uVar6 = ip6addr_ntoa(pvVar7);
      esp_log(3,"OPENTHREAD","I (%lu) %s: Set addr of host to %s\n",uVar1,"OPENTHREAD",uVar6);
      puVar13 = (undefined4 *)((int)pvVar7 + 0x18);
      pvVar7 = (void *)*puVar13;
    } while ((void *)*puVar13 != (void *)0x0);
_L25:
    if (iVar2 == 0) {
      iVar3 = strcasecmp(acStack_158,acStack_19c);
      iVar2 = 0x1d;
      pvVar7 = pvVar5;
      if (iVar3 == 0) goto _L30;
    }
    esp_openthread_task_switching_lock_release();
    mdns_delegate_hostname_set_address(acStack_19c,pvVar5);
  }
  iVar2 = convert_to_ot_srp_error_code();
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  pvVar7 = pvVar5;
_L30:
  while (pvVar7 != (void *)0x0) {
    pvVar5 = *(void **)((int)pvVar7 + 0x18);
    free(pvVar7);
    pvVar7 = pvVar5;
  }
  if (iVar2 == 0) {
    iVar3 = 0;
    do {
      while( true ) {
        iVar3 = otSrpServerHostGetNextService(param_2,iVar3);
        if (iVar3 == 0) goto _L33;
        pcVar8 = (char *)otSrpServerServiceGetInstanceName();
        memset(acStack_114,0,0x41);
        memset(acStack_d0,0,0x41);
        acStack_1b0[0] = '\0';
        acStack_1b0[1] = '\0';
        acStack_1b0[2] = '\0';
        acStack_1b0[3] = '\0';
        acStack_1b0[4] = '\0';
        acStack_1b0[5] = '\0';
        pcVar9 = strchr(pcVar8,0x2e);
        sVar16 = (int)pcVar9 - (int)pcVar8;
        if (0x40 < sVar16) {
          sVar16 = 0x40;
        }
        pcVar9 = pcVar9 + 1;
        pcVar10 = strchr(pcVar9,0x2e);
        __n = (int)pcVar10 - (int)pcVar9;
        if (0x40 < __n) {
          __n = 0x40;
        }
        pcVar10 = pcVar10 + 1;
        pcVar11 = strchr(pcVar10,0x2e);
        __n_00 = (int)pcVar11 - (int)pcVar10;
        if (5 < __n_00) {
          __n_00 = 5;
        }
        strncpy(acStack_114,pcVar8,sVar16);
        acStack_114[sVar16] = '\0';
        strncpy(acStack_d0,pcVar9,__n);
        acStack_d0[__n] = '\0';
        strncpy(acStack_1b0,pcVar10,__n_00);
        acStack_1b0[__n_00] = '\0';
        uVar1 = esp_log_timestamp();
        esp_log(3,"OPENTHREAD","I (%lu) %s: Service %s.%s.%s\n",uVar1,acStack_114,acStack_d0,
                acStack_1b0);
        esp_openthread_task_switching_lock_release();
        iVar4 = mdns_service_exists_with_instance(acStack_114,acStack_d0,acStack_1b0,acStack_19c);
        esp_openthread_task_switching_lock_acquire(0xffffffff);
        iVar12 = otSrpServerServiceIsDeleted(iVar3);
        if (iVar12 == 0) break;
        iVar4 = otSrpServerServiceIsDeleted(iVar3);
        if (iVar4 != 0) {
          esp_openthread_task_switching_lock_release();
          iVar4 = mdns_service_remove_for_host(acStack_114,acStack_d0,acStack_1b0,acStack_19c);
          esp_openthread_task_switching_lock_acquire(0xffffffff);
          if (iVar4 == 0x105) {
            uVar1 = esp_log_timestamp();
            esp_log(2,"OPENTHREAD","W (%lu) %s: Failed to find service: %s.%s.%s.%s\n",uVar1,
                    acStack_19c,acStack_114,acStack_1b0);
          }
          else if (iVar4 != 0) {
_L79:
            iVar2 = 1;
            goto _L33;
          }
        }
      }
      uStack_1b2 = 0;
      uVar1 = otSrpServerServiceGetTxtData(iVar3,&uStack_1b2);
      otDnsInitTxtEntryIterator(auStack_8c,uVar1,uStack_1b2);
      uVar14 = 0;
      while (iVar12 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1a8), iVar12 == 0) {
        uVar14 = uVar14 + 1 & 0xff;
      }
      if (uVar14 == 0) {
_L61:
        puVar13 = (undefined4 *)0x0;
        uVar15 = 0;
      }
      else {
        puVar13 = (undefined4 *)malloc(uVar14 << 3);
        if (puVar13 == (undefined4 *)0x0) {
          iVar2 = 3;
          goto _L33;
        }
        memset(puVar13,0,uVar14 << 3);
        otDnsInitTxtEntryIterator(auStack_8c,uVar1,uStack_1b2);
        uVar14 = 0;
        while (iVar12 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1a8), iVar12 == 0) {
          pcVar10 = (char *)malloc(0x41);
          pcVar11 = (char *)malloc(0x41);
          pcVar9 = pcStack_1a4;
          pcVar8 = pcStack_1a8;
          if (pcStack_1a8 == (char *)0x0) {
            uVar15 = (uint)uStack_1a0;
            sVar16 = 0;
            do {
              if (pcStack_1a4[sVar16] == '=') {
                if ((sVar16 - 1 & 0xffff) < 0x40) {
                  strncpy(pcVar10,pcStack_1a4,sVar16);
                  pcVar10[sVar16] = '\0';
                  iVar12 = uVar15 - sVar16;
                  puVar13[uVar14 * 2] = pcVar10;
                  if ((iVar12 - 2U & 0xffff) < 0x40) {
                    uVar15 = iVar12 - 1U & 0xffff;
                    strncpy(pcVar11,pcVar9 + sVar16 + 1,uVar15);
                    pcVar11[uVar15] = '\0';
                    (puVar13 + uVar14 * 2)[1] = pcVar11;
                    goto _L53;
                  }
                }
                break;
              }
              sVar16 = sVar16 + 1 & 0xffff;
            } while (uVar15 != sVar16);
_L56:
            free(pcVar10);
            free(pcVar11);
          }
          else {
            if ((pcVar10 == (char *)0x0) || (sVar16 = strnlen(pcStack_1a8,0x41), 0x40 < sVar16))
            goto _L56;
            puVar17 = puVar13 + uVar14 * 2;
            strncpy(pcVar10,pcVar8,0x40);
            pcVar10[0x40] = '\0';
            *puVar17 = pcVar10;
            if ((pcVar11 == (char *)0x0) || (uVar15 = (uint)uStack_1a0, 0x40 < uVar15)) goto _L56;
            if (pcStack_1a4 == (char *)0x0) {
              puVar17[1] = 0;
            }
            else {
              strncpy(pcVar11,pcStack_1a4,uVar15);
              puVar17[1] = pcVar11;
              pcVar11[uVar15] = '\0';
            }
_L53:
            uVar14 = uVar14 + 1;
          }
        }
        uVar15 = uVar14 & 0xff;
        if (uVar14 == 0) {
          free(puVar13);
          goto _L61;
        }
      }
      uVar1 = otSrpServerServiceGetPort(iVar3);
      esp_openthread_task_switching_lock_release();
      if (iVar4 == 0) {
        uVar6 = esp_log_timestamp();
        esp_log(3,"OPENTHREAD","I (%lu) %s: Add new service\n",uVar6);
        iVar4 = mdns_service_add_for_host
                          (acStack_114,acStack_d0,acStack_1b0,acStack_19c,uVar1,puVar13,uVar15);
      }
      else {
        uVar6 = esp_log_timestamp();
        esp_log(3,"OPENTHREAD","I (%lu) %s: Update service\n",uVar6);
        iVar4 = mdns_service_port_set_for_host(acStack_114,acStack_d0,acStack_1b0,acStack_19c,uVar1)
        ;
        if (iVar4 == 0) {
          iVar4 = mdns_service_txt_set_for_host
                            (acStack_114,acStack_d0,acStack_1b0,acStack_19c,puVar13,uVar15);
          if (iVar4 == 0) goto _L63;
          uVar1 = esp_log_timestamp();
          pcVar8 = "E (%lu) %s: Failed to add or update service txt\n";
        }
        else {
          uVar1 = esp_log_timestamp();
          pcVar8 = "E (%lu) %s: Failed to add or update service port\n";
        }
        esp_log(1,"OPENTHREAD",pcVar8,uVar1);
      }
_L63:
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      if (puVar13 != (undefined4 *)0x0) {
        puVar17 = puVar13;
        for (uVar14 = 0; uVar14 < uVar15; uVar14 = uVar14 + 1) {
          if ((void *)*puVar17 != (void *)0x0) {
            free((void *)*puVar17);
          }
          if ((void *)puVar17[1] != (void *)0x0) {
            free((void *)puVar17[1]);
          }
          puVar17 = puVar17 + 2;
        }
        free(puVar13);
      }
      if (iVar4 != 0) {
        uVar1 = esp_log_timestamp();
        esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to add or update service\n",uVar1);
        goto _L127;
      }
      uVar14 = otSrpServerServiceGetNumberOfSubTypes(iVar3);
      pvVar5 = malloc(uVar14 << 2);
      memset(pvVar5,0,uVar14 << 2);
      for (uVar15 = 0; uVar15 < uVar14; uVar15 = uVar15 + 1 & 0xffff) {
        iVar4 = otSrpServerServiceGetSubTypeServiceNameAt(iVar3,uVar15);
        if (iVar4 == 0) {
          uVar6 = esp_log_timestamp();
          uVar1 = 0xeb;
          pcVar8 = "E (%lu) %s: %s(%d): Failed to get service subtype\n";
_L126:
          esp_log(1,"OPENTHREAD",pcVar8,uVar6,__FUNCTION___0,uVar1);
          free_subtype_list(pvVar5,uVar14);
          uVar1 = esp_log_timestamp();
          esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to allocate subtype list\n",uVar1);
          goto _L79;
        }
        pvVar7 = malloc(0x41);
        if (pvVar7 == (void *)0x0) {
          uVar6 = esp_log_timestamp();
          uVar1 = 0xee;
          pcVar8 = "E (%lu) %s: %s(%d): No memory for a new subtype entry\n";
          goto _L126;
        }
        split_hostname_constprop_0(iVar4,pvVar7);
        *(void **)(uVar15 * 4 + (int)pvVar5) = pvVar7;
      }
      esp_openthread_task_switching_lock_release();
      iVar4 = mdns_service_subtype_update_multiple_items_for_host
                        (acStack_114,acStack_d0,acStack_1b0,acStack_19c,pvVar5,uVar14 & 0xff);
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      for (iVar12 = 0; iVar12 < (int)uVar14; iVar12 = iVar12 + 1) {
        uVar1 = esp_log_timestamp();
        esp_log(3,"OPENTHREAD","I (%lu) %s: Update subtype: %s\n",uVar1,"OPENTHREAD",
                *(undefined4 *)(iVar12 * 4 + (int)pvVar5));
      }
      free_subtype_list(pvVar5,uVar14);
    } while (iVar4 == 0);
    uVar1 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to update service subtype\n",uVar1);
_L127:
    iVar2 = convert_to_ot_srp_error_code(iVar4);
  }
_L33:
  esp_openthread_get_instance();
  otSrpServerHandleServiceUpdateResult(param_1,iVar2);
  return;
}

