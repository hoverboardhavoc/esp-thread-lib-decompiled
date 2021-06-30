/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_udp.o -> udp_send_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void udp_send_task(void *ctx)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = otMessageGetLength(*(undefined4 *)((int)ctx + 4));
                    /* WARNING: Load size is inaccurate */
  *(undefined1 *)(*ctx + 0x33) = *(undefined1 *)((int)ctx + 0x23);
                    /* WARNING: Load size is inaccurate */
  uVar1 = *(undefined1 *)((int)ctx + 0x24);
  *(undefined1 *)(*ctx + 0x30) = uVar1;
  if (*(char *)((int)ctx + 0x1c) == '\x06') {
    *(undefined1 *)((int)ctx + 0x18) = uVar1;
  }
                    /* WARNING: Load size is inaccurate */
  *(byte *)(*ctx + 0x38) = *(byte *)(*ctx + 0x38) & 0xf7;
  if (*(char *)((int)ctx + 0x22) != '\0') {
                    /* WARNING: Load size is inaccurate */
    *(byte *)(*ctx + 0x38) = *(byte *)(*ctx + 0x38) | 8;
  }
  iVar3 = pbuf_alloc(0x4a,uVar2,0x280);
  otMessageRead(*(undefined4 *)((int)ctx + 4),0,*(undefined4 *)(iVar3 + 4),uVar2);
  if (iVar3 != 0) {
                    /* WARNING: Load size is inaccurate */
    udp_sendto(*ctx,iVar3,(int)ctx + 8,*(undefined2 *)((int)ctx + 0x20));
    pbuf_free(iVar3);
  }
  esp_openthread_lock_acquire(0xffffffff);
  otMessageFree(*(undefined4 *)((int)ctx + 4));
  esp_openthread_lock_release();
  free(ctx);
  return;
}

