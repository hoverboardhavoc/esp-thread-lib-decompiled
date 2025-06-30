/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_infra_if_second.o -> second_netif_ra_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void second_netif_ra_send(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_a0 [32];
  undefined1 auStack_80 [36];
  undefined1 auStack_5c [20];
  undefined4 uStack_48;
  undefined2 uStack_44;
  undefined1 auStack_34 [28];
  
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  uVar2 = esp_openthread_get_instance();
  uVar3 = otThreadGetDeviceRole();
  esp_openthread_task_switching_lock_release();
  iVar4 = nd6_create_ra_with_hdr(0x68);
  if (iVar4 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Failed to create header for br second netif ra\n",
            uVar2,"br_second_netif_create_ra",0x4a);
  }
  else {
    memcpy(auStack_34,s_netif_prefix,0x10);
    memcpy(auStack_80,auStack_34,0x14);
    nd6_append_option_pio(iVar4,auStack_80,s_netif_prefix[0x10],0x708);
    bVar1 = 1 < uVar3;
    if ((param_1 == 3) || (bVar1)) {
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      iVar5 = otBorderRoutingGetOnLinkPrefix(uVar2,auStack_5c);
      iVar6 = otBorderRoutingGetOmrPrefix(uVar2,&uStack_48);
      esp_openthread_task_switching_lock_release();
      if (iVar5 == 0) {
        memcpy(auStack_a0,auStack_5c,0x11);
        append_rio_to_ra(iVar4,auStack_a0,bVar1);
      }
      if (iVar6 == 0) {
        memcpy(auStack_a0,&uStack_48,0x11);
        append_rio_to_ra(iVar4,auStack_a0,bVar1);
      }
    }
    esp_netif_get_handle_from_netif_impl(s_netif);
    uStack_48 = 0;
    uStack_44 = 0;
    iVar5 = esp_netif_get_mac(&uStack_48);
    if (iVar5 == 0) {
      nd6_append_option_sll(iVar4,&uStack_48);
      ip6addr_aton("FF02::1",auStack_34);
      memcpy(auStack_80,auStack_34,0x14);
      iVar5 = icmp6_raw_send(s_raw_pcb,auStack_80,iVar4,1);
      if (iVar5 != 0) {
        uVar2 = esp_log_timestamp();
        esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to send RA on the second netif\n",uVar2);
      }
      pbuf_free(iVar4);
      goto _L85;
    }
    uVar2 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Failed to get mac addr of the second netif\n",uVar2,
            "br_second_netif_create_ra",0x6b);
    pbuf_free(iVar4);
  }
  uVar2 = esp_log_timestamp();
  esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Failed to create RA for the second netif\n",uVar2,
          "create_and_send_second_netif_ra",0x7e);
_L85:
  s_ra_moment_last = esp_timer_get_time();
  if (s_netif_ra_enabled != '\0') {
    if (s_ra_txCount < 4) {
      s_ra_txCount = s_ra_txCount + 1;
      generate_random_time(10000,2000);
      uVar2 = 1;
    }
    else {
      generate_random_time(180000,5000);
      uVar2 = 2;
    }
    sys_timeout(second_netif_ra_send,uVar2);
    return;
  }
  return;
}

