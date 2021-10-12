/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
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
  *(undefined1 *)((int)pvVar5 + 0x33) = *(undefined1 *)((int)param_1 + 0x3f);
  uVar1 = *(undefined1 *)(param_1 + 0x10);
  *(undefined1 *)((int)pvVar5 + 0x30) = uVar1;
  if (*(char *)(param_1 + 0xe) == '\x06') {
    *(undefined1 *)(param_1 + 0xd) = uVar1;
  }
  if (*(char *)(param_1 + 7) == '\x06') {
    *(undefined1 *)(param_1 + 6) = uVar1;
  }
  bVar2 = *(byte *)((int)pvVar5 + 0x38) & 0xf7;
  *(byte *)((int)pvVar5 + 0x38) = bVar2;
  pvVar5 = memcpy(pvVar5,param_1 + 2,0x18);
  *(undefined2 *)((int)pvVar5 + 0x3a) = *(undefined2 *)(param_1 + 8);
  if (*(char *)((int)param_1 + 0x3e) != '\0') {
    *(byte *)((int)pvVar5 + 0x38) = bVar2 | 8;
  }
  iVar4 = pbuf_alloc(0x4a,uVar3,0x280);
  otMessageRead(param_1[1],0,*(undefined4 *)(iVar4 + 4),uVar3);
  udp_sendto(*param_1,iVar4,param_1 + 9,*(undefined2 *)(param_1 + 0xf));
  pbuf_free(iVar4);
  esp_openthread_lock_acquire(0xffffffff);
  otMessageFree(param_1[1]);
  esp_openthread_lock_release();
  free(param_1);
  return;
}

