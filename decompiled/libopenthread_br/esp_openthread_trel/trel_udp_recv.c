/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
 * Source: libopenthread_br -> esp_openthread_trel.o -> trel_udp_recv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void trel_udp_recv(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = otMessageGetLength(param_1);
  if (uVar1 < 0x579) {
    otMessageRead(param_1,0,s_rx_packet,uVar1);
    esp_openthread_get_instance();
    otPlatTrelUdp6HandleReceived(s_rx_packet,uVar1);
    return;
  }
  uVar2 = esp_log_timestamp();
  esp_log_write(2,"OPENTHREAD",&_LC1,uVar2,"OPENTHREAD");
  return;
}

