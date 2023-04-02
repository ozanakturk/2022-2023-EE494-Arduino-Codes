#include <X113647Stepper.h>

int adim = 32*64;
X113647Stepper stepmotor(adim,4,5,6,7);
void setup() {
  // put your setup code here, to run once:
  stepmotor.setSpeed(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  stepmotor.step(adim);
  delay(1000);
  stepmotor.step(-adim);
  delay(1000);
}
