/*
 * Last changed at upstream commit d84f8967f8ce14490e19433b85c8c363d424f4c1
 * https://github.com/espressif/esp-thread-lib/commit/d84f8967f8ce14490e19433b85c8c363d424f4c1
 * Upstream date: 2021-07-13 21:21:08 +0800
 * Upstream subject: openthread: add ot library for esp32h2
 * Source: libopenthread_port -> esp_openthread_flash.o -> otPlatFlashErase
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void otPlatFlashErase(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x1000;
  }
  iVar1 = esp_partition_erase_range(s_ot_partition,uVar2,0x1000);
  if (iVar1 == 0) {
    return;
  }
  pcVar4 = "err == ESP_OK";
  pcVar3 = "otPlatFlashErase";
  iVar1 = __assert_func("/home/chenshu/code/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                        ,0x33,"otPlatFlashErase","err == ESP_OK");
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0x1000;
  }
  iVar1 = esp_partition_read(s_ot_partition,pcVar3 + iVar1,pcVar4,param_2);
  if (iVar1 == 0) {
    return;
  }
  pcVar4 = "err == ESP_OK";
  pcVar3 = "otPlatFlashRead";
  iVar1 = __assert_func("/home/chenshu/code/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                        ,0x3e,"otPlatFlashRead","err == ESP_OK");
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0x1000;
  }
  iVar1 = esp_partition_write(s_ot_partition,pcVar3 + iVar1,pcVar4,param_2);
  if (iVar1 == 0) {
    return;
  }
  __assert_func("/home/chenshu/code/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                ,0x49,"otPlatFlashWrite","err == ESP_OK");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

