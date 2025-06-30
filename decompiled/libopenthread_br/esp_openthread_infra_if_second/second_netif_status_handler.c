/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_infra_if_second.o -> second_netif_status_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000103e4) */
/* WARNING: Removing unreachable block (ram,0x0001048c) */
/* WARNING: Removing unreachable block (ram,0x00010446) */
/* WARNING: Removing unreachable block (ram,0x00010416) */
/* WARNING: Removing unreachable block (ram,0x00010438) */
/* WARNING: Removing unreachable block (ram,0x00010410) */
/* WARNING: Removing unreachable block (ram,0x000103e8) */
/* WARNING: Removing unreachable block (ram,0x0001036e) */
/* WARNING: Removing unreachable block (ram,0x000103a0) */

code * second_netif_status_handler(code *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((*(byte *)(s_netif + 0x20f) & 1) != 0) && (s_netif_ra_enabled == '\0')) {
    iVar2 = 0;
    do {
      sys_untimeout(second_netif_ra_send,iVar2);
      iVar2 = iVar2 + 1;
    } while (iVar2 != 5);
    s_ra_txCount = 0;
    s_netif_ra_enabled = 1;
    uVar1 = generate_random_time(10000,2000);
    sys_timeout(uVar1,second_netif_ra_send,0);
    return (code *)0x0;
  }
  if ((*(byte *)(s_netif + 0x20f) & 1) != 0) {
    return param_1;
  }
  iVar2 = 0;
  do {
    sys_untimeout(second_netif_ra_send);
    iVar2 = iVar2 + 1;
  } while (iVar2 != 5);
  s_netif_ra_enabled = 0;
  return second_netif_ra_send;
}

