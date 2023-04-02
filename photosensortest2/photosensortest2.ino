/*
  Read digital pulse form photoelectric sensor/Infrared
  by miliohm.com
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
int photoElectric = 2;
int prev_state = 0;
int curr_state = 0;
unsigned long first_time = 0;
unsigned long second_time = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(photoElectric, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int curr_state = digitalRead(photoElectric);

  if(prev_state == 1 && curr_state == 0){
    first_time = millis();
  }

  if(prev_state == 0 && curr_state == 1){
    second_time = millis();
    Serial.print("Gecen zaman: ");
    Serial.println(second_time - first_time);
    Serial.print("Hesaplanan Hız: ");
    Serial.println(42.0/(second_time - first_time));
    delay(5000);
  }
  
  // print out the state of the button:
  Serial.println(curr_state);
  prev_state = curr_state;
  delay(1);        // delay in between reads for stability
}
