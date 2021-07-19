/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_port -> esp_openthread_misc.o -> otPlatAssertFail
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void otPlatAssertFail(undefined4 param_1,undefined4 param_2)

{
  otLogCrit(0xc,"-PLAT----: ","Assert failed at %s:%d",param_1,param_2);
  __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_misc.c"
                ,0x56,"otPlatAssertFail","false");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

