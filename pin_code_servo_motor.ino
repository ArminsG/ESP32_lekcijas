#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// LED pini
int greenLED = 4;
int redLED = 16;

//buzzer pins
int buzzerPin = 27;

// servo pins
// servo PWM datu pins
int servoPin = 14;

// LCD pini
// LCD ekrāna VCC ir strāvas pins
//            SDA datu pins
//            SCl takts - sinhronizētājs
// priekš LCD jāpadod adrese, cik kolonnas un cik rindas
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Keypad
// izveido masīvu, lai varētu ērti piekļūt vērtībām
char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// katrai keypad rindai definējam pinus
byte rowPins[4] = {19,18,5,17};
byte colPins[4] = {13,12,15,2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);


String correctPIN = "1234";
String enteredPIN = "";

// funkcija servo motora darbināšanai
void moveServo(int angle) {
  int pulse = map(angle, 0, 180, 1000, 2000);
  for(int i = 0; i < 50; i++) {
    digitalWrite(servoPin, HIGH); // ieslēdzam motoru
    delayMicroseconds(pulse); //gaidām kamēr motors veiks nepieciešamo pagriešanos
    digitalWrite(servoPin, LOW); // izsledzam motoru
    delayMicroseconds(20000 - pulse);
  }
}

// funkcija kas kaut ko parādīs uz ekrāna
void showPinScreen() {
  lcd.clear();
  lcd.print("Enter PIN:");
  lcd.setCursor(0, 1);
  lcd.print("PIN:");
  enteredPIN = "";
}

void setup() {
  pinMode(servoPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  moveServo(0);
  lcd.init();
  lcd.backlight();
  showPinScreen();
}

void loop() {
  char key = keypad.getKey();
  if (!key) return; //ja nekas nav nospiests, tad iziet no cikla

  tone(buzzerPin, 1200, 50); // pīkstinām buzzer 1200Hz 50ms

  if (key == '#') {
    if (enteredPIN == correctPIN) {
      lcd.clear();
      lcd.print("Access granted");
      digitalWrite(greenLED, HIGH);
      moveServo(90);
      delay(2000);
      moveServo(0);
      digitalWrite(greenLED, LOW);
    } else {
      lcd.clear();
      lcd.print("Access denied");
      digitalWrite(redLED, HIGH);
      tone(buzzerPin, 400, 500);
      delay(1500);
      digitalWrite(redLED, LOW);
    }

  showPinScreen();

  } 
  else if (key == '*') {
    showPinScreen();
  }
  else if (key >= '0' && key <= '9' && enteredPIN.length() < 6 ) {
    enteredPIN += key;
    lcd.setCursor(5,1);
    for (int i = 0; i<enteredPIN.length(); i++) {
      lcd.print('*');
    }
  } 

}
