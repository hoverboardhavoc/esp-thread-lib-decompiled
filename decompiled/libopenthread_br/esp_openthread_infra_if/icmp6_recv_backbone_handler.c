/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> icmp6_recv_backbone_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 icmp6_recv_backbone_handler(int param_1)

{
  ushort uVar1;
  int iVar2;
  void *__ptr;
  undefined4 uVar3;
  void *__dest;
  int iVar4;
  
  if (0x28 < *(ushort *)(param_1 + 8)) {
    iVar4 = *(int *)(param_1 + 4);
    iVar2 = icmp6_raw_recv_handler(s_netif);
    if (iVar2 == 0) {
      uVar1 = *(short *)(param_1 + 8) - 0x28;
      __ptr = malloc((uint)uVar1);
      if (__ptr == (void *)0x0) {
        uVar3 = esp_log_timestamp();
        esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to allocate a buffer for payload\n",uVar3);
      }
      else {
        pbuf_copy_partial(param_1,__ptr,(uint)uVar1,0x28);
        __dest = malloc(0x1c);
        if (__dest == (void *)0x0) {
          uVar3 = esp_log_timestamp();
          esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to allocate a buffer for netif reception\n",
                  uVar3);
          __dest = __ptr;
        }
        else {
          *(ushort *)((int)__dest + 0x18) = uVar1;
          *(void **)((int)__dest + 0x14) = __ptr;
          memcpy(__dest,(void *)(iVar4 + 8),0x14);
          iVar2 = esp_openthread_task_queue_post(handle_netif_receive_task,__dest);
          if (iVar2 == 0) {
            return 0;
          }
          uVar3 = esp_log_timestamp();
          esp_log(2,"OPENTHREAD","W (%lu) %s: Failed to send task to ot queue\n",uVar3);
          free(__ptr);
        }
        free(__dest);
      }
    }
  }
  return 0;
}

