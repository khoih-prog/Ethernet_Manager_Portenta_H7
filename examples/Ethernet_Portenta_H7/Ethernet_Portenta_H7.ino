/****************************************************************************************************************************
  Ethernet_Portenta_H7.ino
  For Portenta_H7 boards using Ethernet from Portenta Vision shields.

  Ethernet_Manager_Portenta_H7 is a library for Portenta_H7 boards, with Ethernet from Portenta Vision shields,
  to enable easy configuration/reconfiguration of Credentials and autoconnect/autoreconnect of Ethernet.

  Built by Khoi Hoang https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7
  Licensed under MIT license
 *****************************************************************************************************************************/

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
