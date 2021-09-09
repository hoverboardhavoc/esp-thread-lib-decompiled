/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  int iVar3;
  size_t __n;
  uint uVar4;
  uchar *puVar5;
  short sStack_1ba;
  uint uStack_1b8;
  char *local_1b4;
  Decoder aDStack_1b0 [6];
  short sStack_1aa;
  short sStack_1a8;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined1 auStack_188 [16];
  undefined1 auStack_178 [17];
  undefined1 auStack_167 [8];
  undefined1 auStack_15f [17];
  ushort uStack_14e;
  undefined1 auStack_14c [16];
  uchar auStack_13c [4];
  uint uStack_138;
  ushort uStack_134;
  Dataset aDStack_12c [276];
  
  iVar1 = *(int *)(param_1 + 0x468);
  ot::Spinel::Decoder::Decoder(aDStack_1b0);
  ot::MeshCoP::Dataset::Dataset(aDStack_12c,iVar1 != 0x1518);
  memset(&uStack_198,0,0x68);
  ot::Spinel::Decoder::Init((uchar *)aDStack_1b0,param_2);
  do {
    if (sStack_1a8 == sStack_1aa) {
      uStack_198 = 0;
      uStack_134 = uStack_134 | 1;
      uStack_194 = 0;
      iVar3 = ot::MeshCoP::Dataset::SetFrom((Info *)aDStack_12c);
      if (iVar3 == 0) {
        sVar2 = ot::Instance::Get();
        puVar5 = (uchar *)0x1;
        if (iVar1 != 0x1518) {
          puVar5 = (uchar *)0x2;
        }
        iVar1 = ot::Flash::Set(sVar2 + 0x54,puVar5,(ushort)aDStack_12c);
        return iVar1;
      }
      return iVar3;
    }
    iVar3 = ot::Spinel::Decoder::OpenStruct();
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = ot::Spinel::Decoder::ReadUintPacked((uint *)aDStack_1b0);
    if (iVar3 != 0) {
      return iVar3;
    }
    if (uStack_1b8 == 0x45) {
      iVar3 = ot::Spinel::Decoder::ReadData((uchar **)aDStack_1b0,(ushort *)&local_1b4);
      if (iVar3 != 0) {
        return iVar3;
      }
      if (sStack_1ba != 8) {
        return 7;
      }
      memcpy(auStack_167,local_1b4,8);
      uStack_134 = uStack_134 | 0x10;
    }
    else if (uStack_1b8 < 0x46) {
      if (uStack_1b8 == 0x22) {
        uStack_138 = 0;
        while (sStack_1aa != sStack_1a8) {
          iVar3 = ot::Spinel::Decoder::ReadUint8((uchar *)aDStack_1b0);
          if (iVar3 != 0) {
            return iVar3;
          }
          if (0x1f < ((uint)local_1b4 & 0xff)) {
            return 7;
          }
          uStack_138 = 1 << ((uint)local_1b4 & 0x1f) | uStack_138;
        }
        uStack_134 = uStack_134 | 0x800;
      }
      else if (uStack_1b8 < 0x23) {
        if (uStack_1b8 == 0x21) {
          iVar3 = ot::Spinel::Decoder::ReadUint8((uchar *)aDStack_1b0);
          if (iVar3 != 0) {
            return iVar3;
          }
          uStack_14e = (ushort)(byte)local_1b4;
          uStack_134 = uStack_134 | 0x100;
        }
      }
      else if (uStack_1b8 == 0x36) {
        iVar3 = ot::Spinel::Decoder::ReadUint16((ushort *)aDStack_1b0);
        if (iVar3 != 0) {
          return iVar3;
        }
        uStack_134 = uStack_134 | 0x80;
      }
      else if (uStack_1b8 == 0x44) {
        iVar3 = ot::Spinel::Decoder::ReadUtf8((char **)aDStack_1b0);
        if (iVar3 != 0) {
          return iVar3;
        }
        __n = ot::StringLength(local_1b4,0x10);
        memcpy(auStack_178,local_1b4,__n);
        auStack_178[__n] = 0;
        uStack_134 = uStack_134 | 8;
      }
    }
    else if (uStack_1b8 == 0x62) {
      iVar3 = ot::Spinel::Decoder::ReadItem((uchar **)aDStack_1b0,(ushort)&local_1b4);
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar3 = ot::Spinel::Decoder::ReadUint8((uchar *)aDStack_1b0);
      if (iVar3 != 0) {
        return iVar3;
      }
      if ((char)sStack_1ba != '@') {
        return 7;
      }
      memcpy(auStack_15f,local_1b4,8);
      uStack_134 = uStack_134 | 0x20;
    }
    else if (uStack_1b8 < 99) {
      if (uStack_1b8 == 0x46) {
        iVar3 = ot::Spinel::Decoder::ReadData((uchar **)aDStack_1b0,(ushort *)&local_1b4);
        if (iVar3 != 0) {
          return iVar3;
        }
        if (sStack_1ba != 0x10) {
          return 7;
        }
        memcpy(auStack_188,local_1b4,0x10);
        uStack_134 = uStack_134 | 4;
      }
      else if (uStack_1b8 == 0x4b) {
        iVar3 = ot::Spinel::Decoder::ReadData((uchar **)aDStack_1b0,(ushort *)&local_1b4);
        if (iVar3 != 0) {
          return iVar3;
        }
        if (sStack_1ba != 0x10) {
          return 7;
        }
        memcpy(auStack_14c,local_1b4,0x10);
        uStack_134 = uStack_134 | 0x200;
      }
    }
    else if (uStack_1b8 == 0x151e) {
      iVar3 = ot::Spinel::Decoder::ReadUint32((ulong *)aDStack_1b0);
      if (iVar3 != 0) {
        return iVar3;
      }
      uStack_134 = uStack_134 | 0x40;
    }
    else if (uStack_1b8 == 0x151f) {
      iVar3 = ot::Spinel::Decoder::ReadUint16((ushort *)aDStack_1b0);
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar3 = ot::Spinel::Decoder::ReadUint8((uchar *)aDStack_1b0);
      if (iVar3 != 0) {
        return iVar3;
      }
      uVar4 = otThreadGetVersion();
      if (((2 < uVar4) && (sStack_1aa != sStack_1a8)) &&
         (iVar3 = ot::Spinel::Decoder::ReadUint8((uchar *)aDStack_1b0), iVar3 != 0)) {
        return iVar3;
      }
      ot::SecurityPolicy::SetFlags(auStack_13c,(uchar)&local_1b4);
      uStack_134 = uStack_134 | 0x400;
    }
    iVar3 = ot::Spinel::Decoder::CloseStruct();
    if (iVar3 != 0) {
      return iVar3;
    }
  } while( true );
}

