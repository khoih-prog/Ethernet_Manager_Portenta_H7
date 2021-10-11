/****************************************************************************************************************************
  FlashIAPLimits.h - Filesystem wrapper for LittleFS on the Mbed Portenta_H7
  
  For Portenta_H7 boards using Ethernet from Portenta Vision shields.

  Ethernet_Manager_Portenta_H7 is a library for Portenta_H7 boards, with Ethernet from Portenta Vision shields,
  to enable easy configuration/reconfiguration of Credentials and autoconnect/autoreconnect of Ethernet.

  Built by Khoi Hoang https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7
  Licensed under MIT license

  Version: 1.6.1

  Version  Modified By   Date      Comments
  -------  -----------  ---------- -----------
  1.6.0     K Hoang     15/09/2021  Add support to Portenta_H7 using Arduino mbed_portenta core
  1.6.1     K Hoang     10/10/2021  Update `platform.ini` and `library.json`
*****************************************************************************************************************************/

#pragma once

#ifndef _FlashIAPLimits_h_
#define _FlashIAPLimits_h_

#include <Arduino.h>
#include <FlashIAP.h>
#include <FlashIAPBlockDevice.h>

using namespace mbed;

// A helper struct for FlashIAP limits
struct FlashIAPLimits 
{
  size_t flash_size;
  uint32_t start_address;
  uint32_t available_size;
};

// Get the actual start address and available size for the FlashIAP Block Device
// considering the space already occupied by the sketch (firmware).
FlashIAPLimits getFlashIAPLimits()
{
  // Alignment lambdas
  auto align_down = [](uint64_t val, uint64_t size) 
  {
    return (((val) / size)) * size;
  };
  
  auto align_up = [](uint32_t val, uint32_t size) 
  {
    return (((val - 1) / size) + 1) * size;
  };

  FlashIAPLimits flashIAPLimits;
  
  uint32_t  flash_start_address;
  
  FlashIAP  flash;

  auto result = flash.init();
  
  if (result != 0)
    return { };

  // Find the start of first sector after text area
  int sector_size     = flash.get_sector_size(FLASHIAP_APP_ROM_END_ADDR);

  flash_start_address           = flash.get_flash_start();
  flashIAPLimits.start_address  = align_up(FLASHIAP_APP_ROM_END_ADDR, sector_size);
  flashIAPLimits.flash_size     = flash.get_flash_size();

  result = flash.deinit();

  flashIAPLimits.available_size = flash_start_address + flashIAPLimits.flash_size - flashIAPLimits.start_address;
  
  if (flashIAPLimits.available_size % (sector_size * 2)) 
  {
    flashIAPLimits.available_size = align_down(flashIAPLimits.available_size, sector_size * 2);
  }

  return flashIAPLimits;
}
#endif    // _FlashIAPLimits_h_
