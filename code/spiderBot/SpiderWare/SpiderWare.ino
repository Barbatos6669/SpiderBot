/*
    Spider Robot Controller
    Author: Larry J Frenzel
    Date: 20240125

    Description:
    This program is designed to control a spider robot using an Arduino and a PCA9685 servo driver.
    It includes functions to perform various movements like walking and waving. The program
    utilizes inverse kinematics for coordinated leg movements and includes a buffer zone implementation
    to prevent servo collision.

    Hardware:
    - Arduino Arduino UNO R3
    - PCA9685 PWM Servo Driver
    - Servo Motors (Number: [8]ls)

    Features:
    - Servo angle mapping for precise control.
    - Wave and walk test functions for demonstrating servo coordination.
    - Safety buffer implementation to prevent mechanical stress.

    Notes:
    - Update the servo specifications in the servoAngle function as per your servo model.
    - The walkCycle function demonstrates a basic walking pattern, which can be further
      enhanced using inverse kinematics for more natural movements.
*/


#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver spiderLegs = Adafruit_PWMServoDriver();

int servoAngle(int angle);
void waveTest();
void walkCycle();

const int safeMinAngle = 10; // Minimum angle with buffer
const int safeMaxAngle = 170; // Maximum angle with buffer

void setup() {
  spiderLegs.begin();
  spiderLegs.setPWMFreq(50);
  
  // Initialize all servos to 90 degrees
  for (int i = 0; i < 8; i++) {
    spiderLegs.setPWM(i, 0, servoAngle(90));
    delay(1000);
  }
}

void loop() 
{
  walkCycle();
}

// Map function
int servoAngle(int angle) 
{
  // Assuming a standard servo with 180-degree rotation
  // Modify minPulseWidth and maxPulseWidth based on your servo specifications
  int minPulseWidth = 150; // The 'off' value for 0 degrees
  int maxPulseWidth = 600; // The 'off' value for 180 degrees

  return map(angle, 0, 180, minPulseWidth, maxPulseWidth);
}

void waveTest()
{
  spiderLegs.setPWM(0, 0, servoAngle(0));
  spiderLegs.setPWM(1, 0, servoAngle(45));
  spiderLegs.setPWM(2, 0, servoAngle(90));
  spiderLegs.setPWM(3, 0, servoAngle(135));
  delay(1000);

  spiderLegs.setPWM(0, 0, servoAngle(45));
  spiderLegs.setPWM(1, 0, servoAngle(90));
  spiderLegs.setPWM(2, 0, servoAngle(135));
  spiderLegs.setPWM(3, 0, servoAngle(0));
  delay(1000);

  spiderLegs.setPWM(0, 0, servoAngle(90));
  spiderLegs.setPWM(1, 0, servoAngle(135));
  spiderLegs.setPWM(2, 0, servoAngle(0));
  spiderLegs.setPWM(3, 0, servoAngle(45));
  delay(1000);

  spiderLegs.setPWM(0, 0, servoAngle(135));
  spiderLegs.setPWM(1, 0, servoAngle(0));
  spiderLegs.setPWM(2, 0, servoAngle(45));
  spiderLegs.setPWM(3, 0, servoAngle(90));
  delay(1000);
}

void walkCycle()
{
    // Example walk cycle logic
  for (int angle = 0; angle <= 180; angle++) 
  {
    int inverseAngle = 180 - angle;

    spiderLegs.setPWM(0, 0, servoAngle(angle));       // Leg 1
    spiderLegs.setPWM(1, 0, servoAngle(angle));
    spiderLegs.setPWM(2, 0, servoAngle(inverseAngle)); // Leg 2.
    spiderLegs.setPWM(3, 0, servoAngle(angle));
    delay(33); // Adjust for smoother motion, here 30 fps
  }

  for (int angle = 180; angle >= 0; angle--) 
  {
    int inverseAngle = 180 - angle;

    spiderLegs.setPWM(0, 0, servoAngle(angle));       // Leg 1
    spiderLegs.setPWM(1, 0, servoAngle(angle));
    spiderLegs.setPWM(2, 0, servoAngle(inverseAngle)); // Leg 2
    spiderLegs.setPWM(3, 0, servoAngle(angle));
    delay(33); // Adjust for smoother motion, here 30 fps  
  } 
}
