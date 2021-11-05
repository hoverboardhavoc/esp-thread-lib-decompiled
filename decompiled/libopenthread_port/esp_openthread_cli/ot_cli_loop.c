/*
 * Last changed at upstream commit 84ba294781572ce5fbba05e95b6ebb22f3981d93
 * https://github.com/espressif/esp-thread-lib/commit/84ba294781572ce5fbba05e95b6ebb22f3981d93
 * Upstream date: 2021-11-05 16:42:38 +0800
 * Upstream subject: cli: add linenoise probing(1c286a5)
 * Source: libopenthread_port -> esp_openthread_cli.o -> ot_cli_loop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ot_cli_loop(void)

{
  int iVar1;
  char *__string;
  size_t sVar2;
  undefined4 local_20 [4];
  
  memcpy(local_20,&_LANCHOR2,0x10);
  iVar1 = esp_console_init(local_20);
  if (iVar1 == 0) {
    linenoiseSetMultiLine(1);
    linenoiseHistorySetMaxLen(100);
    linenoiseSetMaxLineLen(local_20[0]);
    linenoiseAllowEmpty(0);
    iVar1 = linenoiseProbe();
    if (iVar1 != 0) {
      linenoiseSetDumbMode(1);
    }
    do {
      __string = (char *)linenoise(&_LC1);
      if ((__string != (char *)0x0) && (sVar2 = strnlen(__string,0x100), sVar2 != 0)) {
        puts("\r");
        esp_openthread_cli_input(__string);
        linenoiseHistoryAdd(__string);
        xTaskGenericNotifyWait(0,0,0,0,0xffffffff);
      }
      linenoiseFree(__string);
    } while( true );
  }
                    /* WARNING: Subroutine does not return */
  abort();
}

