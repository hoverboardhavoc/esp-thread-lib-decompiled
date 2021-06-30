/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_logging.o -> otPlatLog
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void otPlatLog(otLogLevel log_level,otLogRegion log_region,char *format,...)

{
  undefined4 uVar1;
  undefined4 in_a3;
  undefined4 in_a4;
  undefined4 in_a5;
  undefined4 in_a6;
  undefined4 in_a7;
  va_list args;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_14 = in_a3;
  uStack_10 = in_a4;
  uStack_c = in_a5;
  uStack_8 = in_a6;
  uStack_4 = in_a7;
  if (log_level == 2) {
    uVar1 = esp_log_timestamp();
    esp_log_write(2,"OPENTHREAD",&_LC3,uVar1,"OPENTHREAD");
    esp_log_writev(2,"OPENTHREAD",format,&uStack_14);
    esp_log_write(2,"OPENTHREAD",&_LC2);
  }
  else if (log_level < 3) {
    if (log_level == 1) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC1,uVar1,"OPENTHREAD");
      esp_log_writev(1,"OPENTHREAD",format,&uStack_14);
      esp_log_write(1,"OPENTHREAD",&_LC2);
    }
  }
  else if (log_level < 5) {
    uVar1 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC4,uVar1,"OPENTHREAD");
    esp_log_writev(3,"OPENTHREAD",format,&uStack_14);
    esp_log_write(3,"OPENTHREAD",&_LC2);
  }
  return;
}

