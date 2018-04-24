/*
 * Trinket M0 + 74HC165 Shift Register Internet Keyboard
 * Uses: https://github.com/InfectedBytes/ArduinoShiftIn for the shift register
 * 
 * Created: Apr, 2018
 * 
 */

#include <ShiftIn.h>
#include "Keyboard.h"

const int LOL_BUTTON = 7;
const int WTF_BUTTON = 6;
const int SMH_BUTTON = 5;
const int OMG_BUTTON = 4;


// Init ShiftIn instance with one chip.
// The number in brackets defines the number of daisy-chained 74HC165 chips
// So if you are using two chips, you would write: ShiftIn<2> shift;
ShiftIn<1> shift;

void setup() {
  Keyboard.begin();

  // declare pins: pLoadPin, clockEnablePin, dataPin, clockPin
  shift.begin(2, 0, 3, 1);
}

void loop() {
  if (shift.update()) {
    if (shift.state(LOL_BUTTON)) {
      Keyboard.print("lol\n");
    }
    if (shift.state(WTF_BUTTON)) {
      Keyboard.print("wtf\n");
    }
    if (shift.state(SMH_BUTTON)) {
      Keyboard.print("smh\n");
    }
    if (shift.state(OMG_BUTTON)) {
      Keyboard.print("omg\n");
    }
    delay(1);
  }
}
