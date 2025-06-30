/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
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
      esp_log(1,"NAT64","E (%lu) %s: No memory for creating a new icmp session\n",uVar2);
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

