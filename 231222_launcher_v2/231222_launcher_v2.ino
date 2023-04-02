/* Reloader frequency adjuster v2 */
#define PERIOD 10
int pwm_pin = 5;
int pwm_pin2 = 11;
String op;

void pwm(float D){
  while(true){
    Serial.println(D);
    digitalWrite(pwm_pin, HIGH);
    digitalWrite(pwm_pin2, HIGH);
    delay(D * PERIOD);
    digitalWrite(pwm_pin, LOW);
    digitalWrite(pwm_pin2, LOW);
    delay((1 - D) * PERIOD);
    if (Serial.available() > 0) {
      return;
   }
  }
}

void setup() {
  pinMode(pwm_pin, OUTPUT);
  pinMode(pwm_pin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // okuma
   if (Serial.available() > 0) {
    op = Serial.readString();
    
    // 10V için yorum satırları
    pwm(op.toInt()/1000.0);
   }
}
