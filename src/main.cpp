#include "tipos.h"

// Semaforo para que dos tareas no accedan al serial a la vez
SemaphoreHandle_t xSerialSemaphore;

//Declarar los objetos de los sensores
SensorU_t OjosDelante, OjosDetras;

// Tareas
void TaskOjosDelante( void *pvParameters );
void TaskOjosDetras( void *pvParameters );

void setup() {

  Serial.begin(9600);
  
  OjosDelante.direccionEcho = 1;
  OjosDelante.direccionTrig = 2;
  OjosDetras.direccionEcho = 3;
  OjosDetras.direccionTrig = 4;

  //Arrancar el semaforo
  if ( xSerialSemaphore == NULL ){
    xSerialSemaphore = xSemaphoreCreateMutex();
    if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );  
  }

  // Crear las tareas de lectura de sensores
  xTaskCreate(TaskUltrasonicRead,"OjosDelante",128,(void*)&OjosDelante,2,NULL); 
  xTaskCreate(TaskUltrasonicRead,"OjosDetras",128,(void*)&OjosDetras,3,NULL); 
}

void loop(){
  Serial.println("Ojos Delante");
  Serial.println(OjosDelante.distancia);
  Serial.println("Ojos Detras");
  Serial.println(OjosDetras.distancia);
  delay(1000);
}

/*--------------------------------------------------*/
/*--------------------- Tareas ---------------------*/
/*--------------------------------------------------*/


