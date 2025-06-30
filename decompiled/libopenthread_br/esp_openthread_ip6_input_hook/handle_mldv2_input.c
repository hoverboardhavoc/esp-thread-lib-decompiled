/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_ip6_input_hook.o -> handle_mldv2_input
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 handle_mldv2_input(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  byte *pbVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  ushort uVar8;
  undefined1 auStack_58 [16];
  undefined1 uStack_48;
  undefined1 auStack_44 [16];
  undefined1 uStack_34;
  
  if (param_3 < 8) {
    return 0;
  }
  uVar2 = *(undefined1 *)(param_2 + 7);
  uVar3 = *(undefined1 *)(param_2 + 6);
  param_3 = param_3 - 8;
  pcVar4 = (char *)(param_2 + 8);
  memcpy(auStack_58,(void *)(param_1 + 8),0x10);
  uStack_48 = 0;
  uVar8 = 0;
  do {
    if (((param_3 & 0xffff) < 0x14) || (CONCAT11(uVar3,uVar2) <= uVar8)) {
      return 0;
    }
    if (*pcVar4 == '\x04') {
      if (*(short *)(pcVar4 + 2) == 0) {
        memcpy(auStack_44,pcVar4 + 4,0x10);
        uStack_34 = 0;
        iVar5 = esp_openthread_multicast_listener_add(auStack_44,auStack_58,param_4);
        if (iVar5 != 0) {
          uVar6 = esp_log_timestamp();
          pcVar7 = "E (%lu) %s: Failed to add backbone multicast listener\n";
_L48:
          esp_log(1,0x10000,pcVar7,uVar6);
        }
      }
      else {
_L21:
        uVar6 = esp_log_timestamp();
        esp_log(2,0x10000,"W (%lu) %s: Dropping unsupported mldv2 record of type %d\n",uVar6,0x10000
                ,*pcVar4);
      }
    }
    else {
      if ((*(short *)(pcVar4 + 2) != 0) || (*pcVar4 != '\x03')) goto _L21;
      memcpy(auStack_44,pcVar4 + 4,0x10);
      uStack_34 = 0;
      iVar5 = esp_openthread_multicast_listener_remove(auStack_44,auStack_58,param_4);
      if (iVar5 != 0) {
        uVar6 = esp_log_timestamp();
        pcVar7 = "E (%lu) %s: Failed to remove backbone multicast listener\n";
        goto _L48;
      }
    }
    pbVar1 = (byte *)(pcVar4 + 1);
    uVar8 = uVar8 + 1;
    pcVar4 = pcVar4 + (*pbVar1 + 5) * 4;
    param_3 = (param_3 & 0xffff) + (*pbVar1 + 5) * -4;
  } while( true );
}

