/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_flash.o -> otPlatFlashWrite
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void otPlatFlashWrite(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0x1000;
  }
  iVar1 = esp_partition_write(s_ot_partition,iVar1 + param_2,param_3,param_4);
  if (iVar1 == 0) {
    return;
  }
  __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                ,0x49,"otPlatFlashWrite","err == ESP_OK");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

