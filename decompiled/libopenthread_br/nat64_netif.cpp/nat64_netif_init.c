/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> nat64_netif.cpp.o -> nat64_netif_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nat64_netif_init(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  uVar1 = 0;
  if ((s_nat64_netif[0x187] & 1) == 0) {
    memset(s_nat64_netif,0,0x1a4);
    esp_openthread_get_backbone_netif();
    uVar1 = to_underlying_lwip_netif();
    iVar2 = netif_add(s_nat64_netif,0,0,0,0,netif_init_internal,&tcpip_input);
    if (iVar2 == 0) {
      uVar3 = esp_log_timestamp();
      uVar1 = 0xb0;
      puVar4 = &_LC10;
    }
    else {
      netif_set_link_up(s_nat64_netif);
      netif_set_up(s_nat64_netif);
      s_nat64_netif._360_4_ = 0;
      s_backbone_raw_pcb = raw_new_ip_type(0,6);
      if (s_backbone_raw_pcb != 0) {
        raw_bind_netif(uVar1);
        raw_recv(s_backbone_raw_pcb,tcp_raw_recv_handler,0);
        return 0;
      }
      uVar3 = esp_log_timestamp();
      uVar1 = 0xb8;
      puVar4 = &_LC11;
    }
    esp_log_write(1,"NAT64",puVar4,uVar3,"NAT64","nat64_netif_init",uVar1);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

