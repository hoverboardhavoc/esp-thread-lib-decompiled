/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_infra_if_second.o -> second_netif_do_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 second_netif_do_init(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_28 [28];
  
  s_ra_txCount = 0;
  s_ra_moment_last = esp_timer_get_time();
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
    raw_recv(s_raw_pcb,icmp6_recv_second_handler,s_netif);
    netif_set_status_callback(s_netif,second_netif_status_handler);
    uVar2 = 0;
  }
  return uVar2;
}

