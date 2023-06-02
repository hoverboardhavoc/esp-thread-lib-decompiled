/*
 * Last changed at upstream commit e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * https://github.com/espressif/esp-thread-lib/commit/e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * Upstream date: 2023-06-02 12:00:23 +0800
 * Upstream subject: ot br lib: fix issues in certification esp-openthread: a158ca1 openthread:091f68e
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> otPlatInfraIfSendIcmp6Nd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatInfraIfSendIcmp6Nd(void *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  void *__ptr;
  int iVar2;
  int iVar3;
  undefined1 auStack_34 [16];
  undefined4 uStack_24;
  
  __ptr = malloc(0x1c);
  iVar2 = pbuf_alloc(0x36,param_3,0x280);
  if (__ptr == (void *)0x0) {
    uVar1 = 3;
    if (iVar2 != 0) {
_L0:
      pbuf_free(iVar2);
      return uVar1;
    }
  }
  else {
    if (iVar2 != 0) {
      uStack_24 = 0;
      memcpy(auStack_34,param_1,0x10);
      iVar3 = pbuf_take(iVar2,param_2,param_3);
      if (iVar3 == 0) {
        *(undefined1 *)((int)__ptr + 0x14) = 6;
        *(int *)((int)__ptr + 0x18) = iVar2;
        memcpy(__ptr,auStack_34,0x14);
        tcpip_callback(infra_if_raw_send_task,__ptr);
        return 0;
      }
      free(__ptr);
      uVar1 = 1;
      goto _L0;
    }
    free(__ptr);
  }
  return 3;
}

