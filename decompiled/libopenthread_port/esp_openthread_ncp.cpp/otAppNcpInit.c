/*
 * Last changed at upstream commit e527d6b8e8720c9bde49fec26e19cf437458e3b3
 * https://github.com/espressif/esp-thread-lib/commit/e527d6b8e8720c9bde49fec26e19cf437458e3b3
 * Upstream date: 2021-12-03 11:59:45 +0800
 * Upstream subject: port: aggressively process pending tasks (eb7a7fb)
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
    otPlatAssertFail("/home/zhangwenxu/ieee802154/esp-openthread/components/openthread_port/src/esp_openthread_ncp.cpp"
                     ,0x9b);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}

