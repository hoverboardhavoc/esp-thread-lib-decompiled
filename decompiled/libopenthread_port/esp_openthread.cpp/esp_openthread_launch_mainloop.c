/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread.cpp.o -> esp_openthread_launch_mainloop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_launch_mainloop(void)

{
  undefined4 uVar1;
  fd_set *pfVar2;
  int iVar3;
  fd_set *pfVar4;
  undefined1 local_44 [8];
  undefined1 auStack_3c [8];
  undefined1 auStack_34 [8];
  int iStack_2c;
  timeval atStack_28 [2];
  
  uVar1 = esp_openthread_get_instance();
  while( true ) {
    iVar3 = 0;
    do {
      local_44[iVar3] = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 != 8);
    pfVar4 = (fd_set *)local_44;
    pfVar2 = pfVar4;
    do {
      *(undefined1 *)(pfVar2->fds_bits + 2) = 0;
      pfVar2 = (fd_set *)((int)pfVar2->fds_bits + 1);
    } while (pfVar2 != (fd_set *)auStack_3c);
    do {
      *(undefined1 *)(pfVar4->fds_bits + 4) = 0;
      pfVar4 = (fd_set *)((int)pfVar4->fds_bits + 1);
    } while (pfVar4 != (fd_set *)auStack_3c);
    atStack_28[0].tv_sec = 10;
    iStack_2c = -1;
    atStack_28[0].tv_usec = 0;
    esp_openthread_lock_acquire(0xffffffff);
    esp_openthread_platform_update(local_44);
    iVar3 = otTaskletsArePending(uVar1);
    if (iVar3 != 0) {
      atStack_28[0].tv_sec = 0;
      atStack_28[0].tv_usec = 0;
    }
    esp_openthread_lock_release();
    iVar3 = select(iStack_2c + 1,(fd_set *)local_44,(fd_set *)auStack_3c,(fd_set *)auStack_34,
                   atStack_28);
    if (iVar3 < 0) break;
    esp_openthread_lock_acquire(0xffffffff);
    otTaskletsProcess(uVar1);
    iVar3 = esp_openthread_platform_process(uVar1,local_44);
    esp_openthread_lock_release();
    if (iVar3 != 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC3,uVar1,"OPENTHREAD");
      return iVar3;
    }
  }
  uVar1 = esp_log_timestamp();
  esp_log_write(1,"OPENTHREAD",&_LC4,uVar1,"OPENTHREAD");
  return -1;
}

