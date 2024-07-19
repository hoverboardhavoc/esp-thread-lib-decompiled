/*
 * Last changed at upstream commit 203c78501e9a6ea9ca3a929e6f9b6b9691ef16ee
 * https://github.com/espressif/esp-thread-lib/commit/203c78501e9a6ea9ca3a929e6f9b6b9691ef16ee
 * Upstream date: 2024-07-19 18:50:00 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> esp_openthread_infra_if_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_infra_if_init(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (s_raw_pcb == 0) {
    if (param_1 == 0) {
      return 0x102;
    }
    s_netif = param_1;
    esp_openthread_task_switching_lock_release();
    uVar1 = esp_netif_tcpip_exec(0x10000,0);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    esp_openthread_get_instance();
    iVar2 = otBorderRoutingInit(*(char *)(s_netif + 0x20e) + '\x01',*(byte *)(s_netif + 0x20b) & 1);
    if (iVar2 == 0) {
      esp_openthread_get_instance();
      iVar2 = otBorderRoutingSetEnabled(1);
      if (iVar2 == 0) {
        return uVar1;
      }
    }
  }
  return 0x103;
}

