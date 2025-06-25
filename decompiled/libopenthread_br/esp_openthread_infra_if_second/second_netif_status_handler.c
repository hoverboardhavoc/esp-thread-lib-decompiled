/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_infra_if_second.o -> second_netif_status_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000103de) */
/* WARNING: Removing unreachable block (ram,0x00010488) */
/* WARNING: Removing unreachable block (ram,0x00010442) */
/* WARNING: Removing unreachable block (ram,0x00010412) */
/* WARNING: Removing unreachable block (ram,0x00010434) */
/* WARNING: Removing unreachable block (ram,0x0001040c) */
/* WARNING: Removing unreachable block (ram,0x000103e2) */
/* WARNING: Removing unreachable block (ram,0x00010370) */
/* WARNING: Removing unreachable block (ram,0x000103a4) */

undefined4 second_netif_status_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (((*(byte *)(s_netif + 0x20f) & 1) != 0) && (s_netif_ra_enabled == '\0')) {
    iVar1 = 0;
    do {
      iVar2 = iVar1 + 1;
      sys_untimeout(second_netif_ra_send,iVar1);
      iVar1 = iVar2;
    } while (iVar2 != 5);
    s_ra_txCount = 0;
    s_netif_ra_enabled = 1;
    uVar3 = generate_random_time(10000,2000);
    sys_timeout(uVar3,second_netif_ra_send,0);
    return 0;
  }
  if ((*(byte *)(s_netif + 0x20f) & 1) != 0) {
    return param_1;
  }
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    uVar3 = sys_untimeout(second_netif_ra_send,iVar1);
    iVar1 = iVar2;
  } while (iVar2 != 5);
  s_netif_ra_enabled = 0;
  return uVar3;
}

