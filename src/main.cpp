#include "tipos.h"

// Semaforo para que dos tareas no accedan al serial a la vez
SemaphoreHandle_t xSerialSemaphore;

//Declarar los objetos de los sensores
Sensor_t OjosDelante, OjosDetras;

// Tareas
void TaskOjosDelante( void *pvParameters );
void TaskOjosDetras( void *pvParameters );

void setup() {

  Serial.begin(9600);
  
  OjosDelante.direccion = A0;
  OjosDetras.direccion = A1;

  //Arrancar el semaforo
  if ( xSerialSemaphore == NULL ){
    xSerialSemaphore = xSemaphoreCreateMutex();
    if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );  
  }

  // Now set up two Tasks to run independently.
  xTaskCreate(TaskReadAnalog,"OjosDelante",128,(void*)&OjosDelante,2,NULL); 
  xTaskCreate(TaskReadAnalog,"OjosDetras",128,(void*)&OjosDetras,3,NULL); 
}

void loop(){
  Serial.println("Ojos Delante");
  Serial.println(OjosDelante.valor);
  Serial.println("Ojos Detras");
  Serial.println(OjosDetras.valor);
  delay(1000);
}

/*--------------------------------------------------*/
/*--------------------- Tareas ---------------------*/
/*--------------------------------------------------*/


