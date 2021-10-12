/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
 * Source: libopenthread_br -> esp_openthread_trel.o -> otPlatTrelUdp6SendTo
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatTrelUdp6SendTo(void *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 local_50 [2];
  undefined1 auStack_4c [16];
  undefined1 auStack_3c [20];
  undefined4 uStack_28;
  uint uStack_24;
  
  local_50[0] = 0x100;
  iVar2 = otIp6NewMessageFromBuffer(local_50);
  if (iVar2 == 0) {
    uVar3 = 3;
  }
  else {
    uStack_28 = 0;
    uStack_24 = 0;
    memcpy(auStack_4c,s_trel_address,0x10);
    uVar1 = s_unicast_socket._16_2_;
    auStack_3c._16_2_ = s_unicast_socket._16_2_;
    memcpy(auStack_3c,param_1,0x10);
    auStack_3c._18_2_ = uVar1;
    uStack_24 = uStack_24 & 0xfffffb00 | 0x401;
    uVar3 = otPlatUdpSend(s_unicast_socket,iVar2,auStack_4c);
  }
  return uVar3;
}

