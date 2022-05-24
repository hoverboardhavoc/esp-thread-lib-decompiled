/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_misc.o -> otPlatReset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatReset(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  esp_restart();
  uVar1 = esp_reset_reason();
  uVar2 = 3;
  if (uVar1 != 4) {
    if (uVar1 < 5) {
      uVar2 = 1;
      if ((((uVar1 != 2) && (uVar2 = 2, uVar1 != 3)) && (uVar2 = 7, uVar1 != 0)) &&
         (uVar2 = 6, uVar1 == 1)) {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 8;
      if (2 < uVar1 - 5) {
        uVar2 = 6;
      }
    }
  }
  return uVar2;
}

