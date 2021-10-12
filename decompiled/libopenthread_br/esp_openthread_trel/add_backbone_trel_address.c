/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
 * Source: libopenthread_br -> esp_openthread_trel.o -> add_backbone_trel_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void add_backbone_trel_address(void *param_1)

{
  undefined1 auStack_28 [20];
  undefined1 uStack_14;
  
  memcpy(auStack_28,param_1,0x10);
  uStack_14 = 1;
  esp_event_post(_OPENTHREAD_EVENT,8,auStack_28,0x18,0);
  return;
}

