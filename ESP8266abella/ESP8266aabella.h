/*
 * ESP8266aabella.h
 *
 *  Created on: 23/09/2014
 *      Author: Alfonso
 */

#ifndef ESP8266AABELLA_H_
#define ESP8266AABELLA_H_

#include <avr/pgmspace.h>

#define RECEPBUFFERSIZE 120  // Bytes received from serial.
#define RECEPPUBLICBUFFERSIZE 100  // Max MSG size. If smaller, more than one at a time

class ESP8266aabella {

public:

	enum WORK_CHKPNTs {
		CHKPNT_NOTHING=0, // No task

		CHKPNT_NUM_CONN=35, // Conn number
		CHKPNT_RX_MODE=40, // Receiving

		CHKPNT_GET_IP=70, // Get local IP

		CHKPNT_OPEN_TCP_SOCK=75, // Open TCP socket.

		CHKPNT_SEND_DATA_GET_PROMPT=80, // Envia datos por el socket TCP
		CHKPNT_SEND_DATA_SEND_BYTES=81, // Envia datos por el socket TCP

		CHKPNT_CLOSE_TCP_SOCKET=90, // Cierra un socket TCP

	};


private:

	// AT COMMANDS
	/*
	 * Variables for AT commands
	 */
	// BASIC

	static prog_uchar AT[] PROGMEM;
	static prog_uchar AT_RESET[] PROGMEM;

	// Wifi
	static prog_uchar AT_SELECT_WIFI_MODE[] PROGMEM;
	static prog_uchar AT_AP_JOIN[] PROGMEM;
	static prog_uchar AT_AP_LIST_AVAIL[] PROGMEM;
	static prog_uchar AT_AP_DISCONNECT[] PROGMEM;
	static prog_uchar AT_AP_SET_PARAMS[] PROGMEM;

	// TCP/IP
	static prog_uchar AT_CONN_STATUS[] PROGMEM; // Get current Connection Status.
	static prog_uchar AT_NUM_CONN[] PROGMEM; // Number of connections single/multi
	static prog_uchar AT_GET_LOCAL_IP[] PROGMEM; // Get local IP address.
	static prog_uchar AT_OPEN_TCP_SOCKET[] PROGMEM; // Start up TCP connection.
	static prog_uchar AT_SEND_DATA[] PROGMEM; // Send some data though TCP socket.
	static prog_uchar AT_CLOSE_TCP_SOCKET[] PROGMEM; // Close TCP Connection.

	// AT ANSWERS
	/*
	 * Variables for AT responses
	 */
	static prog_char RSP_POWER_ON[] PROGMEM;
	static prog_char RSP_OK[] PROGMEM;
	static prog_char RSP_ERROR[] PROGMEM;
	static prog_char RSP_TCP_SEND_PROMPT[] PROGMEM;
	static prog_char RSP_TCP_SEND_OK[] PROGMEM;


private:

	// Internal running
	int checkpoint; // Current running task
	int workingStatus; // Last registered state for the current task.
	unsigned long currTimeout; // Total timeout for current task.
	unsigned long runnedMillisTotal; // Current millis() used in the current task.

	// Serial port to WifiModule.
	HardwareSerial *serialPort;


public:


	ESP8266aabella();

	// Initialize variables and values.
	void begin(Stream *SerialPort);



};

#endif /* ESP8266AABELLA_H_ */
