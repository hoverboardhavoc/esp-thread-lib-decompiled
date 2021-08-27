/*
 * Last changed at upstream commit c9af7b259218417072614ad265e7e896db15b49a
 * https://github.com/espressif/esp-thread-lib/commit/c9af7b259218417072614ad265e7e896db15b49a
 * Upstream date: 2021-08-27 13:57:40 +0800
 * Upstream subject: openthread: support ESP32-H2 chip(00e1885)
 * Source: libopenthread_port -> esp_openthread_misc.o -> otPlatAssertFail
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void otPlatAssertFail(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = esp_log_timestamp();
  esp_log_write(1,"OPENTHREAD",&_LC1,uVar1,"OPENTHREAD",param_1,param_2);
  __assert_func("//home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_misc.c"
                ,0x57,"otPlatAssertFail","false");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

