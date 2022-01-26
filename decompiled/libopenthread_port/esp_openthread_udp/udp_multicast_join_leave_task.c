/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
 * Source: libopenthread_port -> esp_openthread_udp.o -> udp_multicast_join_leave_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void udp_multicast_join_leave_task(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  if (*param_1 == '\0') {
    netif_get_by_index(param_1[1]);
    iVar1 = mld6_leavegroup_netif(param_1 + 4);
    if (iVar1 == 0) goto _L0;
    uVar2 = esp_log_timestamp();
    puVar3 = &_LC6;
  }
  else {
    netif_get_by_index();
    iVar1 = mld6_joingroup_netif(param_1 + 4);
    if (iVar1 == 0) goto _L0;
    uVar2 = esp_log_timestamp();
    puVar3 = &_LC5;
  }
  esp_log_write(1,"OPENTHREAD",puVar3,uVar2,"OPENTHREAD");
_L0:
  free(param_1);
  return;
}

