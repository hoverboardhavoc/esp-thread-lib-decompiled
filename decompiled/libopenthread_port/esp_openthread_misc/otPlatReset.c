/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_misc.o -> otPlatReset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatReset(void)

{
  undefined4 uVar1;
  
  esp_restart();
  uVar1 = esp_reset_reason();
  switch(uVar1) {
  case 0:
    uVar1 = 7;
    break;
  case 1:
    uVar1 = 0;
    break;
  case 2:
    uVar1 = 1;
    break;
  case 3:
    uVar1 = 2;
    break;
  case 4:
    uVar1 = 3;
    break;
  case 5:
    uVar1 = 8;
    break;
  case 6:
    uVar1 = 8;
    break;
  case 7:
    uVar1 = 8;
    break;
  default:
    uVar1 = 6;
  }
  return uVar1;
}

