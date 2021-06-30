/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioClearSrcMatchExtEntry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */
/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */

otError otPlatRadioClearSrcMatchExtEntry(otInstance *instance,otExtAddress *ext_address)

{
  otError oVar1;
  uint uVar2;
  undefined1 auStack_18 [4];
  otExtAddress addr;
  
  for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1) {
    auStack_18[uVar2] = *(undefined1 *)((7 - uVar2) + (int)ext_address);
  }
  oVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
          ClearSrcMatchExtEntry(&s_radio,(otExtAddress *)auStack_18);
  return oVar1;
}

