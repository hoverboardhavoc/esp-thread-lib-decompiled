/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> HandleHdlcFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::HandleHdlcFrame(otError) */

void __thiscall
esp::openthread::UartSpinelInterface::HandleHdlcFrame(UartSpinelInterface *this,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  if (param_2 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000100b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)this)(*(undefined4 *)(this + 4),*(code **)this);
    return;
  }
  uVar2 = esp_log_timestamp();
  uVar3 = otThreadErrorToString(param_2);
  esp_log_write(1,"OPENTHREAD",&_LC1,uVar2,"OPENTHREAD",uVar3);
  piVar5 = *(int **)(this + 8);
  iVar4 = piVar5[0x102];
  sVar1 = (short)((int)piVar5 + 0x406U);
  if (iVar4 + 4U <= (int)piVar5 + 0x406U) {
    *(undefined1 *)(iVar4 + 2) = 0;
    *(undefined1 *)(iVar4 + 3) = 0;
    iVar4 = piVar5[0x102] + *(ushort *)(piVar5[0x102] + 2) + 4;
    *piVar5 = iVar4;
    *(short *)(piVar5 + 1) = sVar1 - (short)iVar4;
  }
  iVar4 = piVar5[0x102] + *(ushort *)(piVar5[0x102] + 2) + 4;
  *piVar5 = iVar4;
  *(short *)(piVar5 + 1) = sVar1 - (short)iVar4;
  return;
}

