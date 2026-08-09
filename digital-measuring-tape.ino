/*
DIGITAL MEASURING TAPE — SINGLE PROJECT FILE

Project:
Contactless digital distance measurement system using Arduino UNO,
HC-SR04 ultrasonic sensor and a 16x2 I2C LCD.

Hardware:
- Arduino UNO
- HC-SR04 ultrasonic sensor
- 16x2 I2C LCD
- Breadboard and jumper wires
- USB cable / suitable power source

Connections:
HC-SR04 VCC  -> Arduino 5V
HC-SR04 GND  -> Arduino GND
HC-SR04 TRIG -> Arduino D9
HC-SR04 ECHO -> Arduino D10

I2C LCD VCC -> 5V
I2C LCD GND -> GND
I2C LCD SDA -> A4
I2C LCD SCL -> A5

Working:
1. Arduino sends a trigger pulse.
2. HC-SR04 emits an ultrasonic wave.
3. The wave reflects from the object and returns.
4. Arduino measures the echo time.
5. Distance is calculated using the speed of sound.
6. The result is displayed on the LCD.

Formula:
Distance = (Echo time × speed of sound) / 2

Portfolio description:
Designed and programmed a contactless distance measurement system using
ultrasonic sensing and Arduino, with real-time measurement output on an LCD.

Future improvements:
- Hold/reset button
- cm/inch mode
- Measurement history
- Rechargeable battery
- Larger display
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9;
const int echoPin = 10;

float readDistanceCm() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) return -1;

  return duration * 0.0343 / 2.0;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Digital Measure");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(1500);
  lcd.clear();
}

void loop() {
  float distance = readDistanceCm();

  lcd.clear();

  if (distance < 0 || distance > 400) {
    lcd.setCursor(0, 0);
    lcd.print("Out of range");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Distance:");

    lcd.setCursor(0, 1);
    lcd.print(distance, 1);
    lcd.print(" cm");
  }

  delay(400);
}
