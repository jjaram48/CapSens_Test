#include <CapacitiveSensor.h>

/*
   CapitiveSense Library Demo Sketch
   Paul Badger 2008
   Uses a high value resistor e.g. 10M between send pin and receive pin
   Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
   Receive pin is the sensor pin - try different amounts of foil/metal on this pin
*/

//const int ledPin12 = 12;      // led connected to digital pin 12
const int ledPin13 = 13;      // led connected to digital pin 12
const int knockSensor = A0; // the piezo is connected to analog pin 0
const int threshold = 250;  // threshold value to decide when the detected sound is a knock or not

int sensorReading = 0;      // variable to store the value read from the sensor pin
int ledState = LOW;         // variable used to store the last LED status, to toggle the light


CapacitiveSensor   cs_2_4 = CapacitiveSensor(2, 4);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

void setup()
{
  Serial.begin(9600);
//  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  long start = millis();
  long total1 =  cs_2_4.capacitiveSensor(30);


  Serial.print(millis() - start);        // check on performance in milliseconds
  Serial.print("\t");                    // tab character for debug windown spacing

  Serial.print(total1);                  // print sensor output 1
  Serial.println("\t");
  delay(10);                             // arbitrary delay to limit data to serial port

  // if the sensor reading is greater than the threshold:
  if (total1 >= threshold) {
    // toggle the status of the ledPin:
    //    ledState = !ledState;
    ledState = HIGH;
    // update the LED pin itself:
    digitalWrite(ledPin13, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println("One Finger!");
  } else {
    ledState = LOW;
  }
  digitalWrite(ledPin13, ledState);

//  if (total1 >= 2.5 * threshold) {
//    // toggle the status of the ledPin:
//    //    ledState = !ledState;
//    ledState = HIGH;
//    // update the LED pin itself:
//    digitalWrite(ledPin12, ledState);
//    // send the string "Knock!" back to the computer, followed by newline
//    Serial.println("More Fingers!") ;
//  } else {
//    ledState = LOW;
//  }
//  digitalWrite(ledPin12, ledState);

  delay(100);  // delay to avoid overloading the serial port buffer
}
