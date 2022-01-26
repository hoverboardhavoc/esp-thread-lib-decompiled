/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
 * Source: libopenthread_br -> esp_openthread_ip6_input_hook.o -> handle_mld_input.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_mld_input_part_0(int param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined1 auStack_38 [16];
  undefined1 uStack_28;
  undefined1 auStack_24 [16];
  undefined1 uStack_14;
  
  cVar1 = *param_2;
  memcpy(auStack_38,(void *)(param_1 + 8),0x10);
  uStack_28 = 0;
  memcpy(auStack_24,param_2 + 8,0x10);
  uStack_14 = 0;
  if (cVar1 == -0x7d) {
    iVar2 = esp_openthread_multicast_listener_add();
    if (iVar2 == 0) {
      return;
    }
    uVar3 = esp_log_timestamp();
    puVar4 = &_LC1;
  }
  else {
    iVar2 = esp_openthread_multicast_listener_remove(auStack_24,auStack_38,param_3);
    if (iVar2 == 0) {
      return;
    }
    uVar3 = esp_log_timestamp();
    puVar4 = &_LC2;
  }
  esp_log_write(1,"OPENTHREAD",puVar4,uVar3,"OPENTHREAD");
  return;
}

