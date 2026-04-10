/*
 * Last changed at upstream commit 70a7322bfe4dd130c7cf9a94b8dbbeb0dbae0687
 * https://github.com/espressif/esp-thread-lib/commit/70a7322bfe4dd130c7cf9a94b8dbbeb0dbae0687
 * Upstream date: 2026-04-10 09:53:42 +0000
 * Upstream subject: feat(openthread/lib): update thread-lib for upstream a98813b30
 * Source: libopenthread_br -> esp_openthread_infra_if.cpp.o -> dhcp6_pd_listen_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* dhcp6_pd_listen_task(void*) */

undefined4 dhcp6_pd_listen_task(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = netif_get_by_index(*(undefined1 *)((int)param_1 + 4));
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Netif index %lu not found\n",uVar2,
            "dhcp6_pd_listen_task",0x14d,*(undefined4 *)((int)param_1 + 4));
    uVar2 = 0x102;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (*param_1 == '\0') {
      if (s_dhcp6_pd_pcb != 0) {
        udp_remove();
        s_dhcp6_pd_pcb = 0;
      }
    }
    else if (s_dhcp6_pd_pcb == 0) {
      iVar1 = udp_new_ip_type(6);
      s_dhcp6_pd_pcb = iVar1;
      if (iVar1 == 0) {
        uVar2 = esp_log_timestamp();
        esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Failed to allocate PCB\n",uVar2,
                "dhcp6_pd_listen_task",0x156);
        uVar2 = esp_log_timestamp();
        esp_log(1,"OPENTHREAD","E (%lu) %s: Finished dhcp6_pd_listen_task with some errors\n",uVar2)
        ;
        return 0x101;
      }
      uVar2 = *(undefined4 *)((int)param_1 + 4);
      *(undefined2 *)(iVar1 + 0x3a) = 0x222;
      *(char *)(iVar1 + 0x30) = (char)uVar2;
      udp_bind(&ip_addr_any_type);
      udp_recv(s_dhcp6_pd_pcb,dhcp6_pd_recv_cb,0);
    }
    uVar2 = 0;
  }
  return uVar2;
}

