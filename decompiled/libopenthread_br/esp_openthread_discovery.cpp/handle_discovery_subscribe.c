/*
 * Last changed at upstream commit e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * https://github.com/espressif/esp-thread-lib/commit/e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * Upstream date: 2023-06-02 12:00:23 +0800
 * Upstream subject: ot br lib: fix issues in certification esp-openthread: a158ca1 openthread:091f68e
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
  char *pcVar3;
  void *__s;
  undefined4 uVar4;
  size_t sVar5;
  char acStack_1d9 [69];
  char acStack_194 [131];
  char acStack_111 [257];
  
  pcVar3 = strstr(param_2,".default.service.arpa.");
  uVar1 = (int)pcVar3 - (int)param_2;
  if ((pcVar3 != (char *)0x0) && (uVar1 < 0x100)) {
    __s = malloc(0x330);
    if (__s == (void *)0x0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC2,uVar4,"OPENTHREAD");
      return;
    }
    memset(__s,0,0x330);
    memcpy(acStack_111 + 1,param_2,uVar1);
    acStack_111[uVar1 + 1] = '\0';
    sVar5 = strnlen(acStack_111 + 1,0x100);
    if (sVar5 == 0) {
_L0:
      free(__s);
      return;
    }
    sVar2 = sVar5 - 1;
    if (acStack_111[sVar5] != '.') {
      sVar2 = sVar5;
    }
    for (sVar5 = sVar2 - 1; -1 < (int)sVar5; sVar5 = sVar5 - 1) {
      if (acStack_111[sVar5 + 1] == '.') {
        if (sVar5 != 0) {
          if ((0x81 < (int)sVar5) || (uVar1 = (sVar2 - 1) - sVar5, 0x40 < uVar1)) goto _L0;
          strncpy(acStack_194,acStack_111 + 1,sVar5);
          acStack_194[sVar5] = '\0';
          strncpy(acStack_1d9 + 1,acStack_111 + sVar5 + 2,uVar1);
          acStack_1d9[uVar1 + 1] = '\0';
          goto _L0;
        }
        break;
      }
    }
    strncpy(acStack_194,acStack_111 + 1,0x82);
    acStack_1d9[1] = 0;
_L0:
    pcVar3 = strstr(acStack_111 + 1,"._tcp");
    if ((pcVar3 == (char *)0x0) && (pcVar3 = strstr(acStack_111 + 1,"._udp"), pcVar3 == (char *)0x0)
       ) {
      otLogInfoPlat("subscribe host %s",acStack_194);
      uVar4 = mdns_query_async_new(acStack_194,0,0,0x1c,3000,1,handle_mdns_query_notifitcation);
      *(undefined4 *)((int)__s + 0x324) = uVar4;
      uVar4 = 2;
    }
    else {
      otLogInfoPlat("subscribe %s.%s",acStack_194,acStack_1d9 + 1);
      pcVar3 = strchr(acStack_194,0x2e);
      if (pcVar3 == (char *)0x0) {
        uVar4 = mdns_query_async_new
                          (acStack_194,acStack_1d9 + 1,0xc,3000,5,handle_mdns_query_notifitcation);
        *(undefined4 *)((int)__s + 800) = uVar4;
        uVar4 = 0;
      }
      else {
        *pcVar3 = '\0';
        uVar4 = mdns_query_async_new
                          (acStack_194,acStack_1d9 + 1,0x21,3000,1,handle_mdns_query_notifitcation);
        *(undefined4 *)((int)__s + 800) = uVar4;
        uVar4 = mdns_query_async_new
                          (acStack_194,pcVar3 + 1,acStack_1d9 + 1,0x10,3000,1,
                           handle_mdns_query_notifitcation);
        *(undefined4 *)((int)__s + 0x324) = uVar4;
        uVar4 = 1;
      }
    }
    *(undefined4 *)((int)__s + 0x328) = uVar4;
    *(undefined4 *)((int)__s + 0x32c) = s_pending_queries._812_4_;
    s_pending_queries._812_4_ = __s;
  }
  return;
}

