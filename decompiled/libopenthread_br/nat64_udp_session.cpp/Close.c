/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
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
    *(undefined4 *)(this + 0x24) = 0;
  }
  ~UdpSession(this);
  operator_delete(this,0x30);
  return;
}

