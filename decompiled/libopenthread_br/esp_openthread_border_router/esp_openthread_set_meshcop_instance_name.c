/*
 * Last changed at upstream commit 5ae57e156e4cd2ccd8dc51e90266b16b284e64de
 * https://github.com/espressif/esp-thread-lib/commit/5ae57e156e4cd2ccd8dc51e90266b16b284e64de
 * Upstream date: 2024-05-23 11:00:44 +0800
 * Upstream subject: feat(br): update border router lib
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_set_meshcop_instance_name
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_set_meshcop_instance_name(char *param_1)

{
  if (s_meshcop_instance_name != (char *)0x0) {
    free(s_meshcop_instance_name);
    s_meshcop_instance_name = (char *)0x0;
  }
  if ((param_1 != (char *)0x0) &&
     (s_meshcop_instance_name = strndup(param_1,0x3f), s_meshcop_instance_name == (char *)0x0)) {
    return 0x101;
  }
  return 0;
}

