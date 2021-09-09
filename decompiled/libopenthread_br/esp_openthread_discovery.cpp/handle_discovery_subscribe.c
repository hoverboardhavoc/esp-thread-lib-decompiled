/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  char acStack_1e9 [69];
  char acStack_1a4 [131];
  char acStack_121 [269];
  
  pcVar2 = strstr(param_2,".default.service.arpa.");
  __s = malloc(0x330);
  if (__s == (void *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC2,uVar3,"OPENTHREAD");
    return;
  }
  memset(__s,0,0x330);
  if (pcVar2 == (char *)0x0) {
    return;
  }
  uVar1 = (int)pcVar2 - (int)param_2;
  if (0xff < uVar1) {
    return;
  }
  memcpy(acStack_121 + 1,param_2,uVar1);
  acStack_121[uVar1 + 1] = '\0';
  sVar4 = strnlen(acStack_121 + 1,0x100);
  if (sVar4 == 0) {
    return;
  }
  if (acStack_121[sVar4] == '.') {
    sVar4 = sVar4 - 1;
  }
  for (__n = sVar4 - 1; -1 < (int)__n; __n = __n - 1) {
    if (acStack_121[__n + 1] == '.') {
      if (__n != 0) {
        if (0x81 < (int)__n) {
          return;
        }
        uVar1 = (sVar4 - 1) - __n;
        if (0x40 < uVar1) {
          return;
        }
        strncpy(acStack_1a4,acStack_121 + 1,__n);
        acStack_1a4[__n] = '\0';
        strncpy(acStack_1e9 + 1,acStack_121 + __n + 2,uVar1);
        acStack_1e9[uVar1 + 1] = '\0';
        goto _L0;
      }
      break;
    }
  }
  strncpy(acStack_1a4,acStack_121 + 1,0x82);
  acStack_1e9[1] = 0;
_L0:
  pcVar2 = strstr(acStack_121 + 1,"._tcp");
  if ((pcVar2 == (char *)0x0) && (pcVar2 = strstr(acStack_121 + 1,"._udp"), pcVar2 == (char *)0x0))
  {
    otLogInfo(0xc,"-PLAT----: ","subscribe host %s",acStack_1a4);
    uVar3 = mdns_query_async_new(acStack_1a4,0,0,0x1c,3000,1,handle_mdns_query_notifitcation);
    *(undefined4 *)((int)__s + 0x324) = uVar3;
    uVar3 = 2;
  }
  else {
    otLogInfo(0xc,"-PLAT----: ","subscribe %s.%s",acStack_1a4,acStack_1e9 + 1);
    pcVar2 = strchr(acStack_1a4,0x2e);
    if (pcVar2 == (char *)0x0) {
      uVar3 = mdns_query_async_new
                        (acStack_1a4,acStack_1e9 + 1,0xc,3000,5,handle_mdns_query_notifitcation);
      *(undefined4 *)((int)__s + 800) = uVar3;
      *(undefined4 *)((int)__s + 0x328) = 0;
      goto _L0;
    }
    *pcVar2 = '\0';
    uVar3 = mdns_query_async_new
                      (acStack_1a4,pcVar2 + 1,acStack_1e9 + 1,0x21,3000,1,
                       handle_mdns_query_notifitcation);
    *(undefined4 *)((int)__s + 800) = uVar3;
    uVar3 = mdns_query_async_new
                      (acStack_1a4,pcVar2 + 1,acStack_1e9 + 1,0x10,3000,1,
                       handle_mdns_query_notifitcation);
    *(undefined4 *)((int)__s + 0x324) = uVar3;
    uVar3 = 1;
  }
  *(undefined4 *)((int)__s + 0x328) = uVar3;
_L0:
  *(undefined4 *)((int)__s + 0x32c) = s_pending_queries._812_4_;
  s_pending_queries._812_4_ = __s;
  return;
}

