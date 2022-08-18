/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_br -> nat64_icmp_session.cpp.o -> get_next_icmp_ID
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::IcmpSession::get_next_icmp_ID() */

short idf::IcmpSession::get_next_icmp_ID(void)

{
  short sVar1;
  int iVar2;
  
  iVar2 = s_icmp_session_list;
  sVar1 = s_next_icmp_ID;
  do {
    while( true ) {
      if (iVar2 == 0) {
        s_next_icmp_ID = sVar1 + 1;
        return sVar1;
      }
      if (*(short *)(iVar2 + 0x20) == sVar1) break;
      iVar2 = *(int *)(iVar2 + 0x24);
    }
    sVar1 = sVar1 + 1;
    iVar2 = s_icmp_session_list;
  } while (s_next_icmp_ID != sVar1);
  return 0;
}

