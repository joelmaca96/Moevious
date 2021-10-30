#include "sensors.h"

/****************************************************************
 * Función TaskReadAnalog
 * Funcion pensada para ejecutarse como tarea.
 * Lee un sensor analogico y guarda su valor en la estructura.
 * params: Sensor_t --> Estructura del sensor a leer
 ****************************************************************/
void TaskReadAnalog( void *pvParameters){
  SensorA_t * sensor = (SensorA_t *) pvParameters;

  for (;;){

    sensor->valor = analogRead(sensor->direccion);

    duerme(sensor->cadencia);
  }
}


/****************************************************************
 * Función TaskReadDigital
 * Funcion pensada para ejecutarse como tarea.
 * Lee un sensor digital y guarda su valor en la estructura.
 * params: SensorD_t --> Estructura del sensor a leer
 ****************************************************************/
void TaskReadDigital( void *pvParameters){
  SensorD_t * sensor = (SensorD_t *) pvParameters;

  for (;;){

    sensor->valor = digitalRead(sensor->direccion);

    duerme(sensor->cadencia);
  }
}
