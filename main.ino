#include
#include

AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 200 // max range 200cm

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  motor3.setSpeed(180);
  motor4.setSpeed(180);
}

void loop() {
  unsigned int distance = sonar.ping_cm();
  Serial.println(distance);
  if (distance >= 15) {
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  else {
    motor3.run(FORWARD);
    motor4.run(RELEASE);
    delay(500);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  delay(100);
}
