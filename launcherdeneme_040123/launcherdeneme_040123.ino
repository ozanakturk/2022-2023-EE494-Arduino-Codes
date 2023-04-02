int mot1 = 10;
int mot2 = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(mot1, OUTPUT);
  pinMode(mot2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // 5V
  digitalWrite(mot1, 25);
  digitalWrite(mot2, 10);
  delay(100);
}
