#include <Joystick.h>

/* ID, type, buttons, hats
X, Y, Z
XR, YR, ZR,
rudder, throttle, accel, brake, steering
*/
Joystick_ Joystick(0x03, JOYSTICK_TYPE_JOYSTICK, 0, 0, \
  true, true, true, \
  false, false, false, \
  false, true, false, false, false);

// Define axis pins
const int carbPin = A0;
const int thrtPin = A1;
const int propPin = A2;
const int mixtPin = A3;

// Define axis position variables
int carbPos;
int thrtPos;
int propPos;
int mixtPos;

void setup() {
  // Sends a clean report to the host. This is important on any Arduino type.
  Joystick.begin(true);
}

void loop() {

  // Get axis positions
  carbPos = analogRead(carbPin);
  thrtPos = analogRead(thrtPin);
  propPos = analogRead(propPin);
  mixtPos = analogRead(mixtPin);
    
  // Move axes to a new position (16bit)
  Joystick.setXAxis(carbPos);
  Joystick.setThrottle(thrtPos);
  Joystick.setYAxis(propPos);
  Joystick.setZAxis(mixtPos);
  
}
