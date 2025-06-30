/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
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
                                 CONCAT11(*(undefined1 *)(iVar2 + 0x14),
                                          *(undefined1 *)(iVar2 + 0x15)),
                                 CONCAT11(*(undefined1 *)(iVar2 + 0x16),
                                          *(undefined1 *)(iVar2 + 0x17)));
    if (puVar1 != (uchar *)0x0) {
      idf::TcpSession::ForwardV4(puVar1,(ushort)*(undefined4 *)(param_3 + 4));
      pbuf_free(param_3);
    }
    return puVar1 != (uchar *)0x0;
  }
  return false;
}

