/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
    otPlatAssertFail("/Users/chenshu/code/esp-openthread/components/openthread_port/src/esp_openthread_ncp.cpp"
                     ,0x99);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}

