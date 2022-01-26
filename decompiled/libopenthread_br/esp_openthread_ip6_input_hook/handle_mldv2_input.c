/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
 * Source: libopenthread_br -> esp_openthread_ip6_input_hook.o -> handle_mldv2_input
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 handle_mldv2_input(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  uint uVar6;
  undefined1 auStack_68 [16];
  undefined1 uStack_58;
  undefined1 auStack_54 [16];
  undefined1 uStack_44;
  
  if (param_3 < 8) {
    return 0;
  }
  param_3 = param_3 - 8;
  uVar2 = lwip_htons(*(undefined2 *)(param_2 + 6));
  memcpy(auStack_68,(void *)(param_1 + 8),0x10);
  pcVar1 = (char *)(param_2 + 8);
  uStack_58 = 0;
  uVar6 = 0;
  do {
    if ((uVar2 == uVar6) || ((param_3 & 0xffff) < 0x14)) {
      return 0;
    }
    iVar3 = lwip_htons(*(undefined2 *)(pcVar1 + 2));
    if (*pcVar1 == '\x04') {
      if (iVar3 == 0) {
        memcpy(auStack_54,pcVar1 + 4,0x10);
        uStack_44 = 0;
        iVar3 = esp_openthread_multicast_listener_add(auStack_54,auStack_68,param_4);
        if (iVar3 != 0) {
          uVar4 = esp_log_timestamp();
          puVar5 = &_LC1;
_L0:
          esp_log_write(1,"OPENTHREAD",puVar5,uVar4,"OPENTHREAD");
        }
      }
      else {
_L0:
        uVar4 = esp_log_timestamp();
        esp_log_write(2,"OPENTHREAD",&_LC3,uVar4,"OPENTHREAD",*pcVar1);
      }
    }
    else {
      if ((*pcVar1 != '\x03') || (iVar3 != 0)) goto _L0;
      memcpy(auStack_54,pcVar1 + 4,0x10);
      uStack_44 = 0;
      iVar3 = esp_openthread_multicast_listener_remove(auStack_54,auStack_68,param_4);
      if (iVar3 != 0) {
        uVar4 = esp_log_timestamp();
        puVar5 = &_LC2;
        goto _L0;
      }
    }
    param_3 = (param_3 & 0xffff) + ((byte)pcVar1[1] + 5) * -4;
    pcVar1 = pcVar1 + ((byte)pcVar1[1] + 5) * 4;
    uVar6 = uVar6 + 1 & 0xffff;
  } while( true );
}

