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

/*--------------------------------------------------*/
/*-----  Funciones para sensores especificos -------*/
/*--------------------------------------------------*/

/****************************************************************
 * Función TaskUltrasonicRead
 * Funcion pensada para ejecutarse como tarea.
 * Lee un sensor de ultrasonidos HC-SR04 y almacena la distancia en 
 * la estructura que se le pasa como parametro
 * params: SensorU_t --> Estructura del sensor a leer
 ****************************************************************/
void TaskUltrasonicRead (void *pvParameters){
    SensorU_t * sensor = (SensorU_t *) pvParameters;

    for (;;){
        //Limpiar el estado del sensor
        digitalWrite(sensor->direccionTrig, LOW);
        delayMicroseconds(2);

        //Activar el trigger
        digitalWrite(sensor->direccionTrig, HIGH);
        delayMicroseconds(10);
        digitalWrite(sensor->direccionTrig, LOW);


        long tiempo = pulseIn(sensor->direccionEcho, HIGH);
        //Distancia = tiempo *velocidad del sonido al propagarse por el aires /2 (Ida y vuelta))
        sensor->distancia = tiempo * 0.034 / 2; 

        duerme(sensor->cadencia);
    }  
}
