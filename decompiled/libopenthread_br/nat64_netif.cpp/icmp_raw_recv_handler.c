/*
 * Last changed at upstream commit 7d57b18006da6e182ddb87698abdced1566f3b56
 * https://github.com/espressif/esp-thread-lib/commit/7d57b18006da6e182ddb87698abdced1566f3b56
 * Upstream date: 2023-01-10 14:40:17 +0800
 * Upstream subject: openthread: add thread_br lib for esp32c2 and esp32c6 * esp_openthread: c558ac0 * ot-repo: 19e1875
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
  
  __size = (uint)*(ushort *)(param_3 + 10);
  if ((__size == *(ushort *)(param_3 + 8)) && (0x1b < __size)) {
    if (*(int *)param_3 == 0) {
      pvVar1 = *(void **)(param_3 + 4);
    }
    else {
      pvVar1 = malloc(__size);
      pbuf_copy_partial(param_3,pvVar1,__size,0);
    }
    puVar2 = (uchar *)idf::IcmpSession::FindSession
                                ((ip4_addr *)param_4,
                                 *(ushort *)((int)pvVar1 + 0x18) << 8 |
                                 *(ushort *)((int)pvVar1 + 0x18) >> 8);
    if (puVar2 != (uchar *)0x0) {
      iVar3 = idf::IcmpSession::Forward2V6(puVar2,(ushort)pvVar1);
      if (iVar3 == 0) {
        pbuf_free(param_3);
        return 1;
      }
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"NAT64",&_LC2,uVar4,"NAT64",0x10000,0xc1);
    }
  }
  return 0;
}

