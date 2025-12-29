// LED pini
const int redLed = 13;
const int yellowLed = 12;
const int greenLed = 14;

const int go = 5000;
const int wait = 2000;

// stāvokļi
enum TrafficState {
  OFF,
  RED,
  YELLOW1,
  YELLOW2,
  GREEN
};

TrafficState state = OFF;

// gaismu funkcija
void gaismas(int g, int y, int r) {
  digitalWrite(greenLed,  g ? HIGH : LOW);
  digitalWrite(yellowLed, y ? HIGH : LOW);
  digitalWrite(redLed,    r ? HIGH : LOW);
}

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  Serial.begin(115200);

  gaismas(0, 0, 0);
  Serial.println("Sākums: viss izslēgts");
}

void loop() {
  switch (state) {

    case OFF: 
      gaismas(0, 0, 1);
      Serial.println("Sarkanā");
      state = RED;
      delay(go);
      break;

    case RED:
      gaismas(0, 1, 1);
      Serial.println("Sarkanā + Dzeltenā");
      state = YELLOW1;
      delay(wait);
      break;

    case YELLOW1:
      gaismas(1, 0, 0);
      Serial.println("Zaļā");
      state = GREEN;
      delay(go);
      break;

    case GREEN:
      gaismas(0, 1, 0);
      Serial.println("Dzeltenā);
      state = YELLOW2;
      delay(wait);
      break;

    case YELLOW2:
      gaismas(0, 0, 1);
      Serial.println("Sarkanā");
      state = RED;
      delay(go);
      break;
  }
}
