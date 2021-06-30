/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_flash.o -> otPlatFlashErase
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */
/* WARNING: Enum "esp_partition_subtype_t": Some values do not have unique names */

void otPlatFlashErase(otInstance *instance,uint8_t index)

{
  int iVar1;
  undefined3 in_register_0000202d;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 in_a4;
  
  if (CONCAT31(in_register_0000202d,index) == 0) {
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
  iVar1 = __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                        ,0x2f,"otPlatFlashErase","err == ESP_OK");
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0x1000;
  }
  iVar1 = esp_partition_read(s_ot_partition,pcVar3 + iVar1,pcVar4,in_a4);
  if (iVar1 == 0) {
    return;
  }
  pcVar4 = "err == ESP_OK";
  pcVar3 = "otPlatFlashRead";
  iVar1 = __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                        ,0x3a,"otPlatFlashRead","err == ESP_OK");
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0x1000;
  }
  iVar1 = esp_partition_write(s_ot_partition,pcVar3 + iVar1,pcVar4,in_a4);
  if (iVar1 == 0) {
    return;
  }
  __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                ,0x45,"otPlatFlashWrite","err == ESP_OK");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

