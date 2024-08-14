/*
 * Last changed at upstream commit b1d2a662b872a73f6de3c581fc3c2c7aaa01ad83
 * https://github.com/espressif/esp-thread-lib/commit/b1d2a662b872a73f6de3c581fc3c2c7aaa01ad83
 * Upstream date: 2024-08-14 16:06:24 +0800
 * Upstream subject: feat(br): support C5 lib
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
  uint uVar14;
  size_t __n;
  undefined4 *puVar15;
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
  uVar3 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC1,uVar3,"OPENTHREAD",acStack_19c);
  esp_openthread_task_switching_lock_release();
  iVar4 = mdns_hostname_get(acStack_158);
  iVar5 = mdns_hostname_exists(acStack_19c);
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  iVar6 = otSrpServerHostGetAddresses(param_2,&bStack_1b3);
  if (bStack_1b3 == 0) {
    if (iVar5 != 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC3,uVar3,"OPENTHREAD");
      pvVar7 = (void *)0x0;
      goto _L0;
    }
    uVar3 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC4,uVar3,"OPENTHREAD");
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
    uVar14 = 0;
    pvVar1 = (void *)0x0;
    do {
      pvVar7 = malloc(0x1c);
      if (pvVar7 == (void *)0x0) {
        iVar4 = 3;
        goto _L0;
      }
      *(undefined1 *)((int)pvVar7 + 0x14) = 6;
      memcpy(pvVar7,(void *)(uVar14 * 0x10 + iVar6),0x10);
      uVar14 = uVar14 + 1;
      *(undefined1 *)((int)pvVar7 + 0x10) = 0;
      *(void **)((int)pvVar7 + 0x18) = pvVar1;
      pvVar1 = pvVar7;
    } while ((uVar14 & 0xff) < (uint)bStack_1b3);
    if (iVar5 == 0) {
      do {
        uVar3 = esp_log_timestamp();
        uVar8 = ip6addr_ntoa(pvVar1);
        esp_log_write(3,"OPENTHREAD",&_LC5,uVar3,"OPENTHREAD",uVar8);
        puVar15 = (undefined4 *)((int)pvVar1 + 0x18);
        pvVar1 = (void *)*puVar15;
      } while ((void *)*puVar15 != (void *)0x0);
      goto _L0;
    }
    do {
      uVar3 = esp_log_timestamp();
      uVar8 = ip6addr_ntoa(pvVar1);
      esp_log_write(3,"OPENTHREAD",&_LC2,uVar3,"OPENTHREAD",uVar8);
      puVar15 = (undefined4 *)((int)pvVar1 + 0x18);
      pvVar1 = (void *)*puVar15;
    } while ((void *)*puVar15 != (void *)0x0);
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
    sVar16 = (int)pcVar10 - (int)pcVar9;
    if (0x40 < sVar16) {
      sVar16 = 0x40;
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
    strncpy(acStack_114,pcVar9,sVar16);
    acStack_114[sVar16] = '\0';
    strncpy(acStack_d0,pcVar10,__n);
    acStack_d0[__n] = '\0';
    strncpy(acStack_1b0,pcVar11,__n_00);
    acStack_1b0[__n_00] = '\0';
    uVar3 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC6,uVar3,"OPENTHREAD",acStack_114,acStack_d0,acStack_1b0);
    esp_openthread_task_switching_lock_release();
    iVar5 = mdns_service_exists_with_instance(acStack_114,acStack_d0,acStack_1b0,acStack_19c);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    iVar13 = otSrpServerServiceIsDeleted(iVar6);
    if ((iVar13 == 0) && (iVar5 == 0)) {
      uVar3 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC7,uVar3,"OPENTHREAD");
      uStack_1b2 = 0;
      uVar3 = otSrpServerServiceGetTxtData(iVar6,&uStack_1b2);
      otDnsInitTxtEntryIterator(auStack_8c,uVar3,uStack_1b2);
      uVar14 = 0;
      while (iVar5 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1a8), iVar5 == 0) {
        uVar14 = uVar14 + 1 & 0xff;
      }
      if (uVar14 == 0) {
_L0:
        puVar15 = (undefined4 *)0x0;
        uVar2 = 0;
      }
      else {
        puVar15 = (undefined4 *)malloc(uVar14 << 3);
        if (puVar15 == (undefined4 *)0x0) {
          iVar5 = 3;
          goto _L0;
        }
        memset(puVar15,0,uVar14 << 3);
        otDnsInitTxtEntryIterator(auStack_8c,uVar3,uStack_1b2);
        uVar14 = 0;
        while (iVar5 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1a8), iVar5 == 0) {
          pcVar11 = (char *)malloc(0x41);
          pcVar12 = (char *)malloc(0x41);
          pcVar10 = pcStack_1a4;
          pcVar9 = pcStack_1a8;
          if (pcStack_1a8 == (char *)0x0) {
            uVar2 = (uint)uStack_1a0;
            sVar16 = 0;
            do {
              if (pcStack_1a4[sVar16] == '=') {
                if ((sVar16 - 1 & 0xffff) < 0x40) {
                  strncpy(pcVar11,pcStack_1a4,sVar16);
                  uVar2 = uVar2 - sVar16 & 0xffff;
                  pcVar11[sVar16] = '\0';
                  puVar15[uVar14 * 2] = pcVar11;
                  if ((uVar2 - 2 & 0xffff) < 0x40) {
                    uVar2 = uVar2 - 1 & 0xffff;
                    strncpy(pcVar12,pcVar10 + sVar16 + 1,uVar2);
                    pcVar12[uVar2] = '\0';
                    (puVar15 + uVar14 * 2)[1] = pcVar12;
                    goto _L0;
                  }
                }
                break;
              }
              sVar16 = sVar16 + 1 & 0xffff;
            } while (uVar2 != sVar16);
_L0:
            free(pcVar11);
            free(pcVar12);
          }
          else {
            if ((pcVar11 == (char *)0x0) || (sVar16 = strnlen(pcStack_1a8,0x41), 0x40 < sVar16))
            goto _L0;
            strncpy(pcVar11,pcVar9,0x40);
            pcVar11[0x40] = '\0';
            puVar15[uVar14 * 2] = pcVar11;
            if ((pcVar12 == (char *)0x0) || (uVar2 = (uint)uStack_1a0, 0x40 < uVar2)) goto _L0;
            strncpy(pcVar12,pcStack_1a4,uVar2);
            pcVar12[uVar2] = '\0';
            (puVar15 + uVar14 * 2)[1] = pcVar12;
_L0:
            uVar14 = uVar14 + 1;
          }
        }
        uVar2 = uVar14 & 0xff;
        if (uVar14 == 0) {
          free(puVar15);
          goto _L0;
        }
      }
      uVar3 = otSrpServerServiceGetPort(iVar6);
      esp_openthread_task_switching_lock_release();
      iVar5 = mdns_service_add_for_host
                        (acStack_114,acStack_d0,acStack_1b0,acStack_19c,uVar3,puVar15,uVar2);
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      if (puVar15 != (undefined4 *)0x0) {
        puVar17 = puVar15;
        for (uVar14 = 0; uVar14 < uVar2; uVar14 = uVar14 + 1) {
          if ((void *)*puVar17 != (void *)0x0) {
            free((void *)*puVar17);
          }
          if ((void *)puVar17[1] != (void *)0x0) {
            free((void *)puVar17[1]);
          }
          puVar17 = puVar17 + 2;
        }
        free(puVar15);
      }
      if (iVar5 != 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC8,uVar3,"OPENTHREAD");
        iVar5 = convert_to_ot_srp_error_code(iVar5);
        goto _L0;
      }
      uVar2 = otSrpServerServiceGetNumberOfSubTypes(iVar6);
      for (uVar14 = 0; uVar14 != uVar2; uVar14 = uVar14 + 1 & 0xffff) {
        iVar5 = otSrpServerServiceGetSubTypeServiceNameAt(iVar6,uVar14);
        if (iVar5 == 0) {
          uVar3 = esp_log_timestamp();
          esp_log_write(1,"OPENTHREAD",&_LC11,uVar3,"OPENTHREAD");
          goto _L0;
        }
        memset(auStack_8c,0,0x41);
        split_hostname_constprop_0(iVar5,auStack_8c);
        esp_openthread_task_switching_lock_release();
        iVar5 = mdns_service_subtype_add_for_host
                          (acStack_114,acStack_d0,acStack_1b0,acStack_19c,auStack_8c);
        esp_openthread_task_switching_lock_acquire(0xffffffff);
        uVar3 = esp_log_timestamp();
        esp_log_write(3,"OPENTHREAD",&_LC9,uVar3,"OPENTHREAD",auStack_8c);
        if (iVar5 != 0) {
          uVar3 = esp_log_timestamp();
          esp_log_write(1,"OPENTHREAD",&_LC10,uVar3,"OPENTHREAD");
          iVar5 = convert_to_ot_srp_error_code(iVar5);
          if (iVar5 != 0) goto _L0;
          break;
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
          esp_log_write(2,"OPENTHREAD",&_LC12,uVar3,"OPENTHREAD",acStack_19c,acStack_114,acStack_1b0
                       );
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

