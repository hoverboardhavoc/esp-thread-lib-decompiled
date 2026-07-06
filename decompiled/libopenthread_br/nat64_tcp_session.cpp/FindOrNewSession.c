/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
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
      pTVar1 = (TcpSession *)heap_caps_calloc(1,0x30,uVar3);
      if (pTVar1 != (TcpSession *)0x0) {
        TcpSession(pTVar1,param_1,param_2,param_3,param_4,param_5,(ushort)iVar2);
        if (s_session_list != (TcpSession *)0x0) {
          *(TcpSession **)((int)s_session_list + 0x2c) = pTVar1;
        }
        *(TcpSession **)(pTVar1 + 0x28) = s_session_list;
        s_session_list = pTVar1;
        return pTVar1;
      }
      uVar3 = esp_log_timestamp();
      pcVar4 = "E (%lu) %s: No memory for creating a new tcp session\n";
      pTVar1 = (TcpSession *)0x0;
    }
    esp_log(1,"NAT64",pcVar4,uVar3);
  }
  return pTVar1;
}

