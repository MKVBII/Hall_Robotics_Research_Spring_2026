#include <Servo.h>

Servo myServo;

const int xPin = 0;
const int yPin = 1;
const int swPin = 2;

void setup() {
    Serial.begin(9600);
    pinMode(swPin, INPUT_PULLUP);
    myServo.attach(9);
}

void loop() {
    int xVal = analogRead(xPin);
    int yVal = analogRead(yPin);
    int button = digitialRead(sqPin);

    int angle = map(xVal, 0, 1023, 0, 180);
    myServo.write(angle);

    Serial.println("X: ");
    Serial.print(xVal);
    Serial.print(" Angle: ");
    Serial.println(angle);

    delay(50);
}