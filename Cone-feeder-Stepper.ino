#include <AFMotor.h>
const int stepsPerRevolution = 200;
AF_Stepper motor(stepsPerRevolution, 1);
void setup() {
  motor.setSpeed(22);
}
void loop() {
  static const uint8_t STEPS_PER_CYCLE = 4; // Use a multiple of 4 for smoother motion
  static const uint16_t STEPS_PER_SEC = 440; // 22 RPM * 200 steps / 60 seconds
  static const uint16_t STEPS_PER_LOOP = STEPS_PER_SEC / 60; // 1/60th of a second per loop
  static uint8_t stepCount = 0;
  static uint32_t lastStepTime = 0;
  uint32_t currentTime = millis();
  
  if ((currentTime - lastStepTime) >= (1000 / STEPS_PER_SEC)) {
    if (stepCount < STEPS_PER_CYCLE) {
      motor.onestep(FORWARD, SINGLE);
      stepCount++;
    }
    lastStepTime = currentTime;
  }
  
  if (stepCount >= STEPS_PER_CYCLE) {
    stepCount = 0;
  }
}
