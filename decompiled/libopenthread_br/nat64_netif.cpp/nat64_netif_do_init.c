/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> nat64_netif.cpp.o -> nat64_netif_do_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* nat64_netif_do_init(void*) */

undefined4 nat64_netif_do_init(void *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  esp_openthread_get_backbone_netif();
  uVar1 = to_underlying_lwip_netif();
  iVar2 = netif_add(s_nat64_netif,0,0,0,0,netif_init_internal,&tcpip_input);
  if (iVar2 == 0) {
    uVar3 = esp_log_timestamp();
    uVar1 = 0xe8;
    pcVar4 = "E (%lu) %s: %s(%d): Failed to add nat64 interface\n";
  }
  else {
    netif_set_link_up(s_nat64_netif);
    netif_set_up(s_nat64_netif);
    s_nat64_netif._492_4_ = 0;
    s_backbone_raw_pcb = raw_new_ip_type(0,6);
    if (s_backbone_raw_pcb == 0) {
      uVar3 = esp_log_timestamp();
      uVar1 = 0xf0;
      pcVar4 = "E (%lu) %s: %s(%d): Failed to create backbone raw socket\n";
    }
    else {
      s_backbone_icmp_raw_pcb = raw_new_ip_type(0,1);
      if (s_backbone_icmp_raw_pcb != 0) {
        raw_bind_netif(s_backbone_raw_pcb,uVar1);
        raw_bind_netif(s_backbone_icmp_raw_pcb,uVar1);
        raw_recv(s_backbone_raw_pcb,tcp_raw_recv_handler,0);
        raw_recv(s_backbone_icmp_raw_pcb,icmp_raw_recv_handler,0);
        s_nat64_netif_initialized = 1;
        return 0;
      }
      uVar3 = esp_log_timestamp();
      uVar1 = 0xf2;
      pcVar4 = "E (%lu) %s: %s(%d): Failed to create backbone raw icmp pcb\n";
    }
  }
  esp_log(1,"NAT64",pcVar4,uVar3,"nat64_netif_do_init",uVar1);
  return 0xffffffff;
}

