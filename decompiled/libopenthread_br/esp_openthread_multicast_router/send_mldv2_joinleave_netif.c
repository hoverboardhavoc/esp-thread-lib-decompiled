/*
 * Last changed at upstream commit 984efc1578c856af215f33fcfeab645145949b46
 * https://github.com/espressif/esp-thread-lib/commit/984efc1578c856af215f33fcfeab645145949b46
 * Upstream date: 2025-09-19 08:31:45 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 3b3dd203
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
  
  iVar1 = pbuf_alloc(0x36,0x1c,0x280);
  if (iVar1 == 0) {
    iVar3 = 0x101;
  }
  else {
    puVar2 = *(undefined1 **)(iVar1 + 4);
    *(undefined2 *)(puVar2 + 5) = 0;
    *puVar2 = 0x8f;
    *(undefined2 *)(puVar2 + 6) = 0x100;
    puVar2[8] = param_3 + '\x03';
    *(undefined4 *)(puVar2 + 1) = 0;
    puVar2[9] = 0;
    *(undefined2 *)(puVar2 + 10) = 0;
    memcpy(puVar2 + 0xc,param_2,0x10);
    iVar3 = s_icmp_send_pcb;
    *(undefined2 *)(s_icmp_send_pcb + 0x44) = 2;
    *(undefined1 *)(iVar3 + 0x46) = 1;
    raw_bind_netif(param_1);
    uStack_38 = 0x2ff;
    uStack_2c = 0x16000000;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_28 = 0;
    uStack_24 = 6;
    iVar3 = raw_sendto(s_icmp_send_pcb,iVar1,&uStack_38);
    iVar3 = -(uint)(iVar3 != 0);
    pbuf_free(iVar1);
  }
  return iVar3;
}

