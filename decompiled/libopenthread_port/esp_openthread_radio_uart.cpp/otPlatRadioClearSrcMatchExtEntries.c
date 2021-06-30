/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioClearSrcMatchExtEntries
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */
/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */

void otPlatRadioClearSrcMatchExtEntries(otInstance *instance)

{
  otError oVar1;
  undefined4 uVar2;
  int __status;
  
  oVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
          ClearSrcMatchExtEntries(&s_radio);
  if (oVar1 == OT_ERROR_NONE) {
    return;
  }
  oVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
          ClearSrcMatchExtEntries(&s_radio);
  if (oVar1 == OT_ERROR_INVALID_ARGS) {
    uVar2 = 2;
  }
  else {
    uVar2 = 1;
  }
  uVar2 = otExitCodeToString(uVar2);
  otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","otPlatRadioClearSrcMatchExtEntries",
            "/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_radio_uart.cpp"
            ,0xb5,uVar2);
  oVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
          ClearSrcMatchExtEntries(&s_radio);
  if (oVar1 == OT_ERROR_INVALID_ARGS) {
    __status = 2;
  }
  else {
    __status = 1;
  }
                    /* WARNING: Subroutine does not return */
  exit(__status);
}

