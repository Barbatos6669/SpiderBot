#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver spiderLegs = Adafruit_PWMServoDriver();

int mapServo(int angle);


void setup() 
{
  spiderLegs.begin();
  spiderLegs.setPWMFreq(50);
  
}

void loop() 
{
  spiderLegs.setPWM(0, 0, 150);
  delay(1000);

  spiderLegs.setPWM(0,0, 300);
  delay(1000);

}

// Map function
int mapServo(int angle) 
{
  // Assuming a standard servo with 180-degree rotation
  // Modify minPulseWidth and maxPulseWidth based on your servo specifications
  int minPulseWidth = 150; // The 'off' value for 0 degrees
  int maxPulseWidth = 600; // The 'off' value for 180 degrees

  return map(angle, 0, 180, minPulseWidth, maxPulseWidth);
}
