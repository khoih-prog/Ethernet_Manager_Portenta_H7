/****************************************************************************************************************************
  MQTT_Ethernet_Portenta_H7.ino
  For Portenta_H7 boards using Ethernet from Portenta Vision shields.

  Ethernet_Manager_Portenta_H7 is a library for Portenta_H7 boards, with Ethernet from Portenta Vision shields,
  to enable easy configuration/reconfiguration of Credentials and autoconnect/autoreconnect of Ethernet.

  Built by Khoi Hoang https://github.com/khoih-prog/Ethernet_Manager_Portenta_H7
  Licensed under MIT license
 *****************************************************************************************************************************/

#include "defines.h"
#include "Credentials.h"
#include "dynamicParams.h"

#include "Adafruit_MQTT.h"                //https://github.com/adafruit/Adafruit_MQTT_Library
#include "Adafruit_MQTT_Client.h"         //https://github.com/adafruit/Adafruit_MQTT_Library

///////////// Start MQTT ///////////////

// Create a EthernetClient class to connect to the MQTT server
EthernetClient *client                = NULL;

Adafruit_MQTT_Client    *mqtt         = NULL;
Adafruit_MQTT_Publish   *Temperature  = NULL;
Adafruit_MQTT_Subscribe *LED_Control  = NULL;

// You have to get from a sensor. Here is just an example
uint32_t measuredTemp = 5;

//////////// End MQTT ///////////////

Ethernet_Manager ethernet_manager;

IPAddress localEthernetIP;

bool ethernetConnected  = false;
bool inConfigMode       = true;

///////////// Start MQTT ///////////////

#define USE_GLOBAL_TOPIC    true

#if USE_GLOBAL_TOPIC
  String completePubTopic;
  String completeSubTopic;
#endif

///////////////////////////

void deleteOldInstances()
{
  // Delete previous instances
  if (mqtt)
  {
    delete mqtt;
    mqtt = NULL;
    Serial.println(F("Deleting old MQTT object"));
  }

  if (Temperature)
  {
    delete Temperature;
    Temperature = NULL;
    Serial.println(F("Deleting old Temperature object"));
  }
}

///////////////////////////

void createNewInstances()
{
  if (!client)
  {
    client = new EthernetClient;

    if (client)
    {
      Serial.println(F("\nCreating new Ethernet client object OK"));
    }
    else
      Serial.println(F("\nCreating new Ethernet client object failed"));
  }

  // Create new instances from new data
  if (!mqtt)
  {
    // Setup the MQTT client class by passing in the Ethernet client and MQTT server and login details.
    mqtt = new Adafruit_MQTT_Client(client, AIO_SERVER, atoi(AIO_SERVERPORT), AIO_USERNAME, AIO_KEY);

    if (mqtt)
    {
      Serial.println(F("Creating new MQTT object OK"));
      Serial.print(F("AIO_SERVER = ")); Serial.print(AIO_SERVER); Serial.print(F(", AIO_SERVERPORT = ")); Serial.println(AIO_SERVERPORT);
      Serial.print(F("AIO_USERNAME = ")); Serial.print(AIO_USERNAME); Serial.print(F(", AIO_KEY = ")); Serial.println(AIO_KEY);
    }
    else
      Serial.println(F("Creating new MQTT object failed"));
  }

  if (!Temperature)
  {
#if USE_GLOBAL_TOPIC
    completePubTopic = String(AIO_USERNAME) + String(AIO_PUB_TOPIC);
#else
    // Must be static or global
    static String completePubTopic = String(AIO_USERNAME) + String(AIO_PUB_TOPIC);
#endif

    Temperature = new Adafruit_MQTT_Publish(mqtt, completePubTopic.c_str());
    Serial.print(F("Creating new MQTT_Pub_Topic,  Temperature = ")); Serial.println(completePubTopic);

    if (Temperature)
    {
      Serial.println(F("Creating new Temperature object OK"));
      Serial.print(F("Temperature MQTT_Pub_Topic = ")); Serial.println(completePubTopic);
    }
    else
      Serial.println(F("Creating new Temperature object failed"));
  }

  if (!LED_Control)
  {
#if USE_GLOBAL_TOPIC
    completeSubTopic = String(AIO_USERNAME) + String(AIO_SUB_TOPIC);
#else
    // Must be static or global
    static String completeSubTopic = String(AIO_USERNAME) + String(AIO_SUB_TOPIC);
#endif

    LED_Control = new Adafruit_MQTT_Subscribe(mqtt, completeSubTopic.c_str());

    Serial.print(F("Creating new AIO_SUB_TOPIC, LED_Control = ")); Serial.println(completeSubTopic);

    if (LED_Control)
    {
      Serial.println(F("Creating new LED_Control object OK"));
      Serial.print(F("LED_Control AIO_SUB_TOPIC = ")); Serial.println(completeSubTopic);

      mqtt->subscribe(LED_Control);
    }
    else
      Serial.println(F("Creating new LED_Control object failed"));
  }
}

