#include <AFMotor.h>

// Number of steps per output rotation
// Change this as per your motor's specification
const int stepsPerRevolution = 200;
//number of pulses received by the stepper 
volatile unsigned int pulseCount = 0;
// connect motor to port #2 (M3 and M4)
AF_Stepper motor(stepsPerRevolution, 1);
int stepper_rpm = 22;
int step_threshold = stepper_rpm-3
void countPulses() {
  pulseCount++;
}

void setup() {
  
  Serial.begin(9600);
  Serial.println("Coconut Oil Expeller Feeder");

  motor.setSpeed(stepper_rpm);  // 10 rpm   
  attachInterrupt(digitalPinToInterrupt(2), countPulses, RISING);

}

void loop() {
  pulseCount = 0; // reset pulse count
  delay(1000); // wait one second
  float rpm = (float)pulseCount / 200.0 * 60.0; // calculate RPM
  Serial.print("RPM: ");
  Serial.println(rpm);
 // Serial.println("Single coil steps");
 if(rpm > step_threshold){
  motor.step(100, FORWARD, DOUBLE); 
  }else{
    motor.step(25, FORWARD, SINGLE);
  }
 // motor.step(100, BACKWARD, SINGLE); 
}
