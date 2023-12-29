/*
 * Last changed at upstream commit e0969fc15c1991d91446a0dc5e4625ed2c0bb014
 * https://github.com/espressif/esp-thread-lib/commit/e0969fc15c1991d91446a0dc5e4625ed2c0bb014
 * Upstream date: 2023-12-29 15:19:41 +0800
 * Upstream subject: feat(br): update border router lib         esp-openthread: 3db472c         openthread: 41ef807
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> infra_if_do_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 infra_if_do_init(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_28 [28];
  
  memcpy(auStack_28,&_LANCHOR0,0x18);
  iVar1 = mld6_joingroup_netif(s_netif,auStack_28);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    s_raw_pcb = raw_new_ip_type(6,0x3a);
    *(undefined1 *)(s_raw_pcb + 0x33) = 0xff;
    *(undefined1 *)(s_raw_pcb + 0x3b) = 0xff;
    uVar2 = s_netif;
    *(byte *)(s_raw_pcb + 0x39) = *(byte *)(s_raw_pcb + 0x39) | 4;
    *(undefined1 *)(s_raw_pcb + 0x46) = 1;
    *(undefined2 *)(s_raw_pcb + 0x44) = 2;
    raw_bind_netif(uVar2);
    raw_recv(s_raw_pcb,icmp6_raw_recv_handler,s_netif);
    netif_set_status_callback(s_netif,netif_status_handler);
    uVar2 = 0;
  }
  return uVar2;
}

