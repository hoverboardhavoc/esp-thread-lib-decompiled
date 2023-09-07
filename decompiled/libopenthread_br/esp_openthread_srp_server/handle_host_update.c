/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> handle_host_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_host_update(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  void *__s1;
  void *__s2;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  undefined4 *__s;
  undefined *puVar11;
  uint uVar12;
  uint uVar13;
  size_t sVar14;
  size_t __n;
  undefined4 *puVar15;
  size_t __n_00;
  undefined1 uStack_1c7;
  undefined2 uStack_1c6;
  char acStack_1c4 [8];
  char *pcStack_1bc;
  char *pcStack_1b8;
  ushort uStack_1b4;
  undefined1 auStack_1b0 [16];
  undefined1 uStack_1a0;
  undefined1 uStack_19c;
  undefined4 uStack_198;
  char acStack_194 [68];
  char acStack_150 [68];
  char acStack_10c [68];
  char acStack_c8 [68];
  undefined4 uStack_84;
  undefined1 auStack_80 [76];
  
  otSrpServerHostGetFullName(param_2);
  split_hostname_constprop_0(acStack_194);
  uVar2 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC1,uVar2,"OPENTHREAD",acStack_194);
  iVar3 = mdns_hostname_get(acStack_150);
  iVar4 = mdns_hostname_exists(acStack_194);
  __s1 = (void *)otSrpServerHostGetAddresses(param_2,&uStack_1c7);
  if (__s1 == (void *)0x0) {
_L0:
    if (iVar4 != 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC3,uVar2,"OPENTHREAD");
      puVar1 = (undefined1 *)0x0;
      goto _L0;
    }
    uVar2 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC5,uVar2,"OPENTHREAD");
    puVar1 = (undefined1 *)0x0;
