/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> RestoreDatasetFromNcp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::RestoreDatasetFromNcp() */

int __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
RestoreDatasetFromNcp
          (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this
          )

{
  int iVar1;
  
  ot::Instance::Get();
  ot::Flash::Init();
  otLogInfo(0xc,_LC2,"Trying to get saved dataset from NCP");
  iVar1 = Get((ulong)this,(char *)0x1518);
  if (iVar1 == 0) {
    iVar1 = Get((ulong)this,(char *)0x1519);
  }
  ot::Instance::Get();
  return iVar1;
}

