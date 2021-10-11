/****************************************************************************************************************************
  Ethernet_Manager_Portenta_H7_Debug.h
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

#ifndef Ethernet_Manager_Portenta_H7_Debug_H
#define Ethernet_Manager_Portenta_H7_Debug_H

#ifdef ETHERNET_MANAGER_DEBUG_PORT
  #define ETM_DBG_PORT      ETHERNET_MANAGER_DEBUG_PORT
#else
  #define ETM_DBG_PORT      Serial
#endif

// Change _ETHERNET_MANAGER_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _ETHERNET_MANAGER_LOGLEVEL_
  #define _ETHERNET_MANAGER_LOGLEVEL_       0
#endif

const char ETM_MARK[] = "[ETM] ";
const char ETM_SP[]   = " ";

#define ETM_PRINT        ETM_DBG_PORT.print
#define ETM_PRINTLN      ETM_DBG_PORT.println

#define ETM_PRINT_MARK   ETM_PRINT(ETM_MARK)
#define ETM_PRINT_SP     ETM_PRINT(ETM_SP)

////////////////////////////////////////////////////

#define ETM_LOGERROR0(x)        if(_ETHERNET_MANAGER_LOGLEVEL_>0) { ETM_PRINT(x); }
#define ETM_LOGERROR(x)         if(_ETHERNET_MANAGER_LOGLEVEL_>0) { ETM_PRINT_MARK; ETM_PRINTLN(x); }
#define ETM_LOGERROR1(x,y)      if(_ETHERNET_MANAGER_LOGLEVEL_>0) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINTLN(y); }
#define ETM_LOGERROR2(x,y,z)    if(_ETHERNET_MANAGER_LOGLEVEL_>0) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINT(y); ETM_PRINT_SP; ETM_PRINTLN(z); }
#define ETM_LOGERROR3(x,y,z,w)  if(_ETHERNET_MANAGER_LOGLEVEL_>0) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINT(y); ETM_PRINT_SP; ETM_PRINT(z); ETM_PRINT_SP; ETM_PRINTLN(w); }
#define ETM_LOGERROR5(x,y,z,w,xx,yy) if(_ETHERNET_MANAGER_LOGLEVEL_>0) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINT(y); ETM_PRINT_SP; ETM_PRINT(z); ETM_PRINT_SP; ETM_PRINT(w); ETM_PRINT_SP; ETM_PRINT(xx); ETM_PRINT_SP; ETM_PRINTLN(yy); }

////////////////////////////////////////////////////

#define ETM_LOGWARN0(x)         if(_ETHERNET_MANAGER_LOGLEVEL_>1) { ETM_PRINT(x); }
#define ETM_LOGWARN(x)          if(_ETHERNET_MANAGER_LOGLEVEL_>1) { ETM_PRINT_MARK; ETM_PRINTLN(x); }
#define ETM_LOGWARN1(x,y)       if(_ETHERNET_MANAGER_LOGLEVEL_>1) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINTLN(y); }
#define ETM_LOGWARN2(x,y,z)     if(_ETHERNET_MANAGER_LOGLEVEL_>1) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINT(y); ETM_PRINT_SP; ETM_PRINTLN(z); }
#define ETM_LOGWARN3(x,y,z,w)   if(_ETHERNET_MANAGER_LOGLEVEL_>1) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINT(y); ETM_PRINT_SP; ETM_PRINT(z); ETM_PRINT_SP; ETM_PRINTLN(w); }
#define ETM_LOGWARN5(x,y,z,w,xx,yy) if(_ETHERNET_MANAGER_LOGLEVEL_>1) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINT(y); ETM_PRINT_SP; ETM_PRINT(z); ETM_PRINT_SP; ETM_PRINT(w); ETM_PRINT_SP; ETM_PRINT(xx); ETM_PRINT_SP; ETM_PRINTLN(yy); }

////////////////////////////////////////////////////

#define ETM_LOGINFO0(x)         if(_ETHERNET_MANAGER_LOGLEVEL_>2) { ETM_PRINT(x); }
#define ETM_LOGINFO(x)          if(_ETHERNET_MANAGER_LOGLEVEL_>2) { ETM_PRINT_MARK; ETM_PRINTLN(x); }
#define ETM_LOGINFO1(x,y)       if(_ETHERNET_MANAGER_LOGLEVEL_>2) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINTLN(y); }
#define ETM_LOGINFO2(x,y,z)     if(_ETHERNET_MANAGER_LOGLEVEL_>2) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINT(y); ETM_PRINT_SP; ETM_PRINTLN(z); }
#define ETM_LOGINFO3(x,y,z,w)   if(_ETHERNET_MANAGER_LOGLEVEL_>2) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINT(y); ETM_PRINT_SP; ETM_PRINT(z); ETM_PRINT_SP; ETM_PRINTLN(w); }
#define ETM_LOGINFO5(x,y,z,w,xx,yy) if(_ETHERNET_MANAGER_LOGLEVEL_>2) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINT(y); ETM_PRINT_SP; ETM_PRINT(z); ETM_PRINT_SP; ETM_PRINT(w); ETM_PRINT_SP; ETM_PRINT(xx); ETM_PRINT_SP; ETM_PRINTLN(yy); }

////////////////////////////////////////////////////

#define ETM_LOGDEBUG0(x)        if(_ETHERNET_MANAGER_LOGLEVEL_>3) { ETM_PRINT(x); }
#define ETM_LOGDEBUG(x)         if(_ETHERNET_MANAGER_LOGLEVEL_>3) { ETM_PRINT_MARK; ETM_PRINTLN(x); }
#define ETM_LOGDEBUG1(x,y)      if(_ETHERNET_MANAGER_LOGLEVEL_>3) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINTLN(y); }
#define ETM_LOGDEBUG2(x,y,z)    if(_ETHERNET_MANAGER_LOGLEVEL_>3) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINT(y); ETM_PRINT_SP; ETM_PRINTLN(z); }
#define ETM_LOGDEBUG3(x,y,z,w)  if(_ETHERNET_MANAGER_LOGLEVEL_>3) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINT(y); ETM_PRINT_SP; ETM_PRINT(z); ETM_PRINT_SP; ETM_PRINTLN(w); }
#define ETM_LOGDEBUG5(x,y,z,w,xx,yy) if(_ETHERNET_MANAGER_LOGLEVEL_>3) { ETM_PRINT_MARK; ETM_PRINT(x); ETM_PRINT_SP; ETM_PRINT(y); ETM_PRINT_SP; ETM_PRINT(z); ETM_PRINT_SP; ETM_PRINT(w); ETM_PRINT_SP; ETM_PRINT(xx); ETM_PRINT_SP; ETM_PRINTLN(yy); }

////////////////////////////////////////////////////

#endif    //Ethernet_Manager_Portenta_H7_Debug_H
