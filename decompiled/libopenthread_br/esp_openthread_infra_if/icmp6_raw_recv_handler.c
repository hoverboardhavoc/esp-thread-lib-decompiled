/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> icmp6_raw_recv_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 icmp6_raw_recv_handler(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint __size;
  char *__ptr;
  undefined4 *puVar3;
  undefined1 auStack_38 [20];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  iVar2 = *(int *)(param_1 + 4);
  if (0x28 < *(ushort *)(param_1 + 8)) {
    memcpy(&uStack_24,(void *)(iVar2 + 8),0x10);
    memcpy(auStack_38,(void *)(iVar2 + 0x18),0x10);
    uStack_14 = uStack_14 & 0xffffff00;
    if ((((*(int *)(iVar2 + 0x18) == 0x2ff) && (*(int *)(iVar2 + 0x1c) == 0)) &&
        (*(int *)(iVar2 + 0x20) == 0)) &&
       (((*(int *)(iVar2 + 0x24) == 0x1000000 && (*(char *)(iVar2 + 7) == -1)) &&
        (*(char *)(iVar2 + 6) == ':')))) {
      uVar1 = *(short *)(param_1 + 8) - 0x28;
      __size = (uint)uVar1;
      __ptr = (char *)malloc(__size);
      if (__ptr == (char *)0x0) {
        otLogCrit(0xc,"-PLAT----: ","Failed to allocate icmp6 buffer");
      }
      else {
        pbuf_copy_partial(param_1,__ptr,__size,0x28);
        if ((byte)(*__ptr + 0x7bU) < 2) {
          if (*__ptr == -0x7a) {
            ra_recv_handler(__ptr,__size,&uStack_24);
          }
          puVar3 = (undefined4 *)malloc(0x1c);
          *puVar3 = uStack_24;
          puVar3[1] = uStack_20;
          puVar3[2] = uStack_1c;
          puVar3[3] = uStack_18;
          puVar3[4] = uStack_14;
          puVar3[5] = __ptr;
          *(ushort *)(puVar3 + 6) = uVar1;
          esp_openthread_task_queue_post(handle_netif_receive_task,puVar3);
          return 0;
        }
      }
      if (__ptr != (char *)0x0) {
        free(__ptr);
      }
    }
  }
  return 0;
}

