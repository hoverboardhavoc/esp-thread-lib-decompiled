/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> nat64_udp_session.cpp.o -> GetSession
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::UdpSession::GetSession(ip6_addr const&, unsigned short, ip6_addr const&, unsigned short) */

UdpSession *
idf::UdpSession::GetSession(ip6_addr *param_1,ushort param_2,ip6_addr *param_3,ushort param_4)

{
  UdpSession *pUVar1;
  UdpSession *this;
  int iVar2;
  
  pUVar1 = (anonymous_namespace)::s_session_list;
  while( true ) {
    if (pUVar1 == (UdpSession *)0x0) {
      this = (UdpSession *)operator_new(0x30);
      UdpSession(this,param_1,param_2,param_3,param_4);
      iVar2 = Init(this,param_2);
      pUVar1 = (UdpSession *)0x0;
      if (iVar2 == 0) {
        if ((anonymous_namespace)::s_session_list != (UdpSession *)0x0) {
          *(UdpSession **)((anonymous_namespace)::s_session_list + 0x2c) = this;
        }
        *(UdpSession **)(this + 0x28) = (anonymous_namespace)::s_session_list;
        pUVar1 = this;
        (anonymous_namespace)::s_session_list = this;
      }
      return pUVar1;
    }
    iVar2 = Matches(pUVar1,param_1,param_2,param_3,param_4);
    if (iVar2 != 0) break;
    pUVar1 = *(UdpSession **)(pUVar1 + 0x28);
  }
  return pUVar1;
}

