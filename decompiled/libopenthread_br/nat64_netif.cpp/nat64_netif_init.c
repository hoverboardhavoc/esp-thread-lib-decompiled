/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
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
  
  if ((s_nat64_netif_initialized == '\0') || ((s_nat64_netif[0x187] & 1) != 0)) {
    memset(s_nat64_netif,0,0x1a4);
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

