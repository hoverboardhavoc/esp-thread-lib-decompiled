/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
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
  size_t __n;
  char *pcVar2;
  void *__s;
  undefined4 uVar3;
  size_t sVar4;
  char acStack_1d9 [69];
  char acStack_194 [131];
  char acStack_111 [257];
  
  pcVar2 = strstr(param_2,".default.service.arpa.");
  uVar1 = (int)pcVar2 - (int)param_2;
  if ((pcVar2 != (char *)0x0) && (uVar1 < 0x100)) {
    __s = malloc(0x330);
    if (__s == (void *)0x0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC2,uVar3,"OPENTHREAD");
      return;
    }
    memset(__s,0,0x330);
    memcpy(acStack_111 + 1,param_2,uVar1);
    acStack_111[uVar1 + 1] = '\0';
    sVar4 = strnlen(acStack_111 + 1,0x100);
    if (sVar4 == 0) {
_L0:
      free(__s);
      return;
    }
    if (acStack_111[sVar4] == '.') {
      sVar4 = sVar4 - 1;
    }
    for (__n = sVar4 - 1; -1 < (int)__n; __n = __n - 1) {
      if (acStack_111[__n + 1] == '.') {
        if (__n != 0) {
          if ((0x81 < (int)__n) || (uVar1 = (sVar4 - 1) - __n, 0x40 < uVar1)) goto _L0;
          strncpy(acStack_194,acStack_111 + 1,__n);
          acStack_194[__n] = '\0';
          strncpy(acStack_1d9 + 1,acStack_111 + __n + 2,uVar1);
          acStack_1d9[uVar1 + 1] = '\0';
          goto _L0;
        }
        break;
      }
    }
    strncpy(acStack_194,acStack_111 + 1,0x82);
    acStack_1d9[1] = 0;
_L0:
    pcVar2 = strstr(acStack_111 + 1,"._tcp");
    if ((pcVar2 == (char *)0x0) && (pcVar2 = strstr(acStack_111 + 1,"._udp"), pcVar2 == (char *)0x0)
       ) {
      otLogInfoPlat("subscribe host %s",acStack_194);
      uVar3 = mdns_query_async_new(acStack_194,0,0,0x1c,3000,1,handle_mdns_query_notifitcation);
      *(undefined4 *)((int)__s + 0x324) = uVar3;
      uVar3 = 2;
    }
    else {
      otLogInfoPlat("subscribe %s.%s",acStack_194,acStack_1d9 + 1);
      pcVar2 = strchr(acStack_194,0x2e);
      if (pcVar2 == (char *)0x0) {
        uVar3 = mdns_query_async_new
                          (acStack_194,acStack_1d9 + 1,0xc,3000,5,handle_mdns_query_notifitcation);
        *(undefined4 *)((int)__s + 800) = uVar3;
        uVar3 = 0;
      }
      else {
        *pcVar2 = '\0';
        uVar3 = mdns_query_async_new
                          (acStack_194,acStack_1d9 + 1,0x21,3000,1,handle_mdns_query_notifitcation);
        *(undefined4 *)((int)__s + 800) = uVar3;
        uVar3 = mdns_query_async_new
                          (acStack_194,pcVar2 + 1,acStack_1d9 + 1,0x10,3000,1,
                           handle_mdns_query_notifitcation);
        *(undefined4 *)((int)__s + 0x324) = uVar3;
        uVar3 = 1;
      }
    }
    *(undefined4 *)((int)__s + 0x328) = uVar3;
    *(undefined4 *)((int)__s + 0x32c) = s_pending_queries._812_4_;
    s_pending_queries._812_4_ = __s;
  }
  return;
}

