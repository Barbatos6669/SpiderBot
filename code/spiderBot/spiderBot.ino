l#include <Servo.h>

void idle();
void walkCycle();
void rotateRight();
void rotateLeft();
void walkForward();
void walkBackwards();

Servo servoTesting;

int angle = 0;
int speedControl = 0;

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

void setup()
{
  //Servo code
  servoTesting.attach(11); //gpt suggested pwn only, will need to long in to this
  servoTesting.write(angle);

  //keeping the controller code sperate from the servo code
  pinMode(SW_pin, INPUT_PULLUP); // Use INPUT_PULLUP instead
  Serial.begin(9600);
}

void loop()
{

}

void idle()
{

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
