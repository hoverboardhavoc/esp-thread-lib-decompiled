/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> nat64_tcp_session.cpp.o -> FindNextLocalPort
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::TcpSession::FindNextLocalPort() */

ushort idf::TcpSession::FindNextLocalPort(void)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = s_session_list;
  uVar1 = s_next_port;
  do {
    while( true ) {
      if (iVar2 == 0) {
        s_next_port = uVar1 + 1;
        if (0xceff < s_next_port) {
          s_next_port = 0xc000;
        }
        return uVar1;
      }
      if (*(ushort *)(iVar2 + 0x20) == uVar1) break;
      iVar2 = *(int *)(iVar2 + 0x28);
    }
    uVar1 = uVar1 + 1;
    if (0xceff < uVar1) {
      uVar1 = 0xc000;
    }
    iVar2 = s_session_list;
  } while (uVar1 != s_next_port);
  return 0;
}

