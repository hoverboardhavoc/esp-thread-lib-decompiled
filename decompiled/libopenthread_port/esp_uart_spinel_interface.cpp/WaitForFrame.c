/*
 * Last changed at upstream commit d84f8967f8ce14490e19433b85c8c363d424f4c1
 * https://github.com/espressif/esp-thread-lib/commit/d84f8967f8ce14490e19433b85c8c363d424f4c1
 * Upstream date: 2021-07-13 21:21:08 +0800
 * Upstream subject: openthread: add ot library for esp32h2
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> WaitForFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::WaitForFrame(unsigned long long) */

undefined4 esp::openthread::UartSpinelInterface::WaitForFrame(ulonglong param_1)

{
  UartSpinelInterface *in_a0;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint local_38 [2];
  uint local_30 [2];
  timeval atStack_28 [2];
  
  puVar2 = local_30;
  for (uVar3 = 0; uVar3 < 8; uVar3 = uVar3 + 1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (uint *)((int)puVar2 + 1);
  }
  puVar2 = local_38;
  for (uVar3 = 0; uVar3 < 8; uVar3 = uVar3 + 1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (uint *)((int)puVar2 + 1);
  }
  uVar3 = *(uint *)(in_a0 + 0x4c);
  if (uVar3 < 0x40) {
    local_30[uVar3 >> 5] = local_30[uVar3 >> 5] | 1 << (uVar3 & 0x1f);
    local_38[uVar3 >> 5] = local_38[uVar3 >> 5] | 1 << (uVar3 & 0x1f);
  }
  atStack_28[0].tv_sec = __udivdi3(1000000,0);
  atStack_28[0].tv_usec = __umoddi3(1000000,0);
  iVar1 = select(uVar3 + 1,(fd_set *)local_30,(fd_set *)0x0,(fd_set *)local_38,atStack_28);
  if (0 < iVar1) {
    uVar3 = *(uint *)(in_a0 + 0x4c);
    if ((uVar3 < 0x40) && ((local_30[uVar3 >> 5] & 1 << (uVar3 & 0x1f)) != 0)) {
      TryReadAndDecode(in_a0);
      return 0;
    }
    if (0x3f < uVar3) {
      return 0;
    }
    if ((local_38[uVar3 >> 5] & 1 << (uVar3 & 0x1f)) == 0) {
      return 0;
    }
    iVar1 = TryRecoverUart(in_a0);
    if (iVar1 == 0) {
      return 1;
    }
    iVar1 = _esp_error_check_failed
                      ("/home/chenshu/code/esp-openthread/components/openthread_port/src/esp_uart_spinel_interface.cpp"
                       ,0xe5,"otError esp::openthread::UartSpinelInterface::WaitForFrame(uint64_t)",
                       "TryRecoverUart()");
  }
  if (iVar1 == 0) {
    return 0x1c;
  }
  iVar1 = TryRecoverUart(in_a0);
  if (iVar1 != 0) {
    _esp_error_check_failed
              ("/home/chenshu/code/esp-openthread/components/openthread_port/src/esp_uart_spinel_interface.cpp"
               ,0xeb,"otError esp::openthread::UartSpinelInterface::WaitForFrame(uint64_t)",
               "TryRecoverUart()");
    return 0;
  }
  return 1;
}

