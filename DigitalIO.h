#ifndef DigitalIO_h
#define DigitalIO_h
/*
 Digital I/O Library
 Written by Aram Perez, aramperez at mac.com
 Licensed under GPLv2, available at http://www.gnu.org/licenses/gpl-2.0.txt
 */

#include "Arduino.h"

//
// DigitalInput
//
class DigitalInput
{
  int pin;

  DigitalInput();

public:
  DigitalInput(int pinNbr, bool pullup = false ) :
    pin(pinNbr)
  {
    pinMode(pinNbr, pullup ? INPUT_PULLUP : INPUT);
  }
  inline bool Read(){
    return (bool) digitalRead(pin);
  }
};

//
// Base of DigitalOutput class
//
class DigitalOutputBase
{
protected:
  int pin;
  bool state;
public:
  virtual void On() = 0;
  virtual void Off() = 0;
  virtual void Toggle() = 0;
  DigitalOutputBase(int pinNbr) :
    pin(pinNbr),
    state(false)
  {
    pinMode(pinNbr, OUTPUT);
  }
};

//
// DigitalOutput, Active High
//
class DigitalOutputAH : public DigitalOutputBase
{
public:
  DigitalOutputAH(int pinNbr, bool initialState = false) :
    DigitalOutputBase(pinNbr)
  {
        initialState ? On() : Off();
  }
  inline void On(){
    digitalWrite(pin, HIGH);
    state = true;
  }
  inline void Off(){
    digitalWrite(pin, LOW);
    state = false;
  }
  void Toggle(){
    if( state ){
        Off();
    }else{
        On();
    }
  }
};

//
// DigitalOutput, Active Low
//
class DigitalOutputAL : public DigitalOutputBase
{
public:
  DigitalOutputAL(int pinNbr, bool initialState = false) :
    DigitalOutputBase(pinNbr)
  {
        initialState ? On() : Off();
  }
  inline void On(){
    digitalWrite(pin, LOW);
    state = true;
  }
  inline void Off(){
    digitalWrite(pin, HIGH);
    state = false;
  }
  void Toggle(){
    if( state ){
        Off();
    }else{
        On();
    }
  }
};

#endif //DigitalIO_h
