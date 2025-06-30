/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_nd6.o -> infra_if_raw_send_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int infra_if_raw_send_task(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = raw_sendto(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x18),param_1);
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log(2,"OPENTHREAD","W (%lu) %s: Failed to send ND6 message\n",uVar2);
    iVar1 = -1;
  }
  return iVar1;
}

