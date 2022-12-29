/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
 * Source: libopenthread_port -> esp_openthread_ncp.cpp.o -> otAppNcpInit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otAppNcpInit(Instance *param_1)

{
  undefined1 *puVar1;
  
  otPlatUartEnable();
  ot::Ncp::NcpHdlc::NcpHdlc((NcpHdlc *)s_ncp,param_1,NcpSend);
  puVar1 = (undefined1 *)ot::Ncp::NcpBase::GetNcpInstance();
  if (puVar1 != s_ncp) {
    otPlatAssertFail("/home/xusiyu/esp/esp-openthread/components/openthread_port/src/esp_openthread_ncp.cpp"
                     ,0x99);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}

