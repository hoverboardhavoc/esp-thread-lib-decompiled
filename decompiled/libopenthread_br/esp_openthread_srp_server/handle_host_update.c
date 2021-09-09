/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> handle_host_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_host_update(undefined4 param_1,undefined4 param_2)

{
  size_t __n;
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  void *__src;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  undefined4 *__s;
  undefined1 uVar10;
  size_t __n_00;
  uint __n_01;
  size_t sVar11;
  undefined4 *puVar12;
  undefined2 uStack_136;
  char acStack_134 [8];
  char *pcStack_12c;
  char *pcStack_128;
  ushort uStack_124;
  undefined1 auStack_120 [20];
  undefined1 auStack_10c [68];
  char acStack_c8 [68];
  char acStack_84 [80];
  
  otSrpServerHostGetFullName(param_2);
  split_hostname_constprop_3(auStack_10c);
  uVar2 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC1,uVar2,"OPENTHREAD",auStack_10c);
  iVar3 = mdns_hostname_exists(auStack_10c);
  uVar10 = false;
  if (iVar3 == 0) {
    __src = (void *)otSrpServerHostGetAddresses(param_2,acStack_c8);
    acStack_84[0x14] = 6;
    memcpy(acStack_84,__src,0x10);
    acStack_84[0x10] = 0;
    acStack_84[0x18] = '\0';
    acStack_84[0x19] = '\0';
    acStack_84[0x1a] = '\0';
    acStack_84[0x1b] = '\0';
    uVar2 = esp_log_timestamp();
    uVar4 = ip6addr_ntoa(acStack_84);
    esp_log_write(3,"OPENTHREAD",&_LC2,uVar2,"OPENTHREAD",uVar4);
    iVar3 = mdns_delegate_hostname_add(auStack_10c,acStack_84);
    uVar10 = iVar3 != 0;
  }
  iVar3 = 0;
  do {
    iVar3 = otSrpServerHostGetNextService(param_2,iVar3);
    if (iVar3 == 0) break;
    pcVar5 = (char *)otSrpServerServiceGetFullName();
    pcVar6 = strchr(pcVar5,0x2e);
    sVar11 = (int)pcVar6 - (int)pcVar5;
    if (0x40 < sVar11) {
      sVar11 = 0x40;
    }
    pcVar6 = pcVar6 + 1;
    pcVar7 = strchr(pcVar6,0x2e);
    __n_00 = (int)pcVar7 - (int)pcVar6;
    if (0x40 < __n_00) {
      __n_00 = 0x40;
    }
    pcVar7 = pcVar7 + 1;
    pcVar8 = strchr(pcVar7,0x2e);
    __n = (int)pcVar8 - (int)pcVar7;
    if (5 < __n) {
      __n = 5;
    }
    strncpy(acStack_c8,pcVar5,sVar11);
    acStack_c8[sVar11] = '\0';
    strncpy(acStack_84,pcVar6,__n_00);
    acStack_84[__n_00] = '\0';
    strncpy(acStack_134,pcVar7,__n);
    acStack_134[__n] = '\0';
    uVar2 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC3,uVar2,"OPENTHREAD",acStack_c8,acStack_84,acStack_134);
    iVar9 = otSrpServerServiceIsDeleted(iVar3);
    if ((iVar9 == 0) &&
       (iVar9 = mdns_service_exists(acStack_84,acStack_134,auStack_10c), iVar9 == 0)) {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC4,uVar2,"OPENTHREAD");
      uVar2 = otSrpServerServiceGetPort(iVar3);
      iVar9 = mdns_service_add_for_host(acStack_c8,acStack_84,acStack_134,auStack_10c,uVar2,0,0);
_L0:
      if (iVar9 != 0) {
        uVar10 = 1;
        break;
      }
    }
    else {
      iVar9 = otSrpServerServiceIsDeleted(iVar3);
      if (iVar9 != 0) {
        iVar9 = mdns_service_remove_for_host(acStack_84,acStack_134,auStack_10c);
        goto _L0;
      }
    }
    uStack_136 = 0;
    uVar2 = otSrpServerServiceGetTxtData(iVar3,&uStack_136);
    otDnsInitTxtEntryIterator(auStack_120,uVar2,uStack_136);
    uVar1 = 0;
    while (iVar9 = otDnsGetNextTxtEntry(auStack_120,&pcStack_12c), iVar9 == 0) {
      uVar1 = uVar1 + 1 & 0xff;
    }
    if (uVar1 != 0) {
      __s = (undefined4 *)malloc(uVar1 << 3);
      if (__s == (undefined4 *)0x0) {
_L0:
        uVar10 = 3;
        break;
      }
      memset(__s,0,uVar1 << 3);
      otDnsInitTxtEntryIterator(auStack_120,uVar2,uStack_136);
      puVar12 = __s;
      while (iVar9 = otDnsGetNextTxtEntry(auStack_120,&pcStack_12c), iVar9 == 0) {
        pcVar5 = (char *)malloc(0x41);
        if ((pcVar5 == (char *)0x0) || (sVar11 = strnlen(pcStack_12c,0x41), 0x40 < sVar11)) {
_L0:
          free_txt_list_part_0(__s,uVar1);
          goto _L0;
        }
        strncpy(pcVar5,pcStack_12c,0x40);
        pcVar5[0x40] = '\0';
        *puVar12 = pcVar5;
        pcVar5 = (char *)malloc(0x41);
        if (pcVar5 == (char *)0x0) goto _L0;
        __n_01 = (uint)uStack_124;
        if (0x40 < __n_01) goto _L0;
        strncpy(pcVar5,pcStack_128,__n_01);
        pcVar5[__n_01] = '\0';
        puVar12[1] = pcVar5;
        puVar12 = puVar12 + 2;
      }
      iVar9 = mdns_service_txt_set_for_host(acStack_84,acStack_134,auStack_10c,__s,uVar1);
      if (iVar9 != 0) {
        uVar10 = true;
      }
      free_txt_list_part_0(__s,uVar1);
    }
  } while ((bool)uVar10 == false);
  esp_openthread_get_instance();
  otSrpServerHandleServiceUpdateResult(param_1,uVar10);
  return;
}

