/*
 * Last changed at upstream commit 984efc1578c856af215f33fcfeab645145949b46
 * https://github.com/espressif/esp-thread-lib/commit/984efc1578c856af215f33fcfeab645145949b46
 * Upstream date: 2025-09-19 08:31:45 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 3b3dd203
 * Source: libopenthread_br -> nat64_netif.cpp.o -> tcp_raw_recv_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* tcp_raw_recv_handler(void*, raw_pcb*, pbuf*, ip_addr const*) */

bool tcp_raw_recv_handler(void *param_1,raw_pcb *param_2,pbuf *param_3,ip_addr *param_4)

{
  uchar *puVar1;
  int iVar2;
  undefined4 auStack_14 [3];
  
  if ((*(ushort *)(param_3 + 10) == *(ushort *)(param_3 + 8)) && (0x27 < *(ushort *)(param_3 + 8)))
  {
    iVar2 = *(int *)(param_3 + 4);
    auStack_14[0] = *(undefined4 *)(iVar2 + 0xc);
    puVar1 = (uchar *)idf::TcpSession::FindSession
                                ((ip4_addr *)auStack_14,
                                 *(ushort *)(iVar2 + 0x14) >> 8 |
                                 (ushort)((*(ushort *)(iVar2 + 0x14) & 0xff) << 8),
                                 *(ushort *)(iVar2 + 0x16) >> 8 |
                                 (ushort)((*(ushort *)(iVar2 + 0x16) & 0xff) << 8));
    if (puVar1 != (uchar *)0x0) {
      idf::TcpSession::ForwardV4(puVar1,(ushort)*(undefined4 *)(param_3 + 4));
      pbuf_free(param_3);
    }
    return puVar1 != (uchar *)0x0;
  }
  return false;
}

