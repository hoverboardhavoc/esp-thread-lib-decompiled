/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
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
        s_next_port = s_next_port + 1;
        return uVar1;
      }
      if (*(ushort *)(iVar2 + 0x20) == uVar1) break;
      iVar2 = *(int *)(iVar2 + 0x28);
    }
    uVar1 = uVar1 + 1;
    if (0xc0ff < uVar1) {
      uVar1 = 0xc000;
    }
    iVar2 = s_session_list;
  } while (uVar1 != s_next_port);
  return 0;
}

