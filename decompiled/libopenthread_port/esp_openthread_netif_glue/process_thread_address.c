/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> process_thread_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void process_thread_address(undefined4 *param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  char *__s1;
  undefined1 auStack_4c [20];
  undefined1 auStack_38 [20];
  byte bStack_24;
  
  __s1 = (char *)*param_1;
  cVar1 = *__s1;
  esp_openthread_get_instance();
  pvVar2 = (void *)otThreadGetMeshLocalPrefix();
  iVar3 = memcmp(__s1,pvVar2,8);
  pvVar2 = (void *)*param_1;
  if (((*(int *)((int)pvVar2 + 8) == -0x1000000) && (*(short *)((int)pvVar2 + 0xc) == 0xfe)) &&
     (iVar3 == 0)) {
    return;
  }
  memcpy(auStack_4c,pvVar2,0x10);
  puVar5 = OPENTHREAD_EVENT;
  if (param_2 == 0) {
    if (cVar1 == -1) {
      iVar3 = esp_event_post(OPENTHREAD_EVENT,7);
      if (iVar3 == 0) {
        return;
      }
      uVar4 = esp_log_timestamp();
      puVar5 = &_LC3;
    }
    else {
      iVar3 = esp_event_post(OPENTHREAD_EVENT,5,auStack_4c,0x14,0);
      if (iVar3 == 0) {
        return;
      }
      uVar4 = esp_log_timestamp();
      puVar5 = &_LC4;
    }
  }
  else if (cVar1 == -1) {
    iVar3 = esp_event_post(OPENTHREAD_EVENT,6,auStack_4c,0x14,0);
    if (iVar3 == 0) {
      return;
    }
    uVar4 = esp_log_timestamp();
    puVar5 = &_LC1;
  }
  else {
    memcpy(auStack_38,auStack_4c,0x14);
    bStack_24 = (byte)((uint)param_1[1] >> 0xc) & 1;
    iVar3 = esp_event_post(puVar5,4,auStack_38,0x18,0);
    if (iVar3 == 0) {
      return;
    }
    uVar4 = esp_log_timestamp();
    puVar5 = &_LC2;
  }
  esp_log_write(1,"OPENTHREAD",puVar5,uVar4,"OPENTHREAD");
  return;
}

