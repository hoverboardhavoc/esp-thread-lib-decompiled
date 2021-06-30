/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   Get(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> * this,
   spinel_prop_key_t aKey, char * aFormat, ...) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
Get(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *this,
   spinel_prop_key_t aKey,char *aFormat,...)

{
  otError oVar1;
  RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *this_00;
  undefined4 uVar2;
  undefined4 in_a3;
  undefined4 in_a4;
  undefined4 in_a5;
  undefined4 in_a6;
  undefined4 in_a7;
  int iStack_48;
  int aiStack_44 [3];
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_14 = in_a3;
  uStack_10 = in_a4;
  uStack_c = in_a5;
  uStack_8 = in_a6;
  uStack_4 = in_a7;
  if (this->mWaitingTid == '\0') {
    this->mPropertyArgs = &uStack_14;
    oVar1 = RequestWithPropertyFormatV(this,aFormat,2,aKey,(char *)0x0,&uStack_14);
    return oVar1;
  }
  this_00 = (RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *)
            __assert_func("IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                          ,0x5f6,
                          "otError ot::Spinel::RadioSpinel<InterfaceType, ProcessContextType>::Get(spinel_prop_key_t, const char*, ...) [with InterfaceType = esp::openthread::UartSpinelInterface; ProcessContextType = esp_openthread_mainloop_context_t; otError = otError; spinel_prop_key_t = long unsigned int]"
                          ,"mWaitingTid == 0");
  oVar1 = Get(this_00,1,"ii",aiStack_44,&iStack_48);
  if ((oVar1 == OT_ERROR_NONE) && ((aiStack_44[0] != 4 || (iStack_48 != 3)))) {
    otLogCrit(0xc,_LC2,"Spinel version mismatch - Posix:%d.%d, RCP:%d.%d",4,3,iStack_48);
    uVar2 = otExitCodeToString(3);
    otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","CheckSpinelVersion",
              "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x125,
              uVar2);
                    /* WARNING: Subroutine does not return */
    exit(3);
  }
  return oVar1;
}

