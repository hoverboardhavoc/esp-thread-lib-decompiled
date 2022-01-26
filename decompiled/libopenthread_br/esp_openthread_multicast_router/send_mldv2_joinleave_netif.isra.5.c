/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> send_mldv2_joinleave_netif.isra.5
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int send_mldv2_joinleave_netif_isra_5(void *param_1,int param_2)

{
  int iVar1;
  undefined1 *__s;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_38 [36];
  
  iVar3 = pbuf_alloc(0x36,0x1c,0x280);
  iVar1 = 0x101;
  if (iVar3 != 0) {
    __s = *(undefined1 **)(iVar3 + 4);
    memset(__s,0,8);
    *__s = 0x8f;
    uVar2 = lwip_htons(1);
    __s[6] = (char)uVar2;
    __s[7] = (char)((ushort)uVar2 >> 8);
    __s[8] = (param_2 != 0) + '\x03';
    __s[9] = 0;
    __s[10] = 0;
    __s[0xb] = 0;
    memcpy(__s + 0xc,param_1,0x10);
    iVar1 = s_icmp_send_pcb;
    *(undefined2 *)(s_icmp_send_pcb + 0x44) = 2;
    *(undefined1 *)(iVar1 + 0x46) = 1;
    uVar4 = esp_openthread_get_lwip_backbone_netif();
    raw_bind_netif(iVar1,uVar4);
    memcpy(auStack_38,&_L0,0x18);
    iVar1 = raw_sendto(s_icmp_send_pcb,iVar3,auStack_38);
    iVar1 = -(uint)(iVar1 != 0);
    pbuf_free(iVar3);
  }
  return iVar1;
}

