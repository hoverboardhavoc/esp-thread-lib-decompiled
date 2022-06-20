/*
 * Last changed at upstream commit b6b61e3d4891c01e9b44cc1a27e741288192b537
 * https://github.com/espressif/esp-thread-lib/commit/b6b61e3d4891c01e9b44cc1a27e741288192b537
 * Upstream date: 2022-06-20 16:22:56 +0800
 * Upstream subject: openthread: update OpenThread submodule
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
  char *pcVar3;
  int iVar4;
  
  iVar4 = *(int *)(this + 0x700);
  if ((*(uint *)(this + 0x7a8) >> 0xe & 1) == 0) {
    return;
  }
  this[0x7a9] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )((byte)this[0x7a9] & 0xbf);
  otLogWarnPlat("RCP failure detected");
  iVar2 = (*(ushort *)(this + 0x706) + 1) * 0x10000;
  *(short *)(this + 0x706) = (short)((uint)iVar2 >> 0x10);
  if (1 < iVar2 >> 0x10) {
    otLogCritPlat("Too many rcp failures, exiting");
    uVar1 = otExitCodeToString(1);
    otLogCritPlat("%s() at %s:%d: %s","RecoverFromRcpFailure",
                  "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x8cc
                  ,uVar1);
    iVar4 = 1;
    goto _L0;
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
  if (((*(uint *)(this + 0x704) >> 4 & 1) == 0) || (iVar2 = SendReset(this,'\x02'), iVar2 == 0)) {
    iVar2 = WaitResponse(this);
    if (iVar2 == 0) {
      iVar2 = Set((ulong)this,(char *)0x20,&_LC17,1);
      if (iVar2 == 0) {
        *(undefined4 *)(this + 0x700) = 1;
        RestoreProperties(this);
        if (iVar4 == 2) {
          iVar4 = Set((ulong)this,(char *)0x37,&_LC17,1);
          if (iVar4 != 0) {
            iVar4 = Set((ulong)this,(char *)0x37,&_LC17,1);
            uVar1 = 2;
            if (iVar4 != 7) {
              uVar1 = 1;
            }
            uVar1 = otExitCodeToString(uVar1);
            iVar4 = -0x710;
_L0:
            otLogCritPlat("%s() at %s:%d: %s","RecoverFromRcpFailure",
                          "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                          ,iVar4 + 0x1000,uVar1);
            pcVar3 = (char *)0x37;
            goto _L0;
          }
          *(undefined4 *)(this + 0x700) = 2;
        }
        else if (iVar4 - 3U < 2) {
          iVar4 = Set((ulong)this,(char *)0x37,&_LC17,1);
          if (iVar4 != 0) {
            iVar4 = Set((ulong)this,(char *)0x37,&_LC17,1);
            uVar1 = 2;
            if (iVar4 != 7) {
              uVar1 = 1;
            }
            uVar1 = otExitCodeToString(uVar1);
            iVar4 = -0x70b;
            goto _L0;
          }
          *(undefined4 *)(this + 0x674) = 0xb;
          *(undefined4 *)(this + 0x700) = 4;
        }
        if (((*(uint *)(this + 0x7a8) >> 0xf & 1) == 0) ||
           (iVar4 = EnergyScan(this,(uchar)this[0x7a2],*(ushort *)(this + 0x7a4)), iVar4 == 0)) {
          *(short *)(this + 0x706) = *(short *)(this + 0x706) + -1;
          otLogNotePlat("RCP recovery is done");
          return;
        }
        iVar4 = EnergyScan(this,(uchar)this[0x7a2],*(ushort *)(this + 0x7a4));
        uVar1 = 2;
        if (iVar4 != 7) {
          uVar1 = 1;
        }
        uVar1 = otExitCodeToString(uVar1);
        otLogCritPlat("%s() at %s:%d: %s","RecoverFromRcpFailure",
                      "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                      0x8fd,uVar1);
        iVar2 = EnergyScan(this,(uchar)this[0x7a2],*(ushort *)(this + 0x7a4));
      }
      else {
        iVar4 = Set((ulong)this,(char *)0x20,&_LC17,1);
        uVar1 = 2;
        if (iVar4 != 7) {
          uVar1 = 1;
        }
        uVar1 = otExitCodeToString(uVar1);
        otLogCritPlat("%s() at %s:%d: %s","RecoverFromRcpFailure",
                      "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                      0x8e5,uVar1);
        pcVar3 = (char *)0x20;
_L0:
        iVar2 = Set((ulong)this,pcVar3,&_LC17,1);
      }
    }
    else {
      iVar4 = WaitResponse(this);
      uVar1 = 2;
      if (iVar4 != 7) {
        uVar1 = 1;
      }
      uVar1 = otExitCodeToString(uVar1);
      otLogCritPlat("%s() at %s:%d: %s","RecoverFromRcpFailure",
                    "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                    0x8e3,uVar1);
      iVar2 = WaitResponse(this);
    }
  }
  else {
    iVar4 = SendReset(this,'\x02');
    uVar1 = 2;
    if (iVar4 != 7) {
      uVar1 = 1;
    }
    uVar1 = otExitCodeToString(uVar1);
    otLogCritPlat("%s() at %s:%d: %s","RecoverFromRcpFailure",
                  "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x8df
                  ,uVar1);
    iVar2 = SendReset(this,'\x02');
  }
  iVar4 = 2;
  if (iVar2 != 7) {
    iVar4 = 1;
  }
_L0:
                    /* WARNING: Subroutine does not return */
  exit(iVar4);
}

