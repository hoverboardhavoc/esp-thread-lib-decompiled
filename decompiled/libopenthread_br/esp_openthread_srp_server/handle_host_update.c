/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> handle_host_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_host_update(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  void *__src;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  undefined4 *__s;
  uint __n;
  undefined *puVar11;
  uint uVar12;
  size_t __n_00;
  undefined4 *puVar13;
  size_t __n_01;
  size_t sVar14;
  undefined2 uStack_166;
  char acStack_164 [8];
  char *pcStack_15c;
  char *pcStack_158;
  ushort uStack_154;
  undefined1 auStack_150 [68];
  char acStack_10c [68];
  char acStack_c8 [68];
  undefined1 auStack_84 [16];
  undefined1 uStack_74;
  undefined1 uStack_70;
  undefined4 uStack_6c;
  
  otSrpServerHostGetFullName(param_2);
  split_hostname_constprop_0(auStack_150);
  uVar2 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC1,uVar2,"OPENTHREAD",auStack_150);
  iVar3 = mdns_hostname_exists(auStack_150);
  uVar1 = false;
  if (iVar3 == 0) {
    __src = (void *)otSrpServerHostGetAddresses(param_2,acStack_c8);
    uStack_70 = 6;
    memcpy(auStack_84,__src,0x10);
    uStack_74 = 0;
    uStack_6c = 0;
    uVar2 = esp_log_timestamp();
    uVar4 = ip6addr_ntoa(auStack_84);
    esp_log_write(3,"OPENTHREAD",&_LC2,uVar2,"OPENTHREAD",uVar4);
    iVar3 = mdns_delegate_hostname_add(auStack_150,auStack_84);
    uVar1 = iVar3 != 0;
  }
  iVar3 = 0;
  do {
    iVar3 = otSrpServerHostFindNextService(param_2,iVar3,0xd,0,0);
    if (iVar3 == 0) goto _L0;
    pcVar6 = (char *)otSrpServerServiceGetFullName();
    pcVar7 = strchr(pcVar6,0x2e);
    sVar14 = (int)pcVar7 - (int)pcVar6;
    if (0x40 < sVar14) {
      sVar14 = 0x40;
    }
    pcVar7 = pcVar7 + 1;
    pcVar8 = strchr(pcVar7,0x2e);
    __n_00 = (int)pcVar8 - (int)pcVar7;
    if (0x40 < __n_00) {
      __n_00 = 0x40;
    }
    pcVar8 = pcVar8 + 1;
    pcVar9 = strchr(pcVar8,0x2e);
    __n_01 = (int)pcVar9 - (int)pcVar8;
    if (5 < __n_01) {
      __n_01 = 5;
    }
    strncpy(acStack_10c,pcVar6,sVar14);
    acStack_10c[sVar14] = '\0';
    strncpy(acStack_c8,pcVar7,__n_00);
    acStack_c8[__n_00] = '\0';
    strncpy(acStack_164,pcVar8,__n_01);
    acStack_164[__n_01] = '\0';
    uVar2 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC3,uVar2,"OPENTHREAD",acStack_10c,acStack_c8,acStack_164);
    iVar10 = otSrpServerServiceIsDeleted(iVar3);
    if ((iVar10 == 0) &&
       (iVar10 = mdns_service_exists_with_instance(acStack_10c,acStack_c8,acStack_164,auStack_150),
       iVar10 == 0)) {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC4,uVar2,"OPENTHREAD");
      uStack_166 = 0;
      uVar2 = otSrpServerServiceGetTxtData(iVar3,&uStack_166);
      otDnsInitTxtEntryIterator(auStack_84,uVar2,uStack_166);
      uVar12 = 0;
      while (iVar10 = otDnsGetNextTxtEntry(auStack_84,&pcStack_15c), iVar10 == 0) {
        uVar12 = uVar12 + 1 & 0xff;
      }
      if (uVar12 == 0) {
        __s = (undefined4 *)0x0;
      }
      else {
        __s = (undefined4 *)malloc(uVar12 << 3);
        if (__s == (undefined4 *)0x0) {
_L0:
          uVar1 = 3;
          goto _L0;
        }
        memset(__s,0,uVar12 << 3);
        otDnsInitTxtEntryIterator(auStack_84,uVar2,uStack_166);
        puVar13 = __s;
        while (iVar10 = otDnsGetNextTxtEntry(auStack_84,&pcStack_15c), iVar10 == 0) {
          pcVar7 = (char *)malloc(0x41);
          pcVar6 = pcStack_15c;
          if ((pcVar7 == (char *)0x0) || (sVar14 = strnlen(pcStack_15c,0x41), 0x40 < sVar14)) {
_L0:
            free_txt_list(__s,uVar12);
            goto _L0;
          }
          strncpy(pcVar7,pcVar6,0x40);
          pcVar7[0x40] = '\0';
          *puVar13 = pcVar7;
          pcVar6 = (char *)malloc(0x41);
          if ((pcVar6 == (char *)0x0) || (__n = (uint)uStack_154, 0x40 < __n)) goto _L0;
          strncpy(pcVar6,pcStack_158,__n);
          puVar13[1] = pcVar6;
          pcVar6[__n] = '\0';
          puVar13 = puVar13 + 2;
        }
      }
      uVar2 = otSrpServerServiceGetPort(iVar3);
      iVar10 = mdns_service_add_for_host
                         (acStack_10c,acStack_c8,acStack_164,auStack_150,uVar2,__s,uVar12);
      free_txt_list(__s,uVar12);
      if (iVar10 == 0) {
        iVar10 = 0;
_L0:
        uVar2 = otSrpServerServiceGetInstanceName(iVar3);
        iVar10 = otSrpServerHostFindNextService(param_2,iVar10,6,0,uVar2);
        if (iVar10 != 0) {
          iVar5 = otSrpServerServiceGetServiceSubTypeLabel(auStack_84,0x41);
          if (iVar5 == 0) goto _L0;
          uVar2 = esp_log_timestamp();
          puVar11 = &_LC8;
          goto _L0;
        }
        goto _L0;
      }
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC5,uVar2,"OPENTHREAD");
      break;
    }
    iVar10 = otSrpServerServiceIsDeleted(iVar3);
    if ((iVar10 != 0) &&
       (iVar10 = mdns_service_remove_for_host(acStack_10c,acStack_c8,acStack_164,auStack_150),
       iVar10 != 0)) break;
_L0:
  } while ((bool)uVar1 == false);
  uVar1 = 1;
_L0:
  esp_openthread_get_instance();
  otSrpServerHandleServiceUpdateResult(param_1,uVar1);
  return;
_L0:
  uVar2 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC6,uVar2,"OPENTHREAD",auStack_84);
  iVar5 = mdns_service_subtype_add_for_host
                    (acStack_10c,acStack_c8,acStack_164,auStack_150,auStack_84);
  if (iVar5 != 0) {
    uVar2 = esp_log_timestamp();
    puVar11 = &_LC7;
_L0:
    esp_log_write(1,"OPENTHREAD",puVar11,uVar2,"OPENTHREAD");
  }
  goto _L0;
}

