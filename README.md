ESP8266 Arduino library
=======================

Arduino library for ESP8266 based on an old working implementation for SIM900. The SIM900 is done and working, but at the moment is not public, but it will be.

The main idea in the backend of the library is to avoid waiting with a delay() until the module gives an answer to an AT command, Arduino can do a lot of stuff in the loop() instead of wait in a delay()!!!

AT Commands and serial communications could be very slow, and slow down the complete program. The lost time in the delay()'s are very valuable to do other stuff. The loop() gets faster, so you can do more in the same time, or do the same but at higher frecuencies with this library for ESP8266

Currently I'm porting AT Commands (the known ones...) and code from the SIM900 library to the WiFi ESP8266 module. Please, stay tunned if you reach this page!Code will be available soon, at least to start testing.

