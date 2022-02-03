## Ethernet_Manager_Portenta_H7

[![arduino-library-badge](https://www.ardu-badge.com/badge/Ethernet_Manager_Portenta_H7.svg?)](https://www.ardu-badge.com/Ethernet_Manager_Portenta_H7)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/Ethernet_Manager_Portenta_H7.svg)](https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/Ethernet_Manager_Portenta_H7.svg)](http://github.com/khoih-prog/Ethernet_Manager_Portenta_H7/issues)

<a href="https://www.buymeacoffee.com/khoihprog6" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Buy Me A Coffee" style="height: 60px !important;width: 217px !important;" ></a>

---
---

## Table of Contents

* [Important Notes for Portenta_H7](#important-notes-for-portenta_h7)
* [Why do we need this Ethernet_Manager_Portenta_H7 library](#why-do-we-need-this-Ethernet_Manager_Portenta_H7-library)
  * [Features](#features)
  * [Currently supported Boards](#currently-supported-boards)
  * [Currently supported Ethernet shields/modules](#currently-supported-ethernet-shieldsmodules)
* [Changelog](changelog.md) 
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For Portenta_H7 boards using Arduino IDE in Linux](#1-for-portenta_h7-boards-using-arduino-ide-in-linux)
* [Libraries' Patches](#libraries-patches)
  * [1. For Adafruit_MQTT_Library](#1-for-adafruit_mqtt_library)
* [How to use default Credentials and have them pre-loaded onto Config Portal](#how-to-use-default-credentials-and-have-them-pre-loaded-onto-config-portal)
* [How to use](#how-to-use)
  * [1. Basic usage](#1-basic-usage)
  * [2. Add custom parameters](#2-add-custom-parameters)
  * [3. Not using custom parameters](#3-not-using-custom-parameters)
  * [4. To open Config Portal](#4-to-open-config-portal)
  * [5. To use custom HTML Style](#5-to-use-custom-html-style)
  * [6. To use custom Head Elements](#6-to-use-custom-head-elements)
  * [7. To use CORS Header](#7-to-use-cors-header)
* [Important Notes for using Dynamic Parameters' ids](#important-notes-for-using-dynamic-parameters-ids)
* [Examples](#examples)
  * [ 1. Ethernet_Portenta_H7](examples/Ethernet_Portenta_H7)
  * [ 2. MQTT_Ethernet_Portenta_H7](examples/MQTT_Ethernet_Portenta_H7)
* [So, how it works?](#so-how-it-works)
* [Example Ethernet_Portenta_H7](#example-ethernet_portenta_h7)
  * [1. File Ethernet_Portenta_H7.ino](#1-file-ethernet_portenta_h7ino)
  * [2. File defines.h](#2-file-definesh) 
  * [3. File Credentials.h](#3-file-credentialsh) 
  * [4. File dynamicParams.h](#4-file-dynamicparamsh) 
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. Ethernet_Portenta_H7 on PORTENTA_H7_M7](#1-ethernet_portenta_h7-on-portenta_h7_m7)
    * [1.1 Initial start, LittleFS format and Config Portal](#11-initial-start-littlefs-format-and-config-portal)
    * [1.2. Save and Exit Config Portal](#12-save-and-exit-config-portal) 
  * [2. MQTT_Ethernet_Portenta_H7 on PORTENTA_H7_M7](#2-mqtt_ethernet_portenta_h7-on-portenta_h7_m7)
    * [2.1 Initial start, LittleFS format and Config Portal](#21-initial-start-littlefs-format-and-config-portal)
    * [2.2. Save and Exit Config Portal](#22-save-and-exit-config-portal) 
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Important Notes for Portenta_H7

The LittleFS of the new **Portenta_H7** board currently tested OK with only **maximum 8 files**. The files, from 9 and up, somehow strangely can't be written and / or read. This is possibly a bug in the [`ArduinoCore-mbed mbed_portenta core`](https://github.com/arduino/ArduinoCore-mbed). The same behaviour is observed from core v2.0.0 up to v2.5.2.

If LittleFS size is reduced to 1024KB, test is OK with only **maximum 4 files**.

Beware and keep cheking for updates.

---
---

### Why do we need this [Ethernet_Manager_Portenta_H7 library](https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7)

#### Features

- This is the new library, adding to the current WiFiManager sets of libraries. It's designed to help you eliminate `hardcoding` your Credentials in **Portenta_H7 boards using Ethernet** from [Portenta Vision shields](https://store-usa.arduino.cc/products/arduino-portenta-vision-shield-ethernet). It's currently **not supporting SSL**. Will support soon.

- You can update Credentials any time you need to change via Configure Portal. Data are saved in configurable locations in Portenta_H7 LittleFS.
- **DoubleDetectDetector** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
- Configurable **Config Portal Title** to be either BoardName or default undistinguishable names.
- Examples are redesigned to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device

The **Portenta_H7 boards**, are currently supported using [`ArduinoCore-mbed mbed_portenta core`](https://github.com/arduino/ArduinoCore-mbed).

New recent features:

- **DoubleDetectDetector** feature to force Config Portal when double reset is detected within predetermined time, default 10s.
- Configurable **Config Portal Title** to be either BoardName or default undistinguishable names.
- Examples are redesigned to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dynamic Params quickly for each device

---

#### Currently Supported Boards

This [**Ethernet_Manager_Portenta_H7** library](https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7) currently supports these following boards:

 1. **Portenta_H7** boards, using [`ArduinoCore-mbed mbed_portenta core`](https://github.com/arduino/ArduinoCore-mbed)

---
 
#### Currently supported Ethernet shields/modules

1. Portenta_H7 using Ethernet from [Portenta Vision shields](https://store-usa.arduino.cc/products/arduino-portenta-vision-shield-ethernet)

<p align="center">
    <img src="https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7/blob/main/pics/Portenta_Vision.jpg">
</p>

---
---


## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`ArduinoCore-mbed mbed_portenta core 2.6.1+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino **Portenta_H7** boards, such as **Portenta_H7 Rev2 ABX00042, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
 3. [`Functional-Vlpp library v1.0.2+`](https://github.com/khoih-prog/functional-vlpp) to use server's lambda function. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/Functional-Vlpp.svg?)](https://www.ardu-badge.com/Functional-Vlpp)
 4. [`EthernetWebServer library v2.0.0+`](https://github.com/khoih-prog/EthernetWebServer). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer.svg?)](https://www.ardu-badge.com/EthernetWebServer)
 5. [`DoubleResetDetector_Generic v1.8.0+`](https://github.com/khoih-prog/DoubleResetDetector_Generic). To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/DoubleResetDetector_Generic.svg?)](https://www.ardu-badge.com/DoubleResetDetector_Generic)
 6. [`LittleFS_Portenta_H7 v1.1.0+`](https://github.com/khoih-prog/LittleFS_Portenta_H7). To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/LittleFS_Portenta_H7.svg?)](https://www.ardu-badge.com/LittleFS_Portenta_H7) 

---
---

### Installation

The suggested way to install is to:

#### Use Arduino Library Manager

The best way is to use `Arduino Library Manager`. Search for `Ethernet_Manager_Portenta_H7`, then select / install the latest version. You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/Ethernet_Manager_Portenta_H7.svg?)](https://www.ardu-badge.com/Ethernet_Manager_Portenta_H7) for more detailed instructions.

### Manual Install

1. Navigate to [Ethernet_Manager_Portenta_H7](https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7) page.
2. Download the latest release `Ethernet_Manager_Portenta_H7-main.zip`.
3. Extract the zip file to `Ethernet_Manager_Portenta_H7-main` directory 
4. Copy the whole `Ethernet_Manager_Portenta_H7-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**Ethernet_Manager_Portenta_H7** library](https://platformio.org/lib/show/12827/Ethernet_Manager_Portenta_H7) by using [Library Manager](https://platformio.org/lib/show/12827/Ethernet_Manager_Portenta_H7/installation). Search for Ethernet_Manager_Portenta_H7 in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---

### Packages' Patches

#### 1. For Portenta_H7 boards using Arduino IDE in Linux

  **To be able to upload firmware to Portenta_H7 using Arduino IDE in Linux (Ubuntu, etc.)**, you have to copy the file [portenta_post_install.sh](Packages_Patches/arduino/hardware/mbed_portenta/2.5.2/portenta_post_install.sh) into mbed_portenta directory (~/.arduino15/packages/arduino/hardware/mbed_portenta/2.5.2/portenta_post_install.sh). 
  
  Then run the following command using `sudo`
  
```
$ cd ~/.arduino15/packages/arduino/hardware/mbed_portenta/2.5.2
$ chmod 755 portenta_post_install.sh
$ sudo ./portenta_post_install.sh
```

This will create the file `/etc/udev/rules.d/49-portenta_h7.rules` as follows:

```
# Portenta H7 bootloader mode UDEV rules

SUBSYSTEMS=="usb", ATTRS{idVendor}=="2341", ATTRS{idProduct}=="035b", GROUP="plugdev", MODE="0666"
```

Supposing the ArduinoCore-mbed core version is 2.5.2. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/2.5.2/portenta_post_install.sh`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/x.yy.zz/portenta_post_install.sh`


---

### Libraries' Patches

#### 1. For Adafruit_MQTT_Library


To fix [`Adafruit_MQTT_Library library`](https://github.com/adafruit/Adafruit_MQTT_Library), just copy the following file into the [`Adafruit_MQTT_Library library`](https://github.com/adafruit/Adafruit_MQTT_Library) installed directory to overwrite the old files:
- [Adafruit_MQTT.cpp](LibraryPatches/Adafruit_MQTT_Library/Adafruit_MQTT.cpp)

 
---
---

### How to use default Credentials and have them pre-loaded onto Config Portal

See this example and modify as necessary

1. To load [Default Credentials](examples/Ethernet_Generic/Credentials.h)
```
bool LOAD_DEFAULT_CONFIG_DATA = true;
```

2. To use system default to load "blank" when there is no valid Credentials
```
bool LOAD_DEFAULT_CONFIG_DATA = false;
```

3. Example of [Default Credentials](examples/Ethernet_Generic/Credentials.h)

```cpp
/// Start Default Config Data //////////////////

/*
typedef struct Configuration
{
  char header         [16];
  char static_IP      [16];
  char board_name     [24];
  int  checkSum;
} Ethernet_Configuration;
*/

#define TO_LOAD_DEFAULT_CONFIG_DATA      true

#if TO_LOAD_DEFAULT_CONFIG_DATA

bool LOAD_DEFAULT_CONFIG_DATA = false;

Ethernet_Configuration defaultConfig =
{
  //char header[16], dummy, not used
#if USE_SSL
  "Eth_SSL",
#else
  "Eth_NonSSL",
#endif

  // char static_IP      [16];
  //"192.168.2.230",
  // Use dynamic DHCP IP
  "",
  //char board_name     [24];
  "Air-Control",
  // terminate the list
  //int  checkSum, dummy, not used
  0
  /////////// End Default Config Data /////////////
};

#else

bool LOAD_DEFAULT_CONFIG_DATA = false;

Ethernet_Configuration defaultConfig;

#endif    // TO_LOAD_DEFAULT_CONFIG_DATA

/////////// End Default Config Data /////////////
```

---
---

### How to use

#### 1. Basic usage

- Include in your sketch

```cpp
// Must be before #include <Ethernet_Manager_Portenta_H7.h>
#include <Ethernet_Manager_Portenta_H7.h>

Ethernet_Manager ethernet_manager;
```

#### 2. Add custom parameters

- To add custom parameters, just add

```
#ifndef dynamicParams_h
#define dynamicParams_h

#include "defines.h"

// USE_DYNAMIC_PARAMETERS defined in defines.h

/////////////// Start dynamic Credentials ///////////////

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

#if USE_DYNAMIC_PARAMETERS

  #define MAX_MQTT_SERVER_LEN      34
  char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "default-mqtt-server";
  
  #define MAX_MQTT_PORT_LEN        6
  char MQTT_Port   [MAX_MQTT_PORT_LEN + 1]  = "1883";
  
  #define MAX_MQTT_USERNAME_LEN      34
  char MQTT_UserName  [MAX_MQTT_USERNAME_LEN + 1]   = "default-mqtt-username";
  
  #define MAX_MQTT_PW_LEN        34
  char MQTT_PW   [MAX_MQTT_PW_LEN + 1]  = "default-mqtt-password";
  
  #define MAX_MQTT_SUBS_TOPIC_LEN      34
  char MQTT_SubsTopic  [MAX_MQTT_SUBS_TOPIC_LEN + 1]   = "default-mqtt-SubTopic";
  
  #define MAX_MQTT_PUB_TOPIC_LEN       34
  char MQTT_PubTopic   [MAX_MQTT_PUB_TOPIC_LEN + 1]  = "default-mqtt-PubTopic";
  
  MenuItem myMenuItems [] =
  {
    { "mqtt", "MQTT Server",      MQTT_Server,      MAX_MQTT_SERVER_LEN },
    { "mqpt", "Port",             MQTT_Port,        MAX_MQTT_PORT_LEN   },
    { "user", "MQTT UserName",    MQTT_UserName,    MAX_MQTT_USERNAME_LEN },
    { "mqpw", "MQTT PWD",         MQTT_PW,          MAX_MQTT_PW_LEN },
    { "subs", "Subs Topics",      MQTT_SubsTopic,   MAX_MQTT_SUBS_TOPIC_LEN },
    { "pubs", "Pubs Topics",      MQTT_PubTopic,    MAX_MQTT_PUB_TOPIC_LEN },
  };
  
  uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

  MenuItem myMenuItems [] = {};
  
  uint16_t NUM_MENU_ITEMS = 0;
#endif

/////// // End dynamic Credentials ///////////

#endif      //dynamicParams_h
```

#### 3. Not using custom parameters

- If you don't need to add dynamic parameters, use the following in sketch

```
#define USE_DYNAMIC_PARAMETERS      false
```

#### 4. To open Config Portal

- When you want to open a config portal, just add

```cpp
ethernet_manager.begin();
```

#### 5. To use custom HTML Style

```
const char NewCustomsStyle[] /*PROGMEM*/ = "<style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}\
button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>";

...

ethernet_manager.setCustomsStyle(NewCustomsStyle);
```

#### 6. To use custom Head Elements


```
ethernet_manager.setCustomsHeadElement("<style>html{filter: invert(10%);}</style>");
```

#### 7. To use CORS Header

```
ethernet_manager.setCORSHeader("Your Access-Control-Allow-Origin");
```


While in AP mode, connect to it using its `SSID` (ESP_XXXXXX) / `Password` ("MyESP_XXXXXX"), then open a browser to the Portal AP IP, default `192.168.4.1`, configure wifi then click **Save**. The Credentials / WiFi connection information will be saved in non-volatile memory. It will then autoconnect.


Once Credentials / WiFi network information is saved in the host non-volatile memory, it will try to autoconnect to WiFi every time it is started, without requiring any function calls in the sketch.

---
---

### Important Notes for using Dynamic Parameters' ids

1. These ids (such as "mqtt" in example) must be **unique**.

Please be noted that the following **reserved names are already used in library**:

```
"ip"    for Static IP Address
"nm"    for Board Name
```

---
---

### Examples

 1. [Ethernet_Portenta_H7](examples/Ethernet_Portenta_H7)
 2. [MQTT_Ethernet_Portenta_H7](examples/MQTT_Ethernet_Portenta_H7) 

---
---

## So, how it works?

If no valid config data are stored in LittleFS, it will switch to `Configuration Mode`. Connect to access point at the IP address displayed on Terminal or Router's DHCP server :


After you connected to, for example, `192.168.2.132`, the Browser will display the following picture:

<p align="center">
    <img src="https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7/blob/main/pics/ConfigPortal.png">
</p>

Enter your credentials (Blynk Servers/Tokens and Port). If you prefer static IP, input it (for example `192.168.2.222`) in the corresponding field. Otherwise, just leave it `blank` or `nothing` to use auto IP assigned by DHCP server.

<p align="center">
    <img src="https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7/blob/main/pics/ConfigPortal_Data.png">
</p>

Then click `Save`. After the  board auto-restarted, you will see if it's connected to your Blynk server successfully as in  the following picture:

<p align="center">
    <img src="https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7/blob/main/pics/Saved.png">
</p>

This `ethernet_manager.run()` is not a blocking call, so you can use it for critical functions requiring in loop(). 

In operation, if Ethernet or connection is lost, `ethernet_manager.run()` will try reconnecting automatically. Therefore, `ethernet_manager.run()` must be called in the `loop()` function.

```cpp
void loop()
{
  ethernet_manager.run();
  ...
}
```

---
---

### Example [Ethernet_Portenta_H7](examples/Ethernet_Portenta_H7)

#### 1. File [Ethernet_Portenta_H7.ino](examples/Ethernet_Portenta_H7/Ethernet_Portenta_H7.ino)

```
#include "defines.h"
#include "Credentials.h"
#include "dynamicParams.h"

Ethernet_Manager ethernet_manager;

IPAddress localEthernetIP;

void heartBeatPrint()
{
  static int num        = 1;
  static int linkStatus = 0;
  
  localEthernetIP = Ethernet.localIP();
  
  // The linkStatus() is not working with W5100. Just using IP != 0.0.0.0
  // Better to use ping for W5100
  linkStatus = (int) Ethernet.linkStatus();
  ET_LOGINFO3("localEthernetIP = ", localEthernetIP, ", linkStatus = ", (linkStatus == LinkON) ? "LinkON" : "LinkOFF" );
  
  if ( ( (linkStatus == LinkON) ) && ((uint32_t) localEthernetIP != 0) )
  {
    Serial.print(F("H"));
  }
  else
    Serial.print(F("F"));  

  if (num == 80)
  {
    Serial.println();
    num = 1;
  }
  else if (num++ % 10 == 0)
  {
    Serial.print(F(" "));
  }
}

void check_status()
{
  #define STATUS_CHECK_INTERVAL     10000L
  
  static unsigned long checkstatus_timeout = STATUS_CHECK_INTERVAL;
  static bool ledPowerOn = false;

  // Send status report every STATUS_REPORT_INTERVAL (10) seconds: we don't need to send updates frequently if there is no status change.
  if ((millis() > checkstatus_timeout))
  {
    heartBeatPrint();

    digitalWrite(LEDB, ledPowerOn ? HIGH : LOW);
    ledPowerOn = !ledPowerOn;
    
    checkstatus_timeout = millis() + STATUS_CHECK_INTERVAL;
  }
}

#if USING_CUSTOMS_STYLE
const char NewCustomsStyle[] /*PROGMEM*/ = "<style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}\
button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>";
#endif

void setup()
{
  pinMode(LEDB, OUTPUT);
  digitalWrite(LEDB, LED_OFF);
  
  // Debug console
  Serial.begin(115200);
  while (!Serial);

  Serial.print("\nStart Ethernet_Portenta_H7 on "); Serial.println(BOARD_NAME); 
  Serial.print("Ethernet Shield type : "); Serial.println(SHIELD_TYPE);
  Serial.println(ETHERNET_MANAGER_PORTENTA_H7_VERSION);
  Serial.println(DOUBLERESETDETECTOR_GENERIC_VERSION);

  //////////////////////////////////////////////
  
#if USING_CUSTOMS_STYLE
  ethernet_manager.setCustomsStyle(NewCustomsStyle);
#endif

#if USING_CUSTOMS_HEAD_ELEMENT
  ethernet_manager.setCustomsHeadElement("<style>html{filter: invert(10%);}</style>");
#endif

#if USING_CORS_FEATURE  
  ethernet_manager.setCORSHeader("Your Access-Control-Allow-Origin");
#endif

  ethernet_manager.begin();

  //////////////////////////////////////////////

  localEthernetIP = Ethernet.localIP();

  if ( (uint32_t) localEthernetIP != 0 )
  {
    Serial.print(F("Connected! IP address: "));
    Serial.println(localEthernetIP);
  }
  else
  {
    Serial.println(F("Ethernet not Connected! Please check."));
  }
}

#if (USE_DYNAMIC_PARAMETERS)
void displayCredentials()
{
  Serial.println("\nYour stored Credentials :");

  for (int i = 0; i < NUM_MENU_ITEMS; i++)
  {
    Serial.println(String(myMenuItems[i].displayName) + " = " + myMenuItems[i].pdata);
  }
}

void displayCredentialsOnce()
{
  static bool displayedCredentials = false;

  if (!displayedCredentials)
  {
    for (int i = 0; i < NUM_MENU_ITEMS; i++)
    {
      if (!strlen(myMenuItems[i].pdata))
      {
        break;
      }

      if ( i == (NUM_MENU_ITEMS - 1) )
      {
        displayedCredentials = true;
        displayCredentials();
      }
    }
  }
}
#endif

void loop()
{
  ethernet_manager.run();
  
  check_status();

#if (USE_DYNAMIC_PARAMETERS)
  displayCredentialsOnce();
#endif  
}
```

---

#### 2. File [defines.h](examples/Ethernet_Portenta_H7/defines.h)

```
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
```
---

#### 3. File [Credentials.h](examples/Ethernet_Portenta_H7/Credentials.h)

```
#ifndef Credentials_h
#define Credentials_h

#include "defines.h"

/// Start Default Config Data //////////////////

/*
typedef struct Configuration
{
  char header         [24];
  char static_IP      [16];
  char board_name     [24];
  int  checkSum;
} Ethernet_Configuration;
*/

#define TO_LOAD_DEFAULT_CONFIG_DATA      false

#if TO_LOAD_DEFAULT_CONFIG_DATA

bool LOAD_DEFAULT_CONFIG_DATA = false;

Ethernet_Configuration defaultConfig =
{
  //char header[24], dummy, not used
#if USE_SSL
  "Eth_SSL",
#else
  "Eth_NonSSL",
#endif

  // char static_IP      [16];
  //"192.168.2.230",
  // Use dynamic DHCP IP
  "",
  //char board_name     [24];
  "Portenta-Ethernet",
  // terminate the list
  //int  checkSum, dummy, not used
  0
  /////////// End Default Config Data /////////////
};

#else

bool LOAD_DEFAULT_CONFIG_DATA = false;

Ethernet_Configuration defaultConfig;

#endif    // TO_LOAD_DEFAULT_CONFIG_DATA

/////////// End Default Config Data /////////////

#endif    //Credentials_h
```

---

#### 4. File [dynamicParams.h](examples/Ethernet_Portenta_H7/dynamicParams.h)

```
#ifndef dynamicParams_h
#define dynamicParams_h

#include "defines.h"

// USE_DYNAMIC_PARAMETERS defined in defines.h

/////////////// Start dynamic Credentials ///////////////

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

#if USE_DYNAMIC_PARAMETERS

  #define MAX_MQTT_SERVER_LEN      34
  char MQTT_Server  [MAX_MQTT_SERVER_LEN + 1]   = "default-mqtt-server";
  
  #define MAX_MQTT_PORT_LEN        6
  char MQTT_Port   [MAX_MQTT_PORT_LEN + 1]  = "1883";
  
  #define MAX_MQTT_USERNAME_LEN      34
  char MQTT_UserName  [MAX_MQTT_USERNAME_LEN + 1]   = "default-mqtt-username";
  
  #define MAX_MQTT_PW_LEN        34
  char MQTT_PW   [MAX_MQTT_PW_LEN + 1]  = "default-mqtt-password";
  
  #define MAX_MQTT_SUBS_TOPIC_LEN      34
  char MQTT_SubsTopic  [MAX_MQTT_SUBS_TOPIC_LEN + 1]   = "default-mqtt-SubTopic";
  
  #define MAX_MQTT_PUB_TOPIC_LEN       34
  char MQTT_PubTopic   [MAX_MQTT_PUB_TOPIC_LEN + 1]  = "default-mqtt-PubTopic";
  
  MenuItem myMenuItems [] =
  {
    { "mqtt", "MQTT Server",      MQTT_Server,      MAX_MQTT_SERVER_LEN },
    { "mqpt", "Port",             MQTT_Port,        MAX_MQTT_PORT_LEN   },
    { "user", "MQTT UserName",    MQTT_UserName,    MAX_MQTT_USERNAME_LEN },
    { "mqpw", "MQTT PWD",         MQTT_PW,          MAX_MQTT_PW_LEN },
    { "subs", "Subs Topics",      MQTT_SubsTopic,   MAX_MQTT_SUBS_TOPIC_LEN },
    { "pubs", "Pubs Topics",      MQTT_PubTopic,    MAX_MQTT_PUB_TOPIC_LEN },
  };
  
  uint16_t NUM_MENU_ITEMS = sizeof(myMenuItems) / sizeof(MenuItem);  //MenuItemSize;

#else

  MenuItem myMenuItems [] = {};
  
  uint16_t NUM_MENU_ITEMS = 0;
#endif

/////// // End dynamic Credentials ///////////

#endif      //dynamicParams_h
```

---
---

### Debug Terminal Output Samples

#### 1. Ethernet_Portenta_H7 on PORTENTA_H7_M7

This is the terminal output of PORTENTA_H7_M7 with Ethernet from Portenta Vision shield, running [Ethernet_Portenta_H7](examples/Ethernet_Portenta_H7) example.


#### 1.1 Initial start, LittleFS format and Config Portal

```cpp
Start Ethernet_Portenta_H7 on PORTENTA_H7_M7
Ethernet Shield type : Ethernet using Portenta_Ethernet Library
EthernetManager_Portenta_H7 v1.6.1
DoubleResetDetector_Generic v1.7.3
Flash Size: (KB) = 2048.00
FlashIAP Start Address: = 0x8080000
LittleFS size (KB) = 1536.00
LittleFS Mount OK
LittleFS Flag read = 0xd0d01234
Flag read = 0xd0d01234
doubleResetDetected
Saving to DRD file : 0xd0d04321
Saving DRD file OK
LittleFS Flag read = 0xd0d04321
ClearFlag write = 0xd0d04321
[ETM] =====================
[ETM] DRD. Run ConfigPortal
[ETM] =====================
[ETM] Start connectEthernet using DHCP
[ETM] MAC:FE-9F-FE-D9-D4-BA
[ETM] IP: 192.168.2.132
[ETM] bg: isForcedConfigPortal = false
[ETM] bg:Stay forever in CP: DRD/MRD
[ETM] clearForcedCP
[ETM] SaveCPFile 
[ETM] OK
[ETM] CfgIP= 192.168.2.132
Connected! IP address: 192.168.2.132

Your stored Credentials :
MQTT Server = default-mqtt-server
Port = 1883
MQTT UserName = default-mqtt-username
MQTT PWD = default-mqtt-password
Subs Topics = default-mqtt-SubTopic
Pubs Topics = default-mqtt-PubTopic
HHHHHHHHHHETM] 
h:Updating LittleFS: /littlefs/config.etm
[ETM] WCSum=0x c1f
[ETM] CrWCSum=0x 219f
[ETM] h:Rst
```

#### 1.2 Save and Exit Config Portal

```
Start Ethernet_Portenta_H7 on PORTENTA_H7_M7
Ethernet Shield type : Ethernet using Portenta_Ethernet Library
EthernetManager_Portenta_H7 v1.6.1
DoubleResetDetector_Generic v1.7.3
Flash Size: (KB) = 2048.00
FlashIAP Start Address: = 0x8080000
LittleFS size (KB) = 1536.00
LittleFS Mount OK
LittleFS Flag read = 0xd0d04321
Flag read = 0xd0d04321
No doubleResetDetected
Saving DOUBLERESETDETECTOR_FLAG to DRD file : 0xd0d01234
Saving DRD file OK
SetFlag write = 0xd0d01234
[ETM] CCSum=0x c1f ,RCSum=0x c1f
[ETM] CrCCsum=0x 219f ,CrRCsum=0x 219f
[ETM] CrCCsum=0x 219f ,CrRCsum=0x 219f
[ETM] Valid Stored Dynamic Data
[ETM] ======= Start Stored Config Data =======
[ETM] Header= PORTENTA-H7-ETH , BoardName= Portenta_H7_ETH
[ETM] StaticIP= 192.168.2.222
[ETM] Start connectEthernet using Static IP = 192.168.2.222
[ETM] MAC:FE-9D-FD-DA-DC-83
[ETM] IP: 192.168.2.222
[ETM] begin:Ethernet Connected.
Connected! IP address: 192.168.2.222
Stop doubleResetDetecting
Saving to DRD file : 0xd0d04321
Saving DRD file OK
LittleFS Flag read = 0xd0d04321
ClearFlag write = 0xd0d04321
H
Your stored Credentials :
MQTT Server = new-mqtt-server
Port = 1883
MQTT UserName = new-mqtt-username
MQTT PWD = new-mqtt-password
Subs Topics = new-mqtt-SubTopic
Pubs Topics = new-mqtt-PubTopic
```

---

#### 2. MQTT_Ethernet_Portenta_H7 on PORTENTA_H7_M7

This is the terminal output of PORTENTA_H7_M7 with Ethernet from Portenta Vision shield, running [MQTT_Ethernet_Portenta_H7](examples/MQTT_Ethernet_Portenta_H7) example.


<p align="center">
    <img src="https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7/blob/main/pics/MQTT_ConfigPortal.png">
</p>


#### 2.1 Initial start, LittleFS format and Config Portal

```
Start MQTT_Ethernet_Portenta_H7 on PORTENTA_H7_M7
Ethernet Shield type : Ethernet using Portenta_Ethernet Library
EthernetManager_Portenta_H7 v1.6.1
DoubleResetDetector_Generic v1.7.3
Flash Size: (KB) = 2048.00
FlashIAP Start Address: = 0x8080000
LittleFS size (KB) = 1536.00
LittleFS Mount OK
LittleFS Flag read = 0xd0d01234
Flag read = 0xd0d01234
doubleResetDetected
Saving to DRD file : 0xd0d04321
Saving DRD file OK
LittleFS Flag read = 0xd0d04321
ClearFlag write = 0xd0d04321
[ETM] =====================
[ETM] DRD. Run ConfigPortal
[ETM] =====================
[ETM] CCSum=0x 8e7 ,RCSum=0x 8e7
[ETM] CrCCsum=0x 19fa ,CrRCsum=0x 19fa
[ETM] CrCCsum=0x 19fa ,CrRCsum=0x 19fa
[ETM] Valid Stored Dynamic Data
[ETM] ======= Start Stored Config Data =======
[ETM] Header= PORTENTA-H7-ETH , BoardName= Portenta-MQTT
[ETM] StaticIP= 
[ETM] Start connectEthernet using DHCP
[ETM] MAC:FE-98-FB-D7-D5-BA
[ETM] IP: 192.168.2.132
[ETM] bg: isForcedConfigPortal = false
[ETM] bg:Stay forever in CP: DRD/MRD
[ETM] clearForcedCP
[ETM] SaveCPFile 
[ETM] OK
[ETM] CfgIP= 192.168.2.132
Connected! IP address: 192.168.2.132
H
Your stored Credentials :
AIO_SERVER = io.adafruit.com
AIO_SERVERPORT = 1883
AIO_USERNAME = private
AIO_KEY = private
AIO_PUB_TOPIC = /feeds/Temperature
AIO_SUB_TOPIC = /feeds/LED_Control
HHHHHHHHH HHHHHHHHHH HH
```

#### 2.2 Save and Exit Config Portal


<p align="center">
    <img src="https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7/blob/main/pics/MQTT_ConfigPortal_Saved.png">
</p>


```
Start MQTT_Ethernet_Portenta_H7 on PORTENTA_H7_M7
Ethernet Shield type : Ethernet using Portenta_Ethernet Library
EthernetManager_Portenta_H7 v1.6.1
DoubleResetDetector_Generic v1.7.3
Flash Size: (KB) = 2048.00
FlashIAP Start Address: = 0x8080000
LittleFS size (KB) = 1536.00
[ETM] CCSum=0x adb ,RCSum=0x adb
[ETM] CrCCsum=0x 2236 ,CrRCsum=0x 2236
[ETM] CrCCsum=0x 2236 ,CrRCsum=0x 2236
[ETM] Valid Stored Dynamic Data
[ETM] ======= Start Stored Config Data =======
[ETM] Header= PORTENTA-H7-ETH , BoardName= PORTENTA-H7-ETH
[ETM] StaticIP= 192.168.2.222
[ETM] Start connectEthernet using Static IP = 192.168.2.222
[ETM] MAC:FE-9E-FF-D6-DA-BA
[ETM] IP: 192.168.2.222
[ETM] begin:Ethernet Connected.
Connected! IP address: 192.168.2.222
H
Your stored Credentials :
AIO_SERVER = io.adafruit.com
AIO_SERVERPORT = 1883
AIO_USERNAME = user_name
AIO_KEY = aio_key
AIO_PUB_TOPIC = /feeds/Temperature
AIO_SUB_TOPIC = /feeds/LED_Control

Creating new Ethernet client object OK
Creating new MQTT object OK
AIO_SERVER = io.adafruit.com, AIO_SERVERPORT = 1883
AIO_USERNAME = user_name, AIO_KEY = aio_key
Creating new MQTT_Pub_Topic,  Temperature = user_name/feeds/Temperature
Creating new Temperature object OK
Temperature MQTT_Pub_Topic = user_name/feeds/Temperature
Creating new AIO_SUB_TOPIC, LED_Control = user_name/feeds/LED_Control
Creating new LED_Control object OK
LED_Control AIO_SUB_TOPIC = user_name/feeds/LED_Control
THTHTHT
```


---
---

### Debug

Debug is enabled by default on Serial.

You can also change the debugging level from 0 to 4

```cpp
/* Comment this out to disable prints and save space */
#define DEBUG_ETHERNET_WEBSERVER_PORT       Serial

// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_       0
#define _Ethernet_Manager_Portenta_H7_LOGLEVEL_         2
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the core for Arduino boards.

Sometimes, the library will only work if you update the board core to the latest version because I am using newly added functions.

---
---


### Issues ###

Submit issues to: [Ethernet_Manager_Portenta_H7 issues](https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7/issues)

---

### TO DO

1. Same features for other boards with new Ethernet shields.
2. Add SSL/TLS feature.
3. Bug Searching and Killing
4. Support more non-compatible Ethernet Libraries such as Ethernet_Shield_W5200, EtherCard, EtherSia.

### DONE

 1. Add support to **Portenta_H7** using Ethernet from [Portenta Vision shields](https://store-usa.arduino.cc/products/arduino-portenta-vision-shield-ethernet)
 2. More flexible to configure reconnection timeout.
 3. For fresh config data, don't need to wait for connecting timeout before entering config portal.
 4. If the config data not entered completely (Credentials, etc.), entering config portal
 5. Add configurable Config Portal IP
 6. Change Synch XMLHttpRequest to Async
 7. Add configurable Static IP, GW, Subnet Mask and 2 DNS Servers' IP Addresses.
 8. Add checksums
 9. Add auto(re)connect
10. Easy-to-use **Dynamic Parameters** without the necessity to write complicated ArduinoJSon functions
11. Default Credentials and dynamic parameters
12. **DoubleDetectDetector** to force Config Portal when double reset is detected within predetermined time, default 10s.
13. Configurable Config Portal Title
14. Re-structure all examples to separate Credentials / Defines / Dynamic Params / Code so that you can change Credentials / Dyamic Params quickly for each device.
15. Add Table of Contents and Version String
16. Configurable **Customs HTML Headers**, including Customs Style, Customs Head Elements, CORS Header
17. Add functions to control Config Portal from software or Virtual Switches.
18. Add `LibraryPatches` for [**Adafruit_MQTT_Library**](https://github.com/adafruit/Adafruit_MQTT_Library) to fix compiler error for Portenta_H7, RP2040-based and many other boards.

---
---

### Contributions and Thanks

Please help contribute to this project and add your name here.


---

### Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7/blob/main/LICENSE)

---

### Copyright

Copyright 2021- Khoi Hoang
