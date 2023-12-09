/*
 * Last changed at upstream commit b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * https://github.com/espressif/esp-thread-lib/commit/b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * Upstream date: 2023-12-09 16:01:37 +0800
 * Upstream subject: feat(br): update border router lib     esp-openthread: 8d18b44     openthread: 41ef807
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
  char *__string;
  char acStack_1e9 [69];
  char acStack_1a4 [131];
  char acStack_121 [265];
  
  pcVar3 = strstr(param_2,".default.service.arpa.");
  uVar1 = (int)pcVar3 - (int)param_2;
  if ((pcVar3 != (char *)0x0) && (uVar1 < 0x100)) {
    __s = malloc(0x3f0);
    if (__s == (void *)0x0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC5,uVar4,"OPENTHREAD");
      return;
    }
    memset(__s,0,0x3f0);
    memcpy(acStack_121 + 1,param_2,uVar1);
    acStack_121[uVar1 + 1] = '\0';
    sVar5 = strnlen(acStack_121 + 1,0x100);
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
      if (acStack_121[uVar1 + 1] == '.') {
        if (uVar1 != 0) {
          if ((0x81 < uVar1) || (__n = (sVar2 - 1) - uVar1, 0x40 < __n)) goto _L0;
          strncpy(acStack_1a4,acStack_121 + 1,uVar1);
          acStack_1a4[uVar1] = '\0';
          strncpy(acStack_1e9 + 1,acStack_121 + uVar1 + 2,__n);
          acStack_1e9[__n + 1] = '\0';
          goto _L0;
        }
        break;
      }
    }
    strncpy(acStack_1a4,acStack_121 + 1,0x82);
    acStack_1e9[1] = 0;
_L0:
    pcVar3 = strstr(acStack_121 + 1,"._tcp");
    if ((pcVar3 == (char *)0x0) && (pcVar3 = strstr(acStack_121 + 1,"._udp"), pcVar3 == (char *)0x0)
       ) {
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
        __string = pcVar3 + 1;
        *pcVar3 = '\0';
        sVar5 = strnlen(acStack_1a4,0x40);
        memcpy((void *)((int)__s + 0x300),acStack_1a4,sVar5);
        sVar5 = strnlen(__string,0x40);
        memcpy((void *)((int)__s + 0x340),__string,sVar5);
        sVar5 = strnlen(acStack_1e9 + 1,0x40);
        memcpy((void *)((int)__s + 0x380),acStack_1e9 + 1,sVar5);
        uVar4 = mdns_query_async_new
                          (acStack_1a4,__string,acStack_1e9 + 1,0x21,3000,1,
                           handle_mdns_query_notifitcation);
        *(undefined4 *)((int)__s + 0x3e0) = uVar4;
        uVar4 = mdns_query_async_new
                          (acStack_1a4,__string,acStack_1e9 + 1,0x10,3000,1,
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

