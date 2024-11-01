/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> handle_discovery_subscribe
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* handle_discovery_subscribe(void*, char const*) */

void handle_discovery_subscribe(void *param_1,char *param_2)

{
  uint uVar1;
  size_t sVar2;
  uint __n;
  char *pcVar3;
  void *__s;
  undefined4 uVar4;
  size_t sVar5;
  char *pcVar6;
  char acStack_1e9 [69];
  char acStack_1a4 [131];
  char acStack_121 [265];
  
  pcVar3 = strstr(param_2,".default.service.arpa.");
  uVar1 = (int)pcVar3 - (int)param_2;
  if ((pcVar3 != (char *)0x0) && (uVar1 < 0x100)) {
    __s = malloc(0x3f0);
    if (__s == (void *)0x0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD","E (%lu) %s: Failed to create pending query\n",uVar4,"OPENTHREAD"
                   );
      return;
    }
    memset(__s,0,0x3f0);
    pcVar3 = acStack_121 + 1;
    memcpy(pcVar3,param_2,uVar1);
    acStack_121[uVar1 + 1] = '\0';
    sVar5 = strnlen(pcVar3,0x100);
    if (sVar5 == 0) {
_L0:
      free(__s);
      return;
    }
    sVar2 = sVar5 - 1;
    if (acStack_121[sVar5] != '.') {
      sVar2 = sVar5;
    }
    for (uVar1 = sVar2 - 1; -1 < (int)uVar1; uVar1 = uVar1 - 1) {
      if (pcVar3[uVar1] == '.') {
        if (uVar1 != 0) {
          if ((0x81 < uVar1) || (__n = (sVar2 - 1) - uVar1, 0x40 < __n)) goto _L0;
          strncpy(acStack_1a4,pcVar3,uVar1);
          acStack_1a4[uVar1] = '\0';
          strncpy(acStack_1e9 + 1,pcVar3 + uVar1 + 1,__n);
          acStack_1e9[__n + 1] = '\0';
          goto _L0;
        }
        break;
      }
    }
    strncpy(acStack_1a4,pcVar3,0x82);
    acStack_1e9[1] = 0;
_L0:
    pcVar6 = strstr(pcVar3,"._tcp");
    if ((pcVar6 == (char *)0x0) && (pcVar3 = strstr(pcVar3,"._udp"), pcVar3 == (char *)0x0)) {
      otLogInfoPlat("subscribe host %s",acStack_1a4);
      sVar5 = strnlen(acStack_1a4,0x40);
      memcpy((void *)((int)__s + 0x300),acStack_1a4,sVar5);
      uVar4 = mdns_query_async_new(acStack_1a4,0,0,0x1c,3000,1,handle_mdns_query_notifitcation);
      *(undefined4 *)((int)__s + 0x3e4) = uVar4;
      uVar4 = 2;
    }
    else {
      otLogInfoPlat("subscribe %s.%s",acStack_1a4,acStack_1e9 + 1);
      pcVar3 = strchr(acStack_1a4,0x2e);
      if (pcVar3 == (char *)0x0) {
        sVar5 = strnlen(acStack_1a4,0x40);
        memcpy((void *)((int)__s + 0x340),acStack_1a4,sVar5);
        sVar5 = strnlen(acStack_1e9 + 1,0x40);
        memcpy((void *)((int)__s + 0x380),acStack_1e9 + 1,sVar5);
        uVar4 = mdns_query_async_new
                          (0,acStack_1a4,acStack_1e9 + 1,0xc,3000,5,handle_mdns_query_notifitcation)
        ;
        *(undefined4 *)((int)__s + 0x3e0) = uVar4;
        uVar4 = 0;
      }
      else {
        pcVar6 = pcVar3 + 1;
        *pcVar3 = '\0';
        sVar5 = strnlen(acStack_1a4,0x40);
        memcpy((void *)((int)__s + 0x300),acStack_1a4,sVar5);
        sVar5 = strnlen(pcVar6,0x40);
        memcpy((void *)((int)__s + 0x340),pcVar6,sVar5);
        sVar5 = strnlen(acStack_1e9 + 1,0x40);
        memcpy((void *)((int)__s + 0x380),acStack_1e9 + 1,sVar5);
        uVar4 = mdns_query_async_new
                          (acStack_1a4,pcVar6,acStack_1e9 + 1,0x21,3000,1,
                           handle_mdns_query_notifitcation);
        *(undefined4 *)((int)__s + 0x3e0) = uVar4;
        uVar4 = mdns_query_async_new
                          (acStack_1a4,pcVar6,acStack_1e9 + 1,0x10,3000,1,
                           handle_mdns_query_notifitcation);
        *(undefined4 *)((int)__s + 0x3e4) = uVar4;
        uVar4 = 1;
      }
    }
    *(undefined4 *)((int)__s + 1000) = uVar4;
    *(undefined4 *)((int)__s + 0x3ec) = s_pending_queries._1004_4_;
    s_pending_queries._1004_4_ = __s;
  }
  return;
}

