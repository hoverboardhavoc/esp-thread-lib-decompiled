/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> ThreadDatasetHandler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::ThreadDatasetHandler(unsigned char const*, unsigned short) */

int ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ThreadDatasetHandler(uchar *param_1,ushort param_2)

{
  int iVar1;
  short sVar2;
  size_t __n;
  int iVar3;
  uint uVar4;
  uchar *puVar5;
  short local_1a6;
  uint uStack_1a4;
  char *local_1a0;
  Dataset aDStack_19c [268];
  Decoder aDStack_90 [6];
  short sStack_8a;
  short sStack_88;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined1 auStack_68 [16];
  undefined1 auStack_58 [17];
  undefined1 auStack_47 [8];
  char cStack_3f;
  char cStack_3e;
  char cStack_3d;
  char cStack_3c;
  char cStack_3b;
  char cStack_3a;
  char cStack_39;
  char cStack_38;
  ushort uStack_2e;
  undefined1 auStack_2c [16];
  uchar auStack_1c [4];
  uint uStack_18;
  ushort uStack_14;
  
  iVar1 = *(int *)(param_1 + 0x468);
  ot::Spinel::Decoder::Decoder(aDStack_90);
  ot::MeshCoP::Dataset::Dataset(aDStack_19c,iVar1 != 0x1518);
  memset(&uStack_78,0,0x68);
  ot::Spinel::Decoder::Init((uchar *)aDStack_90,param_2);
  do {
    if (sStack_88 == sStack_8a) {
      uStack_78 = 0;
      uStack_74 = 0;
      uStack_14 = uStack_14 | 1;
      iVar3 = ot::MeshCoP::Dataset::SetFrom((Info *)aDStack_19c);
      if (iVar3 != 0) {
        return iVar3;
      }
      sVar2 = ot::Instance::Get();
      if (iVar1 == 0x1518) {
        puVar5 = (uchar *)0x1;
      }
      else {
        puVar5 = (uchar *)0x2;
      }
      iVar1 = ot::Flash::Set(sVar2 + 0x54,puVar5,(ushort)aDStack_19c);
      return iVar1;
    }
    iVar3 = ot::Spinel::Decoder::OpenStruct();
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = ot::Spinel::Decoder::ReadUintPacked((uint *)aDStack_90);
    if (iVar3 != 0) {
      return iVar3;
    }
    if (uStack_1a4 == 0x45) {
      iVar3 = ot::Spinel::Decoder::ReadData((uchar **)aDStack_90,(ushort *)&local_1a0);
      if (iVar3 != 0) {
        return iVar3;
      }
      if (local_1a6 != 8) {
        return 7;
      }
      memcpy(auStack_47,local_1a0,8);
      uStack_14 = uStack_14 | 0x10;
    }
    else if (uStack_1a4 < 0x46) {
      if (uStack_1a4 == 0x22) {
        uStack_18 = 0;
        while (sStack_8a != sStack_88) {
          iVar3 = ot::Spinel::Decoder::ReadUint8((uchar *)aDStack_90);
          if (iVar3 != 0) {
            return iVar3;
          }
          if (0x1f < ((uint)local_1a0 & 0xff)) {
            return 7;
          }
          uStack_18 = 1 << ((uint)local_1a0 & 0x1f) | uStack_18;
        }
        uStack_14 = uStack_14 | 0x800;
      }
      else if (uStack_1a4 < 0x23) {
        if (uStack_1a4 == 0x21) {
          iVar3 = ot::Spinel::Decoder::ReadUint8((uchar *)aDStack_90);
          if (iVar3 != 0) {
            return iVar3;
          }
          uStack_2e = (ushort)(byte)local_1a0;
          uStack_14 = uStack_14 | 0x100;
        }
      }
      else if (uStack_1a4 == 0x36) {
        iVar3 = ot::Spinel::Decoder::ReadUint16((ushort *)aDStack_90);
        if (iVar3 != 0) {
          return iVar3;
        }
        uStack_14 = uStack_14 | 0x80;
      }
      else if (uStack_1a4 == 0x44) {
        iVar3 = ot::Spinel::Decoder::ReadUtf8((char **)aDStack_90);
        if (iVar3 != 0) {
          return iVar3;
        }
        __n = ot::StringLength(local_1a0,0x10);
        memcpy(auStack_58,local_1a0,__n);
        auStack_58[__n] = 0;
        uStack_14 = uStack_14 | 8;
      }
    }
    else if (uStack_1a4 == 0x62) {
      iVar3 = ot::Spinel::Decoder::ReadItem((uchar **)aDStack_90,(ushort)&local_1a0);
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar3 = ot::Spinel::Decoder::ReadUint8((uchar *)aDStack_90);
      if (iVar3 != 0) {
        return iVar3;
      }
      if ((char)local_1a6 != '@') {
        return 7;
      }
      cStack_3f = *local_1a0;
      cStack_3e = local_1a0[1];
      cStack_3d = local_1a0[2];
      cStack_3c = local_1a0[3];
      cStack_3b = local_1a0[4];
      cStack_3a = local_1a0[5];
      cStack_39 = local_1a0[6];
      cStack_38 = local_1a0[7];
      uStack_14 = uStack_14 | 0x20;
    }
    else if (uStack_1a4 < 99) {
      if (uStack_1a4 == 0x46) {
        iVar3 = ot::Spinel::Decoder::ReadData((uchar **)aDStack_90,(ushort *)&local_1a0);
        if (iVar3 != 0) {
          return iVar3;
        }
        if (local_1a6 != 0x10) {
          return 7;
        }
        memcpy(auStack_68,local_1a0,0x10);
        uStack_14 = uStack_14 | 4;
      }
      else if (uStack_1a4 == 0x4b) {
        iVar3 = ot::Spinel::Decoder::ReadData((uchar **)aDStack_90,(ushort *)&local_1a0);
        if (iVar3 != 0) {
          return iVar3;
        }
        if (local_1a6 != 0x10) {
          return 7;
        }
        memcpy(auStack_2c,local_1a0,0x10);
        uStack_14 = uStack_14 | 0x200;
      }
    }
    else if (uStack_1a4 == 0x151e) {
      iVar3 = ot::Spinel::Decoder::ReadUint32((ulong *)aDStack_90);
      if (iVar3 != 0) {
        return iVar3;
      }
      uStack_14 = uStack_14 | 0x40;
    }
    else if (uStack_1a4 == 0x151f) {
      iVar3 = ot::Spinel::Decoder::ReadUint16((ushort *)aDStack_90);
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar3 = ot::Spinel::Decoder::ReadUint8((uchar *)aDStack_90);
      if (iVar3 != 0) {
        return iVar3;
      }
      uVar4 = otThreadGetVersion();
      if (((2 < uVar4) && (sStack_8a != sStack_88)) &&
         (iVar3 = ot::Spinel::Decoder::ReadUint8((uchar *)aDStack_90), iVar3 != 0)) {
        return iVar3;
      }
      ot::SecurityPolicy::SetFlags(auStack_1c,(uchar)&local_1a0);
      uStack_14 = uStack_14 | 0x400;
    }
    iVar3 = ot::Spinel::Decoder::CloseStruct();
    if (iVar3 != 0) {
      return iVar3;
    }
  } while( true );
}

