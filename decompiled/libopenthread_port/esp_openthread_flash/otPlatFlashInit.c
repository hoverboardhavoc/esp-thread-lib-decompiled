/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_flash.o -> otPlatFlashInit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */
/* WARNING: Enum "esp_partition_subtype_t": Some values do not have unique names */

void otPlatFlashInit(otInstance *instance)

{
  uint uVar1;
  uint32_t uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 in_a4;
  
  s_ot_partition = (esp_partition_t *)esp_partition_find_first(1,0xff,"ot_storage");
  if (s_ot_partition == (esp_partition_t *)0x0) {
    __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                  ,0x1e,"otPlatFlashInit","s_ot_partition != NULL");
  }
  else {
    uVar1 = s_ot_partition->size;
    uVar2 = otPlatFlashGetSwapSize(instance);
    if (uVar2 <= uVar1) {
      return;
    }
  }
  iVar3 = __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                        ,0x1f,"otPlatFlashInit",
                        "s_ot_partition->size >= otPlatFlashGetSwapSize(instance)");
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x1000;
  }
  iVar3 = esp_partition_erase_range(s_ot_partition,uVar4,0x1000);
  if (iVar3 == 0) {
    return;
  }
  pcVar6 = "err == ESP_OK";
  pcVar5 = "otPlatFlashErase";
  iVar3 = __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                        ,0x2f,"otPlatFlashErase","err == ESP_OK");
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0x1000;
  }
  iVar3 = esp_partition_read(s_ot_partition,pcVar5 + iVar3,pcVar6,in_a4);
  if (iVar3 == 0) {
    return;
  }
  pcVar6 = "err == ESP_OK";
  pcVar5 = "otPlatFlashRead";
  iVar3 = __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                        ,0x3a,"otPlatFlashRead","err == ESP_OK");
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0x1000;
  }
  iVar3 = esp_partition_write(s_ot_partition,pcVar5 + iVar3,pcVar6,in_a4);
  if (iVar3 == 0) {
    return;
  }
  __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                ,0x45,"otPlatFlashWrite","err == ESP_OK");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

