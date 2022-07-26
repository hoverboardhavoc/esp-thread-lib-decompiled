/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> nat64_netif.cpp.o -> tcp_raw_recv_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* tcp_raw_recv_handler(void*, raw_pcb*, pbuf*, ip_addr const*) */

undefined4 tcp_raw_recv_handler(void *param_1,raw_pcb *param_2,pbuf *param_3,ip_addr *param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  uchar *puVar3;
  undefined4 auStack_14 [2];
  
  uVar2 = 0;
  if ((*(ushort *)(param_3 + 10) == *(ushort *)(param_3 + 8)) && (0x27 < *(ushort *)(param_3 + 10)))
  {
    auStack_14[0] = *(undefined4 *)(*(int *)(param_3 + 4) + 0xc);
    uVar1 = *(ushort *)(*(int *)(param_3 + 4) + 0x14);
    puVar3 = (uchar *)idf::TcpSession::FindSession((ip4_addr *)auStack_14,uVar1 << 8 | uVar1 >> 8);
    if (puVar3 != (uchar *)0x0) {
      uVar2 = 1;
      idf::TcpSession::ForwardV4(puVar3,(ushort)*(undefined4 *)(param_3 + 4));
      pbuf_free(param_3);
    }
  }
  return uVar2;
}

