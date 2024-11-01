/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
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
  esp_log_write(1,"NAT64","E (%lu) %s: No memory for creating a new udp session\n",uVar1,"NAT64");
  return (UdpSession *)0x0;
}

