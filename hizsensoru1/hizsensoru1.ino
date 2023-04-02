int encoder_pin = 2; // modülden sinyal çıkış pini
unsigned int rpm; // rpm tutan veri
long long pulses; // sinyal sayısı
unsigned long timeold;
// devir başına sinyal sayısı
// kodlayıcı diskinize göre
unsigned int pulsesperturn = 20;

int range = 1000;

void counter()
{
   //sayımı arttır
   pulses++;
}
void setup()
{
   Serial.begin(9600);
   pinMode(encoder_pin, INPUT);
   //Interrupt 0 is digital pin 2
   //boşlukta tetikleme olur (YÜKSEK'ten DÜŞÜK'e değiştirin)
   attachInterrupt(0, counter, RISING);
   // başlat
   pulses = 0;
   rpm = 0;
   timeold = 0;
}
void loop()
{
   if (millis() - timeold >= range) {
      //Hesaplamalar sırasında kesintileri işlemeyin
      detachInterrupt(0);
      rpm = (60 * 1000 / pulsesperturn )/ (millis() - timeold)* pulses;
      timeold = millis();
      pulses = 0;
      Serial.print("RPM = ");
      Serial.println(rpm,DEC);
      //Kesinti işlemeyi yeniden başlatın
      attachInterrupt(0, counter, FALLING);
   }
}
