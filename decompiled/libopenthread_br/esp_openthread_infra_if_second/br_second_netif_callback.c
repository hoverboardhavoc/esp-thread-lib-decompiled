/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_infra_if_second.o -> br_second_netif_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void br_second_netif_callback(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 & 4) == 0) {
    return;
  }
  esp_openthread_get_instance();
  iVar2 = otThreadGetDeviceRole();
  esp_openthread_task_switching_lock_release();
  uVar3 = 1;
  if (2 < iVar2 - 2U) {
    iVar1 = 0;
    if (iVar2 != 0) goto _L0;
    uVar3 = 3;
  }
  iVar1 = esp_netif_tcpip_exec(notify_lwip_send_ra,uVar3);
_L0:
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  if (iVar1 != 0) {
    uVar3 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Failed to notify lwip to send RA\n",uVar3,
            "OPENTHREAD","br_second_netif_callback",0xe0);
    return;
  }
  return;
}

