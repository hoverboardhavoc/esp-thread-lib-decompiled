/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_infra_if_second.o -> notify_lwip_send_ra
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 notify_lwip_send_ra(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if ((s_netif_ra_enabled != '\x01') && (param_1 != 0)) {
    uVar2 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Invalid state for sending RA on the second netif\n",
            uVar2,"notify_lwip_send_ra",0xa8);
    return 0xffffffff;
  }
  iVar1 = 0;
  do {
    sys_untimeout(second_netif_ra_send,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 != 5);
  if (param_1 == 3) {
    uVar2 = 0xfa;
    uVar4 = 0x2ee;
  }
  else {
    if (3 < param_1) {
      if (param_1 != 4) {
_L39:
        uVar2 = esp_log_timestamp();
        esp_log(1,"OPENTHREAD","E (%lu) %s: Invalid state to notify lwip to send RA\n",uVar2);
        return 0xffffffff;
      }
      iVar1 = esp_timer_get_time();
      uVar3 = 500;
      if (0x7a507 < (uint)(iVar1 - s_ra_moment_last)) {
        uVar3 = esp_random();
        uVar3 = uVar3 % 500;
      }
      goto _L41;
    }
    if (param_1 == 0) {
      s_netif_ra_enabled = '\x01';
    }
    else if (param_1 != 1) goto _L39;
    uVar2 = 2000;
    uVar4 = 10000;
  }
  s_ra_txCount = 0;
  uVar3 = generate_random_time(uVar4,uVar2);
_L41:
  sys_timeout(uVar3,second_netif_ra_send,param_1);
  return 0;
}

