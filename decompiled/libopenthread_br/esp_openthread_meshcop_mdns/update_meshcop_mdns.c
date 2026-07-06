/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_meshcop_mdns.o -> update_meshcop_mdns
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void update_meshcop_mdns(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined1 uStack_115;
  undefined1 auStack_114 [256];
  undefined2 uStack_14;
  
  esp_openthread_get_instance();
  iVar1 = otBorderAgentGetMeshCoPServiceTxtData(auStack_114);
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    uVar5 = 0x2b;
    pcVar4 = "E (%lu) %s: %s(%d): Failed to get Openthread MeshCop raw TXT data\n";
_L13:
    esp_log(1,0x10000,pcVar4,uVar2,"update_meshcop_mdns",uVar5);
    return;
  }
  uStack_115 = 0;
  iVar1 = alloc_txt_list_with_explicit_value_len(auStack_114,uStack_14,&uStack_115);
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    uVar5 = 0x31;
    pcVar4 = "E (%lu) %s: %s(%d): Failed to allocate TXT items array\n";
    goto _L13;
  }
  esp_openthread_task_switching_lock_release();
  iVar3 = mdns_service_txt_set_with_explicit_txt_item_value_len("_meshcop",&_LC3,iVar1,uStack_115);
  if (iVar3 == 0) {
    iVar3 = mdns_service_txt_item_set("_meshcop",&_LC3,&_LC7,"BorderRouter");
    if (iVar3 == 0) {
      iVar3 = mdns_service_txt_item_set("_meshcop",&_LC3,&_LC10,"OpenThread");
      if (iVar3 == 0) goto _L6;
      uVar2 = esp_log_timestamp();
      uVar5 = 0x3d;
      pcVar4 = "E (%lu) %s: %s(%d): Failed to set vendor name in meshcop mdns service\n";
    }
    else {
      uVar2 = esp_log_timestamp();
      uVar5 = 0x3b;
      pcVar4 = "E (%lu) %s: %s(%d): Failed to set model name in meshcop mdns service\n";
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    uVar5 = 0x34;
    pcVar4 = "E (%lu) %s: %s(%d): Failed to update Openthread MeshCop TXT data\n";
  }
  esp_log(1,0x10000,pcVar4,uVar2,"update_meshcop_mdns",uVar5);
_L6:
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  free_txt_list_with_explicit_value_len(iVar1,uStack_115);
  return;
}

