#include "sensors.h"

/****************************************************************
 * Función TaskReadAnalog
 * Funcion pensada para ejecutarse como tarea.
 * Lee un sensor analogico y guarda su valor en la estructura.
 * \param Sensor_t --> Estructura del sensor a leer
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
 * \param SensorD_t --> Estructura del sensor a leer
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
 * \param SensorU_t --> Estructura del sensor a leer
 ****************************************************************/
void TaskUltrasonicRead (void *pvParameters){
    SensorU_t * sensor = (SensorU_t *) pvParameters;

    pinMode(sensor->direccionTrig, OUTPUT);
    pinMode(sensor->direccionEcho, INPUT);
    
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
        uint32_t distancia_temp = tiempo * 0.034 / 2; 

        //Almacenar el ultimo valor en el fifo de distancias
        FIFO(sensor->distancias, distancia_temp);

        //Para obtener la media de las ultimas 10 mediciones, se realiza una media ponderada, dando más
        //importancia a las mediciones mas nuevas.
        float pesos[10] = {1, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1};

        //filtrar distancias incongruentes buscando diferencias demasiado grandes (mediciones incorrectas)
        //y asignandoles un peso 0 para conservar sus valores.

        for(uint8_t index = 0;index < 10;index++){
          uint8_t limit_sup =  index != 9; 
          uint8_t limit_inf =  index != 0;

          float diferencia_sup = 0, diferencia_inf = 0;
          diferencia_sup = abs(sensor->distancias[index]-sensor->distancias[index+limit_sup]);
          diferencia_inf = abs(sensor->distancias[index]-sensor->distancias[index-limit_inf]);

          if(diferencia_inf > 400 && diferencia_sup > 400){
            pesos[index] = 0;
          }
        }


        //Calcular la media ponderada
        float suma_pesos= 0;
        float suma_distancias = 0;
        for(uint8_t index = 0;index < 10;index++){
          suma_pesos += pesos[index];
          suma_distancias += sensor->distancias[index]*pesos[index];

        }

        sensor->distancia = suma_distancias/suma_pesos;

        duerme(sensor->cadencia);
    }  
}
