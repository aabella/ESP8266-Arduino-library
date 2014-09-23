/*
 * ESP8266aabella.cpp
 *
 *  Created on: 23/09/2014
 *      Author: Alfonso
 */

#include "ESP8266aabella.h"

// AT COMMANDS
// BASIC
prog_uchar ESP8266aabella::AT[] PROGMEM={"AT"};
prog_uchar ESP8266aabella::AT_RESET[] PROGMEM={"AT+RST"};

// Wifi
prog_uchar ESP8266aabella::AT_SELECT_WIFI_MODE[] PROGMEM={"AT+CWMODE"};
prog_uchar ESP8266aabella::AT_AP_JOIN[] PROGMEM={"AT+CWJAP"};
prog_uchar ESP8266aabella::AT_AP_LIST_AVAIL[] PROGMEM={"AT+CWLAP"};
prog_uchar ESP8266aabella::AT_AP_DISCONNECT[] PROGMEM={"AT+CWQAP"};
prog_uchar ESP8266aabella::AT_AP_SET_PARAMS[] PROGMEM={"AT+CWSAP"};

// TCP/IP
prog_uchar ESP8266aabella::AT_CONN_STATUS[] PROGMEM={"AT+CIPSTATUS"};
prog_uchar ESP8266aabella::AT_NUM_CONN[] PROGMEM={"AT+CIPMUX=@"};
prog_uchar ESP8266aabella::AT_GET_LOCAL_IP[] PROGMEM={"AT+CIFSR"};
prog_uchar ESP8266aabella::AT_OPEN_TCP_SOCKET[] PROGMEM={"AT+CIPSTART=\"TCP\",\"@\",\"#\""};
prog_uchar ESP8266aabella::AT_SEND_DATA[] PROGMEM={"AT+CIPSEND=@"};
prog_uchar ESP8266aabella::AT_CLOSE_TCP_SOCKET[] PROGMEM={"AT+CIPCLOSE"};


// AT ANSWERS
prog_char ESP8266aabella::RSP_POWER_ON[] PROGMEM={"ready"};
prog_char ESP8266aabella::RSP_OK[] PROGMEM={"OK"};
prog_char ESP8266aabella::RSP_ERROR[] PROGMEM={"ERROR"};
prog_char ESP8266aabella::RSP_TCP_SEND_PROMPT[] PROGMEM={">"};
prog_char ESP8266aabella::RSP_TCP_SEND_OK[] PROGMEM={"SEND OK"};



ESP8266aabella::ESP8266aabella() {

}

ESP8266aabella::~ESP8266aabella() {

}


/**
 * Init internal variables and values, leaving the module ready to recive orders.
 *
 * @param SerialPort Serial port used to talk with the ESP8266 module. This port should be previously initialized.
 */
void ESP8266aabella::begin(Stream *SerialPort) {

this->serialPort = serialPort;
this->checkpoint=CHKPNT_NOTHING;
this->workingStatus=99;
this->currTimeout=0;
this->runnedMillisTotal=0;

}
