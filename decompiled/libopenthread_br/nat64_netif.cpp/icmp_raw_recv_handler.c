/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> nat64_netif.cpp.o -> icmp_raw_recv_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* icmp_raw_recv_handler(void*, raw_pcb*, pbuf*, ip_addr const*) */

undefined4 icmp_raw_recv_handler(void *param_1,raw_pcb *param_2,pbuf *param_3,ip_addr *param_4)

{
  void *pvVar1;
  uchar *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint __size;
  
  __size = (uint)*(ushort *)(param_3 + 8);
  if ((*(ushort *)(param_3 + 10) == __size) && (0x1b < __size)) {
    if (*(int *)param_3 == 0) {
      pvVar1 = *(void **)(param_3 + 4);
    }
    else {
      pvVar1 = malloc(__size);
      pbuf_copy_partial(param_3,pvVar1,__size,0);
    }
    puVar2 = (uchar *)idf::IcmpSession::FindSession
                                ((ip4_addr *)param_4,
                                 CONCAT11(*(undefined1 *)((int)pvVar1 + 0x18),
                                          *(undefined1 *)((int)pvVar1 + 0x19)));
    if (puVar2 != (uchar *)0x0) {
      iVar3 = idf::IcmpSession::Forward2V6(puVar2,(ushort)pvVar1);
      if (iVar3 == 0) {
        pbuf_free(param_3);
        return 1;
      }
      uVar4 = esp_log_timestamp();
      esp_log(1,"NAT64","E (%lu) %s: %s(%d): failed to forward\n",uVar4,"icmp_raw_recv_handler",0xc4
             );
    }
  }
  return 0;
}

