/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_logging.o -> otPlatLog
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatLog(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_14 = param_3;
  uStack_10 = param_4;
  uStack_c = param_5;
  uStack_8 = param_6;
  uStack_4 = param_7;
  if (param_1 == 2) {
    uVar1 = esp_log_timestamp();
    esp_log_write(2,0x10000,&_LC3,uVar1,0x10000);
    esp_log_writev(2,0x10000,param_2,&uStack_14);
    uVar1 = 2;
  }
  else if (param_1 < 3) {
    if (param_1 != 1) {
      return;
    }
    uVar1 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar1,0x10000);
    esp_log_writev(1,0x10000,param_2,&uStack_14);
    uVar1 = 1;
  }
  else {
    if (1 < param_1 - 3U) {
      return;
    }
    uVar1 = esp_log_timestamp();
    esp_log_write(3,0x10000,&_LC4,uVar1,0x10000);
    esp_log_writev(3,0x10000,param_2,&uStack_14);
    uVar1 = 3;
  }
  esp_log_write(uVar1,0x10000,&_LC2);
  return;
}

