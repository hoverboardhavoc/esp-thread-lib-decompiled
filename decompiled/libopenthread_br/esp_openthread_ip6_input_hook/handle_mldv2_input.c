/*
 * Last changed at upstream commit e0ff2a014fc5165513405b2e35649eb05be77ec9
 * https://github.com/espressif/esp-thread-lib/commit/e0ff2a014fc5165513405b2e35649eb05be77ec9
 * Upstream date: 2022-03-07 14:30:05 +0800
 * Upstream subject: openthread: update OpenThread submodule
 * Source: libopenthread_br -> esp_openthread_ip6_input_hook.o -> handle_mldv2_input
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 handle_mldv2_input(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  ushort uVar1;
  ushort uVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined *puVar6;
  uint uVar7;
  undefined1 auStack_68 [16];
  undefined1 uStack_58;
  undefined1 auStack_54 [16];
  undefined1 uStack_44;
  
  if (param_3 < 8) {
    return 0;
  }
  uVar1 = *(ushort *)(param_2 + 6);
  param_3 = param_3 - 8;
  pcVar3 = (char *)(param_2 + 8);
  memcpy(auStack_68,(void *)(param_1 + 8),0x10);
  uStack_58 = 0;
  uVar7 = 0;
  do {
    if ((((uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8)) == uVar7) || ((param_3 & 0xffff) < 0x14)) {
      return 0;
    }
    uVar2 = *(ushort *)(pcVar3 + 2);
    if (*pcVar3 == '\x04') {
      if (uVar2 >> 8 == 0 && (uVar2 & 0xff) == 0) {
        memcpy(auStack_54,pcVar3 + 4,0x10);
        uStack_44 = 0;
        iVar4 = esp_openthread_multicast_listener_add(auStack_54,auStack_68,param_4);
        if (iVar4 != 0) {
          uVar5 = esp_log_timestamp();
          puVar6 = &_LC1;
_L0:
          esp_log_write(1,"OPENTHREAD",puVar6,uVar5,"OPENTHREAD");
        }
      }
      else {
_L0:
        uVar5 = esp_log_timestamp();
        esp_log_write(2,"OPENTHREAD",&_LC3,uVar5,"OPENTHREAD",*pcVar3);
      }
    }
    else {
      if ((*pcVar3 != '\x03') || (uVar2 >> 8 != 0 || (uVar2 & 0xff) != 0)) goto _L0;
      memcpy(auStack_54,pcVar3 + 4,0x10);
      uStack_44 = 0;
      iVar4 = esp_openthread_multicast_listener_remove(auStack_54,auStack_68,param_4);
      if (iVar4 != 0) {
        uVar5 = esp_log_timestamp();
        puVar6 = &_LC2;
        goto _L0;
      }
    }
    param_3 = (param_3 & 0xffff) + ((byte)pcVar3[1] + 5) * -4;
    pcVar3 = pcVar3 + ((byte)pcVar3[1] + 5) * 4;
    uVar7 = uVar7 + 1 & 0xffff;
  } while( true );
}

