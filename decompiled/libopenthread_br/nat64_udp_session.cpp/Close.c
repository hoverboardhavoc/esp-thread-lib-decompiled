/*
 * Last changed at upstream commit b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * https://github.com/espressif/esp-thread-lib/commit/b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * Upstream date: 2023-12-09 16:01:37 +0800
 * Upstream subject: feat(br): update border router lib     esp-openthread: 8d18b44     openthread: 41ef807
 * Source: libopenthread_br -> nat64_udp_session.cpp.o -> Close
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::UdpSession::Close() */

void __thiscall idf::UdpSession::Close(UdpSession *this)

{
  sys_untimeout(OnSessionTimeout,this);
  if (*(int *)(this + 0x24) != 0) {
    udp_remove();
  }
  ~UdpSession(this);
  operator_delete(this,0x30);
  return;
}

