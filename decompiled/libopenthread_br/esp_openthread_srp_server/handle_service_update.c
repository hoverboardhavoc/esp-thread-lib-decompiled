/*
 * Last changed at upstream commit a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * https://github.com/espressif/esp-thread-lib/commit/a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * Upstream date: 2024-04-18 16:47:55 +0800
 * Upstream subject: feat(br): update border router lib           esp-openthread: 07f637d           openthread: be7d36e
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> handle_service_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_service_update(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  void *__s1;
  void *__s2;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
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
  undefined1 auStack_8c [56];
  undefined1 auStack_54 [32];
  
  iVar11 = otSrpServerHostIsDeleted(param_2);
  if (iVar11 != 0) {
    uVar12 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC13,uVar12,"OPENTHREAD");
    otSrpServerHostGetFullName(param_2);
    split_hostname_constprop_0(auStack_54);
    uVar12 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC14,uVar12,"OPENTHREAD",auStack_54);
    esp_openthread_task_switching_lock_release();
    iVar11 = mdns_delegate_hostname_remove(auStack_54);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    esp_openthread_get_instance();
    otSrpServerHandleServiceUpdateResult(param_1,iVar11 != 0);
    return;
  }
  uVar12 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC15,uVar12,"OPENTHREAD");
  otSrpServerHostGetFullName(param_2);
  split_hostname_constprop_0(acStack_19c);
  uVar12 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC1,uVar12,"OPENTHREAD",acStack_19c);
  esp_openthread_task_switching_lock_release();
  iVar11 = mdns_hostname_get(acStack_158);
  iVar3 = mdns_hostname_exists(acStack_19c);
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  __s1 = (void *)otSrpServerHostGetAddresses(param_2,&uStack_1cf);
  if (__s1 == (void *)0x0) {
_L0:
    if (iVar3 != 0) {
      uVar12 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC3,uVar12,"OPENTHREAD");
      puVar1 = (undefined1 *)0x0;
      goto _L0;
    }
    uVar12 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC5,uVar12,"OPENTHREAD");
    puVar1 = (undefined1 *)0x0;
_L0:
    if ((iVar11 != 0) || (iVar11 = strcasecmp(acStack_158,acStack_19c), iVar11 != 0)) {
      esp_openthread_task_switching_lock_release();
      mdns_delegate_hostname_add(acStack_19c,puVar1);
      goto _L0;
    }
  }
  else {
    esp_openthread_get_instance();
    __s2 = (void *)otThreadGetMeshLocalPrefix();
    iVar4 = memcmp(__s1,__s2,8);
    if (iVar4 == 0) goto _L0;
    uStack_1a4 = 6;
    memcpy(auStack_1b8,__s1,0x10);
    uStack_1a8 = 0;
    uStack_1a0 = 0;
    if (iVar3 == 0) {
      uVar12 = esp_log_timestamp();
      uVar5 = ip6addr_ntoa(auStack_1b8);
      esp_log_write(3,"OPENTHREAD",&_LC4,uVar12,"OPENTHREAD",uVar5);
      puVar1 = auStack_1b8;
      goto _L0;
    }
    uVar12 = esp_log_timestamp();
    uVar5 = ip6addr_ntoa(auStack_1b8);
    esp_log_write(3,"OPENTHREAD",&_LC2,uVar12,"OPENTHREAD",uVar5);
    puVar1 = auStack_1b8;
_L0:
    if ((iVar11 != 0) || (iVar11 = strcasecmp(acStack_158,acStack_19c), iVar11 != 0)) {
      esp_openthread_task_switching_lock_release();
      mdns_delegate_hostname_set_address(acStack_19c,puVar1);
_L0:
      iVar3 = convert_to_ot_srp_error_code();
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      iVar11 = iVar3;
      if (iVar3 == 0) {
        iVar4 = 0;
        do {
          iVar4 = otSrpServerHostGetNextService(param_2,iVar4);
          iVar11 = iVar3;
          if (iVar4 == 0) break;
          pcVar6 = (char *)otSrpServerServiceGetInstanceName();
          memset(acStack_114,0,0x41);
          memset(acStack_d0,0,0x41);
          acStack_1cc[0] = '\0';
          acStack_1cc[1] = '\0';
          acStack_1cc[2] = '\0';
          acStack_1cc[3] = '\0';
          acStack_1cc[4] = '\0';
          acStack_1cc[5] = '\0';
          pcVar7 = strchr(pcVar6,0x2e);
          sVar13 = (int)pcVar7 - (int)pcVar6;
          if (0x40 < sVar13) {
            sVar13 = 0x40;
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
          strncpy(acStack_114,pcVar6,sVar13);
          acStack_114[sVar13] = '\0';
          strncpy(acStack_d0,pcVar7,__n);
          acStack_d0[__n] = '\0';
          strncpy(acStack_1cc,pcVar8,__n_00);
          acStack_1cc[__n_00] = '\0';
          uVar12 = esp_log_timestamp();
          esp_log_write(3,"OPENTHREAD",&_LC6,uVar12,"OPENTHREAD",acStack_114,acStack_d0,acStack_1cc)
          ;
          esp_openthread_task_switching_lock_release();
          iVar11 = mdns_service_exists_with_instance(acStack_114,acStack_d0,acStack_1cc,acStack_19c)
          ;
          esp_openthread_task_switching_lock_acquire(0xffffffff);
          iVar10 = otSrpServerServiceIsDeleted(iVar4);
          if ((iVar10 == 0) && (iVar11 == 0)) {
            uVar12 = esp_log_timestamp();
            esp_log_write(3,"OPENTHREAD",&_LC7,uVar12,"OPENTHREAD");
            uStack_1ce = 0;
            uVar12 = otSrpServerServiceGetTxtData(iVar4,&uStack_1ce);
            otDnsInitTxtEntryIterator(auStack_8c,uVar12,uStack_1ce);
            uVar15 = 0;
            while (iVar11 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1c4), iVar11 == 0) {
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
                iVar11 = 3;
                break;
              }
              memset(__s,0,uVar15 << 3);
              otDnsInitTxtEntryIterator(auStack_8c,uVar12,uStack_1ce);
              uVar15 = 0;
              while (iVar11 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1c4), iVar11 == 0) {
                pcVar8 = (char *)malloc(0x41);
                pcVar9 = (char *)malloc(0x41);
                pcVar7 = pcStack_1c0;
                pcVar6 = pcStack_1c4;
                if (pcStack_1c4 == (char *)0x0) {
                  uVar2 = (uint)uStack_1bc;
                  sVar13 = 0;
                  do {
                    if (pcStack_1c0[sVar13] == '=') {
                      if ((sVar13 - 1 & 0xffff) < 0x40) {
                        strncpy(pcVar8,pcStack_1c0,sVar13);
                        uVar2 = uVar2 - sVar13 & 0xffff;
                        pcVar8[sVar13] = '\0';
                        __s[uVar15 * 2] = pcVar8;
                        if ((uVar2 - 2 & 0xffff) < 0x40) {
                          uVar2 = uVar2 - 1 & 0xffff;
                          strncpy(pcVar9,pcVar7 + sVar13 + 1,uVar2);
                          pcVar9[uVar2] = '\0';
                          (__s + uVar15 * 2)[1] = pcVar9;
                          goto _L0;
                        }
                      }
                      break;
                    }
                    sVar13 = sVar13 + 1 & 0xffff;
                  } while (uVar2 != sVar13);
_L0:
                  free(pcVar8);
                  free(pcVar9);
                }
                else {
                  if ((pcVar8 == (char *)0x0) || (sVar13 = strnlen(pcStack_1c4,0x41), 0x40 < sVar13)
                     ) goto _L0;
                  strncpy(pcVar8,pcVar6,0x40);
                  pcVar8[0x40] = '\0';
                  __s[uVar15 * 2] = pcVar8;
                  if ((pcVar9 == (char *)0x0) || (uVar2 = (uint)uStack_1bc, 0x40 < uVar2)) goto _L0;
                  strncpy(pcVar9,pcStack_1c0,uVar2);
                  pcVar9[uVar2] = '\0';
                  (__s + uVar15 * 2)[1] = pcVar9;
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
            uVar12 = otSrpServerServiceGetPort(iVar4);
            esp_openthread_task_switching_lock_release();
            iVar11 = mdns_service_add_for_host
                               (acStack_114,acStack_d0,acStack_1cc,acStack_19c,uVar12,__s,uVar2);
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
            if (iVar11 != 0) {
              uVar12 = esp_log_timestamp();
              esp_log_write(1,"OPENTHREAD",&_LC8,uVar12,"OPENTHREAD");
              iVar11 = convert_to_ot_srp_error_code(iVar11);
              break;
            }
            uVar2 = otSrpServerServiceGetNumberOfSubTypes(iVar4);
            for (uVar15 = 0; uVar15 != uVar2; uVar15 = uVar15 + 1 & 0xffff) {
              iVar11 = otSrpServerServiceGetSubTypeServiceNameAt(iVar4,uVar15);
              if (iVar11 == 0) {
                uVar12 = esp_log_timestamp();
                esp_log_write(1,"OPENTHREAD",&_LC11,uVar12,"OPENTHREAD");
                goto _L0;
              }
              memset(auStack_8c,0,0x41);
              split_hostname_constprop_0(iVar11,auStack_8c);
              esp_openthread_task_switching_lock_release();
              iVar11 = mdns_service_subtype_add_for_host
                                 (acStack_114,acStack_d0,acStack_1cc,acStack_19c,auStack_8c);
              esp_openthread_task_switching_lock_acquire(0xffffffff);
              uVar12 = esp_log_timestamp();
              esp_log_write(3,"OPENTHREAD",&_LC9,uVar12,"OPENTHREAD",auStack_8c);
              if (iVar11 != 0) {
                uVar12 = esp_log_timestamp();
                esp_log_write(1,"OPENTHREAD",&_LC10,uVar12,"OPENTHREAD");
                iVar11 = convert_to_ot_srp_error_code(iVar11);
                if (iVar11 != 0) goto _L0;
                break;
              }
            }
          }
          else {
            iVar11 = otSrpServerServiceIsDeleted(iVar4);
            if (iVar11 != 0) {
              esp_openthread_task_switching_lock_release();
              iVar11 = mdns_service_remove_for_host(acStack_114,acStack_d0,acStack_1cc,acStack_19c);
              esp_openthread_task_switching_lock_acquire(0xffffffff);
              if (iVar11 == 0x105) {
                uVar12 = esp_log_timestamp();
                esp_log_write(2,"OPENTHREAD",&_LC12,uVar12,"OPENTHREAD",acStack_19c,acStack_114,
                              acStack_1cc);
              }
              else if (iVar11 != 0) {
_L0:
                iVar11 = 1;
                break;
              }
            }
          }
        } while( true );
      }
      goto _L0;
    }
  }
  iVar11 = 0x1d;
_L0:
  esp_openthread_get_instance();
  otSrpServerHandleServiceUpdateResult(param_1,iVar11);
  return;
}