///////////////////////////

void MQTT_connect()
{
  int8_t ret;

  createNewInstances();

  // Return if already connected
  if (mqtt->connected())
  {
    return;
  }

#if LOCAL_DEBUG
  Serial.println(F("\nConnecting to Ethernet MQTT (3 attempts)..."));
#endif

  uint8_t attempt = 3;

  while ( (ret = mqtt->connect()) )
  {
    // connect will return 0 for connected
    Serial.println(mqtt->connectErrorString(ret));

#if LOCAL_DEBUG
    Serial.println(F("Another attemtpt to connect to MQTT in 5 seconds..."));
#endif

    mqtt->disconnect();
    delay(5000);  // wait 5 seconds
    attempt--;

    if (attempt == 0)
    {
      Serial.println(F("Ethernet MQTT connection failed. Continuing with program..."));
      return;
    }
  }

#if LOCAL_DEBUG
  Serial.println(F("Ethernet MQTT connection successful!"));
#endif
}

///////////////////////////

void publishMQTT()
{
  MQTT_connect();

  if (Temperature->publish(measuredTemp))
  {
    //Serial.println(F("Failed to send value to Temperature feed!"));
    Serial.print(F("T"));        // T means publishing OK
  }
  else
  {
    //Serial.println(F("Value to Temperature feed sucessfully sent!"));
    Serial.print(F("F"));        // F means publishing failure
  }
}

///////////////////////////

void subscribeMQTT()
{
  Adafruit_MQTT_Subscribe *subscription;

  MQTT_connect();

  while ((subscription = mqtt->readSubscription(5000)))
  {
    if (subscription == LED_Control)
    {
      Serial.print(F("\nGot: "));
      Serial.println((char *)LED_Control->lastread);

      if (!strcmp((char*) LED_Control->lastread, "ON"))
      {
        digitalWrite(LED_PIN, HIGH);
      }
      else
      {
        digitalWrite(LED_PIN, LOW);
      }
    }
  }
}

///////////// End MQTT ///////////////

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
    ethernetConnected = true;
  }
  else
  {
    Serial.print(F("F"));
    ethernetConnected = false;
  }

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

///////////////////////////

void check_status()
{
  static unsigned long checkstatus_timeout = 0;
  static bool ledPowerOn = false; 

  //KH
#define HEARTBEAT_INTERVAL    5000L
  // Print Ethernet hearbeat, Publish MQTT Topic every HEARTBEAT_INTERVAL (5) seconds.
  if ((millis() > checkstatus_timeout) || (checkstatus_timeout == 0))
  {
    if (ethernetConnected)
    {
      if (!inConfigMode)
      {
        // MQTT related jobs
        publishMQTT();
        subscribeMQTT();
      }
    }

    digitalWrite(LEDB, ledPowerOn ? LOW : HIGH);

    ledPowerOn = !ledPowerOn;

    heartBeatPrint();
    checkstatus_timeout = millis() + HEARTBEAT_INTERVAL;
  }
}

///////////////////////////

#if USING_CUSTOMS_STYLE
const char NewCustomsStyle[] /*PROGMEM*/ = "<style>div,input{padding:5px;font-size:1em;}input{width:95%;}body{text-align: center;}\
button{background-color:blue;color:white;line-height:2.4rem;font-size:1.2rem;width:100%;}fieldset{border-radius:0.3rem;margin:0px;}</style>";
#endif

///////////////////////////

void setup()
{
  pinMode(LEDB, OUTPUT);
  digitalWrite(LEDB, LED_OFF);
      
  // Debug console
  Serial.begin(115200);
  while (!Serial);

  Serial.print("\nStart MQTT_Ethernet_Portenta_H7 on "); Serial.println(BOARD_NAME); 
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

///////////////////////////

#if (USE_DYNAMIC_PARAMETERS)
void displayCredentials()
{
  Serial.println("\nYour stored Credentials :");

  for (int i = 0; i < NUM_MENU_ITEMS; i++)
  {
    Serial.println(String(myMenuItems[i].displayName) + " = " + myMenuItems[i].pdata);
  }
}
///////////////////////////

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

///////////////////////////

void loop()
{  
  inConfigMode = ethernet_manager.run();
  
  check_status();
  
  #if (USE_DYNAMIC_PARAMETERS)
    displayCredentialsOnce();
  #endif
}
