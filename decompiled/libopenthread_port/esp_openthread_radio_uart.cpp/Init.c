/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::Init(bool, bool, bool) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
Init(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this,
    bool param_1,bool param_2,bool param_3)

{
  uint __status;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  undefined3 in_register_00002035;
  bool local_21 [13];
  
  if (((CONCAT31(in_register_0000202d,param_1) == 0) || (iVar1 = SendReset(this), iVar1 == 0)) &&
     (iVar1 = WaitResponse(this), iVar1 == 0)) {
    if ((*(uint *)(this + 0x704) >> 1 & 1) == 0) {
      iVar1 = 1;
      goto _L0;
    }
    iVar1 = CheckSpinelVersion(this);
    if (((iVar1 == 0) && (iVar1 = Get((ulong)this,(char *)0x2,&_LC27,this + 0x678,0x80), iVar1 == 0)
        ) && (iVar1 = Get((ulong)this,(char *)0x8,&_LC28,this + 0x6f8), iVar1 == 0)) {
      iVar2 = IsRcp(this,local_21);
      if (iVar2 == 0) {
        if (CONCAT31(in_register_00002031,param_2) == 0) {
          __status = 3;
        }
        else {
          iVar1 = RestoreDatasetFromNcp(this);
          __status = (uint)(iVar1 != 0);
        }
        uVar3 = otExitCodeToString(__status);
        otLogCrit(0xc,_LC2,"%s() at %s:%d: %s",&Init(bool,bool,bool)::__func__,
                  "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x104,
                  uVar3);
                    /* WARNING: Subroutine does not return */
        exit(__status);
      }
      if (CONCAT31(in_register_00002035,param_3) == 0) {
        iVar2 = CheckRcpApiVersion(this,local_21[0]);
        if (iVar2 != 0) {
          iVar1 = CheckRcpApiVersion(this,local_21[0]);
          if (iVar1 == 7) {
            uVar3 = 2;
          }
          else {
            uVar3 = 1;
          }
          uVar3 = otExitCodeToString(uVar3);
          otLogCrit(0xc,_LC2,"%s() at %s:%d: %s",&Init(bool,bool,bool)::__func__,
                    "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                    0x109,uVar3);
          iVar1 = CheckRcpApiVersion(this,local_21[0]);
          if (iVar1 == 7) {
            iVar1 = 2;
          }
          else {
            iVar1 = 1;
          }
                    /* WARNING: Subroutine does not return */
          exit(iVar1);
        }
        iVar2 = CheckRadioCapabilities(this);
        if (iVar2 != 0) {
          iVar1 = CheckRadioCapabilities(this);
          if (iVar1 == 7) {
            uVar3 = 2;
          }
          else {
            uVar3 = 1;
          }
          uVar3 = otExitCodeToString(uVar3);
          otLogCrit(0xc,_LC2,"%s() at %s:%d: %s",&Init(bool,bool,bool)::__func__,
                    "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                    0x10a,uVar3);
          iVar1 = CheckRadioCapabilities(this);
          if (iVar1 == 7) {
            iVar1 = 2;
          }
          else {
            iVar1 = 1;
          }
                    /* WARNING: Subroutine does not return */
          exit(iVar1);
        }
      }
      *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> **)
       (this + 0x600) = this + 0x47c;
      *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> **)
       (this + 0x620) = this + 0x4fb;
      *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> **)
       (this + 0x640) = this + 0x57a;
    }
  }
  if (iVar1 == 0) {
    return;
  }
_L0:
  if (iVar1 == 7) {
    uVar3 = 2;
  }
  else {
    uVar3 = 1;
  }
  uVar3 = otExitCodeToString(uVar3);
  otLogCrit(0xc,_LC2,"%s() at %s:%d: %s",&Init(bool,bool,bool)::__func__,
            "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x112,uVar3)
  ;
  if (iVar1 == 7) {
    iVar1 = 2;
  }
  else {
    iVar1 = 1;
  }
                    /* WARNING: Subroutine does not return */
  exit(iVar1);
}

