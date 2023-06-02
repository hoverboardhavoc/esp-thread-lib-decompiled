/*
 * Last changed at upstream commit e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * https://github.com/espressif/esp-thread-lib/commit/e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * Upstream date: 2023-06-02 12:00:23 +0800
 * Upstream subject: ot br lib: fix issues in certification esp-openthread: a158ca1 openthread:091f68e
 * Source: libopenthread_br -> nat64_netif.cpp.o -> tcp_raw_recv_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* tcp_raw_recv_handler(void*, raw_pcb*, pbuf*, ip_addr const*) */

bool tcp_raw_recv_handler(void *param_1,raw_pcb *param_2,pbuf *param_3,ip_addr *param_4)

{
  ushort uVar1;
  uchar *puVar2;
  undefined4 auStack_14 [3];
  
  if ((*(ushort *)(param_3 + 10) == *(ushort *)(param_3 + 8)) && (0x27 < *(ushort *)(param_3 + 10)))
  {
    auStack_14[0] = *(undefined4 *)(*(int *)(param_3 + 4) + 0xc);
    uVar1 = *(ushort *)(*(int *)(param_3 + 4) + 0x14);
    puVar2 = (uchar *)idf::TcpSession::FindSession((ip4_addr *)auStack_14,uVar1 << 8 | uVar1 >> 8);
    if (puVar2 != (uchar *)0x0) {
      idf::TcpSession::ForwardV4(puVar2,(ushort)*(undefined4 *)(param_3 + 4));
      pbuf_free(param_3);
    }
    return puVar2 != (uchar *)0x0;
  }
  return false;
}

