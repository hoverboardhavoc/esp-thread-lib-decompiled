/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
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
    otPlatAssertFail("/home/wangqixiang/workspace/gitlab-esp/esp-openthread/components/openthread_port/src/esp_openthread_ncp.cpp"
                     ,0x99);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}

