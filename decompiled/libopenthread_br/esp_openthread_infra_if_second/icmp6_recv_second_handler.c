/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_infra_if_second.o -> icmp6_recv_second_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 icmp6_recv_second_handler(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_24 [20];
  
  if (*(ushort *)(param_1 + 8) < 0x29) {
    uVar1 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: Secondary netif received pbuf with unexpected length: %u\n",
            uVar1,"OPENTHREAD",*(undefined2 *)(param_1 + 8));
  }
  else {
    iVar3 = *(int *)(param_1 + 4);
    iVar2 = icmp6_raw_recv_handler(s_netif);
    if (iVar2 == 0) {
      memcpy(auStack_24,(void *)(iVar3 + 8),0x14);
      if (((*(char *)(*(int *)(param_1 + 4) + 0x28) == -0x7b) &&
          (iVar2 = is_address_from_netif(auStack_24,s_netif), iVar2 == 0)) &&
         (s_netif_ra_enabled != '\0')) {
        notify_lwip_send_ra(4);
      }
    }
  }
  return 0;
}

