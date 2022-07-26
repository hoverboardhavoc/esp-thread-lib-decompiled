/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> nat64_udp_session.cpp.o -> OnDestUdpReceived__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::UdpSession::OnDestUdpReceived(void*, udp_pcb*, pbuf*, ip_addr const*, unsigned short) */

void idf::UdpSession::OnDestUdpReceived
               (void *param_1,udp_pcb *param_2,pbuf *param_3,ip_addr *param_4,ushort param_5)

{
  OnDestUdpReceived((UdpSession *)param_1,param_3);
  pbuf_free(param_3);
  return;
}

