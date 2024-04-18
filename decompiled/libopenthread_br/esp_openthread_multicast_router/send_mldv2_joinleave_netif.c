/*
 * Last changed at upstream commit a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * https://github.com/espressif/esp-thread-lib/commit/a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * Upstream date: 2024-04-18 16:47:55 +0800
 * Upstream subject: feat(br): update border router lib           esp-openthread: 07f637d           openthread: be7d36e
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
  undefined1 auStack_38 [28];
  
  iVar3 = pbuf_alloc(0x36,0x1c,0x280);
  iVar1 = 0x101;
  if (iVar3 != 0) {
    puVar2 = *(undefined1 **)(iVar3 + 4);
    memset(puVar2 + 1,0,7);
    *puVar2 = 0x8f;
    puVar2[7] = 1;
    puVar2[9] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
    puVar2[8] = param_3 + '\x03';
    memcpy(puVar2 + 0xc,param_2,0x10);
    iVar1 = s_icmp_send_pcb;
    *(undefined2 *)(s_icmp_send_pcb + 0x44) = 2;
    *(undefined1 *)(iVar1 + 0x46) = 1;
    raw_bind_netif(param_1);
    memcpy(auStack_38,&_LANCHOR0,0x18);
    iVar1 = raw_sendto(s_icmp_send_pcb,iVar3,auStack_38);
    iVar1 = -(uint)(iVar1 != 0);
    pbuf_free(iVar3);
  }
  return iVar1;
}

