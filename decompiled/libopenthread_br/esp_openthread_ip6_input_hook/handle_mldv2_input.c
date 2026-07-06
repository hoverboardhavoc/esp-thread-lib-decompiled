/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
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
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  undefined1 auStack_58 [16];
  undefined1 uStack_48;
  undefined1 auStack_44 [16];
  undefined1 uStack_34;
  
  if (param_3 < 8) {
    return 0;
  }
  uVar2 = *(ushort *)(param_2 + 6);
  param_3 = param_3 - 8;
  pcVar3 = (char *)(param_2 + 8);
  memcpy(auStack_58,(void *)(param_1 + 8),0x10);
  uStack_48 = 0;
  uVar7 = 0;
  do {
    if ((((uVar2 & 0xff) << 8 | (uint)(uVar2 >> 8)) == uVar7) || ((param_3 & 0xffff) < 0x14)) {
      return 0;
    }
    if (*pcVar3 == '\x04') {
      if (*(short *)(pcVar3 + 2) == 0) {
        memcpy(auStack_44,pcVar3 + 4,0x10);
        uStack_34 = 0;
        iVar4 = esp_openthread_multicast_listener_add(auStack_44,auStack_58,param_4);
        if (iVar4 != 0) {
          uVar5 = esp_log_timestamp();
          pcVar6 = "E (%lu) %s: Failed to add backbone multicast listener\n";
_L45:
          esp_log(1,0x10000,pcVar6,uVar5);
        }
      }
      else {
_L22:
        uVar5 = esp_log_timestamp();
        esp_log(2,0x10000,"W (%lu) %s: Dropping unsupported mldv2 record of type %d\n",uVar5,0x10000
                ,*pcVar3);
      }
    }
    else {
      if ((*(short *)(pcVar3 + 2) != 0) || (*pcVar3 != '\x03')) goto _L22;
      memcpy(auStack_44,pcVar3 + 4,0x10);
      uStack_34 = 0;
      iVar4 = esp_openthread_multicast_listener_remove(auStack_44,auStack_58,param_4);
      if (iVar4 != 0) {
        uVar5 = esp_log_timestamp();
        pcVar6 = "E (%lu) %s: Failed to remove backbone multicast listener\n";
        goto _L45;
      }
    }
    pbVar1 = (byte *)(pcVar3 + 1);
    pcVar3 = pcVar3 + (*pbVar1 + 5) * 4;
    param_3 = (param_3 & 0xffff) + (*pbVar1 + 5) * -4;
    uVar7 = uVar7 + 1 & 0xffff;
  } while( true );
}

