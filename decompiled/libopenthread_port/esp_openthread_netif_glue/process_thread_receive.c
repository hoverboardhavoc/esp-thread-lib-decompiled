/*
 * Last changed at upstream commit d84f8967f8ce14490e19433b85c8c363d424f4c1
 * https://github.com/espressif/esp-thread-lib/commit/d84f8967f8ce14490e19433b85c8c363d424f4c1
 * Upstream date: 2021-07-13 21:21:08 +0800
 * Upstream subject: openthread: add ot library for esp32h2
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> process_thread_receive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void process_thread_receive(undefined4 param_1)

{
  size_t __size;
  void *pvVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  
  __size = otMessageGetLength();
  pvVar1 = malloc(__size);
  if (pvVar1 == (void *)0x0) {
_L0:
    iVar3 = 3;
  }
  else {
    sVar2 = otMessageRead(param_1,0,pvVar1,__size);
    if (__size != sVar2) {
      __assert_func("/home/chenshu/code/esp-openthread/components/openthread_port/src/esp_openthread_netif_glue.c"
                    ,0x70,"process_thread_receive","read_length == length");
      goto _L0;
    }
    iVar3 = esp_netif_receive(DAT_00010b48,pvVar1,__size,0);
    if (iVar3 == 0) goto _L0;
  }
  uVar4 = esp_err_to_name(iVar3);
  otLogWarn(0xc,"-PLAT----: ","process_thread_receive failed: %s",uVar4);
_L0:
  otMessageFree(param_1);
  return;
}

