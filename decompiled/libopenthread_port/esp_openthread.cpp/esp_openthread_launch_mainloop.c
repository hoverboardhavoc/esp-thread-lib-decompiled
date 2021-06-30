/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread.cpp.o -> esp_openthread_launch_mainloop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_openthread_launch_mainloop(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  fd_mask *pfVar4;
  uint uVar5;
  undefined1 local_34 [4];
  esp_openthread_mainloop_context_t mainloop;
  
  uVar1 = esp_openthread_get_instance();
  while( true ) {
    puVar3 = local_34;
    for (uVar5 = 0; uVar5 < 8; uVar5 = uVar5 + 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    pfVar4 = mainloop.read_fds.fds_bits + 1;
    for (uVar5 = 0; uVar5 < 8; uVar5 = uVar5 + 1) {
      *(undefined1 *)pfVar4 = 0;
      pfVar4 = (fd_mask *)((int)pfVar4 + 1);
    }
    pfVar4 = mainloop.write_fds.fds_bits + 1;
    for (uVar5 = 0; uVar5 < 8; uVar5 = uVar5 + 1) {
      *(undefined1 *)pfVar4 = 0;
      pfVar4 = (fd_mask *)((int)pfVar4 + 1);
    }
    mainloop.error_fds.fds_bits[1] = 0xffffffff;
    mainloop.max_fd = 10;
    mainloop.timeout.tv_sec = 0;
    esp_openthread_lock_acquire(0xffffffff);
    esp_openthread_platform_update(local_34);
    iVar2 = otTaskletsArePending(uVar1);
    if (iVar2 != 0) {
      mainloop.max_fd = 0;
      mainloop.timeout.tv_sec = 0;
    }
    esp_openthread_lock_release();
    iVar2 = select(mainloop.error_fds.fds_bits[1] + 1,(fd_set *)local_34,
                   (fd_set *)(mainloop.read_fds.fds_bits + 1),
                   (fd_set *)(mainloop.write_fds.fds_bits + 1),(timeval *)&mainloop.max_fd);
    if (iVar2 < 0) break;
    esp_openthread_lock_acquire(0xffffffff);
    otTaskletsProcess(uVar1);
    iVar2 = esp_openthread_platform_process(uVar1,local_34);
    esp_openthread_lock_release();
    if (iVar2 != 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC4,uVar1,"OPENTHREAD");
      return iVar2;
    }
  }
  uVar1 = esp_log_timestamp();
  esp_log_write(1,"OPENTHREAD",&_LC5,uVar1,"OPENTHREAD");
  return -1;
}

