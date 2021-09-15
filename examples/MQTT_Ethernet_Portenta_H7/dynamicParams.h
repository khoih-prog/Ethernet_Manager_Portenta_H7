/****************************************************************************************************************************
  dynamicParams.h
  For Portenta_H7 boards using Ethernet from Portenta Vision shields.

  Ethernet_Manager_Portenta_H7 is a library for Portenta_H7 boards, with Ethernet from Portenta Vision shields,
  to enable easy configuration/reconfiguration of Credentials and autoconnect/autoreconnect of Ethernet.

  Built by Khoi Hoang https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef dynamicParams_h
#define dynamicParams_h

#include "defines.h"

// USE_DYNAMIC_PARAMETERS defined in defined.h

/////////////// Start dynamic Credentials ///////////////

//Defined in <WiFiManager_Generic_Lite_RP2040.h>
/**************************************
  #define MAX_ID_LEN                5
  #define MAX_DISPLAY_NAME_LEN      16

  typedef struct
  {
  char id             [MAX_ID_LEN + 1];
  char displayName    [MAX_DISPLAY_NAME_LEN + 1];
  char *pdata;
  uint8_t maxlen;
  } MenuItem;
**************************************/

#define AIO_SERVER_LEN       20
#define AIO_SERVERPORT_LEN   6
#define AIO_USERNAME_LEN     20
#define AIO_KEY_LEN          40

// 
#define AIO_PUB_TOPIC_LEN    40
#define AIO_SUB_TOPIC_LEN    40

// If you don't USE_DYNAMIC_PARAMETERS, you can hardcode thse info to use

/////////////////////////////////////////////////////////////////////////////////////////

char AIO_SERVER     [AIO_SERVER_LEN + 1]        = "io.adafruit.com";
char AIO_SERVERPORT [AIO_SERVERPORT_LEN + 1]    = "1883";     //1883, or 8883 for SSL
char AIO_USERNAME   [AIO_USERNAME_LEN + 1]      = "private";
char AIO_KEY        [AIO_KEY_LEN + 1]           = "private";

char AIO_PUB_TOPIC  [AIO_PUB_TOPIC_LEN + 1]     = "/feeds/Temperature";
char AIO_SUB_TOPIC  [AIO_SUB_TOPIC_LEN + 1]     = "/feeds/LED_Control";

/////////////////////////////////////////////////////////////////////////////////////////

#if USE_DYNAMIC_PARAMETERS

MenuItem myMenuItems [] =
{
  { "svr", "AIO_SERVER",      AIO_SERVER,     AIO_SERVER_LEN },
  { "prt", "AIO_SERVERPORT",  AIO_SERVERPORT, AIO_SERVERPORT_LEN },
  { "usr", "AIO_USERNAME",    AIO_USERNAME,   AIO_USERNAME_LEN },
  { "key", "AIO_KEY",         AIO_KEY,        AIO_KEY_LEN },
  { "pub", "AIO_PUB_TOPIC",   AIO_PUB_TOPIC,  AIO_PUB_TOPIC_LEN },
  { "sub", "AIO_SUB_TOPIC",   AIO_SUB_TOPIC,  AIO_SUB_TOPIC_LEN },
};

uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

MenuItem myMenuItems [] = {};

uint16_t NUM_MENU_ITEMS = 0;

#endif    //USE_DYNAMIC_PARAMETERS


#endif      //dynamicParams_h
