/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
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
  IcmpSession *this;
  undefined4 uVar2;
  
  uVar1 = get_next_icmp_ID();
  this = (IcmpSession *)FindSession(param_2,param_3,param_4);
  if (this == (IcmpSession *)0x0) {
    uVar2 = esp_openthread_get_alloc_caps();
    this = (IcmpSession *)heap_caps_calloc(1,0x2c,uVar2);
    if (this == (IcmpSession *)0x0) {
      uVar2 = esp_log_timestamp();
      esp_log(1,"NAT64","E (%lu) %s: No memory for creating a new icmp session\n",uVar2,"NAT64");
    }
    else {
      IcmpSession(this,param_1,param_2,param_3,param_4,uVar1);
      if (s_icmp_session_list != (IcmpSession *)0x0) {
        *(IcmpSession **)(s_icmp_session_list + 0x28) = this;
      }
      *(IcmpSession **)(this + 0x24) = s_icmp_session_list;
      s_icmp_session_list = this;
      sys_timeout(60000,OnSessionTimeout,this);
      this = s_icmp_session_list;
    }
  }
  else {
    sys_untimeout(OnSessionTimeout,this);
    *(raw_pcb **)this = param_1;
    *(ushort *)(this + 0x20) = uVar1;
    sys_timeout(60000,OnSessionTimeout,this);
  }
  return this;
}

