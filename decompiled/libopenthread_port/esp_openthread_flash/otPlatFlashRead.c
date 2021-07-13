/*
 * Last changed at upstream commit d84f8967f8ce14490e19433b85c8c363d424f4c1
 * https://github.com/espressif/esp-thread-lib/commit/d84f8967f8ce14490e19433b85c8c363d424f4c1
 * Upstream date: 2021-07-13 21:21:08 +0800
 * Upstream subject: openthread: add ot library for esp32h2
 * Source: libopenthread_port -> esp_openthread_flash.o -> otPlatFlashRead
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void otPlatFlashRead(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0x1000;
  }
  iVar1 = esp_partition_read(s_ot_partition,iVar1 + param_2,param_3,param_4);
  if (iVar1 == 0) {
    return;
  }
  pcVar3 = "err == ESP_OK";
  pcVar2 = "otPlatFlashRead";
  iVar1 = __assert_func("/home/chenshu/code/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                        ,0x3e,"otPlatFlashRead","err == ESP_OK");
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0x1000;
  }
  iVar1 = esp_partition_write(s_ot_partition,pcVar2 + iVar1,pcVar3,param_4);
  if (iVar1 == 0) {
    return;
  }
  __assert_func("/home/chenshu/code/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                ,0x49,"otPlatFlashWrite","err == ESP_OK");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

