/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread.cpp.o -> esp_openthread_launch_mainloop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_launch_mainloop(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined1 local_34 [8];
  undefined1 local_2c [8];
  undefined1 local_24 [8];
  int iStack_1c;
  timeval tStack_18;
  
  uVar1 = esp_openthread_get_instance();
  while( true ) {
    puVar3 = local_34;
    for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    puVar3 = local_2c;
    for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    puVar3 = local_24;
    for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    iStack_1c = -1;
    tStack_18.tv_sec = 10;
    tStack_18.tv_usec = 0;
    esp_openthread_lock_acquire(0xffffffff);
    esp_openthread_platform_update(local_34);
    iVar2 = otTaskletsArePending(uVar1);
    if (iVar2 != 0) {
      tStack_18.tv_sec = 0;
      tStack_18.tv_usec = 0;
    }
    esp_openthread_lock_release();
    iVar2 = select(iStack_1c + 1,(fd_set *)local_34,(fd_set *)local_2c,(fd_set *)local_24,&tStack_18
                  );
    if (iVar2 < 0) break;
    esp_openthread_lock_acquire(0xffffffff);
    otTaskletsProcess(uVar1);
    iVar2 = esp_openthread_platform_process(uVar1,local_34);
    esp_openthread_lock_release();
    if (iVar2 != 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC3,uVar1,"OPENTHREAD");
      return iVar2;
    }
  }
  uVar1 = esp_log_timestamp();
  esp_log_write(1,"OPENTHREAD",&_LC4,uVar1,"OPENTHREAD");
  return -1;
}

