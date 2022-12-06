/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> LogSpinelFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::LogSpinelFrame(unsigned char const*, unsigned short, bool) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
LogSpinelFrame(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
               *this,uchar *param_1,ushort param_2,bool param_3)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  char *pcVar4;
  undefined2 in_register_00002032;
  undefined3 in_register_00002035;
  uint uVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined1 uStack_19f;
  undefined1 uStack_19e;
  undefined1 uStack_19d;
  int iStack_19c;
  uint uStack_198;
  int iStack_194;
  uint uStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  byte local_180 [16];
  uint auStack_170 [4];
  undefined4 uStack_160;
  undefined1 auStack_15c [146];
  char acStack_ca [2];
  undefined4 uStack_c8;
  undefined4 local_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined1 uStack_80;
  
  uStack_160 = 0;
  memset(auStack_15c,0,0x92);
  iVar3 = otLoggingGetLevel();
  if (iVar3 < 5) goto _L0;
  if (CONCAT31(in_register_00002035,param_3) == 0) {
    pcVar6 = "Received spinel frame";
  }
  else {
    pcVar6 = "Sent spinel frame";
  }
  iVar3 = spinel_datatype_unpack
                    (param_1,CONCAT22(in_register_00002032,param_2),&_LC27,&uStack_19f,&iStack_19c,
                     &uStack_198,&iStack_194,&uStack_190);
  if (iVar3 < 1) goto _L0;
  spinel_command_to_cstr(iStack_19c);
  iVar3 = Snprintf((char *)this,(ulong)&uStack_160,(char *)0x96);
  if (iStack_19c != 1) {
    puVar2 = auStack_15c + iVar3 + -4;
    spinel_prop_key_to_cstr(uStack_198);
    iVar3 = Snprintf((char *)this,(ulong)puVar2,acStack_ca + -(int)puVar2);
    puVar1 = (undefined4 *)(puVar2 + iVar3);
    if (iStack_19c != 2) {
      if (uStack_198 == 0x70) {
        auStack_170[0] = 0x97;
        iVar3 = spinel_datatype_unpack_in_place(iStack_194,uStack_190,&_LC50,&uStack_c8,auStack_170)
        ;
        uVar5 = auStack_170[0];
        if (0x96 < auStack_170[0]) {
          iVar3 = __assert_func(0,0,0,0);
        }
        if (0 < iVar3) {
          *(undefined1 *)((int)&uStack_c8 + uVar5) = 0;
          goto _L0;
        }
        goto _L0;
      }
      if (uStack_198 < 0x71) {
        if (uStack_198 < 0x28) {
          if (0x23 < uStack_198) {
_L0:
            iVar3 = spinel_datatype_unpack(iStack_194,uStack_190,&_LC35,&uStack_c8);
            goto joined_r0x0001149e;
          }
          if (uStack_198 == 2) {
            iVar3 = spinel_datatype_unpack(iStack_194,uStack_190,&_LC52,&uStack_c8);
            if (iVar3 < 0) goto _L0;
_L0:
            pcVar6 = acStack_ca + -(int)puVar1;
_L0:
            Snprintf((char *)this,(ulong)puVar1,pcVar6);
          }
          else if (uStack_198 < 3) {
            if (uStack_198 == 0) {
              iVar3 = spinel_datatype_unpack(iStack_194,uStack_190,&_LC31,&uStack_c8);
              if (0 < iVar3) {
                spinel_status_to_cstr(uStack_c8);
                goto _L0;
              }
              goto _L0;
            }
            if (uStack_198 == 1) {
              iVar3 = spinel_datatype_unpack(iStack_194,uStack_190,&_LC48,auStack_170,&uStack_c8);
              goto joined_r0x0001149e;
            }
          }
          else if (uStack_198 == 8) {
_L0:
            uStack_c8 = 0;
            local_c4 = 0;
            iVar3 = spinel_datatype_unpack_in_place(iStack_194,uStack_190,&_LC66,&uStack_c8);
            if (iVar3 < 1) goto _L0;
            Snprintf((char *)this,(ulong)puVar1,acStack_ca + -(int)puVar1);
          }
          else if (uStack_198 < 9) {
            if (uStack_198 == 5) {
              iVar3 = Snprintf((char *)this,(ulong)puVar1,acStack_ca + -(int)puVar1);
              puVar2 = (undefined1 *)((int)puVar1 + iVar3);
              while (uStack_190 != 0) {
                iVar3 = spinel_datatype_unpack(iStack_194,&_LC31,&uStack_c8);
                if (iVar3 < 1) goto _L0;
                iStack_194 = iStack_194 + iVar3;
                uStack_190 = uStack_190 - iVar3;
                spinel_capability_to_cstr(uStack_c8);
                iVar3 = Snprintf((char *)this,(ulong)puVar2,acStack_ca + -(int)puVar2);
                puVar2 = puVar2 + iVar3;
              }
            }
          }
          else {
            if (uStack_198 == 0x22) goto _L0;
            if (uStack_198 != 0x23) {
              if (uStack_198 == 0x20) goto _L0;
              uVar5 = 0x21;
              goto _L237;
            }
          }
        }
        else if (uStack_198 == 0x31) {
          iVar3 = spinel_datatype_unpack(iStack_194,uStack_190,&_LC50,&uStack_c8,auStack_170);
          if (iVar3 < 1) goto _L0;
          iVar3 = Snprintf((char *)this,(ulong)puVar1,acStack_ca + -(int)puVar1);
          puVar2 = (undefined1 *)((int)puVar1 + iVar3);
          for (uVar5 = 0; uVar5 < auStack_170[0]; uVar5 = uVar5 + 1 & 0xff) {
            iVar3 = Snprintf((char *)this,(ulong)puVar2,acStack_ca + -(int)puVar2);
            puVar2 = puVar2 + iVar3;
          }
        }
        else if (uStack_198 < 0x32) {
          if (uStack_198 == 0x2b) {
_L0:
            iVar3 = spinel_datatype_unpack(iStack_194,uStack_190,&_LC44,auStack_170,&uStack_c8);
            if (iVar3 < 1) goto _L0;
            Snprintf((char *)this,(ulong)puVar1,acStack_ca + -(int)puVar1);
          }
          else if (uStack_198 < 0x2c) {
            if (uStack_198 == 0x29) {
_L0:
              auStack_170[0] = 0x20;
              iVar3 = spinel_datatype_unpack_in_place
                                (iStack_194,uStack_190,&_LC50,&uStack_c8,auStack_170);
              if (0 < iVar3) {
                puVar7 = &uStack_c8;
                for (; auStack_170[0] != 0; auStack_170[0] = auStack_170[0] - iVar3) {
                  iVar3 = spinel_datatype_unpack(puVar7,&_LC37,local_180);
                  if ((iVar3 < 1) || (0x1f < local_180[0])) goto _L0;
                  puVar7 = (undefined4 *)((int)puVar7 + iVar3);
                }
                goto _L0;
              }
              goto _L0;
            }
            if (uStack_198 == 0x2a) goto _L0;
          }
          else {
            if (uStack_198 == 0x2c) goto _L0;
            uVar5 = 0x30;
_L237:
            if (uStack_198 == uVar5) {
_L0:
              iVar3 = spinel_datatype_unpack(iStack_194,uStack_190,&_LC37,&uStack_c8);
              goto joined_r0x0001149e;
            }
          }
        }
        else if (uStack_198 < 0x37) {
          if ((0x34 < uStack_198) || (uStack_198 == 0x32)) {
_L0:
            iVar3 = spinel_datatype_unpack(iStack_194,uStack_190,&_LC39,&uStack_c8);
            goto joined_r0x0001149e;
          }
          if (uStack_198 == 0x34) goto _L0;
        }
        else {
          if (uStack_198 == 0x39) goto _L0;
          if (uStack_198 < 0x3a) {
            if (uStack_198 == 0x37) {
_L0:
              iVar3 = spinel_datatype_unpack(iStack_194,uStack_190,&_LC33,&uStack_c8);
              goto joined_r0x000113c0;
            }
            uVar5 = 0x38;
            goto _L237;
          }
        }
      }
      else if (uStack_198 == 0x803) {
        iVar3 = spinel_datatype_unpack
                          (iStack_194,uStack_190,&_LC93,auStack_170,&uStack_c8,local_180);
        if (iVar3 < 1) goto _L0;
        Snprintf((char *)this,(ulong)puVar1,acStack_ca + -(int)puVar1);
      }
      else {
        if (uStack_198 < 0x804) {
          if (uStack_198 == 0xb0) {
_L0:
            iVar3 = spinel_datatype_unpack(iStack_194,uStack_190,&_LC31,&uStack_c8);
joined_r0x0001149e:
            if (0 < iVar3) {
              Snprintf((char *)this,(ulong)puVar1,acStack_ca + -(int)puVar1);
              goto _L0;
            }
          }
          else {
            if (0xb0 < uStack_198) {
              if (uStack_198 == 0x800) {
                uStack_18c = 0x10;
                uStack_188 = 0x10;
                uStack_184 = 0x10;
                iVar3 = spinel_datatype_unpack
                                  (iStack_194,uStack_190,"CCddd",&uStack_19e,&uStack_19d,local_180,
                                   &uStack_18c,auStack_170);
              }
              else {
                if (1 < uStack_198 - 0x801) goto _L0;
                iVar3 = spinel_datatype_unpack(iStack_194,uStack_190,&_LC30,&uStack_c8);
              }
              goto joined_r0x0001149e;
            }
            if (uStack_198 != 0x71) {
              if (uStack_198 == 0x74) {
                iVar3 = spinel_datatype_unpack(iStack_194,uStack_190,&_LC52,&uStack_c8);
                if (-1 < iVar3) {
                  iStack_194 = iStack_194 + iVar3;
                  uStack_190 = uStack_190 - iVar3;
                  iVar3 = spinel_datatype_unpack(&_LC37,auStack_170);
                  goto joined_r0x0001149e;
                }
                goto _L0;
              }
              goto _L0;
            }
            if (iStack_19c != 6) {
              if (iStack_19c == 3) {
                iVar3 = spinel_datatype_unpack
                                  (iStack_194,uStack_190,"dCCCbbbbLL",&uStack_c8,&local_c4,
                                   (int)&local_c4 + 2,&local_b0,(int)&local_b0 + 1);
                if (0 < iVar3) {
                  Snprintf((char *)this,(ulong)puVar1,acStack_ca + -(int)puVar1);
                  otLogDebgPlat(&_LC56,&uStack_160);
                  goto _L0;
                }
                goto _L0;
              }
              goto _L0;
            }
            iVar3 = spinel_datatype_unpack
                              (iStack_194,uStack_190,"dccSt(CCX)t(i)",&uStack_c8,&local_c4,
                               (int)&uStack_b4 + 1,&uStack_184,local_180);
            if (0 < iVar3) {
              Snprintf((char *)this,(ulong)puVar1,acStack_ca + -(int)puVar1);
              otLogDebgPlat(&_LC56,&uStack_160);
_L0:
              Snprintf((char *)this,(ulong)&uStack_160,(char *)0x96);
              goto _L0;
            }
          }
_L0:
          pcVar4 = "%s, failed to parse spinel frame !";
          goto _L0;
        }
        if (uStack_198 == 0x1304) {
          iVar3 = Snprintf((char *)this,(ulong)puVar1,acStack_ca + -(int)puVar1);
          puVar2 = (undefined1 *)((int)puVar1 + iVar3);
          if (uStack_190 < 2) {
_L0:
            Snprintf((char *)this,(ulong)puVar2,acStack_ca + -(int)puVar2);
          }
          else {
            while (1 < uStack_190) {
              iVar3 = spinel_datatype_unpack(iStack_194,&_LC39,&uStack_c8);
              if (iVar3 < 1) goto _L0;
              iStack_194 = iStack_194 + iVar3;
              uStack_190 = uStack_190 - iVar3;
              iVar3 = Snprintf((char *)this,(ulong)puVar2,acStack_ca + -(int)puVar2);
              puVar2 = puVar2 + iVar3;
            }
          }
        }
        else if (uStack_198 < 0x1305) {
          if (uStack_198 == 0x120c) {
            iVar3 = spinel_datatype_unpack
                              (iStack_194,uStack_190,"t(LLLLLLLL)t(LLLLLLLLL)bL",&local_c4,
                               &uStack_c0,&uStack_bc,&uStack_b8,&uStack_b4);
            if (0 < iVar3) {
              otLogDebgPlat("%s ...",&uStack_160);
              otLogDebgPlat(" txRequest:%lu",local_c4);
              otLogDebgPlat(" txGrantImmediate:%lu",uStack_c0);
              otLogDebgPlat(" txGrantWait:%lu",uStack_bc);
              otLogDebgPlat(" txGrantWaitActivated:%lu",uStack_b8);
              otLogDebgPlat(" txGrantWaitTimeout:%lu",uStack_b4);
              otLogDebgPlat(" txGrantDeactivatedDuringRequest:%lu",local_b0);
              otLogDebgPlat(" txDelayedGrant:%lu",uStack_ac);
              otLogDebgPlat(" avgTxRequestToGrantTime:%lu",uStack_a8);
              otLogDebgPlat(" rxRequest:%lu",uStack_a4);
              otLogDebgPlat(" rxGrantImmediate:%lu",uStack_a0);
              otLogDebgPlat(" rxGrantWait:%lu",uStack_9c);
              otLogDebgPlat(" rxGrantWaitActivated:%lu",uStack_98);
              otLogDebgPlat(" rxGrantWaitTimeout:%lu",uStack_94);
              otLogDebgPlat(" rxGrantDeactivatedDuringRequest:%lu",uStack_90);
              otLogDebgPlat(" rxDelayedGrant:%lu",uStack_8c);
              otLogDebgPlat(" avgRxRequestToGrantTime:%lu",uStack_88);
              otLogDebgPlat(" rxGrantNone:%lu",uStack_84);
              otLogDebgPlat(" stopped:%u",uStack_80);
              pcVar6 = (char *)0x96;
              puVar1 = &uStack_160;
              goto _L0;
            }
            goto _L0;
          }
          if (uStack_198 < 0x120d) {
            if (uStack_198 < 0x806) goto _L0;
            if (uStack_198 == 0x120b) goto _L0;
          }
          else if ((uStack_198 == 0x120d) || (uStack_198 == 0x1303)) goto _L0;
        }
        else if (uStack_198 == 0x1305) {
          iVar3 = Snprintf((char *)this,(ulong)puVar1,acStack_ca + -(int)puVar1);
          puVar2 = (undefined1 *)((int)puVar1 + iVar3);
          if (uStack_190 < 8) goto _L0;
          while (7 < uStack_190) {
            iVar3 = spinel_datatype_unpack_in_place(iStack_194,&_LC66,&uStack_c8);
            if (iVar3 < 1) goto _L0;
            iStack_194 = iStack_194 + iVar3;
            uStack_190 = uStack_190 - iVar3;
            iVar3 = Snprintf((char *)this,(ulong)puVar2,acStack_ca + -(int)puVar2);
            puVar2 = puVar2 + iVar3;
          }
        }
        else if (uStack_198 == 0x3bc0) {
          iVar3 = spinel_datatype_unpack(iStack_194,uStack_190,&_LC52,auStack_170,&uStack_c8);
joined_r0x000113c0:
          if (0 < iVar3) goto _L0;
          goto _L0;
        }
      }
    }
  }
_L0:
  pcVar6 = (char *)&uStack_160;
  pcVar4 = "%s";
_L0:
  otLogDebgPlat(pcVar4,pcVar6);
  return;
}

