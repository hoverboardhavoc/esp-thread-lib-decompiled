/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
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
  
  pUVar1 = s_session_list;
  while( true ) {
    if (pUVar1 == (UdpSession *)0x0) {
      this = (UdpSession *)operator_new(0x30);
      UdpSession(this,param_1,param_2,param_3,param_4);
      iVar2 = Init(this,param_2);
      pUVar1 = (UdpSession *)0x0;
      if (iVar2 == 0) {
        if (s_session_list != (UdpSession *)0x0) {
          *(UdpSession **)(s_session_list + 0x2c) = this;
        }
        *(UdpSession **)(this + 0x28) = s_session_list;
        pUVar1 = this;
        s_session_list = this;
      }
      return pUVar1;
    }
    iVar2 = Matches(pUVar1,param_1,param_2,param_3,param_4);
    if (iVar2 != 0) break;
    pUVar1 = *(UdpSession **)(pUVar1 + 0x28);
  }
  return pUVar1;
}

