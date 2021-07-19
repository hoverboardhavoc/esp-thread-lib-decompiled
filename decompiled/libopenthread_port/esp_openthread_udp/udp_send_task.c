/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_port -> esp_openthread_udp.o -> udp_send_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void udp_send_task(int *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  uVar2 = otMessageGetLength(param_1[1]);
  *(undefined1 *)(*param_1 + 0x33) = *(undefined1 *)((int)param_1 + 0x3b);
  uVar1 = (undefined1)param_1[0xf];
  *(undefined1 *)(*param_1 + 0x30) = uVar1;
  if ((char)param_1[0xd] == '\x06') {
    *(undefined1 *)(param_1 + 0xc) = uVar1;
  }
  if ((char)param_1[7] == '\x06') {
    *(undefined1 *)(param_1 + 6) = uVar1;
  }
  *(byte *)(*param_1 + 0x38) = *(byte *)(*param_1 + 0x38) & 0xf7;
  piVar8 = (int *)*param_1;
  iVar3 = param_1[3];
  iVar4 = param_1[4];
  iVar5 = param_1[5];
  iVar6 = param_1[6];
  iVar7 = param_1[7];
  *piVar8 = param_1[2];
  piVar8[1] = iVar3;
  piVar8[2] = iVar4;
  piVar8[3] = iVar5;
  piVar8[4] = iVar6;
  piVar8[5] = iVar7;
  if (*(char *)((int)param_1 + 0x3a) != '\0') {
    *(byte *)(*param_1 + 0x38) = *(byte *)(*param_1 + 0x38) | 8;
  }
  iVar3 = pbuf_alloc(0x4a,uVar2,0x280);
  otMessageRead(param_1[1],0,*(undefined4 *)(iVar3 + 4),uVar2);
  if (iVar3 != 0) {
    udp_sendto(*param_1,iVar3,param_1 + 8,(short)param_1[0xe]);
    pbuf_free(iVar3);
  }
  esp_openthread_lock_acquire(0xffffffff);
  otMessageFree(param_1[1]);
  esp_openthread_lock_release();
  free(param_1);
  return;
}

