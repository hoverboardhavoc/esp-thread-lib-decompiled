/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_flash.o -> otPlatFlashErase
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatFlashErase(int param_1)

{
  int iVar1;
  
  iVar1 = esp_partition_erase_range(s_ot_partition,(uint)(param_1 != 0) << 0xc,0x1000);
  if (iVar1 != 0) {
    __assert_func(0,0,0,0);
  }
  return;
}

