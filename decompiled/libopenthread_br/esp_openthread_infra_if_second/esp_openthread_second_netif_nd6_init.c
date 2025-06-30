/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_infra_if_second.o -> esp_openthread_second_netif_nd6_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_second_netif_nd6_init(int param_1,void *param_2,undefined1 param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  
  pvVar2 = memcpy(s_netif_prefix,param_2,0x10);
  iVar4 = s_raw_pcb;
  *(undefined1 *)((int)pvVar2 + 0x10) = param_3;
  iVar1 = 0x103;
  if ((iVar4 == 0) && (iVar1 = 0x102, param_1 != 0)) {
    s_netif = esp_netif_get_netif_impl(param_1);
    esp_openthread_task_switching_lock_release();
    iVar1 = esp_netif_tcpip_exec(second_netif_do_init,0);
    if (iVar1 == 0) {
      iVar1 = esp_netif_tcpip_exec(notify_lwip_send_ra,0);
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to initialize the second netif\n",uVar3);
    }
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    if (iVar1 == 0) {
      esp_openthread_get_instance();
      iVar4 = otSetStateChangedCallback(br_second_netif_callback,0);
      iVar1 = -(uint)(iVar4 != 0);
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log(1,"OPENTHREAD","E (%lu) %s: Unable to notify lwip to send RA\n",uVar3);
    }
  }
  return iVar1;
}

