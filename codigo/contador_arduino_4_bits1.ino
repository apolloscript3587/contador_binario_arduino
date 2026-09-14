const int leds[] = {9, 10, 11, 12};

int contador = 0;

int tiempo_espera = 1000;

void setup() {
  for (int i = 0; i < 4; i += 1) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; i += 1) {
    int bit = (contador >> i) & 1;
    digitalWrite(leds[i], bit);
  }
  
  contador += 1;
  
  delay(tiempo_espera);
}