#include <Servo.h>

const int pinflex = 0;

Servo myServo;

void setup() {

myServo.attach(10);
Serial.begin(9600);
}

void loop() {

int flexpos;

int servopos;

flexpos = analogRead(pinflex);

servopos = map(flexpos, 840, 900, 0, 180);

servopos = constrain(servopos, 0, 180);

myServo.write(servopos);
//Serial.println(flexpos);
delay(25);

}
