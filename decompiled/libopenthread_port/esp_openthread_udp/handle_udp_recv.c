/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_udp.o -> handle_udp_recv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void handle_udp_recv(undefined4 param_1,undefined4 param_2,void *param_3,undefined2 param_4)

{
  char cVar1;
  undefined1 uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined4 *__ptr;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  
  __ptr = (undefined4 *)malloc(0x24);
  iVar5 = _memcpy;
  iVar4 = _esp_log_write;
  iVar8 = _ip_data;
  if (__ptr == (undefined4 *)0x0) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC1,uVar6,"OPENTHREAD");
  }
  *__ptr = param_1;
  __ptr[1] = param_2;
  memcpy(__ptr + 2,param_3,0x18);
  cVar1 = *(char *)((int)param_3 + 0x14);
  *(undefined2 *)(__ptr + 8) = param_4;
  if (cVar1 == '\x06') {
    uVar2 = *(undefined1 *)(iVar5 + 7);
  }
  else {
    uVar2 = *(undefined1 *)(iVar4 + 8);
  }
  *(undefined1 *)((int)__ptr + 0x22) = uVar2;
  bVar3 = *(byte *)(iVar8 + 0x196);
  esp_openthread_get_backbone_netif();
  uVar7 = esp_netif_get_netif_impl_index();
  *(bool *)((int)__ptr + 0x23) = (bVar3 + 1 & 0xff) == uVar7;
  iVar8 = esp_openthread_task_queue_post(udp_recv_task,__ptr);
  if (iVar8 != 0) {
    free(__ptr);
    return;
  }
  return;
}

