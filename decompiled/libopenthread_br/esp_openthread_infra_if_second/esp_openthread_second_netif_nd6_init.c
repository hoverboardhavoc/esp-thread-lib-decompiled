/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_infra_if_second.o -> esp_openthread_second_netif_nd6_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_second_netif_nd6_init(int param_1,void *param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  memcpy(s_netif_prefix,param_2,0x10);
  iVar1 = 0x103;
  s_netif_prefix[0x10] = param_3;
  if ((s_raw_pcb == 0) && (iVar1 = 0x102, param_1 != 0)) {
    s_netif = esp_netif_get_netif_impl(param_1);
    esp_openthread_task_switching_lock_release();
    iVar1 = esp_netif_tcpip_exec(second_netif_do_init,0);
    if (iVar1 == 0) {
      iVar1 = esp_netif_tcpip_exec(notify_lwip_send_ra,0);
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to initialize the second netif\n",uVar2,
              "OPENTHREAD");
    }
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    if (iVar1 == 0) {
      esp_openthread_get_instance();
      iVar1 = otSetStateChangedCallback(br_second_netif_callback,0);
      iVar1 = -(uint)(iVar1 != 0);
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log(1,"OPENTHREAD","E (%lu) %s: Unable to notify lwip to send RA\n",uVar2,"OPENTHREAD");
    }
  }
  return iVar1;
}

