/*
 Blink
 Turns on an LED on for one second, then off for one second, repeatedly.
 Based on the DigitalIO library

 This example code is in the public domain.
 */

#include <DigitalIO.h>

//Define the digital output object
DigitalOutputAH led(LED_BUILTIN);

// the setup routine runs once when you press reset:
void setup() {
}

// the loop routine runs over and over again forever:
void loop() {
  led.On();   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  led.Off();    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
  led.Toggle(); // toggle the LED, if on, turn off or if off, turn on
  delay(1000);
}
