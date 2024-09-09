/*
 * Last changed at upstream commit 56af58057c259405aa90c478e294f6216cc2f6db
 * https://github.com/espressif/esp-thread-lib/commit/56af58057c259405aa90c478e294f6216cc2f6db
 * Upstream date: 2024-09-09 14:04:56 +0200
 * Upstream subject: update(ot_lib): Rebuild with lwip 2.2.0-esp
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
  
  if ((s_nat64_netif_initialized == '\0') || ((s_nat64_netif[0x20f] & 1) != 0)) {
    memset(s_nat64_netif,0,0x230);
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

