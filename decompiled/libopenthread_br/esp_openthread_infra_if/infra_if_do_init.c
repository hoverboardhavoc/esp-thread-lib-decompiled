/*
 * Last changed at upstream commit e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * https://github.com/espressif/esp-thread-lib/commit/e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * Upstream date: 2023-06-02 12:00:23 +0800
 * Upstream subject: ot br lib: fix issues in certification esp-openthread: a158ca1 openthread:091f68e
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> infra_if_do_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int infra_if_do_init(void)

{
  int iVar1;
  undefined1 auStack_28 [28];
  
  memcpy(auStack_28,&_LANCHOR0,0x18);
  iVar1 = mld6_joingroup_netif(s_netif,auStack_28);
  if (iVar1 == 0) {
    s_raw_pcb = raw_new_ip_type(6,0x3a);
    iVar1 = s_netif;
    *(byte *)(s_raw_pcb + 0x39) = *(byte *)(s_raw_pcb + 0x39) | 4;
    *(undefined1 *)(s_raw_pcb + 0x46) = 1;
    *(undefined2 *)(s_raw_pcb + 0x44) = 2;
    raw_bind_netif(iVar1);
    raw_recv(s_raw_pcb,icmp6_raw_recv_handler,s_netif);
    netif_set_status_callback(s_netif,netif_status_handler);
    esp_openthread_get_instance();
    iVar1 = otBorderRoutingInit(*(char *)(s_netif + 0x18a) + '\x01',*(byte *)(s_netif + 0x187) & 1);
    if (iVar1 == 0) {
      esp_openthread_get_instance();
      iVar1 = otBorderRoutingSetEnabled(1);
      return -(uint)(iVar1 != 0);
    }
  }
  return -1;
}

