/*
 * Last changed at upstream commit ea50a6be280755ad026c0b1774efe61c48171ad6
 * https://github.com/espressif/esp-thread-lib/commit/ea50a6be280755ad026c0b1774efe61c48171ad6
 * Upstream date: 2021-09-03 15:31:55 +0800
 * Upstream subject: br: add discovery delegate(f7cecf0)
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> handle_discovery_subscribe
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* handle_discovery_subscribe(void*, char const*) */

void handle_discovery_subscribe(void *param_1,char *param_2)

{
  char *pcVar1;
  void *__s;
  int iVar2;
  undefined4 uVar3;
  uint __n;
  char acStack_1e8 [68];
  char acStack_1a4 [132];
  char acStack_120 [268];
  
  pcVar1 = strstr(param_2,".default.service.arpa.");
  __n = (int)pcVar1 - (int)param_2;
  __s = malloc(0x330);
  if (__s == (void *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC6,uVar3,"OPENTHREAD");
  }
  else {
    memset(__s,0,0x330);
    if ((pcVar1 != (char *)0x0) && (__n < 0x100)) {
      memcpy(acStack_120,param_2,__n);
      acStack_120[__n] = '\0';
      iVar2 = split_prefix_suffix(acStack_120,acStack_1a4,0x82,acStack_1e8,0x41);
      if (iVar2 != 0) {
        iVar2 = is_service_name(acStack_120);
        if (iVar2 == 0) {
          otLogInfo(0xc,"-PLAT----: ","subscribe host %s",acStack_1a4);
          uVar3 = mdns_query_async_new(acStack_1a4,0,0,0x1c,3000,1,handle_mdns_query_notifitcation);
          *(undefined4 *)((int)__s + 0x324) = uVar3;
          *(undefined4 *)((int)__s + 0x328) = 2;
        }
        else {
          otLogInfo(0xc,"-PLAT----: ","subscribe %s.%s",acStack_1a4,acStack_1e8);
          pcVar1 = strchr(acStack_1a4,0x2e);
          if (pcVar1 == (char *)0x0) {
            uVar3 = mdns_query_async_new
                              (0,acStack_1a4,acStack_1e8,0xc,3000,5,handle_mdns_query_notifitcation)
            ;
            *(undefined4 *)((int)__s + 800) = uVar3;
            *(undefined4 *)((int)__s + 0x328) = 0;
          }
          else {
            *pcVar1 = '\0';
            uVar3 = mdns_query_async_new
                              (acStack_1a4,pcVar1 + 1,acStack_1e8,0x21,3000,1,
                               handle_mdns_query_notifitcation);
            *(undefined4 *)((int)__s + 800) = uVar3;
            uVar3 = mdns_query_async_new
                              (acStack_1a4,pcVar1 + 1,acStack_1e8,0x10,3000,1,
                               handle_mdns_query_notifitcation);
            *(undefined4 *)((int)__s + 0x324) = uVar3;
            *(undefined4 *)((int)__s + 0x328) = 1;
          }
        }
        *(undefined4 *)((int)__s + 0x32c) = s_pending_queries._812_4_;
        s_pending_queries._812_4_ = __s;
      }
    }
  }
  return;
}

