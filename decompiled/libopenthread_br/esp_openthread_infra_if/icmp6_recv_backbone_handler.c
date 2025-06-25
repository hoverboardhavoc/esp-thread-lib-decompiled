/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> icmp6_recv_backbone_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 icmp6_recv_backbone_handler(int param_1)

{
  int iVar1;
  void *__ptr;
  undefined4 uVar2;
  void *__dest;
  ushort uVar3;
  int iVar4;
  
  if (0x28 < *(ushort *)(param_1 + 8)) {
    iVar4 = *(int *)(param_1 + 4);
    iVar1 = icmp6_raw_recv_handler(s_netif);
    if (iVar1 == 0) {
      uVar3 = *(short *)(param_1 + 8) - 0x28;
      __ptr = malloc((uint)uVar3);
      if (__ptr == (void *)0x0) {
        uVar2 = esp_log_timestamp();
        esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to allocate a buffer for payload\n",uVar2,
                "OPENTHREAD");
      }
      else {
        pbuf_copy_partial(param_1,__ptr,(uint)uVar3,0x28);
        __dest = malloc(0x1c);
        if (__dest == (void *)0x0) {
          uVar2 = esp_log_timestamp();
          esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to allocate a buffer for netif reception\n",
                  uVar2,"OPENTHREAD");
          __dest = __ptr;
        }
        else {
          *(ushort *)((int)__dest + 0x18) = uVar3;
          *(void **)((int)__dest + 0x14) = __ptr;
          memcpy(__dest,(void *)(iVar4 + 8),0x14);
          iVar1 = esp_openthread_task_queue_post(handle_netif_receive_task,__dest);
          if (iVar1 == 0) {
            return 0;
          }
          uVar2 = esp_log_timestamp();
          esp_log(2,"OPENTHREAD","W (%lu) %s: Failed to send task to ot queue\n",uVar2,"OPENTHREAD")
          ;
          free(__ptr);
        }
        free(__dest);
      }
    }
  }
  return 0;
}

