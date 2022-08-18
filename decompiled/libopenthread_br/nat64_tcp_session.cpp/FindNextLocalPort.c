/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
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
        if (0xc0ff < s_next_port) {
          s_next_port = 0xc000;
        }
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

