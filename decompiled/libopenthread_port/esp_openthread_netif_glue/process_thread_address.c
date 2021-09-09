/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> process_thread_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void process_thread_address(undefined4 *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined1 auStack_4c [20];
  undefined1 auStack_38 [20];
  byte bStack_24;
  
  cVar1 = *(char *)*param_1;
  memcpy(auStack_4c,(char *)*param_1,0x10);
  puVar4 = OPENTHREAD_EVENT;
  if (param_2 == 0) {
    if (cVar1 == -1) {
      iVar2 = esp_event_post(OPENTHREAD_EVENT,7);
      if (iVar2 == 0) {
        return;
      }
      uVar3 = esp_log_timestamp();
      puVar4 = &_LC3;
    }
    else {
      iVar2 = esp_event_post(OPENTHREAD_EVENT,5,auStack_4c,0x14,0);
      if (iVar2 == 0) {
        return;
      }
      uVar3 = esp_log_timestamp();
      puVar4 = &_LC4;
    }
  }
  else if (cVar1 == -1) {
    iVar2 = esp_event_post(OPENTHREAD_EVENT,6,auStack_4c,0x14,0);
    if (iVar2 == 0) {
      return;
    }
    uVar3 = esp_log_timestamp();
    puVar4 = &_LC1;
  }
  else {
    memcpy(auStack_38,auStack_4c,0x14);
    bStack_24 = (byte)((uint)param_1[1] >> 0xc) & 1;
    iVar2 = esp_event_post(puVar4,4,auStack_38,0x18,0);
    if (iVar2 == 0) {
      return;
    }
    uVar3 = esp_log_timestamp();
    puVar4 = &_LC2;
  }
  esp_log_write(1,"OPENTHREAD",puVar4,uVar3,"OPENTHREAD");
  return;
}

