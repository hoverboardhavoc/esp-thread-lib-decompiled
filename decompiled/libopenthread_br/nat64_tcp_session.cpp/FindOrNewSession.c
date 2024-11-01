/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> nat64_tcp_session.cpp.o -> FindOrNewSession
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::TcpSession::FindOrNewSession(raw_pcb*, ip6_addr const&, unsigned short, ip6_addr const&,
   unsigned short) */

TcpSession *
idf::TcpSession::FindOrNewSession
          (raw_pcb *param_1,ip6_addr *param_2,ushort param_3,ip6_addr *param_4,ushort param_5)

{
  TcpSession *pTVar1;
  int iVar2;
  undefined4 uVar3;
  TcpSession *this;
  char *pcVar4;
  
  pTVar1 = (TcpSession *)FindSession(param_2,param_3,param_4,param_5);
  if (pTVar1 == (TcpSession *)0x0) {
    iVar2 = FindNextLocalPort();
    if (iVar2 == 0) {
      uVar3 = esp_log_timestamp();
      pcVar4 = "E (%lu) %s: No ports for creating a new tcp session\n";
    }
    else {
      uVar3 = esp_openthread_get_alloc_caps();
      this = (TcpSession *)heap_caps_calloc(1,0x30,uVar3);
      if (this != (TcpSession *)0x0) {
        TcpSession(this,param_1,param_2,param_3,param_4,param_5,(ushort)iVar2);
        if (s_session_list != (TcpSession *)0x0) {
          *(TcpSession **)((int)s_session_list + 0x2c) = this;
        }
        *(TcpSession **)(this + 0x28) = s_session_list;
        s_session_list = this;
        return this;
      }
      uVar3 = esp_log_timestamp();
      pcVar4 = "E (%lu) %s: No memory for creating a new tcp session\n";
    }
    esp_log_write(1,"NAT64",pcVar4,uVar3,"NAT64");
  }
  return pTVar1;
}

