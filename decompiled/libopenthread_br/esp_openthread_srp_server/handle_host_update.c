/*
 * Last changed at upstream commit a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * https://github.com/espressif/esp-thread-lib/commit/a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * Upstream date: 2024-04-18 16:47:55 +0800
 * Upstream subject: feat(br): update border router lib           esp-openthread: 07f637d           openthread: be7d36e
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> handle_host_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_host_update(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  void *__s1;
  void *__s2;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  int iVar12;
  size_t __n;
  undefined4 *__s;
  size_t sVar13;
  undefined4 *puVar14;
  uint uVar15;
  size_t __n_00;
  undefined1 uStack_1cf;
  undefined2 uStack_1ce;
  char acStack_1cc [8];
  char *pcStack_1c4;
  char *pcStack_1c0;
  ushort uStack_1bc;
  undefined1 auStack_1b8 [16];
  undefined1 uStack_1a8;
  undefined1 uStack_1a4;
  undefined4 uStack_1a0;
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
  __s1 = (void *)otSrpServerHostGetAddresses(param_2,&uStack_1cf);
  if (__s1 == (void *)0x0) {
_L0:
    if (iVar5 != 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC3,uVar3,"OPENTHREAD");
      puVar1 = (undefined1 *)0x0;
      goto _L0;
    }
    uVar3 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC5,uVar3,"OPENTHREAD");
    puVar1 = (undefined1 *)0x0;
_L0:
    if ((iVar4 != 0) || (iVar4 = strcasecmp(acStack_158,acStack_19c), iVar4 != 0)) {
      esp_openthread_task_switching_lock_release();
      mdns_delegate_hostname_add(acStack_19c,puVar1);
      goto _L0;
    }
  }
  else {
    esp_openthread_get_instance();
    __s2 = (void *)otThreadGetMeshLocalPrefix();
    iVar6 = memcmp(__s1,__s2,8);
    if (iVar6 == 0) goto _L0;
    uStack_1a4 = 6;
    memcpy(auStack_1b8,__s1,0x10);
    uStack_1a8 = 0;
    uStack_1a0 = 0;
    if (iVar5 == 0) {
      uVar3 = esp_log_timestamp();
      uVar7 = ip6addr_ntoa(auStack_1b8);
      esp_log_write(3,"OPENTHREAD",&_LC4,uVar3,"OPENTHREAD",uVar7);
      puVar1 = auStack_1b8;
      goto _L0;
    }
    uVar3 = esp_log_timestamp();
    uVar7 = ip6addr_ntoa(auStack_1b8);
    esp_log_write(3,"OPENTHREAD",&_LC2,uVar3,"OPENTHREAD",uVar7);
    puVar1 = auStack_1b8;
_L0:
    if ((iVar4 != 0) || (iVar4 = strcasecmp(acStack_158,acStack_19c), iVar4 != 0)) {
      esp_openthread_task_switching_lock_release();
      mdns_delegate_hostname_set_address(acStack_19c,puVar1);
_L0:
      iVar5 = convert_to_ot_srp_error_code();
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      iVar4 = iVar5;
      if (iVar5 == 0) {
        iVar6 = 0;
        do {
          iVar6 = otSrpServerHostGetNextService(param_2,iVar6);
          iVar4 = iVar5;
          if (iVar6 == 0) break;
          pcVar8 = (char *)otSrpServerServiceGetInstanceName();
          memset(acStack_114,0,0x41);
          memset(acStack_d0,0,0x41);
          acStack_1cc[0] = '\0';
          acStack_1cc[1] = '\0';
          acStack_1cc[2] = '\0';
          acStack_1cc[3] = '\0';
          acStack_1cc[4] = '\0';
          acStack_1cc[5] = '\0';
          pcVar9 = strchr(pcVar8,0x2e);
          sVar13 = (int)pcVar9 - (int)pcVar8;
          if (0x40 < sVar13) {
            sVar13 = 0x40;
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
          strncpy(acStack_114,pcVar8,sVar13);
          acStack_114[sVar13] = '\0';
          strncpy(acStack_d0,pcVar9,__n);
          acStack_d0[__n] = '\0';
          strncpy(acStack_1cc,pcVar10,__n_00);
          acStack_1cc[__n_00] = '\0';
          uVar3 = esp_log_timestamp();
          esp_log_write(3,"OPENTHREAD",&_LC6,uVar3,"OPENTHREAD",acStack_114,acStack_d0,acStack_1cc);
          esp_openthread_task_switching_lock_release();
          iVar4 = mdns_service_exists_with_instance(acStack_114,acStack_d0,acStack_1cc,acStack_19c);
          esp_openthread_task_switching_lock_acquire(0xffffffff);
          iVar12 = otSrpServerServiceIsDeleted(iVar6);
          if ((iVar12 == 0) && (iVar4 == 0)) {
            uVar3 = esp_log_timestamp();
            esp_log_write(3,"OPENTHREAD",&_LC7,uVar3,"OPENTHREAD");
            uStack_1ce = 0;
            uVar3 = otSrpServerServiceGetTxtData(iVar6,&uStack_1ce);
            otDnsInitTxtEntryIterator(auStack_8c,uVar3,uStack_1ce);
            uVar15 = 0;
            while (iVar4 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1c4), iVar4 == 0) {
              uVar15 = uVar15 + 1 & 0xff;
            }
            if (uVar15 == 0) {
_L0:
              uVar2 = 0;
              __s = (undefined4 *)0x0;
            }
            else {
              __s = (undefined4 *)malloc(uVar15 << 3);
              if (__s == (undefined4 *)0x0) {
                iVar4 = 3;
                break;
              }
              memset(__s,0,uVar15 << 3);
              otDnsInitTxtEntryIterator(auStack_8c,uVar3,uStack_1ce);
              uVar15 = 0;
              while (iVar4 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1c4), iVar4 == 0) {
                pcVar10 = (char *)malloc(0x41);
                pcVar11 = (char *)malloc(0x41);
                pcVar9 = pcStack_1c0;
                pcVar8 = pcStack_1c4;
                if (pcStack_1c4 == (char *)0x0) {
                  uVar2 = (uint)uStack_1bc;
                  sVar13 = 0;
                  do {
                    if (pcStack_1c0[sVar13] == '=') {
                      if ((sVar13 - 1 & 0xffff) < 0x40) {
                        strncpy(pcVar10,pcStack_1c0,sVar13);
                        uVar2 = uVar2 - sVar13 & 0xffff;
                        pcVar10[sVar13] = '\0';
                        __s[uVar15 * 2] = pcVar10;
                        if ((uVar2 - 2 & 0xffff) < 0x40) {
                          uVar2 = uVar2 - 1 & 0xffff;
                          strncpy(pcVar11,pcVar9 + sVar13 + 1,uVar2);
                          pcVar11[uVar2] = '\0';
                          (__s + uVar15 * 2)[1] = pcVar11;
                          goto _L0;
                        }
                      }
                      break;
                    }
                    sVar13 = sVar13 + 1 & 0xffff;
                  } while (uVar2 != sVar13);
_L0:
                  free(pcVar10);
                  free(pcVar11);
                }
                else {
                  if ((pcVar10 == (char *)0x0) ||
                     (sVar13 = strnlen(pcStack_1c4,0x41), 0x40 < sVar13)) goto _L0;
                  strncpy(pcVar10,pcVar8,0x40);
                  pcVar10[0x40] = '\0';
                  __s[uVar15 * 2] = pcVar10;
                  if ((pcVar11 == (char *)0x0) || (uVar2 = (uint)uStack_1bc, 0x40 < uVar2))
                  goto _L0;
                  strncpy(pcVar11,pcStack_1c0,uVar2);
                  pcVar11[uVar2] = '\0';
                  (__s + uVar15 * 2)[1] = pcVar11;
_L0:
                  uVar15 = uVar15 + 1;
                }
              }
              uVar2 = uVar15 & 0xff;
              if (uVar15 == 0) {
                free(__s);
                goto _L0;
              }
            }
            uVar3 = otSrpServerServiceGetPort(iVar6);
            esp_openthread_task_switching_lock_release();
            iVar4 = mdns_service_add_for_host
                              (acStack_114,acStack_d0,acStack_1cc,acStack_19c,uVar3,__s,uVar2);
            esp_openthread_task_switching_lock_acquire(0xffffffff);
            if (__s != (undefined4 *)0x0) {
              puVar14 = __s;
              for (uVar15 = 0; uVar15 < uVar2; uVar15 = uVar15 + 1) {
                if ((void *)*puVar14 != (void *)0x0) {
                  free((void *)*puVar14);
                }
                if ((void *)puVar14[1] != (void *)0x0) {
                  free((void *)puVar14[1]);
                }
                puVar14 = puVar14 + 2;
              }
              free(__s);
            }
            if (iVar4 != 0) {
              uVar3 = esp_log_timestamp();
              esp_log_write(1,"OPENTHREAD",&_LC8,uVar3,"OPENTHREAD");
              iVar4 = convert_to_ot_srp_error_code(iVar4);
              break;
            }
            uVar2 = otSrpServerServiceGetNumberOfSubTypes(iVar6);
            for (uVar15 = 0; uVar15 != uVar2; uVar15 = uVar15 + 1 & 0xffff) {
              iVar4 = otSrpServerServiceGetSubTypeServiceNameAt(iVar6,uVar15);
              if (iVar4 == 0) {
                uVar3 = esp_log_timestamp();
                esp_log_write(1,"OPENTHREAD",&_LC11,uVar3,"OPENTHREAD");
                goto _L0;
              }
              memset(auStack_8c,0,0x41);
              split_hostname_constprop_0(iVar4,auStack_8c);
              esp_openthread_task_switching_lock_release();
              iVar4 = mdns_service_subtype_add_for_host
                                (acStack_114,acStack_d0,acStack_1cc,acStack_19c,auStack_8c);
              esp_openthread_task_switching_lock_acquire(0xffffffff);
              uVar3 = esp_log_timestamp();
              esp_log_write(3,"OPENTHREAD",&_LC9,uVar3,"OPENTHREAD",auStack_8c);
              if (iVar4 != 0) {
                uVar3 = esp_log_timestamp();
                esp_log_write(1,"OPENTHREAD",&_LC10,uVar3,"OPENTHREAD");
                iVar4 = convert_to_ot_srp_error_code(iVar4);
                if (iVar4 != 0) goto _L0;
                break;
              }
            }
          }
          else {
            iVar4 = otSrpServerServiceIsDeleted(iVar6);
            if (iVar4 != 0) {
              esp_openthread_task_switching_lock_release();
              iVar4 = mdns_service_remove_for_host(acStack_114,acStack_d0,acStack_1cc,acStack_19c);
              esp_openthread_task_switching_lock_acquire(0xffffffff);
              if (iVar4 == 0x105) {
                uVar3 = esp_log_timestamp();
                esp_log_write(2,"OPENTHREAD",&_LC12,uVar3,"OPENTHREAD",acStack_19c,acStack_114,
                              acStack_1cc);
              }
              else if (iVar4 != 0) {
_L0:
                iVar4 = 1;
                break;
              }
            }
          }
        } while( true );
      }
      goto _L0;
    }
  }
  iVar4 = 0x1d;
_L0:
  esp_openthread_get_instance();
  otSrpServerHandleServiceUpdateResult(param_1,iVar4);
  return;
}

