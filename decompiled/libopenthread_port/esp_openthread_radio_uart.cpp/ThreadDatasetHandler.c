/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> ThreadDatasetHandler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: opDataset */
/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   ThreadDatasetHandler(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, uint8_t * aBuffer, uint16_t aLength) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
ThreadDatasetHandler
          (RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
           *this,uint8_t *aBuffer,uint16_t aLength)

{
  spinel_prop_key_t sVar1;
  short sVar2;
  size_t __n;
  otError oVar3;
  uint uVar4;
  uchar *puVar5;
  short local_1a6;
  uint uStack_1a4;
  uint16_t len;
  uint propKey;
  uint8_t *key;
  Dataset dataset;
  Decoder decoder;
  otOperationalDataset opDataset;
  
  sVar1 = this->mWaitingKey;
  ot::Spinel::Decoder::Decoder((Decoder *)&dataset.mType);
  ot::MeshCoP::Dataset::Dataset((Dataset *)&key,(uint)(sVar1 != 0x1518));
  memset(decoder.mPrevEnd + 2,0,0x68);
  ot::Spinel::Decoder::Init((uchar *)&dataset.mType,(ushort)aBuffer);
  do {
    if (decoder.mLength == decoder.mFrame._2_2_) {
      decoder.mPrevEnd[2] = 0;
      decoder.mPrevEnd[3] = 0;
      opDataset.mActiveTimestamp._0_4_ = 0;
      opDataset.mChannelMask._0_2_ = (ushort)opDataset.mChannelMask | 1;
      oVar3 = ot::MeshCoP::Dataset::SetFrom((Info *)&key);
      if (oVar3 != OT_ERROR_NONE) {
        return oVar3;
      }
      sVar2 = ot::Instance::Get();
      if (sVar1 == 0x1518) {
        puVar5 = (uchar *)0x1;
      }
      else {
        puVar5 = (uchar *)0x2;
      }
      oVar3 = ot::Flash::Set(sVar2 + 0x54,puVar5,(ushort)&key);
      return oVar3;
    }
    oVar3 = ot::Spinel::Decoder::OpenStruct();
    if (oVar3 != OT_ERROR_NONE) {
      return oVar3;
    }
    oVar3 = ot::Spinel::Decoder::ReadUintPacked(&dataset.mType);
    if (oVar3 != OT_ERROR_NONE) {
      return oVar3;
    }
    if (uStack_1a4 == 0x45) {
      oVar3 = ot::Spinel::Decoder::ReadData((uchar **)&dataset.mType,(ushort *)&propKey);
      if (oVar3 != OT_ERROR_NONE) {
        return oVar3;
      }
      if (local_1a6 != 8) {
        return OT_ERROR_INVALID_ARGS;
      }
      memcpy(opDataset.mNetworkName.m8 + 0xd,(void *)propKey,8);
      opDataset.mChannelMask._0_2_ = (ushort)opDataset.mChannelMask | 0x10;
    }
    else if (uStack_1a4 < 0x46) {
      if (uStack_1a4 == 0x22) {
        opDataset.mSecurityPolicy = (otSecurityPolicy)0x0;
        while (decoder.mFrame._2_2_ != decoder.mLength) {
          oVar3 = ot::Spinel::Decoder::ReadUint8((uchar *)&dataset.mType);
          if (oVar3 != OT_ERROR_NONE) {
            return oVar3;
          }
          if (0x1f < (propKey & 0xff)) {
            return OT_ERROR_INVALID_ARGS;
          }
          opDataset.mSecurityPolicy =
               (otSecurityPolicy)(1 << (propKey & 0x1f) | (uint)opDataset.mSecurityPolicy);
        }
        opDataset.mChannelMask._0_2_ = (ushort)opDataset.mChannelMask | 0x800;
      }
      else if (uStack_1a4 < 0x23) {
        if (uStack_1a4 == 0x21) {
          oVar3 = ot::Spinel::Decoder::ReadUint8((uchar *)&dataset.mType);
          if (oVar3 != OT_ERROR_NONE) {
            return oVar3;
          }
          opDataset.mDelay._2_2_ = (ushort)(byte)propKey;
          opDataset.mChannelMask._0_2_ = (ushort)opDataset.mChannelMask | 0x100;
        }
      }
      else if (uStack_1a4 == 0x36) {
        oVar3 = ot::Spinel::Decoder::ReadUint16((ushort *)&dataset.mType);
        if (oVar3 != OT_ERROR_NONE) {
          return oVar3;
        }
        opDataset.mChannelMask._0_2_ = (ushort)opDataset.mChannelMask | 0x80;
      }
      else if (uStack_1a4 == 0x44) {
        oVar3 = ot::Spinel::Decoder::ReadUtf8((char **)&dataset.mType);
        if (oVar3 != OT_ERROR_NONE) {
          return oVar3;
        }
        __n = ot::StringLength((char *)propKey,0x10);
        memcpy(opDataset.mMasterKey.m8 + 0xc,(void *)propKey,__n);
        opDataset.mMasterKey.m8[__n + 0xc] = '\0';
        opDataset.mChannelMask._0_2_ = (ushort)opDataset.mChannelMask | 8;
      }
    }
    else if (uStack_1a4 == 0x62) {
      oVar3 = ot::Spinel::Decoder::ReadItem((uchar **)&dataset.mType,(ushort)&propKey);
      if (oVar3 != OT_ERROR_NONE) {
        return oVar3;
      }
      oVar3 = ot::Spinel::Decoder::ReadUint8((uchar *)&dataset.mType);
      if (oVar3 != OT_ERROR_NONE) {
        return oVar3;
      }
      if ((char)local_1a6 != '@') {
        return OT_ERROR_INVALID_ARGS;
      }
      opDataset.mExtendedPanId.m8[4] = *(uint8_t *)propKey;
      opDataset.mExtendedPanId.m8[5] = *(uint8_t *)(propKey + 1);
      opDataset.mExtendedPanId.m8[6] = *(uint8_t *)(propKey + 2);
      opDataset.mExtendedPanId.m8[7] = *(uint8_t *)(propKey + 3);
      opDataset.mMeshLocalPrefix.m8[0] = *(uint8_t *)(propKey + 4);
      opDataset.mMeshLocalPrefix.m8[1] = *(uint8_t *)(propKey + 5);
      opDataset.mMeshLocalPrefix.m8[2] = *(uint8_t *)(propKey + 6);
      opDataset.mMeshLocalPrefix.m8[3] = *(uint8_t *)(propKey + 7);
      opDataset.mChannelMask._0_2_ = (ushort)opDataset.mChannelMask | 0x20;
    }
    else if (uStack_1a4 < 99) {
      if (uStack_1a4 == 0x46) {
        oVar3 = ot::Spinel::Decoder::ReadData((uchar **)&dataset.mType,(ushort *)&propKey);
        if (oVar3 != OT_ERROR_NONE) {
          return oVar3;
        }
        if (local_1a6 != 0x10) {
          return OT_ERROR_INVALID_ARGS;
        }
        memcpy((void *)((int)&opDataset.mPendingTimestamp + 4),(void *)propKey,0x10);
        opDataset.mChannelMask._0_2_ = (ushort)opDataset.mChannelMask | 4;
      }
      else if (uStack_1a4 == 0x4b) {
        oVar3 = ot::Spinel::Decoder::ReadData((uchar **)&dataset.mType,(ushort *)&propKey);
        if (oVar3 != OT_ERROR_NONE) {
          return oVar3;
        }
        if (local_1a6 != 0x10) {
          return OT_ERROR_INVALID_ARGS;
        }
        memcpy(&opDataset.mPanId,(void *)propKey,0x10);
        opDataset.mChannelMask._0_2_ = (ushort)opDataset.mChannelMask | 0x200;
      }
    }
    else if (uStack_1a4 == 0x151e) {
      oVar3 = ot::Spinel::Decoder::ReadUint32(&dataset.mType);
      if (oVar3 != OT_ERROR_NONE) {
        return oVar3;
      }
      opDataset.mChannelMask._0_2_ = (ushort)opDataset.mChannelMask | 0x40;
    }
    else if (uStack_1a4 == 0x151f) {
      oVar3 = ot::Spinel::Decoder::ReadUint16((ushort *)&dataset.mType);
      if (oVar3 != OT_ERROR_NONE) {
        return oVar3;
      }
      oVar3 = ot::Spinel::Decoder::ReadUint8((uchar *)&dataset.mType);
      if (oVar3 != OT_ERROR_NONE) {
        return oVar3;
      }
      uVar4 = otThreadGetVersion();
      if (((2 < uVar4) && (decoder.mFrame._2_2_ != decoder.mLength)) &&
         (oVar3 = ot::Spinel::Decoder::ReadUint8((uchar *)&dataset.mType), oVar3 != OT_ERROR_NONE))
      {
        return oVar3;
      }
      ot::SecurityPolicy::SetFlags(opDataset.mPskc.m8 + 0xc,(uchar)&propKey);
      opDataset.mChannelMask._0_2_ = (ushort)opDataset.mChannelMask | 0x400;
    }
    oVar3 = ot::Spinel::Decoder::CloseStruct();
    if (oVar3 != OT_ERROR_NONE) {
      return oVar3;
    }
  } while( true );
}

