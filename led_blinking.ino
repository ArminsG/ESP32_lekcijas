
#define LED_PIN 2 //definējam mainīgo

//deklarējam funkciju kas nostrādā vienu reizi pie startēšanas

void setup() {
  pinMode(LED_PIN, OUTPUT); //pasakām kur būs pieslēgts LED un to ka šī ir izeja
}

// cikliskā funkcija, kas nodrošina nepārtraukto darbību
void loop() {
  digitalWrite(LED_PIN, HIGH); //pasakām, ka jāpadod strāva
  delay(5000); //ieturam apuzi, lai redzam, ka led iedegas
  digitalWrite(LED_PIN, LOW); //izslēdzam led
  delay(5000);
}
