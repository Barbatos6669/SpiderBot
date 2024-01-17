#include <Servo.h>

void idle(int servo1Angle,  int servo2Angle, int servo3Angle, int servo4ZAngle); // I will come up with better vairable names later when i actrually assign the servos
void walkCycle();
void rotateRight();
void rotateLeft();
void walkForward();
void walkBackwards();

// Shoulder and Hip joints
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Next in line joint, ill come up with better names later
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;

int angle = 0;
int speedControl = 0;

int xValue;
int yValue;
int swPin;

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

void setup()
{
  //Servo code
  servo1.attach(11); //gpt suggested pwn only, will need to long in to this
  servo2.attach(10);
  servo3.attach(9);
  servo4.attach(6);

  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);

  //keeping the controller code sperate from the servo code
  pinMode(SW_pin, INPUT_PULLUP); // Use INPUT_PULLUP instead
  Serial.begin(9600);
}

void loop() 
{
  xValue = analogRead(X_pin);
  yValue = analogRead(Y_pin);
  swPin = digitalRead(SW_pin);

  // Example deadzone implementation
  int deadzone = 50;
  int midPoint = 512;

  Serial.print("xValue: ");
  Serial.print(xValue);
  Serial.println();

  if (xValue < midPoint - deadzone) {
    Serial.print("Spider is walking Forward");
    walkForward();
  } else if (xValue > midPoint + deadzone) {
    Serial.print("Spider is walking Backwards");
    walkBackwards();
  } else if (yValue < midPoint - deadzone) {
    Serial.print("Spider is rotating right");
    rotateRight();
  } else if (yValue > midPoint + deadzone) {
    Serial.print("Spider is rotating left");
    rotateLeft();
  } else {
    Serial.print("Spider is in idle mode");
    idle(180,0,180,0);
  }

  delay(1000);
}


void idle(int servo1Angle,  int servo2Angle, int servo3Angle, int servo4ZAngle)
{
  servo1.write(servo1Angle);
  servo2.write(servo2Angle);
  servo3.write(servo3Angle);
  servo4.write(servo4ZAngle);
}

void walkCycle()
{

}

void rotateRight()
{

}

void rotateLeft()
{

}

void walkForward()
{

}

void walkBackwards()
{

}
