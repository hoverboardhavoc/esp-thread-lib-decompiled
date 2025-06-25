/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_nd6.o -> infra_if_raw_send_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 infra_if_raw_send_task(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = raw_sendto(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x18),param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log(2,"OPENTHREAD","W (%lu) %s: Failed to send ND6 message\n",uVar2,"OPENTHREAD");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

