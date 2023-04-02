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
// high 45 mid 41
void loop() {
  // okuma
   if (Serial.available() > 0) {
    op = Serial.readString();
    
    // 10V için yorum satırları
    if(op == "STOP"){
      pwm(0.0);
    }
    if(op == "1"){
      pwm(0.41);
    }
    else if(op == "2"){
      pwm(0.45);
    }
    else if(op == "3"){
      pwm(0.405);
    }
    else if(op == "4"){
      pwm(0.4);
    }
    else if(op == "5"){
      pwm(0.42);
    }
    else if(op == "6"){ //0.45 4. ve 5. arasına attı
      pwm(0.45);
    }
    else if(op == "7"){
      pwm(0.46);
    }
    else if(op == "8"){
      pwm(0.48);
    }
    else if(op == "9"){
      pwm(0.50);
    }
    else if(op == "10"){
      pwm(1.0);
    }
    else{
      pwm(0.0);
    }
       
    //pwm((op.toInt())/10.0);
   }
}
