/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_flash.o -> otPlatFlashInit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void otPlatFlashInit(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (s_ot_partition == 0) {
    __assert_func("//home/zhangwenxu/ieee802154/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                  ,0x22,"otPlatFlashInit","s_ot_partition != NULL");
  }
  else {
    uVar1 = *(uint *)(s_ot_partition + 0x10);
    uVar2 = otPlatFlashGetSwapSize();
    if (uVar2 <= uVar1) {
      return;
    }
  }
  iVar3 = __assert_func("//home/zhangwenxu/ieee802154/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                        ,0x23,"otPlatFlashInit",
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
  iVar3 = __assert_func("//home/zhangwenxu/ieee802154/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                        ,0x33,"otPlatFlashErase","err == ESP_OK");
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0x1000;
  }
  iVar3 = esp_partition_read(s_ot_partition,pcVar5 + iVar3,pcVar6,param_1);
  if (iVar3 == 0) {
    return;
  }
  pcVar6 = "err == ESP_OK";
  pcVar5 = "otPlatFlashRead";
  iVar3 = __assert_func("//home/zhangwenxu/ieee802154/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                        ,0x3e,"otPlatFlashRead","err == ESP_OK");
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0x1000;
  }
  iVar3 = esp_partition_write(s_ot_partition,pcVar5 + iVar3,pcVar6,param_1);
  if (iVar3 == 0) {
    return;
  }
  __assert_func("//home/zhangwenxu/ieee802154/esp-openthread/components/openthread_port/src/esp_openthread_flash.c"
                ,0x49,"otPlatFlashWrite","err == ESP_OK");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

