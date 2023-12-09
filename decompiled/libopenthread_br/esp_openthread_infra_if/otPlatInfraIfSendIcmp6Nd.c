/*
 * Last changed at upstream commit b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * https://github.com/espressif/esp-thread-lib/commit/b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * Upstream date: 2023-12-09 16:01:37 +0800
 * Upstream subject: feat(br): update border router lib     esp-openthread: 8d18b44     openthread: 41ef807
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> otPlatInfraIfSendIcmp6Nd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatInfraIfSendIcmp6Nd(void *param_1,undefined4 param_2,undefined4 param_3)

{
  void *__ptr;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_34 [16];
  undefined4 uStack_24;
  
  __ptr = malloc(0x1c);
  iVar1 = pbuf_alloc(0x36,param_3,0x280);
  if (__ptr == (void *)0x0) {
    uVar3 = 3;
  }
  else {
    if (iVar1 == 0) {
      uVar3 = 3;
    }
    else {
      uStack_24 = 0;
      memcpy(auStack_34,param_1,0x10);
      iVar2 = pbuf_take(iVar1,param_2,param_3);
      uVar3 = 1;
      if (iVar2 == 0) {
        *(undefined1 *)((int)__ptr + 0x14) = 6;
        *(int *)((int)__ptr + 0x18) = iVar1;
        memcpy(__ptr,auStack_34,0x14);
        tcpip_callback(infra_if_raw_send_task,__ptr);
        return 0;
      }
    }
    free(__ptr);
  }
  if (iVar1 != 0) {
    pbuf_free(iVar1);
  }
  return uVar3;
}

