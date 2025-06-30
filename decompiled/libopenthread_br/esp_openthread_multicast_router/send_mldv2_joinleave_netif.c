/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> send_mldv2_joinleave_netif
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int send_mldv2_joinleave_netif(undefined4 param_1,void *param_2,char param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar3 = pbuf_alloc(0x36,0x1c,0x280);
  iVar1 = 0x101;
  if (iVar3 != 0) {
    puVar2 = *(undefined1 **)(iVar3 + 4);
    memset(puVar2 + 1,0,7);
    *puVar2 = 0x8f;
    puVar2[8] = param_3 + '\x03';
    puVar2[7] = 1;
    puVar2[9] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
    memcpy(puVar2 + 0xc,param_2,0x10);
    iVar1 = s_icmp_send_pcb;
    *(undefined2 *)(s_icmp_send_pcb + 0x44) = 2;
    *(undefined1 *)(iVar1 + 0x46) = 1;
    raw_bind_netif(param_1);
    uStack_38 = 0x2ff;
    uStack_2c = 0x16000000;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_28 = 0;
    uStack_24 = 6;
    iVar1 = raw_sendto(s_icmp_send_pcb,iVar3,&uStack_38);
    iVar1 = -(uint)(iVar1 != 0);
    pbuf_free(iVar3);
  }
  return iVar1;
}

