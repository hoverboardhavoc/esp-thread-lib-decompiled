/*
 * Last changed at upstream commit 7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * https://github.com/espressif/esp-thread-lib/commit/7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * Upstream date: 2021-11-03 15:55:12 +0800
 * Upstream subject: openthread: mdns & RCP ota update(3571cf8)
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
    otPlatAssertFail("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_ncp.cpp"
                     ,0x9b);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}

