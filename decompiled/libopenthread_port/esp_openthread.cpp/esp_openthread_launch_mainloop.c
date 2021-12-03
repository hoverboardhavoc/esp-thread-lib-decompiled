/*
 * Last changed at upstream commit e527d6b8e8720c9bde49fec26e19cf437458e3b3
 * https://github.com/espressif/esp-thread-lib/commit/e527d6b8e8720c9bde49fec26e19cf437458e3b3
 * Upstream date: 2021-12-03 11:59:45 +0800
 * Upstream subject: port: aggressively process pending tasks (eb7a7fb)
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
  fd_set *pfVar3;
  int iVar4;
  fd_set *pfVar5;
  undefined1 local_44 [8];
  undefined1 auStack_3c [8];
  undefined1 auStack_34 [8];
  int iStack_2c;
  timeval atStack_28 [2];
  
  uVar1 = esp_openthread_get_instance();
  while( true ) {
    iVar4 = 0;
    do {
      local_44[iVar4] = 0;
      iVar4 = iVar4 + 1;
    } while (iVar4 != 8);
    pfVar5 = (fd_set *)local_44;
    pfVar3 = pfVar5;
    do {
      *(undefined1 *)(pfVar3->fds_bits + 2) = 0;
      pfVar3 = (fd_set *)((int)pfVar3->fds_bits + 1);
    } while (pfVar3 != (fd_set *)auStack_3c);
    do {
      *(undefined1 *)(pfVar5->fds_bits + 4) = 0;
      pfVar5 = (fd_set *)((int)pfVar5->fds_bits + 1);
    } while (pfVar5 != (fd_set *)auStack_3c);
    atStack_28[0].tv_sec = 10;
    iStack_2c = -1;
    atStack_28[0].tv_usec = 0;
    esp_openthread_lock_acquire(0xffffffff);
    esp_openthread_platform_update(local_44);
    iVar4 = otTaskletsArePending(uVar1);
    if (iVar4 != 0) {
      atStack_28[0].tv_sec = 0;
      atStack_28[0].tv_usec = 0;
    }
    esp_openthread_lock_release();
    iVar4 = select(iStack_2c + 1,(fd_set *)local_44,(fd_set *)auStack_3c,(fd_set *)auStack_34,
                   atStack_28);
    if (iVar4 < 0) break;
    esp_openthread_lock_acquire(0xffffffff);
    iVar4 = esp_openthread_platform_process(uVar1,local_44);
    while (iVar2 = otTaskletsArePending(uVar1), iVar2 != 0) {
      otTaskletsProcess(uVar1);
    }
    esp_openthread_lock_release();
    if (iVar4 != 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC3,uVar1,"OPENTHREAD");
      return iVar4;
    }
  }
  uVar1 = esp_log_timestamp();
  esp_log_write(1,"OPENTHREAD",&_LC4,uVar1,"OPENTHREAD");
  return -1;
}

