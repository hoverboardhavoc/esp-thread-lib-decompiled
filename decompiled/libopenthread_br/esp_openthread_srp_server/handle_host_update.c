/*
 * Last changed at upstream commit e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * https://github.com/espressif/esp-thread-lib/commit/e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * Upstream date: 2023-06-02 12:00:23 +0800
 * Upstream subject: ot br lib: fix issues in certification esp-openthread: a158ca1 openthread:091f68e
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
  void *__s1;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  undefined4 *__s;
  int iVar10;
  undefined1 *puVar11;
  undefined *puVar12;
  uint __n;
  size_t __n_00;
  uint uVar13;
  undefined1 uVar14;
  size_t __n_01;
  undefined4 *puVar15;
  size_t sVar16;
  undefined1 uStack_183;
  undefined2 uStack_182;
  char acStack_180 [8];
  char *pcStack_178;
  char *pcStack_174;
  ushort uStack_170;
  undefined1 auStack_16c [16];
  undefined1 uStack_15c;
  undefined1 uStack_158;
  undefined4 uStack_154;
  undefined1 auStack_150 [68];
  char acStack_10c [68];
  char acStack_c8 [68];
  undefined1 auStack_84 [16];
  byte bStack_74;
  
  otSrpServerHostGetFullName(param_2);
  split_hostname_constprop_0(auStack_150);
  uVar1 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC1,uVar1,"OPENTHREAD",auStack_150);
  iVar2 = mdns_hostname_exists(auStack_150);
  if (iVar2 == 0) {
    __s1 = (void *)otSrpServerHostGetAddresses(param_2,&uStack_183);
    if (__s1 != (void *)0x0) goto _L0;
_L0:
    uVar1 = esp_log_timestamp();
    puVar12 = &_LC5;
  }
  else {
    iVar3 = mdns_delegate_hostname_remove(auStack_150);
    if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
    __s1 = (void *)otSrpServerHostGetAddresses(param_2,&uStack_183);
    if (__s1 != (void *)0x0) {
_L0:
      esp_openthread_get_instance();
      iVar3 = otBorderRoutingGetOmrPrefix(auStack_84);
      if ((iVar3 == 0) && (iVar3 = memcmp(__s1,auStack_84,(uint)(bStack_74 >> 3)), iVar3 == 0)) {
        uStack_158 = 6;
        memcpy(auStack_16c,__s1,0x10);
        uStack_15c = 0;
        uStack_154 = 0;
        if (iVar2 == 0) {
          uVar1 = esp_log_timestamp();
          uVar4 = ip6addr_ntoa(auStack_16c);
          puVar12 = &_LC4;
        }
        else {
          uVar1 = esp_log_timestamp();
          uVar4 = ip6addr_ntoa(auStack_16c);
          puVar12 = &_LC3;
        }
        esp_log_write(3,"OPENTHREAD",puVar12,uVar1,"OPENTHREAD",uVar4);
        puVar11 = auStack_16c;
        goto _L0;
      }
      if (iVar2 == 0) goto _L0;
    }
    uVar1 = esp_log_timestamp();
    puVar12 = &_LC2;
  }
  esp_log_write(3,"OPENTHREAD",puVar12,uVar1,"OPENTHREAD");
  puVar11 = (undefined1 *)0x0;
_L0:
  iVar3 = mdns_delegate_hostname_add(auStack_150,puVar11);
  iVar2 = 0;
  do {
    iVar2 = otSrpServerHostFindNextService(param_2,iVar2,0xd,0,0);
    if (iVar2 == 0) {
      uVar14 = iVar3 != 0;
      goto _L0;
    }
    pcVar5 = (char *)otSrpServerServiceGetFullName();
    pcVar6 = strchr(pcVar5,0x2e);
    sVar16 = (int)pcVar6 - (int)pcVar5;
    if (0x40 < sVar16) {
      sVar16 = 0x40;
    }
    pcVar6 = pcVar6 + 1;
    pcVar7 = strchr(pcVar6,0x2e);
    __n_01 = (int)pcVar7 - (int)pcVar6;
    if (0x40 < __n_01) {
      __n_01 = 0x40;
    }
    pcVar7 = pcVar7 + 1;
    pcVar8 = strchr(pcVar7,0x2e);
    __n_00 = (int)pcVar8 - (int)pcVar7;
    if (5 < __n_00) {
      __n_00 = 5;
    }
    strncpy(acStack_10c,pcVar5,sVar16);
    acStack_10c[sVar16] = '\0';
    strncpy(acStack_c8,pcVar6,__n_01);
    acStack_c8[__n_01] = '\0';
    strncpy(acStack_180,pcVar7,__n_00);
    acStack_180[__n_00] = '\0';
    uVar1 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC6,uVar1,"OPENTHREAD",acStack_10c,acStack_c8,acStack_180);
    iVar9 = otSrpServerServiceIsDeleted(iVar2);
    if ((iVar9 == 0) &&
       (iVar9 = mdns_service_exists_with_instance(acStack_10c,acStack_c8,acStack_180,auStack_150),
       iVar9 == 0)) {
      uVar1 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC7,uVar1,"OPENTHREAD");
      uStack_182 = 0;
      uVar1 = otSrpServerServiceGetTxtData(iVar2,&uStack_182);
      otDnsInitTxtEntryIterator(auStack_84,uVar1,uStack_182);
      uVar13 = 0;
      while (iVar9 = otDnsGetNextTxtEntry(auStack_84,&pcStack_178), iVar9 == 0) {
        uVar13 = uVar13 + 1 & 0xff;
      }
      if (uVar13 == 0) {
        __s = (undefined4 *)0x0;
      }
      else {
        __s = (undefined4 *)malloc(uVar13 << 3);
        if (__s == (undefined4 *)0x0) {
_L0:
          uVar14 = 3;
          goto _L0;
        }
        memset(__s,0,uVar13 << 3);
        otDnsInitTxtEntryIterator(auStack_84,uVar1,uStack_182);
        puVar15 = __s;
        while (iVar9 = otDnsGetNextTxtEntry(auStack_84,&pcStack_178), iVar9 == 0) {
          pcVar6 = (char *)malloc(0x41);
          pcVar5 = pcStack_178;
          if ((pcVar6 == (char *)0x0) || (sVar16 = strnlen(pcStack_178,0x41), 0x40 < sVar16)) {
_L0:
            free_txt_list(__s,uVar13);
            goto _L0;
          }
          strncpy(pcVar6,pcVar5,0x40);
          pcVar6[0x40] = '\0';
          *puVar15 = pcVar6;
          pcVar5 = (char *)malloc(0x41);
          if ((pcVar5 == (char *)0x0) || (__n = (uint)uStack_170, 0x40 < __n)) goto _L0;
          strncpy(pcVar5,pcStack_174,__n);
          puVar15[1] = pcVar5;
          pcVar5[__n] = '\0';
          puVar15 = puVar15 + 2;
        }
      }
      uVar1 = otSrpServerServiceGetPort(iVar2);
      iVar9 = mdns_service_add_for_host
                        (acStack_10c,acStack_c8,acStack_180,auStack_150,uVar1,__s,uVar13);
      free_txt_list(__s,uVar13);
      if (iVar9 == 0) {
        iVar9 = 0;
_L0:
        uVar1 = otSrpServerServiceGetInstanceName(iVar2);
        iVar9 = otSrpServerHostFindNextService(param_2,iVar9,6,0,uVar1);
        if (iVar9 != 0) {
          iVar10 = otSrpServerServiceGetServiceSubTypeLabel(auStack_84,0x41);
          if (iVar10 == 0) goto _L0;
          uVar1 = esp_log_timestamp();
          puVar12 = &_LC11;
          goto _L0;
        }
        goto _L0;
      }
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC8,uVar1,"OPENTHREAD");
      break;
    }
    iVar9 = otSrpServerServiceIsDeleted(iVar2);
    if ((iVar9 != 0) &&
       (iVar9 = mdns_service_remove_for_host(acStack_10c,acStack_c8,acStack_180,auStack_150),
       iVar9 != 0)) break;
_L0:
  } while (iVar3 == 0);
  uVar14 = 1;
_L0:
  esp_openthread_get_instance();
  otSrpServerHandleServiceUpdateResult(param_1,uVar14);
  return;
_L0:
  uVar1 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC9,uVar1,"OPENTHREAD",auStack_84);
  iVar10 = mdns_service_subtype_add_for_host
                     (acStack_10c,acStack_c8,acStack_180,auStack_150,auStack_84);
  if (iVar10 != 0) {
    uVar1 = esp_log_timestamp();
    puVar12 = &_LC10;
_L0:
    esp_log_write(1,"OPENTHREAD",puVar12,uVar1,"OPENTHREAD");
  }
  goto _L0;
}

