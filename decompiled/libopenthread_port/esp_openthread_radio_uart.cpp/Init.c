/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void
   Init(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> * this,
   bool aResetRadio, bool aRestoreDatasetFromNcp, bool aSkipRcpCompatibilityCheck) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
Init(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *this,
    bool aResetRadio,bool aRestoreDatasetFromNcp,bool aSkipRcpCompatibilityCheck)

{
  uint __status;
  bool bVar1;
  otError oVar2;
  undefined3 extraout_var;
  otError oVar3;
  undefined4 uVar4;
  int iVar5;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  undefined3 in_register_00002035;
  bool local_21 [4];
  bool supportsRcpApiVersion;
  
  if (((CONCAT31(in_register_0000202d,aResetRadio) == 0) ||
      (oVar2 = SendReset(this), oVar2 == OT_ERROR_NONE)) &&
     (oVar2 = WaitResponse(this), oVar2 == OT_ERROR_NONE)) {
    if ((*(uint *)&this->field_0x704 >> 1 & 1) == 0) {
      oVar2 = OT_ERROR_FAILED;
      goto _L0;
    }
    oVar2 = CheckSpinelVersion(this);
    if (((oVar2 == OT_ERROR_NONE) &&
        (oVar2 = Get(this,2,"U",this->mVersion,0x80), oVar2 == OT_ERROR_NONE)) &&
       (oVar2 = Get(this,8,"E",&this->mIeeeEui64), oVar2 == OT_ERROR_NONE)) {
      bVar1 = IsRcp(this,local_21);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        if (CONCAT31(in_register_00002031,aRestoreDatasetFromNcp) == 0) {
          __status = 3;
        }
        else {
          oVar2 = RestoreDatasetFromNcp(this);
          __status = (uint)(oVar2 != OT_ERROR_NONE);
        }
        uVar4 = otExitCodeToString(__status);
        otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","Init",
                  "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x104,
                  uVar4);
                    /* WARNING: Subroutine does not return */
        exit(__status);
      }
      if (CONCAT31(in_register_00002035,aSkipRcpCompatibilityCheck) == 0) {
        oVar3 = CheckRcpApiVersion(this,local_21[0]);
        if (oVar3 != OT_ERROR_NONE) {
          oVar2 = CheckRcpApiVersion(this,local_21[0]);
          if (oVar2 == OT_ERROR_INVALID_ARGS) {
            uVar4 = 2;
          }
          else {
            uVar4 = 1;
          }
          uVar4 = otExitCodeToString(uVar4);
          otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","Init",
                    "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                    0x109,uVar4);
          oVar2 = CheckRcpApiVersion(this,local_21[0]);
          if (oVar2 == OT_ERROR_INVALID_ARGS) {
            iVar5 = 2;
          }
          else {
            iVar5 = 1;
          }
                    /* WARNING: Subroutine does not return */
          exit(iVar5);
        }
        oVar3 = CheckRadioCapabilities(this);
        if (oVar3 != OT_ERROR_NONE) {
          oVar2 = CheckRadioCapabilities(this);
          if (oVar2 == OT_ERROR_INVALID_ARGS) {
            uVar4 = 2;
          }
          else {
            uVar4 = 1;
          }
          uVar4 = otExitCodeToString(uVar4);
          otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","Init",
                    "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                    0x10a,uVar4);
          oVar2 = CheckRadioCapabilities(this);
          if (oVar2 == OT_ERROR_INVALID_ARGS) {
            iVar5 = 2;
          }
          else {
            iVar5 = 1;
          }
                    /* WARNING: Subroutine does not return */
          exit(iVar5);
        }
      }
      (this->mRxRadioFrame).mPsdu = this->mRxPsdu;
      (this->mTxRadioFrame).mPsdu = this->mTxPsdu;
      (this->mAckRadioFrame).mPsdu = this->mAckPsdu;
    }
  }
  if (oVar2 == OT_ERROR_NONE) {
    return;
  }
_L0:
  if (oVar2 == OT_ERROR_INVALID_ARGS) {
    uVar4 = 2;
  }
  else {
    uVar4 = 1;
  }
  uVar4 = otExitCodeToString(uVar4);
  otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","Init",
            "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x112,uVar4)
  ;
  if (oVar2 == OT_ERROR_INVALID_ARGS) {
    iVar5 = 2;
  }
  else {
    iVar5 = 1;
  }
                    /* WARNING: Subroutine does not return */
  exit(iVar5);
}

