#include "tipos.h"
#include "config/config.h"

void setup() {
  Serial.begin(9600);
  Serial.println("Estoy vivo!!!!\n");
  printf("Y puedo usar printf!!\n");

  Configuracion.init();
}

void loop() {
  // put your main code here, to run repeatedly:
}