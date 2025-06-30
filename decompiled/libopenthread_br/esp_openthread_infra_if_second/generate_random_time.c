/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_infra_if_second.o -> generate_random_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int generate_random_time(uint param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 < param_2) {
    uVar1 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Invalid jitter\n",uVar1,"generate_random_time",0x8a)
    ;
    iVar2 = 0x2ee;
  }
  else {
    uVar3 = esp_random();
    iVar2 = uVar3 % (param_2 * 2 + 1) + (param_1 - param_2);
  }
  return iVar2;
}

