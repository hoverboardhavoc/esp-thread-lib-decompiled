/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
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
      iVar1 = otBorderRoutingInit(*(char *)(param_1 + 0x18a) + '\x01',*(byte *)(param_1 + 0x187) & 1
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

