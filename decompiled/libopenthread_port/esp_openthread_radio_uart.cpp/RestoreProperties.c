/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> RestoreProperties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::RestoreProperties() */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
RestoreProperties(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  *this)

{
  int iVar1;
  char *pcVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *pRVar6;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *pRVar7;
  NetworkInfo aNStack_58 [12];
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *pRStack_4c;
  
  iVar1 = Set((ulong)this,(char *)0x36,&_LC39,(uint)*(ushort *)(this + 0x66e));
  if (iVar1 == 0) {
    iVar1 = Set((ulong)this,(char *)0x35,&_LC39,(uint)*(ushort *)(this + 0x66c));
    if (iVar1 != 0) {
      iVar1 = Set((ulong)this,(char *)0x35,&_LC39,(uint)*(ushort *)(this + 0x66c));
      uVar4 = 2;
      if (iVar1 != 7) {
        uVar4 = 1;
      }
      uVar4 = otExitCodeToString(uVar4);
      otLogCritPlat("%s() at %s:%d: %s","RestoreProperties",
                    "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                    0x923,uVar4);
      puVar3 = &_LC39;
      pcVar2 = (char *)0x35;
      pRStack_4c = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    *)(uint)*(ushort *)(this + 0x66c);
      goto _L0;
    }
    pRVar6 = this + 0x664;
    iVar1 = Set((ulong)this,(char *)0x34,&_LC66,pRVar6);
    if (iVar1 != 0) {
      iVar1 = Set((ulong)this,(char *)0x34,&_LC66,pRVar6);
      uVar4 = 2;
      if (iVar1 != 7) {
        uVar4 = 1;
      }
      uVar4 = otExitCodeToString(uVar4);
      otLogCritPlat("%s() at %s:%d: %s","RestoreProperties",
                    "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                    0x924,uVar4);
      puVar3 = &_LC66;
      pcVar2 = (char *)0x34;
      pRStack_4c = pRVar6;
      goto _L0;
    }
    iVar1 = Set((ulong)this,(char *)0x21,&_LC37,(uint)(byte)this[0x671]);
    if (iVar1 != 0) {
      iVar1 = Set((ulong)this,(char *)0x21,&_LC37,(uint)(byte)this[0x671]);
      uVar4 = 2;
      if (iVar1 != 7) {
        uVar4 = 1;
      }
      uVar4 = otExitCodeToString(uVar4);
      otLogCritPlat("%s() at %s:%d: %s","RestoreProperties",
                    "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                    0x925,uVar4);
      pRStack_4c = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    *)(uint)(byte)this[0x671];
      puVar3 = &_LC37;
      pcVar2 = (char *)0x21;
      goto _L0;
    }
    if ((*(uint *)(this + 0x7a8) >> 9 & 1) == 0) {
_L0:
      if (*(int *)this != 0) {
        iVar1 = Settings::Read<ot::SettingsBase::NetworkInfo>
                          ((Settings *)(*(int *)this + 0x4c),aNStack_58);
        if (iVar1 != 0) {
          iVar1 = Settings::Read<ot::SettingsBase::NetworkInfo>
                            ((Settings *)(*(int *)this + 0x4c),aNStack_58);
          uVar4 = 2;
          if (iVar1 != 7) {
            uVar4 = 1;
          }
          uVar4 = otExitCodeToString(uVar4);
          otLogCritPlat("%s() at %s:%d: %s","RestoreProperties",
                        "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                        ,0x932,uVar4);
          iVar1 = Settings::Read<ot::SettingsBase::NetworkInfo>
                            ((Settings *)(*(int *)this + 0x4c),aNStack_58);
          goto _L0;
        }
        iVar1 = Set((ulong)this,(char *)0x801,&_LC30,pRStack_4c);
        if (iVar1 != 0) {
          iVar1 = Set((ulong)this,(char *)0x801,&_LC30,pRStack_4c);
          uVar4 = 2;
          if (iVar1 != 7) {
            uVar4 = 1;
          }
          uVar4 = otExitCodeToString(uVar4);
          otLogCritPlat("%s() at %s:%d: %s","RestoreProperties",
                        "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                        ,0x933,uVar4);
          puVar3 = &_LC30;
          pcVar2 = (char *)0x801;
          goto _L0;
        }
      }
      pRVar6 = this + 0x73a;
      for (iVar1 = 0; iVar1 < *(short *)(this + 0x74e); iVar1 = iVar1 + 1) {
        iVar5 = Insert((ulong)this,(char *)0x1304,&_LC39,(uint)*(ushort *)pRVar6);
        pRVar6 = pRVar6 + 2;
        if (iVar5 != 0) {
          iVar5 = Insert((ulong)this,(char *)0x1304,&_LC39,
                         (uint)*(ushort *)(this + iVar1 * 2 + 0x73a));
          uVar4 = 2;
          if (iVar5 != 7) {
            uVar4 = 1;
          }
          uVar4 = otExitCodeToString(uVar4);
          otLogCritPlat("%s() at %s:%d: %s","RestoreProperties",
                        "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                        ,0x939,uVar4);
          pRVar6 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    *)(uint)*(ushort *)(this + iVar1 * 2 + 0x73a);
          puVar3 = &_LC39;
          pcVar2 = (char *)0x1304;
          goto _L0;
        }
      }
      iVar1 = 0;
      pRVar6 = this + 0x750;
_L0:
      if (iVar1 < *(short *)(this + 0x7a0)) {
        iVar5 = Insert((ulong)this,(char *)0x1305,&_LC66,pRVar6);
        if (iVar5 == 0) goto _L0;
        iVar1 = Insert((ulong)this,(char *)0x1305,&_LC66,pRVar6);
        uVar4 = 2;
        if (iVar1 != 7) {
          uVar4 = 1;
        }
        uVar4 = otExitCodeToString(uVar4);
        otLogCritPlat("%s() at %s:%d: %s","RestoreProperties",
                      "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                      0x93f,uVar4);
        puVar3 = &_LC66;
        pcVar2 = (char *)0x1305;
_L0:
        iVar1 = Insert((ulong)this,pcVar2,puVar3,pRVar6);
        goto _L0;
      }
      if (((*(uint *)(this + 0x7a8) >> 10 & 1) == 0) ||
         (iVar1 = Set((ulong)this,(char *)0x24,&_LC35,(int)(char)this[0x7a6]), iVar1 == 0)) {
        if (((*(uint *)(this + 0x7a8) >> 0xb & 1) == 0) ||
           (iVar1 = Set((ulong)this,(char *)0x25,&_LC35,(int)(char)this[0x7a7]), iVar1 == 0)) {
          if (((*(uint *)(this + 0x7a8) >> 0xc & 1) == 0) ||
             (iVar1 = Set((ulong)this,(char *)0x120d,&_LC33,*(uint *)(this + 0x7a8) >> 8 & 1),
             iVar1 == 0)) {
            if (((*(uint *)(this + 0x7a8) >> 0xd & 1) == 0) ||
               (iVar1 = Set((ulong)this,(char *)0x2a,&_LC35,(int)(char)this[0x7a8]), iVar1 == 0)) {
              iVar1 = 0xb;
              while (((this[iVar1 + 0x7c5] ==
                       (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                        )0x7f || (iVar5 = Set((ulong)this,(char *)0x2b,&_LC44,iVar1), iVar5 == 0))
                     || (iVar5 == 0x17))) {
                iVar1 = iVar1 + 1;
                if (iVar1 == 0x1b) {
                  CalcRcpTimeOffset(this);
                  return;
                }
              }
              uVar4 = otExitCodeToString(1);
              otLogCritPlat("%s() at %s:%d: %s","RestoreProperties",
                            "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                            ,0x962,uVar4);
              iVar5 = 1;
              goto _L0;
            }
            iVar1 = Set((ulong)this,(char *)0x2a,&_LC35,(int)(char)this[0x7a8]);
            uVar4 = 2;
            if (iVar1 != 7) {
              uVar4 = 1;
            }
            uVar4 = otExitCodeToString(uVar4);
            otLogCritPlat("%s() at %s:%d: %s","RestoreProperties",
                          "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                          ,0x954,uVar4);
            pRStack_4c = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                          *)(int)(char)this[0x7a8];
            puVar3 = &_LC35;
            pcVar2 = (char *)0x2a;
          }
          else {
            iVar1 = Set((ulong)this,(char *)0x120d,&_LC33,*(uint *)(this + 0x7a8) >> 8 & 1);
            uVar4 = 2;
            if (iVar1 != 7) {
              uVar4 = 1;
            }
            uVar4 = otExitCodeToString(uVar4);
            otLogCritPlat("%s() at %s:%d: %s","RestoreProperties",
                          "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                          ,0x94f,uVar4);
            puVar3 = &_LC33;
            pcVar2 = (char *)0x120d;
            pRStack_4c = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                          *)(*(uint *)(this + 0x7a8) >> 8 & 1);
          }
        }
        else {
          iVar1 = Set((ulong)this,(char *)0x25,&_LC35,(int)(char)this[0x7a7]);
          uVar4 = 2;
          if (iVar1 != 7) {
            uVar4 = 1;
          }
          uVar4 = otExitCodeToString(uVar4);
          otLogCritPlat("%s() at %s:%d: %s","RestoreProperties",
                        "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                        ,0x94a,uVar4);
          pRStack_4c = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                        *)(int)(char)this[0x7a7];
          puVar3 = &_LC35;
          pcVar2 = (char *)0x25;
        }
      }
      else {
        iVar1 = Set((ulong)this,(char *)0x24,&_LC35,(int)(char)this[0x7a6]);
        uVar4 = 2;
        if (iVar1 != 7) {
          uVar4 = 1;
        }
        uVar4 = otExitCodeToString(uVar4);
        otLogCritPlat("%s() at %s:%d: %s","RestoreProperties",
                      "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                      0x945,uVar4);
        pRStack_4c = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                      *)(int)(char)this[0x7a6];
        puVar3 = &_LC35;
        pcVar2 = (char *)0x24;
      }
      goto _L0;
    }
    pRVar6 = this + 0x70a;
    pRVar7 = this + 0x71a;
    iVar1 = Set((ulong)this,(char *)0x800,"CCddd",(uint)(byte)this[0x708],(uint)(byte)this[0x709],
                pRVar6,0x10,pRVar7);
    if (iVar1 == 0) goto _L0;
    iVar1 = Set((ulong)this,(char *)0x800,"CCddd",(uint)(byte)this[0x708],(uint)(byte)this[0x709],
                pRVar6,0x10,pRVar7);
    uVar4 = 2;
    if (iVar1 != 7) {
      uVar4 = 1;
    }
    uVar4 = otExitCodeToString(uVar4);
    otLogCritPlat("%s() at %s:%d: %s","RestoreProperties",
                  "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x929
                  ,uVar4);
    iVar1 = Set((ulong)this,(char *)0x800,"CCddd",(uint)(byte)this[0x708],(uint)(byte)this[0x709],
                pRVar6,0x10,pRVar7);
  }
  else {
    iVar1 = Set((ulong)this,(char *)0x36,&_LC39,(uint)*(ushort *)(this + 0x66e));
    uVar4 = 2;
    if (iVar1 != 7) {
      uVar4 = 1;
    }
    uVar4 = otExitCodeToString(uVar4);
    otLogCritPlat("%s() at %s:%d: %s","RestoreProperties",
                  "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x922
                  ,uVar4);
    puVar3 = &_LC39;
    pcVar2 = (char *)0x36;
    pRStack_4c = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  *)(uint)*(ushort *)(this + 0x66e);
_L0:
    iVar1 = Set((ulong)this,pcVar2,puVar3,pRStack_4c);
  }
_L0:
  iVar5 = 2;
  if (iVar1 != 7) {
    iVar5 = 1;
  }
_L0:
                    /* WARNING: Subroutine does not return */
  exit(iVar5);
_L0:
  iVar1 = iVar1 + 1;
  pRVar6 = pRVar6 + 8;
  goto _L0;
}

