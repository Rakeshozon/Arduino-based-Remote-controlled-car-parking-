# IR Remote Controlled Servo Motor

This project demonstrates how to control a servo motor using an IR remote with an Arduino. The servo motor moves based on IR remote signals. An LED is also included to indicate when an IR signal is received.

## YouTube Video
Check out the complete demonstration with sound effects and detailed explanation on YouTube:
[![Watch the Video](https://img.youtube.com/vi/Xy9lPuEaP0k/0.jpg)](https://www.youtube.com/watch?v=Xy9lPuEaP0k)

## Components Required
- Arduino Board (Uno, Mega, or similar)
- IR Receiver Module (TSOP1838 or similar)
- IR Remote
- Servo Motor (SG90 or similar)
- LED
- Jumper Wires
- Breadboard (optional)

## Circuit Diagram
- **IR Receiver**:
  - VCC to 5V on Arduino
  - GND to GND on Arduino
  - Signal to Digital Pin 7 on Arduino
- **Servo Motor**:
  - VCC to 5V on Arduino
  - GND to GND on Arduino
  - Signal to Digital Pin 9 on Arduino
- **LED**:
  - Positive (Anode) to Digital Pin 13
  - Negative (Cathode) to GND

## Code Explanation

```cpp
#include <IRremote.hpp>
#define USE_IRREMOTE_HPP_AS_PLAIN_INCLUDE
#include <Servo.h>

Servo myservo;
int pos = 0;
int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  IrReceiver.begin(7); // Start the IR receiver on pin 7
  myservo.attach(9);  // Attach the servo to pin 9
}

void loop() {
  while (IrReceiver.decode() == 0) {
    digitalWrite(led, LOW);
    delay(100);
  }
  
  if (IrReceiver.decode()) {
    unsigned long value = IrReceiver.decodedIRData.decodedRawData;
    Serial.print("KEY Value in DEC = ");
    Serial.println(value, DEC);//change this value accordingly
    digitalWrite(led, HIGH);
    delay(200);

    if (value == 3810328320) {
      for (pos = 0; pos <= 90; pos += 1) {
        myservo.write(pos);
        delay(15);
      }
    } else if (value == 3125149440) {
      for (pos = 90; pos >= 0; pos -= 1) {
        myservo.write(pos);
        delay(15);
      }
    } else {
      myservo.write(0);
    }
  }
  IrReceiver.resume(); // Continue receiving IR signals
}
```

### How It Works
- The IR receiver module detects signals from the IR remote.
- When a signal is received, the LED turns on and the signal is read.
- The signal's numerical value determines the servo's movement:
  - If the value is `3810328320`, the servo moves from 0° to 90°.
  - If the value is `3125149440`, the servo moves back from 90° to 0°.
  - Any other signal resets the servo to 0°.

## Steps to Build
1. Assemble the circuit as per the diagram above.
2. Install the **IRremote** and **Servo** libraries in Arduino IDE.
3. Upload the provided code to your Arduino board.
4. Point your IR remote at the receiver and press buttons to control the servo.

## License
This project is open-source and free to use.

---
If you liked this project, don't forget to check out the YouTube video for a detailed demonstration!

[Watch on YouTube](https://www.youtube.com/watch?v=Xy9lPuEaP0k)

