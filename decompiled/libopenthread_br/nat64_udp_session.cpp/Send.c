/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
 * Source: libopenthread_br -> nat64_udp_session.cpp.o -> Send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::UdpSession::Send(unsigned char*, unsigned short) */

undefined4 __thiscall idf::UdpSession::Send(UdpSession *this,uchar *param_1,ushort param_2)

{
  int iVar1;
  int iVar2;
  undefined2 in_register_00002032;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 auStack_38 [5];
  char cStack_24;
  
  uVar4 = CONCAT22(in_register_00002032,param_2);
  iVar1 = pbuf_alloc(0x4a,uVar4,0x280);
  auStack_38[0] = *(undefined4 *)(this + 0x18);
  cStack_24 = '\0';
  esp_openthread_get_backbone_netif();
  iVar2 = to_underlying_lwip_netif();
  if (cStack_24 == '\x06') {
    iVar3 = 0;
    if (iVar2 != 0) {
      iVar3 = ip6_select_source_address(auStack_38);
    }
  }
  else {
    iVar3 = 0;
    if (iVar2 != 0) {
      iVar3 = iVar2 + 4;
    }
  }
  sys_untimeout(OnSessionTimeout,this);
  sys_timeout(3600000,OnSessionTimeout,this);
  pbuf_take_at(iVar1,param_1,uVar4,0);
  uVar5 = 0;
  if (iVar1 != 0) {
    iVar2 = udp_sendto_if_src(*(undefined4 *)(this + 0x24),iVar1,auStack_38,
                              *(undefined2 *)(this + 0x1c),iVar2,iVar3);
    if (iVar2 != 0) {
      uVar4 = 0;
    }
    pbuf_free(iVar1);
    uVar5 = uVar4;
  }
  return uVar5;
}

