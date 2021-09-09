/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_udp.o -> udp_send_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void udp_send_task(undefined4 *param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  
  uVar3 = otMessageGetLength(param_1[1]);
  pvVar5 = (void *)*param_1;
  *(undefined1 *)((int)pvVar5 + 0x33) = *(undefined1 *)((int)param_1 + 0x3b);
  uVar1 = *(undefined1 *)(param_1 + 0xf);
  *(undefined1 *)((int)pvVar5 + 0x30) = uVar1;
  if (*(char *)(param_1 + 0xd) == '\x06') {
    *(undefined1 *)(param_1 + 0xc) = uVar1;
  }
  if (*(char *)(param_1 + 7) == '\x06') {
    *(undefined1 *)(param_1 + 6) = uVar1;
  }
  bVar2 = *(byte *)((int)pvVar5 + 0x38) & 0xf7;
  *(byte *)((int)pvVar5 + 0x38) = bVar2;
  pvVar5 = memcpy(pvVar5,param_1 + 2,0x18);
  if (*(char *)((int)param_1 + 0x3a) != '\0') {
    *(byte *)((int)pvVar5 + 0x38) = bVar2 | 8;
  }
  iVar4 = pbuf_alloc(0x4a,uVar3,0x280);
  otMessageRead(param_1[1],0,*(undefined4 *)(iVar4 + 4),uVar3);
  udp_sendto(*param_1,iVar4,param_1 + 8,*(undefined2 *)(param_1 + 0xe));
  pbuf_free(iVar4);
  esp_openthread_lock_acquire(0xffffffff);
  otMessageFree(param_1[1]);
  esp_openthread_lock_release();
  free(param_1);
  return;
}

