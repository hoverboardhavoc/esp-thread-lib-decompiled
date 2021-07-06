/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_udp.o -> udp_send_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void udp_send_task(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = otMessageGetLength(param_1[1]);
  *(undefined1 *)(*param_1 + 0x33) = *(undefined1 *)((int)param_1 + 0x23);
  iVar2 = param_1[9];
  *(char *)(*param_1 + 0x30) = (char)iVar2;
  if ((char)param_1[7] == '\x06') {
    *(char *)(param_1 + 6) = (char)iVar2;
  }
  *(byte *)(*param_1 + 0x38) = *(byte *)(*param_1 + 0x38) & 0xf7;
  if (*(char *)((int)param_1 + 0x22) != '\0') {
    *(byte *)(*param_1 + 0x38) = *(byte *)(*param_1 + 0x38) | 8;
  }
  iVar2 = pbuf_alloc(0x4a,uVar1,0x280);
  otMessageRead(param_1[1],0,*(undefined4 *)(iVar2 + 4),uVar1);
  if (iVar2 != 0) {
    udp_sendto(*param_1,iVar2,param_1 + 2,(short)param_1[8]);
    pbuf_free(iVar2);
  }
  esp_openthread_lock_acquire(0xffffffff);
  otMessageFree(param_1[1]);
  esp_openthread_lock_release();
  free(param_1);
  return;
}

