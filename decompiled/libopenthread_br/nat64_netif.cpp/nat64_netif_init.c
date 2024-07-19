/*
 * Last changed at upstream commit 203c78501e9a6ea9ca3a929e6f9b6b9691ef16ee
 * https://github.com/espressif/esp-thread-lib/commit/203c78501e9a6ea9ca3a929e6f9b6b9691ef16ee
 * Upstream date: 2024-07-19 18:50:00 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> nat64_netif.cpp.o -> nat64_netif_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nat64_netif_init(void)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if ((s_nat64_netif_initialized == '\0') || ((s_nat64_netif[0x20b] & 1) != 0)) {
    memset(s_nat64_netif,0,0x228);
    esp_openthread_task_switching_lock_release();
    pcVar1 = nat64_netif_do_init;
  }
  else {
    esp_openthread_task_switching_lock_release();
    pcVar1 = nat64_rebind_netif;
  }
  uVar2 = esp_netif_tcpip_exec(pcVar1,0);
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  return uVar2;
}

