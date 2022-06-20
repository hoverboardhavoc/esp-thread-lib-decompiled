/*
 * Last changed at upstream commit b6b61e3d4891c01e9b44cc1a27e741288192b537
 * https://github.com/espressif/esp-thread-lib/commit/b6b61e3d4891c01e9b44cc1a27e741288192b537
 * Upstream date: 2022-06-20 16:22:56 +0800
 * Upstream subject: openthread: update OpenThread submodule
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
  short sVar1;
  int iVar2;
  uint uVar3;
  size_t __n;
  uchar *puVar4;
  int iVar5;
  short sStack_1c2;
  uint uStack_1c0;
  char *local_1bc;
  Decoder aDStack_1b8 [6];
  short sStack_1b2;
  short sStack_1b0;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined1 auStack_180 [16];
  undefined1 auStack_170 [17];
  undefined1 auStack_15f [8];
  undefined1 auStack_157 [17];
  ushort uStack_146;
  undefined1 auStack_144 [16];
  uchar auStack_134 [4];
  uint uStack_130;
  ushort uStack_12c;
  Dataset aDStack_128 [268];
  
  iVar5 = *(int *)(param_1 + 0x46c);
  ot::Spinel::Decoder::Decoder(aDStack_1b8);
  ot::MeshCoP::Dataset::Dataset(aDStack_128);
  memset(&uStack_1a0,0,0x78);
  ot::Spinel::Decoder::Init((uchar *)aDStack_1b8,param_2);
  do {
    if (sStack_1b2 == sStack_1b0) {
      uStack_12c = uStack_12c | 1;
      uStack_1a0 = 0;
      uStack_19c = 0;
      uStack_198 = 0;
      uStack_194 = 0;
      iVar2 = ot::MeshCoP::Dataset::SetFrom((Info *)aDStack_128);
      if (iVar2 == 0) {
        sVar1 = ot::Instance::Get();
        puVar4 = (uchar *)0x1;
        if (iVar5 != 0x1518) {
          puVar4 = (uchar *)0x2;
        }
        iVar5 = ot::Flash::Set(sVar1 + 0x54,puVar4,(ushort)aDStack_128);
        return iVar5;
      }
      return iVar2;
    }
    iVar2 = ot::Spinel::Decoder::OpenStruct();
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = ot::Spinel::Decoder::ReadUintPacked((uint *)aDStack_1b8);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (uStack_1c0 == 0x46) {
      iVar2 = ot::Spinel::Decoder::ReadData((uchar **)aDStack_1b8,(ushort *)&local_1bc);
      if (iVar2 != 0) {
        return iVar2;
      }
      if (sStack_1c2 != 0x10) {
        return 7;
      }
      memcpy(auStack_180,local_1bc,0x10);
      uStack_12c = uStack_12c | 4;
    }
    else if (uStack_1c0 < 0x47) {
      if (uStack_1c0 == 0x36) {
        iVar2 = ot::Spinel::Decoder::ReadUint16((ushort *)aDStack_1b8);
        if (iVar2 != 0) {
          return iVar2;
        }
        uStack_12c = uStack_12c | 0x80;
      }
      else if (uStack_1c0 < 0x37) {
        if (uStack_1c0 == 0x21) {
          iVar2 = ot::Spinel::Decoder::ReadUint8((uchar *)aDStack_1b8);
          if (iVar2 != 0) {
            return iVar2;
          }
          uStack_146 = (ushort)(byte)local_1bc;
          uStack_12c = uStack_12c | 0x100;
        }
        else if (uStack_1c0 == 0x22) {
          uStack_130 = 0;
          while (sStack_1b2 != sStack_1b0) {
            iVar2 = ot::Spinel::Decoder::ReadUint8((uchar *)aDStack_1b8);
            if (iVar2 != 0) {
              return iVar2;
            }
            if (0x1f < ((uint)local_1bc & 0xff)) {
              return 7;
            }
            uStack_130 = 1 << ((uint)local_1bc & 0x1f) | uStack_130;
          }
          uStack_12c = uStack_12c | 0x800;
        }
      }
      else if (uStack_1c0 == 0x44) {
        iVar2 = ot::Spinel::Decoder::ReadUtf8((char **)aDStack_1b8);
        if (iVar2 != 0) {
          return iVar2;
        }
        __n = ot::StringLength(local_1bc,0x10);
        memcpy(auStack_170,local_1bc,__n);
        auStack_170[__n] = 0;
        uStack_12c = uStack_12c | 8;
      }
      else if (uStack_1c0 == 0x45) {
        iVar2 = ot::Spinel::Decoder::ReadData((uchar **)aDStack_1b8,(ushort *)&local_1bc);
        if (iVar2 != 0) {
          return iVar2;
        }
        if (sStack_1c2 != 8) {
          return 7;
        }
        memcpy(auStack_15f,local_1bc,8);
        uStack_12c = uStack_12c | 0x10;
      }
    }
    else if (uStack_1c0 == 0x151e) {
      iVar2 = ot::Spinel::Decoder::ReadUint32((ulong *)aDStack_1b8);
      if (iVar2 != 0) {
        return iVar2;
      }
      uStack_12c = uStack_12c | 0x40;
    }
    else if (uStack_1c0 < 0x151f) {
      if (uStack_1c0 == 0x4b) {
        iVar2 = ot::Spinel::Decoder::ReadData((uchar **)aDStack_1b8,(ushort *)&local_1bc);
        if (iVar2 != 0) {
          return iVar2;
        }
        if (sStack_1c2 != 0x10) {
          return 7;
        }
        memcpy(auStack_144,local_1bc,0x10);
        uStack_12c = uStack_12c | 0x200;
      }
      else if (uStack_1c0 == 0x62) {
        iVar2 = ot::Spinel::Decoder::ReadItem((uchar **)aDStack_1b8,(ushort)&local_1bc);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar2 = ot::Spinel::Decoder::ReadUint8((uchar *)aDStack_1b8);
        if (iVar2 != 0) {
          return iVar2;
        }
        if ((char)sStack_1c2 != '@') {
          return 7;
        }
        memcpy(auStack_157,local_1bc,8);
        uStack_12c = uStack_12c | 0x20;
      }
    }
    else if (uStack_1c0 == 0x151f) {
      iVar2 = ot::Spinel::Decoder::ReadUint16((ushort *)aDStack_1b8);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = ot::Spinel::Decoder::ReadUint8((uchar *)aDStack_1b8);
      if (iVar2 != 0) {
        return iVar2;
      }
      uVar3 = otThreadGetVersion();
      if (((2 < uVar3) && (sStack_1b2 != sStack_1b0)) &&
         (iVar2 = ot::Spinel::Decoder::ReadUint8((uchar *)aDStack_1b8), iVar2 != 0)) {
        return iVar2;
      }
      ot::SecurityPolicy::SetFlags(auStack_134,(uchar)&local_1bc);
      uStack_12c = uStack_12c | 0x400;
    }
    iVar2 = ot::Spinel::Decoder::CloseStruct();
    if (iVar2 != 0) {
      return iVar2;
    }
  } while( true );
}

