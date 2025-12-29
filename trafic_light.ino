//definējam mainīgos
const int redLed = 13;
const int yellowLed = 12;
const int greenLed = 14;

void setup() {
  //iedodam piniem statusu, ka tie saņems strāvu
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  //palaižam seriālo komunikāciju (biti sekundē)
  Serial.begin(115200);

  //ko izvadam konsolē/terminālī
  Serial.println("*** luksafors darbojas ***");
  Serial.println("Sākam darbu ... \n OK");


}

void loop() {
  // lai minimizētu koda garumu, statusu maina tikai tām gaismām, kas mainās,
  // bet uzskatāmības labad definējam visu gaismu statusu
  // sākam ar zaļo gaismu 
  digitalWrite(greenLed, HIGH);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, LOW);
  Serial.println("Ieslēgta zaļā gaisma, drīkst braukt");
  delay(5000); //dealy nav labākais visos gadījumos, jo aizkavē visas programmas izpildi

  // dzeltenā gaisma 
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(redLed, LOW);
  Serial.println("Ieslēgta dzeltenā gaisma, tikai pabeigt kustību");
  delay(2000);

  // sarkanā gaisma 
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, HIGH);
  Serial.println("Ieslēgta sarkanā gaisma, STOP");
  delay(5000);

  // dzeltenā pirms zaļās gaismas
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(redLed, HIGH);
  Serial.println("Gatavojies braukt");
  delay(2000);

}
