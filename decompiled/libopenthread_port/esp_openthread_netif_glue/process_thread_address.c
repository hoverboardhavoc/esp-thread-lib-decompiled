/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> process_thread_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void process_thread_address(undefined4 *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  bool bVar6;
  void *__src;
  undefined1 auStack_4c [20];
  undefined1 auStack_38 [20];
  byte bStack_24;
  
  pcVar2 = (char *)*param_1;
  cVar1 = *pcVar2;
  if (((*(int *)(pcVar2 + 8) == -0x1000000) && (*(short *)(pcVar2 + 0xc) == 0xfe)) &&
     (iVar3 = is_mesh_local_addr(), iVar3 != 0)) {
    return;
  }
  __src = (void *)*param_1;
  memcpy(auStack_4c,__src,0x10);
  if (param_2 == 0) {
    if (cVar1 == -1) {
      iVar3 = esp_event_post(7);
      if (iVar3 == 0) {
        return;
      }
      uVar4 = esp_log_timestamp();
      puVar5 = &_LC22;
    }
    else {
      iVar3 = esp_event_post(OPENTHREAD_EVENT,5,auStack_4c,0x14,0);
      if (iVar3 == 0) {
        return;
      }
      uVar4 = esp_log_timestamp();
      puVar5 = &_LC23;
    }
  }
  else if (cVar1 == -1) {
    iVar3 = esp_event_post(OPENTHREAD_EVENT,6,auStack_4c,0x14,0);
    if (iVar3 == 0) {
      return;
    }
    uVar4 = esp_log_timestamp();
    puVar5 = &_LC20;
  }
  else {
    memcpy(auStack_38,auStack_4c,0x14);
    iVar3 = is_mesh_local_addr(__src);
    bStack_24 = 0;
    if (iVar3 == 0) {
      bVar6 = false;
      if (*(int *)*param_1 == -0x1800000) {
        bVar6 = ((int *)*param_1)[1] == 0;
      }
      bStack_24 = 1 - bVar6;
    }
    bStack_24 = bStack_24 & 1;
    iVar3 = esp_event_post(OPENTHREAD_EVENT,4,auStack_38,0x18,0);
    if (iVar3 == 0) {
      return;
    }
    uVar4 = esp_log_timestamp();
    puVar5 = &_LC21;
  }
  esp_log_write(1,"OPENTHREAD",puVar5,uVar4,"OPENTHREAD");
  return;
}