_L0:
    if ((iVar3 == 0) && (iVar3 = strcasecmp(acStack_150,acStack_194), iVar3 == 0)) goto _L0;
    iVar3 = mdns_delegate_hostname_add(acStack_194,puVar1);
  }
  else {
    esp_openthread_get_instance();
    __s2 = (void *)otThreadGetMeshLocalPrefix();
    iVar5 = memcmp(__s1,__s2,8);
    if (iVar5 == 0) goto _L0;
    uStack_19c = 6;
    memcpy(auStack_1b0,__s1,0x10);
    uStack_1a0 = 0;
    uStack_198 = 0;
    if (iVar4 == 0) {
      uVar2 = esp_log_timestamp();
      uVar6 = ip6addr_ntoa(auStack_1b0);
      esp_log_write(3,"OPENTHREAD",&_LC4,uVar2,"OPENTHREAD",uVar6);
      puVar1 = auStack_1b0;
      goto _L0;
    }
    uVar2 = esp_log_timestamp();
    uVar6 = ip6addr_ntoa(auStack_1b0);
    esp_log_write(3,"OPENTHREAD",&_LC2,uVar2,"OPENTHREAD",uVar6);
    puVar1 = auStack_1b0;
_L0:
    if ((iVar3 == 0) && (iVar3 = strcasecmp(acStack_150,acStack_194), iVar3 == 0)) goto _L0;
    iVar3 = mdns_delegate_hostname_set_address(acStack_194,puVar1);
  }
  if (iVar3 == 0) {
    iVar3 = 0;
_L0:
    do {
      do {
        while( true ) {
          iVar3 = otSrpServerHostGetNextService(param_2,iVar3);
          if (iVar3 == 0) {
            uVar2 = 0;
            goto _L27;
          }
          pcVar7 = (char *)otSrpServerServiceGetInstanceName();
          acStack_10c[0] = '\0';
          acStack_10c[1] = '\0';
          acStack_10c[2] = '\0';
          acStack_10c[3] = '\0';
          memset(acStack_10c + 4,0,0x3d);
          acStack_c8[0] = '\0';
          acStack_c8[1] = '\0';
          acStack_c8[2] = '\0';
          acStack_c8[3] = '\0';
          memset(acStack_c8 + 4,0,0x3d);
          acStack_1c4[0] = '\0';
          acStack_1c4[1] = '\0';
          acStack_1c4[2] = '\0';
          acStack_1c4[3] = '\0';
          acStack_1c4[4] = '\0';
          acStack_1c4[5] = '\0';
          pcVar8 = strchr(pcVar7,0x2e);
          sVar14 = (int)pcVar8 - (int)pcVar7;
          if (0x40 < sVar14) {
            sVar14 = 0x40;
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
          strncpy(acStack_10c,pcVar7,sVar14);
          acStack_10c[sVar14] = '\0';
          strncpy(acStack_c8,pcVar8,__n);
          acStack_c8[__n] = '\0';
          strncpy(acStack_1c4,pcVar9,__n_00);
          acStack_1c4[__n_00] = '\0';
          uVar2 = esp_log_timestamp();
          esp_log_write(3,"OPENTHREAD",&_LC6,uVar2,"OPENTHREAD",acStack_10c,acStack_c8,acStack_1c4);
          iVar4 = otSrpServerServiceIsDeleted(iVar3);
          if ((iVar4 != 0) ||
             (iVar4 = mdns_service_exists_with_instance
                                (acStack_10c,acStack_c8,acStack_1c4,acStack_194), iVar4 != 0))
          break;
          uVar2 = esp_log_timestamp();
          esp_log_write(3,"OPENTHREAD",&_LC7,uVar2,"OPENTHREAD");
          uStack_1c6 = 0;
          uVar2 = otSrpServerServiceGetTxtData(iVar3,&uStack_1c6);
          otDnsInitTxtEntryIterator(&uStack_84,uVar2,uStack_1c6);
          uVar12 = 0;
          while (iVar4 = otDnsGetNextTxtEntry(&uStack_84,&pcStack_1bc), iVar4 == 0) {
            uVar12 = uVar12 + 1 & 0xff;
          }
          if (uVar12 == 0) {
            __s = (undefined4 *)0x0;
          }
          else {
            __s = (undefined4 *)malloc(uVar12 << 3);
            if (__s == (undefined4 *)0x0) {
_L0:
              uVar2 = 3;
              goto _L27;
            }
            memset(__s,0,uVar12 << 3);
            otDnsInitTxtEntryIterator(&uStack_84,uVar2,uStack_1c6);
            puVar15 = __s;
            while (iVar4 = otDnsGetNextTxtEntry(&uStack_84,&pcStack_1bc), iVar4 == 0) {
              pcVar8 = (char *)malloc(0x41);
              pcVar7 = pcStack_1bc;
              if ((pcVar8 == (char *)0x0) || (sVar14 = strnlen(pcStack_1bc,0x41), 0x40 < sVar14)) {
_L0:
                free_txt_list(__s,uVar12);
                goto _L0;
              }
              strncpy(pcVar8,pcVar7,0x40);
              pcVar8[0x40] = '\0';
              *puVar15 = pcVar8;
              pcVar7 = (char *)malloc(0x41);
              if ((pcVar7 == (char *)0x0) || (uVar13 = (uint)uStack_1b4, 0x40 < uVar13)) goto _L0;
              strncpy(pcVar7,pcStack_1b8,uVar13);
              puVar15[1] = pcVar7;
              pcVar7[uVar13] = '\0';
              puVar15 = puVar15 + 2;
            }
          }
          uVar2 = otSrpServerServiceGetPort(iVar3);
          iVar4 = mdns_service_add_for_host
                            (acStack_10c,acStack_c8,acStack_1c4,acStack_194,uVar2,__s,uVar12);
          free_txt_list(__s,uVar12);
          if (iVar4 != 0) {
            uVar2 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD",&_LC8,uVar2,"OPENTHREAD");
            goto _L0;
          }
          uVar12 = otSrpServerServiceGetNumberOfSubTypes(iVar3);
          for (uVar13 = 0; uVar13 != uVar12; uVar13 = uVar13 + 1 & 0xffff) {
            iVar4 = otSrpServerServiceGetSubTypeServiceNameAt(iVar3,uVar13);
            if (iVar4 == 0) {
              uVar2 = esp_log_timestamp();
              puVar11 = &_LC11;
_L0:
              esp_log_write(1,"OPENTHREAD",puVar11,uVar2,"OPENTHREAD");
            }
            else {
              uStack_84 = 0;
              memset(auStack_80,0,0x3d);
              split_hostname_constprop_0(iVar4,&uStack_84);
              iVar4 = mdns_service_subtype_add_for_host
                                (acStack_10c,acStack_c8,acStack_1c4,acStack_194,&uStack_84);
              uVar2 = esp_log_timestamp();
              esp_log_write(3,"OPENTHREAD",&_LC9,uVar2,"OPENTHREAD",&uStack_84);
              if (iVar4 != 0) {
                uVar2 = esp_log_timestamp();
                puVar11 = &_LC10;
                goto _L0;
              }
            }
          }
        }
        iVar4 = otSrpServerServiceIsDeleted(iVar3);
      } while (iVar4 == 0);
      iVar4 = mdns_service_remove_for_host(acStack_10c,acStack_c8,acStack_1c4,acStack_194);
      if (iVar4 == 0x105) {
        uVar2 = esp_log_timestamp();
        esp_log_write(2,"OPENTHREAD",&_LC12,uVar2,"OPENTHREAD",acStack_194,acStack_10c,acStack_1c4);
        goto _L0;
      }
    } while (iVar4 == 0);
  }
_L0:
  uVar2 = 1;
_L27:
  esp_openthread_get_instance();
  otSrpServerHandleServiceUpdateResult(param_1,uVar2);
  return;
}

