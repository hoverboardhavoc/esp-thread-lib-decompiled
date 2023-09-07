/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
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
    iVar2 = otBorderRoutingInit(*(char *)(s_netif + 0x18a) + '\x01',*(byte *)(s_netif + 0x187) & 1);
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

