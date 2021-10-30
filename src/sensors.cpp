#include "sensors.h"

/****************************************************************
 * Función TaskReadAnalog
 * Funcion penasda para ejecutarse como tarea.
 * Lee un sensor analogico y guarda su valor en la estructura
 * params: Sensor_t --> Estructura del sensor a leer
 ****************************************************************/
void TaskReadAnalog( void *pvParameters){
  Sensor_t * sensor = (Sensor_t *) pvParameters;

  for (;;){

    sensor->valor = analogRead(sensor->direccion);

    duerme(100);
  }
}
