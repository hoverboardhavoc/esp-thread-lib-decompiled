/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> nat64_udp_session.cpp.o -> Send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::UdpSession::Send(unsigned char*, unsigned short) */

uint __thiscall idf::UdpSession::Send(UdpSession *this,uchar *param_1,ushort param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined2 in_register_00002032;
  uint uVar4;
  int iVar5;
  undefined4 auStack_38 [5];
  char cStack_24;
  
  uVar4 = CONCAT22(in_register_00002032,param_2);
  iVar2 = pbuf_alloc(0x4a,uVar4,0x280);
  auStack_38[0] = *(undefined4 *)(this + 0x18);
  cStack_24 = '\0';
  esp_openthread_get_backbone_netif();
  iVar3 = to_underlying_lwip_netif();
  if (cStack_24 == '\x06') {
    iVar5 = 0;
    if (iVar3 != 0) {
      iVar5 = ip6_select_source_address(auStack_38);
    }
  }
  else {
    iVar5 = 0;
    if (iVar3 != 0) {
      iVar5 = iVar3 + 4;
    }
  }
  sys_untimeout(OnSessionTimeout,this);
  sys_timeout(3600000,OnSessionTimeout,this);
  pbuf_take_at(iVar2,param_1,uVar4,0);
  uVar1 = 0;
  if (iVar2 != 0) {
    iVar3 = udp_sendto_if_src(*(undefined4 *)(this + 0x24),iVar2,auStack_38,
                              *(undefined2 *)(this + 0x1c),iVar3,iVar5);
    uVar1 = uVar4 & -(uint)(iVar3 == 0);
    pbuf_free(iVar2);
  }
  return uVar1;
}

