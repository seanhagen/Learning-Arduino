/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
*/
/* 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
//int led = 13;
const int ledOne = 10;
const int ledTwo = 13;
const int button = 2;

int buttonState = LOW;
int setState = LOW;
int counter = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode( ledOne, OUTPUT );
  pinMode( ledTwo, OUTPUT );
  pinMode( button, INPUT );
}


void loop() {
  buttonState = digitalRead( button );

  if ( buttonState == HIGH ){
    setState = ( setState == HIGH ) ? LOW : HIGH;
  }

  digitalWrite( ledOne, setState );
  digitalWrite( ledTwo, setState );

}
*/

const int ledOne = 13;

char inData[20];
char inChar=-1;
byte index = 0;

void setup() {
  Serial.begin(9600);
  pinMode( ledOne, OUTPUT );
  Serial.write("Power on!");
}

char Comp( char* This );

void loop() {

  if ( Comp("led on")==0 ){
    digitalWrite( ledOne, HIGH );
  }

  if ( Comp("led off")==0 ){
    digitalWrite( ledOne, LOW );
  }

  /*
  if ( Serial.available() > 0 ){
    incomingByte = Serial.read();

    if ( incomingByte >= 0 ){
      for ( int i=0; i<2; i++ ){
        digitalWrite( ledOne, HIGH );
        delay( 500 );
        digitalWrite( ledOne, LOW );
      }
    }
    
    Serial.print("Got byte: ");
    Serial.println(incomingByte);

    delay(200);
  }
  */

}

char Comp( char* This ) {
  while( Serial.available() > 0 ){
    inChar = Serial.read();

    Serial.write( inChar );
    
    if ( index < 19 ){
      inData[index++] = inChar;
      inData[index] = '\0';
    } else {
      index = 0;
      Serial.print("reset");
    }
  }

  if ( strcmp( inData, This ) == 0 ) {
    for ( int i=0; i<19; i++){
      inData[i]=0;
    }
    index=0;
    return(0);
  } else {
    return(1);
  }
}