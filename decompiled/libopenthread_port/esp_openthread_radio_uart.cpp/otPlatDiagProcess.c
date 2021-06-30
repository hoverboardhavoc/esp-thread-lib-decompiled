/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatDiagProcess
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */
/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */

otError otPlatDiagProcess(otInstance *instance,int argc,char **argv,char *output,
                         size_t output_max_len)

{
  char *__s;
  int iVar1;
  int iVar2;
  otError oVar3;
  char acStack_120 [4];
  char cmd [256];
  
  __s = acStack_120;
  memset(acStack_120,0,0x100);
  for (iVar1 = 0; iVar1 < argc; iVar1 = iVar1 + 1) {
    iVar2 = snprintf(__s,(size_t)(cmd + (0xfc - (int)__s)),"%s ");
    __s = __s + iVar2;
  }
  oVar3 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
          PlatDiagProcess(&s_radio,acStack_120,output,output_max_len);
  return oVar3;
}

