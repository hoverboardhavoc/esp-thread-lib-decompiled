/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
 * Source: libopenthread_br -> nat64.cpp.o -> nat64_remove_all_sessions
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nat64_remove_all_sessions(void)

{
  idf::TcpSession::remove_all_tcp_sessions();
  idf::IcmpSession::remove_all_icmp_sessions();
  idf::UdpSession::remove_all_udp_sessions();
  return 0;
}

