/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> otPlatInfraIfSendIcmp6Nd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatInfraIfSendIcmp6Nd(void *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *__ptr;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  __ptr = (undefined4 *)malloc(0x1c);
  iVar1 = pbuf_alloc(0x36,param_3,0x280);
  if (__ptr == (undefined4 *)0x0) {
    uVar3 = 3;
  }
  else if (iVar1 == 0) {
    uVar3 = 3;
  }
  else {
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    memcpy(&uStack_34,param_1,0x10);
    iVar2 = pbuf_take(iVar1,param_2,param_3);
    if (iVar2 == 0) {
      __ptr[6] = iVar1;
      *(undefined1 *)(__ptr + 5) = 6;
      *__ptr = uStack_34;
      __ptr[1] = uStack_30;
      __ptr[2] = uStack_2c;
      __ptr[3] = uStack_28;
      __ptr[4] = uStack_24;
      tcpip_callback(infra_if_raw_send_task,__ptr);
      iVar1 = 0;
      __ptr = (undefined4 *)0x0;
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  if (__ptr != (undefined4 *)0x0) {
    free(__ptr);
  }
  if (iVar1 != 0) {
    pbuf_free(iVar1);
  }
  return uVar3;
}

