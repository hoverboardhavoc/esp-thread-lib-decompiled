/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  byte bStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  cVar1 = *(char *)*param_1;
  memcpy(&uStack_24,(char *)*param_1,0x10);
  if (param_2 == 0) {
    if (cVar1 == -1) {
      iVar2 = esp_event_post(OPENTHREAD_EVENT,7,&uStack_24,0x14,0);
      if (iVar2 != 0) {
        otLogCrit(0xc,"-PLAT----: ","Failed to post OpenThread leave multicast group event");
      }
    }
    else {
      iVar2 = esp_event_post(OPENTHREAD_EVENT,5,&uStack_24,0x14,0);
      if (iVar2 != 0) {
        otLogCrit(0xc,"-PLAT----: ","Failed to post OpenThread lost ip6 address event");
      }
    }
  }
  else if (cVar1 == -1) {
    iVar2 = esp_event_post(OPENTHREAD_EVENT,6,&uStack_24,0x14,0);
    if (iVar2 != 0) {
      otLogCrit(0xc,"-PLAT----: ","Failed to post OpenThread join multicast group event");
    }
  }
  else {
    uStack_3c = uStack_24;
    uStack_38 = uStack_20;
    uStack_34 = uStack_1c;
    uStack_30 = uStack_18;
    uStack_2c = uStack_14;
    bStack_28 = (byte)((uint)param_1[1] >> 0xc) & 1;
    iVar2 = esp_event_post(OPENTHREAD_EVENT,4,&uStack_3c,0x18,0);
    if (iVar2 != 0) {
      otLogCrit(0xc,"-PLAT----: ","Failed to post OpenThread got ip6 address event");
    }
  }
  return;
}

