const int leds[] = {9, 10, 11, 12};
const int boton = 8;

int contador = 0;

int tiempo_espera = 200;

void setup() {
  for (int i = 0; i < 4; i += 1) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(boton, INPUT_PULLUP);
}

void loop() {
  for (int i = 0; i < 4; i += 1) {
    int bit = (contador >> i) & 1;
    digitalWrite(leds[i], bit);
  }

  if (digitalRead(boton) == LOW) {
    contador += 1;

    delay(tiempo_espera);
  }
}
