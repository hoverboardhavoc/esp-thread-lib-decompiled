/*
 * Last changed at upstream commit b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * https://github.com/espressif/esp-thread-lib/commit/b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * Upstream date: 2023-12-09 16:01:37 +0800
 * Upstream subject: feat(br): update border router lib     esp-openthread: 8d18b44     openthread: 41ef807
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
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  void *__s1;
  void *__s2;
  int iVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  size_t __n;
  undefined4 *__s;
  size_t sVar13;
  undefined4 *puVar14;
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
  uVar4 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC1,uVar4,"OPENTHREAD",acStack_19c);
  iVar5 = mdns_hostname_get(acStack_158);
  iVar6 = mdns_hostname_exists(acStack_19c);
  __s1 = (void *)otSrpServerHostGetAddresses(param_2,&uStack_1cf);
  if (__s1 == (void *)0x0) {
_L0:
    if (iVar6 != 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC3,uVar4,"OPENTHREAD");
      puVar1 = (undefined1 *)0x0;
      goto _L0;
    }
    uVar4 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC5,uVar4,"OPENTHREAD");
    puVar1 = (undefined1 *)0x0;
_L0:
    if ((iVar5 != 0) || (iVar5 = strcasecmp(acStack_158,acStack_19c), iVar5 != 0)) {
      mdns_delegate_hostname_add(acStack_19c,puVar1);
      goto _L0;
    }
  }
  else {
    esp_openthread_get_instance();
    __s2 = (void *)otThreadGetMeshLocalPrefix();
    iVar7 = memcmp(__s1,__s2,8);
    if (iVar7 == 0) goto _L0;
    uStack_1a4 = 6;
    memcpy(auStack_1b8,__s1,0x10);
    uStack_1a8 = 0;
    uStack_1a0 = 0;
    if (iVar6 == 0) {
      uVar4 = esp_log_timestamp();
      uVar8 = ip6addr_ntoa(auStack_1b8);
      esp_log_write(3,"OPENTHREAD",&_LC4,uVar4,"OPENTHREAD",uVar8);
      puVar1 = auStack_1b8;
      goto _L0;
    }
    uVar4 = esp_log_timestamp();
    uVar8 = ip6addr_ntoa(auStack_1b8);
    esp_log_write(3,"OPENTHREAD",&_LC2,uVar4,"OPENTHREAD",uVar8);
    puVar1 = auStack_1b8;
_L0:
    if ((iVar5 != 0) || (iVar5 = strcasecmp(acStack_158,acStack_19c), iVar5 != 0)) {
      mdns_delegate_hostname_set_address(acStack_19c,puVar1);
_L0:
      iVar6 = convert_to_ot_srp_error_code();
      iVar5 = iVar6;
      if (iVar6 == 0) {
        iVar7 = 0;
        do {
          iVar7 = otSrpServerHostGetNextService(param_2,iVar7);
          iVar5 = iVar6;
          if (iVar7 == 0) break;
          pcVar9 = (char *)otSrpServerServiceGetInstanceName();
          memset(acStack_114,0,0x41);
          memset(acStack_d0,0,0x41);
          acStack_1cc[0] = '\0';
          acStack_1cc[1] = '\0';
          acStack_1cc[2] = '\0';
          acStack_1cc[3] = '\0';
          acStack_1cc[4] = '\0';
          acStack_1cc[5] = '\0';
          pcVar10 = strchr(pcVar9,0x2e);
          sVar13 = (int)pcVar10 - (int)pcVar9;
          if (0x40 < sVar13) {
            sVar13 = 0x40;
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
          strncpy(acStack_114,pcVar9,sVar13);
          acStack_114[sVar13] = '\0';
          strncpy(acStack_d0,pcVar10,__n);
          acStack_d0[__n] = '\0';
          strncpy(acStack_1cc,pcVar11,__n_00);
          acStack_1cc[__n_00] = '\0';
          uVar4 = esp_log_timestamp();
          esp_log_write(3,"OPENTHREAD",&_LC6,uVar4,"OPENTHREAD",acStack_114,acStack_d0,acStack_1cc);
          iVar5 = otSrpServerServiceIsDeleted(iVar7);
          if ((iVar5 == 0) &&
             (iVar5 = mdns_service_exists_with_instance
                                (acStack_114,acStack_d0,acStack_1cc,acStack_19c), iVar5 == 0)) {
            uVar4 = esp_log_timestamp();
            esp_log_write(3,"OPENTHREAD",&_LC7,uVar4,"OPENTHREAD");
            uStack_1ce = 0;
            uVar4 = otSrpServerServiceGetTxtData(iVar7,&uStack_1ce);
            otDnsInitTxtEntryIterator(auStack_8c,uVar4,uStack_1ce);
            uVar2 = 0;
            while (iVar5 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1c4), iVar5 == 0) {
              uVar2 = uVar2 + 1 & 0xff;
            }
            if (uVar2 == 0) {
_L0:
              uVar3 = 0;
              __s = (undefined4 *)0x0;
            }
            else {
              __s = (undefined4 *)malloc(uVar2 << 3);
              if (__s == (undefined4 *)0x0) {
                iVar5 = 3;
                break;
              }
              memset(__s,0,uVar2 << 3);
              otDnsInitTxtEntryIterator(auStack_8c,uVar4,uStack_1ce);
              uVar2 = 0;
              while (iVar5 = otDnsGetNextTxtEntry(auStack_8c,&pcStack_1c4), iVar5 == 0) {
                pcVar11 = (char *)malloc(0x41);
                pcVar12 = (char *)malloc(0x41);
                pcVar10 = pcStack_1c0;
                pcVar9 = pcStack_1c4;
                if (pcStack_1c4 == (char *)0x0) {
                  uVar3 = (uint)uStack_1bc;
                  sVar13 = 0;
                  do {
                    if (pcStack_1c0[sVar13] == '=') {
                      if ((sVar13 - 1 & 0xffff) < 0x40) {
                        strncpy(pcVar11,pcStack_1c0,sVar13);
                        uVar3 = uVar3 - sVar13 & 0xffff;
                        pcVar11[sVar13] = '\0';
                        __s[uVar2 * 2] = pcVar11;
                        if ((uVar3 - 2 & 0xffff) < 0x40) {
                          uVar3 = uVar3 - 1 & 0xffff;
                          strncpy(pcVar12,pcVar10 + sVar13 + 1,uVar3);
                          pcVar12[uVar3] = '\0';
                          (__s + uVar2 * 2)[1] = pcVar12;
                          goto _L0;
                        }
                      }
                      break;
                    }
                    sVar13 = sVar13 + 1 & 0xffff;
                  } while (uVar3 != sVar13);
_L0:
                  free(pcVar11);
                  free(pcVar12);
                }
                else {
                  if ((pcVar11 == (char *)0x0) ||
                     (sVar13 = strnlen(pcStack_1c4,0x41), 0x40 < sVar13)) goto _L0;
                  strncpy(pcVar11,pcVar9,0x40);
                  pcVar11[0x40] = '\0';
                  __s[uVar2 * 2] = pcVar11;
                  if ((pcVar12 == (char *)0x0) || (uVar3 = (uint)uStack_1bc, 0x40 < uVar3))
                  goto _L0;
                  strncpy(pcVar12,pcStack_1c0,uVar3);
                  pcVar12[uVar3] = '\0';
                  (__s + uVar2 * 2)[1] = pcVar12;
_L0:
                  uVar2 = uVar2 + 1;
                }
              }
              uVar3 = uVar2 & 0xff;
              if (uVar2 == 0) {
                free(__s);
                goto _L0;
              }
            }
            uVar4 = otSrpServerServiceGetPort(iVar7);
            iVar5 = mdns_service_add_for_host
                              (acStack_114,acStack_d0,acStack_1cc,acStack_19c,uVar4,__s,uVar3);
            if (__s != (undefined4 *)0x0) {
              puVar14 = __s;
              for (uVar2 = 0; uVar2 < uVar3; uVar2 = uVar2 + 1) {
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
            if (iVar5 != 0) {
              uVar4 = esp_log_timestamp();
              esp_log_write(1,"OPENTHREAD",&_LC8,uVar4,"OPENTHREAD");
              iVar5 = convert_to_ot_srp_error_code(iVar5);
              break;
            }
            uVar3 = otSrpServerServiceGetNumberOfSubTypes(iVar7);
            for (uVar2 = 0; uVar2 != uVar3; uVar2 = uVar2 + 1 & 0xffff) {
              iVar5 = otSrpServerServiceGetSubTypeServiceNameAt(iVar7,uVar2);
              if (iVar5 == 0) {
                uVar4 = esp_log_timestamp();
                esp_log_write(1,"OPENTHREAD",&_LC11,uVar4,"OPENTHREAD");
                goto _L0;
              }
              memset(auStack_8c,0,0x41);
              split_hostname_constprop_0(iVar5,auStack_8c);
              iVar5 = mdns_service_subtype_add_for_host
                                (acStack_114,acStack_d0,acStack_1cc,acStack_19c,auStack_8c);
              uVar4 = esp_log_timestamp();
              esp_log_write(3,"OPENTHREAD",&_LC9,uVar4,"OPENTHREAD",auStack_8c);
              if (iVar5 != 0) {
                uVar4 = esp_log_timestamp();
                esp_log_write(1,"OPENTHREAD",&_LC10,uVar4,"OPENTHREAD");
                iVar5 = convert_to_ot_srp_error_code(iVar5);
                if (iVar5 != 0) goto _L0;
                break;
              }
            }
          }
          else {
            iVar5 = otSrpServerServiceIsDeleted(iVar7);
            if (iVar5 != 0) {
              iVar5 = mdns_service_remove_for_host(acStack_114,acStack_d0,acStack_1cc,acStack_19c);
              if (iVar5 == 0x105) {
                uVar4 = esp_log_timestamp();
                esp_log_write(2,"OPENTHREAD",&_LC12,uVar4,"OPENTHREAD",acStack_19c,acStack_114,
                              acStack_1cc);
              }
              else if (iVar5 != 0) {
_L0:
                iVar5 = 1;
                break;
              }
            }
          }
        } while( true );
      }
      goto _L0;
    }
  }
  iVar5 = 0x1d;
_L0:
  esp_openthread_get_instance();
  otSrpServerHandleServiceUpdateResult(param_1,iVar5);
  return;
}

