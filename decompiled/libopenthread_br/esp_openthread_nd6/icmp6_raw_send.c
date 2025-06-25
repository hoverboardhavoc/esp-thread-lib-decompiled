/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_nd6.o -> icmp6_raw_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 icmp6_raw_send(undefined4 param_1,void *param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined1 auStack_30 [20];
  undefined1 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_1c = 6;
  uStack_18 = param_3;
  memcpy(auStack_30,param_2,0x14);
  uStack_14 = param_1;
  if (param_4 == 0) {
    esp_openthread_task_switching_lock_release();
    uVar1 = esp_netif_tcpip_exec(infra_if_raw_send_task,auStack_30);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
  }
  else {
    uVar1 = infra_if_raw_send_task(auStack_30);
  }
  return uVar1;
}

