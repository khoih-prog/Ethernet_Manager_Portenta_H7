/****************************************************************************************************************************
  defines.h
  For Portenta_H7 boards using Ethernet from Portenta Vision shields.

  Ethernet_Manager_Portenta_H7 is a library for Portenta_H7 boards, with Ethernet from Portenta Vision shields,
  to enable easy configuration/reconfiguration of Credentials and autoconnect/autoreconnect of Ethernet.

  Built by Khoi Hoang https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if ( ( defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_PORTENTA_H7_M4) ) && defined(ARDUINO_ARCH_MBED) )
  #warning Use MBED ARDUINO_PORTENTA_H7 and LittleFS
  
  #if defined(BOARD_NAME)
    #undef BOARD_NAME
  #endif

  #if defined(CORE_CM7)
    #warning Using Portenta H7 M7 core
    #define BOARD_NAME              "PORTENTA_H7_M7"
  #else
    #warning Using Portenta H7 M4 core
    #define BOARD_NAME              "PORTENTA_H7_M4"
  #endif

  #define USE_ETHERNET_PORTENTA_H7    true
  
  #include <Portenta_Ethernet.h>
  #include <Ethernet.h>
  #warning Using Portenta_Ethernet lib for Portenta_H7.
  #define SHIELD_TYPE           "Ethernet using Portenta_Ethernet Library"
  
#else
  #error This code is intended to run on the MBED ARDUINO_PORTENTA_H7 platform! Please check your Tools->Board setting. 
#endif

/////////////////////////////////////////////

/* Comment this out to disable prints and save space */
#define DEBUG_ETHERNET_WEBSERVER_PORT       Serial

// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_       2
#define _ETHERNET_MANAGER_LOGLEVEL_         2

#define DRD_GENERIC_DEBUG                   true

/////////////////////////////////////////////

// You have to select true for the first time for any board
#define FORCE_REFORMAT            false

/////////////////////////////////////////////

#if 0
//#define SS_PIN_DEFAULT        USE_THIS_SS_PIN

//#include <SPI.h>

//#define USE_ETHERNET_WRAPPER    true
#define USE_ETHERNET_WRAPPER    false

// Use true  for ENC28J60 and UIPEthernet library (https://github.com/UIPEthernet/UIPEthernet)
// Use false for W5x00 and Ethernetx library      (https://www.arduino.cc/en/Reference/Ethernet)

// Only one if the following to be true
#define USE_UIP_ETHERNET      false
#define USE_ETHERNET          false
#define USE_ETHERNET2         false
#define USE_ETHERNET3         false
#define USE_ETHERNET_LARGE    false
#define USE_ETHERNET_ESP8266  false
#define USE_ETHERNET_ENC      false
#define USE_CUSTOM_ETHERNET   false

#endif

/////////////////////////////////////////////

// Add customs headers from v1.2.0
#define USING_CUSTOMS_STYLE                 true
#define USING_CUSTOMS_HEAD_ELEMENT          true
#define USING_CORS_FEATURE                  true

/////////////////////////////////////////////

// Config Timeout 120s (default 60s)
#define CONFIG_TIMEOUT                      120000L

#define USE_DYNAMIC_PARAMETERS              true

//////////////////////////////////////////

#include <Ethernet_Manager_Portenta_H7.h>

#define ETHERNET_HOST_NAME   "Portenta-Ethernet"

#endif      //defines_h
