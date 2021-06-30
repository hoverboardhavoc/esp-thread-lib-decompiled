/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_udp.o -> udp_recv_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void udp_recv_task(void *ctx)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  void *pvVar7;
  void *__ptr;
  undefined1 auStack_54 [4];
  otMessageSettings msg_settings;
  otMessageInfo message_info;
  
  auStack_54[0] = 0;
  msg_settings.mLinkSecurityEnabled = true;
  msg_settings._1_3_ = 0;
  piVar2 = *(int **)((int)ctx + 4);
  pvVar7 = (void *)piVar2[1];
  message_info.mPeerAddr.mFields.m16[6] = 0;
  msg_settings.mPriority = OT_MESSAGE_PRIORITY_LOW;
  message_info.mSockAddr.mFields.m32[0] = 0;
  message_info.mSockAddr.mFields.m32[1] = 0;
  message_info.mSockAddr.mFields.m32[2] = 0;
  message_info.mLinkInfo._0_1_ = *(undefined1 *)((int)ctx + 0x22);
  message_info.mPeerAddr.mFields.m16[7] = *(uint16_t *)((int)ctx + 0x20);
  if (*(char *)((int)ctx + 0x1c) == '\0') {
    *(undefined4 *)((int)ctx + 0x14) = *(undefined4 *)((int)ctx + 8);
    *(undefined4 *)((int)ctx + 0x10) = 0xffff0000;
    *(undefined4 *)((int)ctx + 0xc) = 0;
    *(undefined4 *)((int)ctx + 8) = 0;
    *(undefined1 *)((int)ctx + 0x18) = 0;
  }
  memcpy((void *)((int)&message_info.mSockAddr.mFields + 0xc),(void *)((int)ctx + 8),0x10);
  __ptr = (void *)*piVar2;
  if ((void *)*piVar2 != (void *)0x0) {
    uVar1 = *(ushort *)(piVar2 + 2);
    pvVar7 = malloc((uint)uVar1);
    __ptr = pvVar7;
    if (pvVar7 != (void *)0x0) {
      pbuf_copy_partial(piVar2,pvVar7,(uint)uVar1,0);
    }
  }
  if (pvVar7 == (void *)0x0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC3,uVar5,"OPENTHREAD");
  }
  else {
    esp_openthread_get_instance();
    iVar3 = otUdpNewMessage(auStack_54);
    if (iVar3 == 0) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC4,uVar5,"OPENTHREAD");
    }
    else {
      iVar4 = otMessageAppend(pvVar7,(short)piVar2[2]);
      if (iVar4 == 0) {
                    /* WARNING: Load size is inaccurate */
        pcVar6 = *(code **)(*ctx + 0x24);
        (*pcVar6)(*(undefined4 *)(*ctx + 0x28),iVar3,&msg_settings.mPriority,pcVar6);
        otMessageFree(iVar3);
      }
      else {
        uVar5 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC5,uVar5,"OPENTHREAD");
      }
    }
  }
  free(ctx);
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  pbuf_free(piVar2);
  return;
}

