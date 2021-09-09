/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> esp_openthread_infra_if_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_infra_if_init(int param_1)

{
  int iVar1;
  undefined1 auStack_28 [28];
  
  memcpy(auStack_28,&_LANCHOR2,0x18);
  iVar1 = 0x103;
  if ((s_raw_pcb == 0) && (iVar1 = 0x102, param_1 != 0)) {
    iVar1 = mld6_joingroup_netif(param_1,auStack_28);
    if (iVar1 == 0) {
      iVar1 = raw_new_ip_type(6,0x3a);
      s_raw_pcb = iVar1;
      *(byte *)(iVar1 + 0x39) = *(byte *)(iVar1 + 0x39) | 4;
      *(undefined1 *)(iVar1 + 0x46) = 1;
      *(undefined2 *)(iVar1 + 0x44) = 2;
      raw_bind_netif(param_1);
      raw_recv(s_raw_pcb,icmp6_raw_recv_handler,param_1);
      netif_set_status_callback(param_1,0x10000);
      s_netif = param_1;
      esp_openthread_get_instance();
      iVar1 = otBorderRoutingInit(*(char *)(param_1 + 0x196) + '\x01',*(byte *)(param_1 + 0x193) & 1
                                 );
      if (iVar1 == 0) {
        esp_openthread_get_instance();
        iVar1 = otBorderRoutingSetEnabled(1);
        return -(uint)(iVar1 != 0);
      }
    }
    iVar1 = -1;
  }
  return iVar1;
}

