/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_misc.o -> otPlatGetResetReason
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatGetResetReason(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = esp_reset_reason();
  uVar2 = 2;
  if (uVar1 != 3) {
    if (uVar1 < 4) {
      uVar2 = 0;
      if ((uVar1 != 1) && (uVar2 = 1, uVar1 < 2)) {
        uVar2 = 7;
      }
    }
    else {
      uVar2 = 3;
      if ((uVar1 != 4) && (uVar2 = 6, uVar1 < 8)) {
        uVar2 = 8;
      }
    }
  }
  return uVar2;
}

