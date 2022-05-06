/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> RecoverFromRcpFailure
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::RecoverFromRcpFailure() */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
RecoverFromRcpFailure
          (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this
          )

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (-1 < *(int *)(this + 0x7a8) << 0x11) {
    return;
  }
  uVar4 = *(uint *)(this + 0x700);
  this[0x7a9] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )((byte)this[0x7a9] & 0xbf);
  otLogWarnPlat("RCP failure detected");
  iVar2 = (*(ushort *)(this + 0x706) + 1) * 0x10000;
  *(short *)(this + 0x706) = (short)((uint)iVar2 >> 0x10);
  if (1 < iVar2 >> 0x10) {
    otLogCritPlat("Too many rcp failures, exiting");
    uVar1 = otExitCodeToString(1);
    otLogCritPlat("%s() at %s:%d: %s","BSD TCP function",
                  "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x8c9
                  ,uVar1);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  otLogWarnPlat("Trying to recover (%d/%d)",1);
  *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> **)
   (this + 0x40c) = this + 10;
  *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> **)
   (this + 4) = this + 0xe;
  *(undefined2 *)(this + 8) = 0x3fc;
  *(undefined4 *)(this + 0x700) = 0;
  Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
            ((MultiFrameBuffer<(unsigned_short)1024> *)(this + 4),0);
  if (*(code **)(this + 0x460) != (code *)0x0) {
    (**(code **)(this + 0x460))();
  }
  *(undefined4 *)(this + 0x464) = 0x10000;
  this[0x468] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0;
  *(undefined4 *)(this + 0x46c) = 0;
  this[0x704] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )((byte)this[0x704] & 0xf5);
  *(undefined4 *)(this + 0x47c) = 0;
  if (((*(uint *)(this + 0x704) >> 4 & 1) != 0) && (iVar2 = SendReset(this,'\x02'), iVar2 != 0)) {
    iVar2 = SendReset(this,'\x02');
    uVar1 = 2;
    if (iVar2 != 7) {
      uVar1 = 1;
    }
    uVar1 = otExitCodeToString(uVar1);
    otLogCritPlat("%s() at %s:%d: %s","BSD TCP function",
                  "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x8dc
                  ,uVar1);
    iVar2 = SendReset(this,'\x02');
    iVar3 = 2;
    if (iVar2 != 7) {
      iVar3 = 1;
    }
                    /* WARNING: Subroutine does not return */
    exit(iVar3);
  }
  iVar2 = WaitResponse(this);
  if (iVar2 != 0) {
    iVar2 = WaitResponse(this);
    uVar1 = 2;
    if (iVar2 != 7) {
      uVar1 = 1;
    }
    uVar1 = otExitCodeToString(uVar1);
    otLogCritPlat("%s() at %s:%d: %s","BSD TCP function",
                  "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x8e0
                  ,uVar1);
    iVar2 = WaitResponse(this);
    iVar3 = 2;
    if (iVar2 != 7) {
      iVar3 = 1;
    }
                    /* WARNING: Subroutine does not return */
    exit(iVar3);
  }
  iVar2 = Set((ulong)this,(char *)0x20,&_LC16,1);
  if (iVar2 != 0) {
    iVar2 = Set((ulong)this,(char *)0x20,&_LC16,1);
    uVar1 = 2;
    if (iVar2 != 7) {
      uVar1 = 1;
    }
    uVar1 = otExitCodeToString(uVar1);
    otLogCritPlat("%s() at %s:%d: %s","BSD TCP function",
                  "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x8e2
                  ,uVar1);
    iVar2 = Set((ulong)this,(char *)0x20,&_LC16,1);
    iVar3 = 2;
    if (iVar2 != 7) {
      iVar3 = 1;
    }
                    /* WARNING: Subroutine does not return */
    exit(iVar3);
  }
  *(undefined4 *)(this + 0x700) = 1;
  RestoreProperties(this);
  if (uVar4 == 2) {
    iVar2 = Set((ulong)this,(char *)0x37,&_LC16,1);
    if (iVar2 != 0) {
      iVar2 = Set((ulong)this,(char *)0x37,&_LC16,1);
      uVar1 = 2;
      if (iVar2 != 7) {
        uVar1 = 1;
      }
      uVar1 = otExitCodeToString(uVar1);
      otLogCritPlat("%s() at %s:%d: %s","BSD TCP function",
                    "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                    0x8ed,uVar1);
      iVar2 = Set((ulong)this,(char *)0x37,&_LC16,1);
      iVar3 = 2;
      if (iVar2 != 7) {
        iVar3 = 1;
      }
                    /* WARNING: Subroutine does not return */
      exit(iVar3);
    }
    *(undefined4 *)(this + 0x700) = 2;
  }
  else if ((1 < uVar4) && (uVar4 < 5)) {
    iVar2 = Set((ulong)this,(char *)0x37,&_LC16,1);
    if (iVar2 != 0) {
      iVar2 = Set((ulong)this,(char *)0x37,&_LC16,1);
      uVar1 = 2;
      if (iVar2 != 7) {
        uVar1 = 1;
      }
      uVar1 = otExitCodeToString(uVar1);
      otLogCritPlat("%s() at %s:%d: %s","BSD TCP function",
                    "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                    0x8f2,uVar1);
      iVar2 = Set((ulong)this,(char *)0x37,&_LC16,1);
      iVar3 = 2;
      if (iVar2 != 7) {
        iVar3 = 1;
      }
                    /* WARNING: Subroutine does not return */
      exit(iVar3);
    }
    *(undefined4 *)(this + 0x674) = 0xb;
    *(undefined4 *)(this + 0x700) = 4;
  }
  if ((*(int *)(this + 0x7a8) << 0x10 < 0) &&
     (iVar2 = EnergyScan(this,(uchar)this[0x7a2],*(ushort *)(this + 0x7a4)), iVar2 != 0)) {
    iVar2 = EnergyScan(this,(uchar)this[0x7a2],*(ushort *)(this + 0x7a4));
    uVar1 = 2;
    if (iVar2 != 7) {
      uVar1 = 1;
    }
    uVar1 = otExitCodeToString(uVar1);
    otLogCritPlat("%s() at %s:%d: %s","BSD TCP function",
                  "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x8fa
                  ,uVar1);
    iVar2 = EnergyScan(this,(uchar)this[0x7a2],*(ushort *)(this + 0x7a4));
    iVar3 = 2;
    if (iVar2 != 7) {
      iVar3 = 1;
    }
                    /* WARNING: Subroutine does not return */
    exit(iVar3);
  }
  *(short *)(this + 0x706) = *(short *)(this + 0x706) + -1;
  return;
}

