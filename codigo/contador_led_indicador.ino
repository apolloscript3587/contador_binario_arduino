const int leds[] = {9, 10, 11, 12};
const int led_indicador = 13;

int contador = 0;

int tiempo_espera = 1000;

void setup() {
  for (int i = 0; i < 4; i += 1) {
    pinMode(leds[i], OUTPUT);
  }
  
  pinMode(led_indicador, OUTPUT);
}

void loop() {
  for (int i = 0; i < 4; i += 1) {
    int bit = (contador >> i) & 1;
    digitalWrite(leds[i], bit);
  }
  
  contador += 1;
  
  if (contador == 16) {
    digitalWrite(led_indicador, HIGH);
  } else {
    digitalWrite(led_indicador, LOW);
  }
  
  delay(tiempo_espera);
}
