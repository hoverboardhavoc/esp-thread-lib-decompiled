/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
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
  int iVar3;
  __fd_mask local_50 [6];
  int iStack_38;
  timeval tStack_30;
  __fd_mask _Stack_28;
  
  uVar1 = esp_openthread_get_instance();
  do {
    local_50[1] = 0;
    local_50[0] = 0;
    local_50[3] = 0;
    local_50[2] = 0;
    local_50[5] = 0;
    local_50[4] = 0;
    iStack_38 = -1;
    tStack_30.tv_sec = 10;
    tStack_30.tv_usec = 0;
    _Stack_28 = 0;
    esp_openthread_lock_acquire(0xffffffff);
    esp_openthread_platform_update(local_50);
    iVar2 = otTaskletsArePending(uVar1);
    if (iVar2 != 0) {
      tStack_30.tv_sec = 0;
      tStack_30.tv_usec = 0;
      _Stack_28 = 0;
    }
    esp_openthread_lock_release();
    iVar2 = select(iStack_38 + 1,(fd_set *)local_50,(fd_set *)(local_50 + 2),
                   (fd_set *)(local_50 + 4),&tStack_30);
    if (iVar2 < 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC5,uVar1,"OPENTHREAD");
      return -1;
    }
    esp_openthread_lock_acquire(0xffffffff);
    iVar2 = esp_openthread_platform_process(uVar1,local_50);
    while (iVar3 = otTaskletsArePending(uVar1), iVar3 != 0) {
      otTaskletsProcess(uVar1);
    }
    esp_openthread_lock_release();
  } while (iVar2 == 0);
  uVar1 = esp_log_timestamp();
  esp_log_write(1,"OPENTHREAD",&_L0,uVar1,"OPENTHREAD");
  return iVar2;
}

