/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> nat64_udp_session.cpp.o -> Send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::UdpSession::Send(unsigned char*, unsigned short) */

undefined4 __thiscall idf::UdpSession::Send(UdpSession *this,uchar *param_1,ushort param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined2 in_register_00002032;
  
  uVar1 = CONCAT22(in_register_00002032,param_2);
  iVar2 = pbuf_alloc(0x4a,uVar1,0x280);
  sys_untimeout(OnSessionTimeout,this);
  sys_timeout(3600000,OnSessionTimeout,this);
  pbuf_take_at(iVar2,param_1,uVar1,0);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    iVar3 = udp_send(*(undefined4 *)(this + 0x24),iVar2);
    if (iVar3 != 0) {
      uVar1 = 0;
    }
    pbuf_free(iVar2);
  }
  return uVar1;
}

