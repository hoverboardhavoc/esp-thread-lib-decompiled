/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
    esp_log_write(2,"OPENTHREAD",&_LC3,uVar1,"OPENTHREAD");
    esp_log_writev(2,"OPENTHREAD",param_2,&uStack_14);
    esp_log_write(2,"OPENTHREAD",&_LC2);
  }
  else if (param_1 < 3) {
    if (param_1 == 1) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC1,uVar1,"OPENTHREAD");
      esp_log_writev(1,"OPENTHREAD",param_2,&uStack_14);
      esp_log_write(1,"OPENTHREAD",&_LC2);
    }
  }
  else if (param_1 < 5) {
    uVar1 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC4,uVar1,"OPENTHREAD");
    esp_log_writev(3,"OPENTHREAD",param_2,&uStack_14);
    esp_log_write(3,"OPENTHREAD",&_LC2);
  }
  return;
}

