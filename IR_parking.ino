#include <IRremote.hpp>
#define USE_IRREMOTE_HPP_AS_PLAIN_INCLUDE
#include <Servo.h>


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

int led = 13;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  IrReceiver.begin(7); // Start the receiver
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object

}


void loop() {
  while (IrReceiver.decode() == 0) {
    digitalWrite(led, LOW);
    delay(100);
  }
  if (IrReceiver.decode()) {
    unsigned long value = IrReceiver.decodedIRData.decodedRawData;
    Serial.print("KEY Value in DEC = ");
    Serial.println(value, DEC);
    digitalWrite(led, HIGH);
    delay(200);
if (value == 3810328320){
       for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);// tell servo to go to position in variable 'pos'
    delay(15);// waits 15 ms for the servo to reach the position
  }}else if(value == 3125149440){
     for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }}else{
   myservo.write(0);
    }}
  IrReceiver.resume(); // Enable receiving of the next value
}
