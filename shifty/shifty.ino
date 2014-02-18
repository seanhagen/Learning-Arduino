#include <Shifter.h>

const int dataPin = 4;
const int clockPin = 7;
const int latchPin = 9;
const int numRegisters = 1;
const int time = 50 * 1000;

Shifter *shifty = new Shifter( dataPin, clockPin, latchPin, numRegisters );
int counter = 0;

bool shift_one = false;
uint8_t shifter = 0x00000000;

void setup() {
  Serial.begin(9600);
  Serial.println("Power on!");
}

void loop() {
  if ( counter == time ) {
    Serial.write("Shifting bit to register ");
    Serial.println(shifter);

    shifty->out( shifter );

    Serial.println("Shifting byte over by one");
    shifter = shifter << 1;

    if ( shift_one ){
      Serial.println("Setting last bit to 1");
      shifter |= 1;
      shift_one = false;
    } else {
      Serial.println("Setting last bit to 0");
      shifter |= 0;
      shift_one = true;
    }

    
    Serial.write("Shift byte is now: ");
    Serial.println(shifter);

    counter = 0;
  }
  counter += 1;
}
