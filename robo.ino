#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>

#define TRIG_PIN A4
#define ECHO_PIN A5
#define MAX_DISTANCE 200
#define MAX_SPEED 190
#define MAX_SPEED_OFFSET 20

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(3, MOTOR12_1KHZ);

Servo myservo;
boolean goesForward = false;
int distance = 100;
int speedSet = 0;
void setup() {
  myservo.attach(9);
  myservo.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance =  readPing();
  delay(100);
  distance =  readPing();
  delay(100);
  distance =  readPing();
  delay(100);
}

void loop() {
  int distanceR = 0;
  int distanceL = 0;
  delay(40);

  if(distance<=15) {
    moveStop();
    delay(100);
    moveBackward();
    delay(300);
    moveStop();
    delay(200);
    distanceR = lookRight();
    delay(200);
    distanceL = lookLeft();
    delay(200);

    if(distanceR>=distanceL) {
      turnRight();
      moveStop();
    }else {
      turnleft();
      moveStop();
    }
   }else {
    moveForward();
   }
   distance = readPing();
}
int lookRight() {
  myservo.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115);
  return distance;
}

int lookLeft () {
  myservo.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115);
  return distance;
}
