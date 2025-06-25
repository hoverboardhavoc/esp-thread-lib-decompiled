/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_infra_if_second.o -> notify_lwip_send_ra
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 notify_lwip_send_ra(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar1 = 0;
  if ((s_netif_ra_enabled == '\0') && (param_1 != 0)) {
    uVar3 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Invalid state for sending RA on the second netif\n",
            uVar3,"OPENTHREAD","notify_lwip_send_ra",0xa8);
    return 0xffffffff;
  }
  do {
    iVar2 = iVar1 + 1;
    sys_untimeout(second_netif_ra_send,iVar1);
    iVar1 = iVar2;
  } while (iVar2 != 5);
  if (param_1 == 3) {
    uVar3 = 0xfa;
    uVar5 = 0x2ee;
  }
  else {
    if (3 < param_1) {
      if (param_1 != 4) {
_L0:
        uVar3 = esp_log_timestamp();
        esp_log(1,"OPENTHREAD","E (%lu) %s: Invalid state to notify lwip to send RA\n",uVar3,
                "OPENTHREAD");
        return 0xffffffff;
      }
      iVar1 = esp_timer_get_time();
      uVar4 = 500;
      if (0x7a507 < (uint)(iVar1 - s_ra_moment_last)) {
        uVar4 = esp_random();
        uVar4 = uVar4 % 500;
      }
      goto _L0;
    }
    if (param_1 == 0) {
      s_netif_ra_enabled = '\x01';
    }
    else if (param_1 != 1) goto _L0;
    uVar3 = 2000;
    uVar5 = 10000;
  }
  s_ra_txCount = 0;
  uVar4 = generate_random_time(uVar5,uVar3);
_L0:
  sys_timeout(uVar4,second_netif_ra_send,param_1);
  return 0;
}

