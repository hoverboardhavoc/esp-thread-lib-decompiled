/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_set_meshcop_instance_name
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint esp_openthread_set_meshcop_instance_name(char *param_1)

{
  uint uVar1;
  
  if (s_meshcop_instance_name != (char *)0x0) {
    free(s_meshcop_instance_name);
    s_meshcop_instance_name = (char *)0x0;
  }
  uVar1 = 0;
  if (param_1 != (char *)0x0) {
    s_meshcop_instance_name = strndup(param_1,0x3f);
    uVar1 = -(uint)(s_meshcop_instance_name == (char *)0x0) & 0x101;
  }
  return uVar1;
}

