/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_br -> esp_openthread_ip6_input_hook.o -> handle_mldv2_input
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 handle_mldv2_input(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  byte *pbVar1;
  ushort uVar2;
  ushort uVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined *puVar7;
  uint uVar8;
  undefined1 auStack_68 [16];
  undefined1 uStack_58;
  undefined1 auStack_54 [16];
  undefined1 uStack_44;
  
  if (param_3 < 8) {
    return 0;
  }
  uVar2 = *(ushort *)(param_2 + 6);
  param_3 = param_3 - 8;
  pcVar4 = (char *)(param_2 + 8);
  memcpy(auStack_68,(void *)(param_1 + 8),0x10);
  uStack_58 = 0;
  uVar8 = 0;
  do {
    if ((((uVar2 & 0xff) << 8 | (uint)(uVar2 >> 8)) == uVar8) || ((param_3 & 0xffff) < 0x14)) {
      return 0;
    }
    uVar3 = *(ushort *)(pcVar4 + 2);
    if (*pcVar4 == '\x04') {
      if (uVar3 >> 8 == 0 && (uVar3 & 0xff) == 0) {
        memcpy(auStack_54,pcVar4 + 4,0x10);
        uStack_44 = 0;
        iVar5 = esp_openthread_multicast_listener_add(auStack_54,auStack_68,param_4);
        if (iVar5 != 0) {
          uVar6 = esp_log_timestamp();
          puVar7 = &_LC1;
_L0:
          esp_log_write(1,0x10000,puVar7,uVar6,0x10000);
        }
      }
      else {
_L0:
        uVar6 = esp_log_timestamp();
        esp_log_write(2,0x10000,&_LC3,uVar6,0x10000,*pcVar4);
      }
    }
    else {
      if ((*pcVar4 != '\x03') || (uVar3 >> 8 != 0 || (uVar3 & 0xff) != 0)) goto _L0;
      memcpy(auStack_54,pcVar4 + 4,0x10);
      uStack_44 = 0;
      iVar5 = esp_openthread_multicast_listener_remove(auStack_54,auStack_68,param_4);
      if (iVar5 != 0) {
        uVar6 = esp_log_timestamp();
        puVar7 = &_LC2;
        goto _L0;
      }
    }
    pbVar1 = (byte *)(pcVar4 + 1);
    pcVar4 = pcVar4 + (*pbVar1 + 5) * 4;
    param_3 = (param_3 & 0xffff) + (*pbVar1 + 5) * -4;
    uVar8 = uVar8 + 1 & 0xffff;
  } while( true );
}

