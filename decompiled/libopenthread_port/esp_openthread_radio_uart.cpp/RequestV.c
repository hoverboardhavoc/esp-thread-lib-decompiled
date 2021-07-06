/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> RequestV
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010aaa) */
/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::RequestV(unsigned long, unsigned long, char const*, void*) */

int __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
RequestV(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this,
        ulong param_1,ulong param_2,char *param_3,void *param_4)

{
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar1;
  int iVar2;
  
  iVar2 = GetNextTid(this);
  if (iVar2 == 0) {
    iVar2 = 5;
  }
  else {
    RVar1 = SUB41(iVar2,0);
    iVar2 = SendCommand(this,param_1,param_2,(uchar)RVar1,param_3,param_4);
    if (iVar2 == 0) {
      if (param_2 == 0x71) {
        if (this[0x463] ==
            (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)0x0
           ) {
          this[0x463] = RVar1;
          return 0;
        }
        __assert_func("IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                      0x6e1,
                      "otError ot::Spinel::RadioSpinel<InterfaceType, ProcessContextType>::RequestV(uint32_t, spinel_prop_key_t, const char*, va_list) [with InterfaceType = esp::openthread::UartSpinelInterface; ProcessContextType = esp_openthread_mainloop_context_t; otError = otError; uint32_t = long unsigned int; spinel_prop_key_t = long unsigned int; va_list = void*]"
                      ,"mTxRadioTid == 0");
      }
      *(ulong *)(this + 0x468) = param_2;
      this[0x464] = RVar1;
      iVar2 = WaitResponse(this);
    }
  }
  return iVar2;
}

