/*
 * Last changed at upstream commit 70a7322bfe4dd130c7cf9a94b8dbbeb0dbae0687
 * https://github.com/espressif/esp-thread-lib/commit/70a7322bfe4dd130c7cf9a94b8dbbeb0dbae0687
 * Upstream date: 2026-04-10 09:53:42 +0000
 * Upstream subject: feat(openthread/lib): update thread-lib for upstream a98813b30
 * Source: libopenthread_br -> esp_openthread_infra_if.cpp.o -> dhcp6_pd_recv_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* dhcp6_pd_recv_cb(void*, udp_pcb*, pbuf*, ip_addr const*, unsigned short) */

void dhcp6_pd_recv_cb(void *param_1,udp_pcb *param_2,pbuf *param_3,ip_addr *param_4,ushort param_5)

{
  int iVar1;
  undefined4 uVar2;
  void *__ptr;
  undefined4 uVar3;
  int iVar4;
  uint __size;
  char *pcVar5;
  undefined2 in_register_0000203a;
  undefined2 auStack_24 [6];
  
  uVar2 = esp_openthread_get_instance();
  auStack_24[0] = 0x100;
  if (CONCAT22(in_register_0000203a,param_5) != 0x223) {
    if (param_3 == (pbuf *)0x0) {
      return;
    }
    goto _L36;
  }
  if (param_3 == (pbuf *)0x0) {
    return;
  }
  __size = (uint)*(ushort *)(param_3 + 8);
  if (__size == 0) goto _L36;
  __ptr = malloc(__size);
  if (__ptr == (void *)0x0) {
    uVar3 = esp_log_timestamp();
    uVar2 = 300;
    pcVar5 = "E (%lu) %s: %s(%d): Failed to allocate buffer\n";
_L55:
    esp_log(1,"OPENTHREAD",pcVar5,uVar3,"dhcp6_pd_recv_cb",uVar2);
    iVar1 = 0;
_L43:
    uVar2 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: Finished dhcp6_pd_recv_cb with some errors\n",uVar2);
    if (__ptr != (void *)0x0) goto _L44;
  }
  else {
    pbuf_copy_partial(param_3,__ptr,__size,0);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    iVar1 = otUdpNewMessage(uVar2,auStack_24);
    if (iVar1 == 0) {
      uVar3 = esp_log_timestamp();
      uVar2 = 0x131;
      pcVar5 = "E (%lu) %s: %s(%d): Failed to allocate otMessage\n";
      goto _L55;
    }
    iVar4 = otMessageAppend(__ptr,*(undefined2 *)(param_3 + 8));
    if (iVar4 != 0) {
      uVar2 = esp_log_timestamp();
      esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Failed to append to message\n",uVar2,
              "dhcp6_pd_recv_cb",0x132);
      goto _L43;
    }
    otPlatInfraIfDhcp6PdClientHandleReceived(uVar2,iVar1,param_2[0x30]);
    iVar1 = 0;
    esp_openthread_task_switching_lock_release();
_L44:
    free(__ptr);
  }
  if (iVar1 != 0) {
    otMessageFree(iVar1);
  }
_L36:
  pbuf_free(param_3);
  return;
}

