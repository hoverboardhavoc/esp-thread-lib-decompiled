/*
 * Last changed at upstream commit 90d32076b158280332a6f931440e2145c0d51b08
 * https://github.com/espressif/esp-thread-lib/commit/90d32076b158280332a6f931440e2145c0d51b08
 * Upstream date: 2022-04-26 15:33:17 +0800
 * Upstream subject: openthread: support esp32h2beta1 & esp32h2beta2
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
    otPlatAssertFail("/home/zwx/esp/esp-openthread/components/openthread_port/src/esp_openthread_ncp.cpp"
                     ,0x99);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}

