/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_br -> nat64_icmp_session.cpp.o -> FindOrNewSession
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::IcmpSession::FindOrNewSession(raw_pcb*, ip6_addr const&, unsigned short, ip4_addr const&) */

IcmpSession *
idf::IcmpSession::FindOrNewSession
          (raw_pcb *param_1,ip6_addr *param_2,ushort param_3,ip4_addr *param_4)

{
  ushort uVar1;
  IcmpSession *pIVar2;
  
  uVar1 = get_next_icmp_ID();
  pIVar2 = (IcmpSession *)FindSession(param_2,param_3,param_4);
  if (pIVar2 == (IcmpSession *)0x0) {
    pIVar2 = (IcmpSession *)operator_new(0x2c);
    IcmpSession(pIVar2,param_1,param_2,param_3,param_4,uVar1);
    if (s_icmp_session_list != (IcmpSession *)0x0) {
      *(IcmpSession **)(s_icmp_session_list + 0x28) = pIVar2;
    }
    *(IcmpSession **)(pIVar2 + 0x24) = s_icmp_session_list;
    s_icmp_session_list = pIVar2;
    sys_timeout(60000,OnSessionTimeout,pIVar2);
    pIVar2 = s_icmp_session_list;
  }
  else {
    sys_untimeout(OnSessionTimeout,pIVar2);
    *(raw_pcb **)pIVar2 = param_1;
    *(ushort *)(pIVar2 + 0x20) = uVar1;
    sys_timeout(60000,OnSessionTimeout,pIVar2);
  }
  return pIVar2;
}

