/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
 * Source: libopenthread_br -> esp_openthread_trel.o -> otPlatTrelUdp6UpdateAddress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatTrelUdp6UpdateAddress(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = subscribe_backbone_multicast_address(s_trel_address);
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(2,"OPENTHREAD",&_LC2,uVar2,"OPENTHREAD");
  }
  iVar1 = add_backbone_trel_address(param_1);
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(2,"OPENTHREAD",&_LC3,uVar2,"OPENTHREAD");
  }
  memcpy(s_trel_address,param_1,0x10);
  return;
}

