/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
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
  undefined4 uVar1;
  UdpSession *pUVar2;
  int iVar3;
  
  for (pUVar2 = s_session_list; pUVar2 != (UdpSession *)0x0;
      pUVar2 = *(UdpSession **)(pUVar2 + 0x28)) {
    iVar3 = Matches(pUVar2,param_1,param_2,param_3,param_4);
    if (iVar3 != 0) {
      return pUVar2;
    }
  }
  uVar1 = esp_openthread_get_alloc_caps();
  pUVar2 = (UdpSession *)heap_caps_calloc(1,0x30,uVar1);
  if (pUVar2 != (UdpSession *)0x0) {
    UdpSession(pUVar2,param_1,param_2,param_3,param_4);
    iVar3 = Init(pUVar2,param_2);
    if (iVar3 == 0) {
      if (s_session_list != (UdpSession *)0x0) {
        *(UdpSession **)(s_session_list + 0x2c) = pUVar2;
      }
      *(UdpSession **)(pUVar2 + 0x28) = s_session_list;
      s_session_list = pUVar2;
      return pUVar2;
    }
  }
  uVar1 = esp_log_timestamp();
  esp_log(1,"NAT64","E (%lu) %s: No memory for creating a new udp session\n",uVar1);
  return (UdpSession *)0x0;
}

