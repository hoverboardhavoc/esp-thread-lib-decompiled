/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
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
  undefined *puVar4;
  
  esp_openthread_get_backbone_netif();
  uVar1 = to_underlying_lwip_netif();
  iVar2 = netif_add(s_nat64_netif,0,0,0,0,netif_init_internal,&tcpip_input);
  if (iVar2 == 0) {
    uVar3 = esp_log_timestamp();
    uVar1 = 0xe8;
    puVar4 = &_LC2;
  }
  else {
    netif_set_link_up(s_nat64_netif);
    netif_set_up(s_nat64_netif);
    s_nat64_netif._360_4_ = 0;
    s_backbone_raw_pcb = raw_new_ip_type(0,6);
    if (s_backbone_raw_pcb == 0) {
      uVar3 = esp_log_timestamp();
      uVar1 = 0xf0;
      puVar4 = &_LC3;
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
      puVar4 = &_LC4;
    }
  }
  esp_log_write(1,"NAT64",puVar4,uVar3,"NAT64","nat64_netif_do_init",uVar1);
  return 0xffffffff;
}

