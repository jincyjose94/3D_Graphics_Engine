/*
 * GENERATED FILE - DO NOT EDIT
 * Copyright 2008-2013 Code Red Technologies Ltd,
 * Copyright 2013-2023 NXP
 * Generated linker script file for LPC11C24/301
 * Created from memory.ldt by FMCreateLinkMemory
 * Using Freemarker v2.3.30
 * MCUXpresso IDE v11.8.0 [Build 1165] [2023-07-26] on Oct 18, 2023, 10:39:18 AM
 */

MEMORY
{
  /* Define each memory region */
  MFlash32 (rx) : ORIGIN = 0x0, LENGTH = 0x8000 /* 32K bytes (alias Flash) */  
  RamLoc8 (rwx) : ORIGIN = 0x10000000, LENGTH = 0x2000 /* 8K bytes (alias RAM) */  
}

  /* Define a symbol for the top of each memory region */
  __base_MFlash32 = 0x0  ; /* MFlash32 */  
  __base_Flash = 0x0 ; /* Flash */  
  __top_MFlash32 = 0x0 + 0x8000 ; /* 32K bytes */  
  __top_Flash = 0x0 + 0x8000 ; /* 32K bytes */  
  __base_RamLoc8 = 0x10000000  ; /* RamLoc8 */  
  __base_RAM = 0x10000000 ; /* RAM */  
  __top_RamLoc8 = 0x10000000 + 0x2000 ; /* 8K bytes */  
  __top_RAM = 0x10000000 + 0x2000 ; /* 8K bytes */  
