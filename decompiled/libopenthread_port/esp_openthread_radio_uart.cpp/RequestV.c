/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> RequestV
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010aaa) */
/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   RequestV(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *
   this, uint32_t command, spinel_prop_key_t aKey, char * aFormat, va_list aArgs) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
RequestV(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *this,
        uint32_t command,spinel_prop_key_t aKey,char *aFormat,va_list aArgs)

{
  spinel_tid_t tid;
  undefined3 extraout_var;
  otError oVar1;
  
  tid = GetNextTid(this);
  if (CONCAT31(extraout_var,tid) == 0) {
    oVar1 = OT_ERROR_BUSY;
  }
  else {
    oVar1 = SendCommand(this,command,aKey,tid,aFormat,aArgs);
    if (oVar1 == OT_ERROR_NONE) {
      if (aKey == 0x71) {
        if (this->mTxRadioTid == '\0') {
          this->mTxRadioTid = tid;
          return OT_ERROR_NONE;
        }
        __assert_func("IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                      0x6e1,
                      "otError ot::Spinel::RadioSpinel<InterfaceType, ProcessContextType>::RequestV(uint32_t, spinel_prop_key_t, const char*, va_list) [with InterfaceType = esp::openthread::UartSpinelInterface; ProcessContextType = esp_openthread_mainloop_context_t; otError = otError; uint32_t = long unsigned int; spinel_prop_key_t = long unsigned int; va_list = void*]"
                      ,"mTxRadioTid == 0");
      }
      this->mWaitingKey = aKey;
      this->mWaitingTid = tid;
      oVar1 = WaitResponse(this);
    }
  }
  return oVar1;
}

