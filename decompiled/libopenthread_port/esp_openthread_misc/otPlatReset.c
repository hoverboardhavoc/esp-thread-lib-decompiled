/*
 * Last changed at upstream commit d84f8967f8ce14490e19433b85c8c363d424f4c1
 * https://github.com/espressif/esp-thread-lib/commit/d84f8967f8ce14490e19433b85c8c363d424f4c1
 * Upstream date: 2021-07-13 21:21:08 +0800
 * Upstream subject: openthread: add ot library for esp32h2
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
  if (uVar1 == 3) {
    uVar2 = 2;
  }
  else if (uVar1 < 4) {
    if (uVar1 == 1) {
      uVar2 = 0;
    }
    else if (uVar1 < 2) {
      uVar2 = 7;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (uVar1 == 5) {
    uVar2 = 8;
  }
  else if (uVar1 < 5) {
    uVar2 = 3;
  }
  else if (uVar1 == 6) {
    uVar2 = 8;
  }
  else if (uVar1 == 7) {
    uVar2 = 8;
  }
  else {
    uVar2 = 6;
  }
  return uVar2;
}

