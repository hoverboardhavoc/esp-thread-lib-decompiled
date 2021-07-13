/*
 * Last changed at upstream commit d84f8967f8ce14490e19433b85c8c363d424f4c1
 * https://github.com/espressif/esp-thread-lib/commit/d84f8967f8ce14490e19433b85c8c363d424f4c1
 * Upstream date: 2021-07-13 21:21:08 +0800
 * Upstream subject: openthread: add ot library for esp32h2
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
  __assert_func("/home/chenshu/code/esp-openthread/components/openthread_port/src/esp_openthread_misc.c"
                ,0x56,"otPlatAssertFail","false");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

