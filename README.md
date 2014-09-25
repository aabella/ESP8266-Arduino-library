ESP82667/WI07c Arduino library
=======================

Arduino library for ESP8266 based on an previous working implementation for SIM900. The SIM900 implementation is done and working, but at the moment is not public.

The main idea in the backend of the library is to avoid waiting (with a delay() or a while or whatever) until the module gives an answer to an AT command. Reset, send, or open a new connection, could take a long time. Arduino can do a lot of stuff in the loop() instead of waiting in a delay() or while!!!

AT Commands and serial communications could be very slow, and so, slow down the complete program. The lost time in the delay() or while are very valuable to do other stuff. The loop() gets faster, so you can do more in the same time, or do the same but at higher frecuencies with this library for ESP8266.

The first version is the TCP Client. Slowly I can add the UDP or server stuff, but I think the most urgent and usefull is connect, get IP and open a socket to somewhere.

The code is Object oriented and developed as efficient in memory usage as I can do, but any idea is welcomed. String library is not used internally to avoid heap fragmentation as possible in long running programs. The library is structured to make easier to modify or add AT commands.

Currently I'm porting AT Commands (the known ones...) and code from the SIM900 library to the WiFi ESP8266 module. Please, stay tunned if you reach this page! Code will be available soon, at least to start testing =)

Pinout
------

    TODO

Wiki
------

[GitHub Wiki](https://github.com/aabella/ESP8266-Arduino-library/wiki)

Interesting info about the module
----------------------------------

* [ElectroDragon] (http://www.electrodragon.com/w/Wi07c)
* [NURDspace] (https://nurdspace.nl/ESP8266)
* [Forum] (http://www.esp8266.com/)

By Alfonso Abella.
