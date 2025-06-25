/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_border_router_state_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_border_router_state_callback(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 auStack_24 [20];
  
  esp_openthread_get_instance();
  iVar1 = otBorderRoutingGetNat64Prefix(auStack_24);
  if (iVar1 == 0) {
    if (s_nat64_initialized != '\0') {
      iVar1 = nat64_netif_get();
      if ((*(byte *)(iVar1 + 0x20f) & 1) != 0) goto _L0;
    }
    iVar1 = nat64_init();
    if (iVar1 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log(3,0x10000,"I (%lu) %s: NAT64 ready\n",uVar2,0x10000);
      s_nat64_initialized = '\x01';
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: Failed to initialize NAT64\n",uVar2,0x10000);
    }
  }
_L0:
  if (param_1 << 7 < 0) {
    uVar2 = esp_openthread_get_instance();
    esp_openthread_get_instance();
    uVar3 = otIp6IsEnabled();
    otBackboneRouterSetEnabled(uVar2,uVar3);
  }
  if (-1 < param_1 << 6) {
    return;
  }
  esp_openthread_get_instance();
  uVar4 = otBackboneRouterGetState();
  if (uVar4 < 2) {
    esp_openthread_multicast_forwarding_set_enabled(0);
    return;
  }
  if (uVar4 != 2) {
    uVar2 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: Unknown backbone border router state\n",uVar2,0x10000);
    return;
  }
  esp_openthread_multicast_forwarding_set_enabled(1);
  esp_openthread_task_switching_lock_release();
  tcpip_callback(multicast_probe_task,0);
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  return;
}

