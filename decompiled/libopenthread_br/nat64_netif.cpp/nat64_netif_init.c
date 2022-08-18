/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_br -> nat64_netif.cpp.o -> nat64_netif_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nat64_netif_init(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if ((s_nat64_netif[0x187] & 1) == 0) {
    memset(s_nat64_netif,0,0x1a4);
    esp_openthread_get_backbone_netif();
    uVar4 = to_underlying_lwip_netif();
    iVar1 = netif_add(s_nat64_netif,0,0,0,0,netif_init_internal,&tcpip_input);
    if (iVar1 == 0) {
      uVar2 = esp_log_timestamp();
      uVar4 = 0xe8;
      puVar3 = &_LC13;
    }
    else {
      netif_set_link_up(s_nat64_netif);
      netif_set_up(s_nat64_netif);
      s_nat64_netif._360_4_ = 0;
      s_backbone_raw_pcb = raw_new_ip_type(0,6);
      if (s_backbone_raw_pcb == 0) {
        uVar2 = esp_log_timestamp();
        uVar4 = 0xf0;
        puVar3 = &_LC14;
      }
      else {
        s_backbone_icmp_raw_pcb = raw_new_ip_type(0,1);
        if (s_backbone_icmp_raw_pcb != 0) {
          raw_bind_netif(s_backbone_raw_pcb,uVar4);
          raw_bind_netif(s_backbone_icmp_raw_pcb,uVar4);
          raw_recv(s_backbone_raw_pcb,tcp_raw_recv_handler,0);
          raw_recv(s_backbone_icmp_raw_pcb,icmp_raw_recv_handler,0);
          return 0;
        }
        uVar2 = esp_log_timestamp();
        uVar4 = 0xf2;
        puVar3 = &_LC15;
      }
    }
    esp_log_write(1,"NAT64",puVar3,uVar2,"NAT64","nat64_netif_init",uVar4);
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

