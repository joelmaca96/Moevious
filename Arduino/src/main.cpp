#include "tipos.h"

//Declarar los objetos de los sensores
SensorU_t OjosDetras;

//Declarar la clase de los motores
Motores motors;

//Declarar el objeto para la configuracion
ConfigData Configuracion;

// Estructura para almacenar el estado del robot
Status_t Status;

// Prototipos de funciones
void ControlTask (void *pvParameters);

void setup() {

  Serial.begin(9600);
  
  OjosDetras.direccionEcho  = echo_rear;
  OjosDetras.direccionTrig  = trig_rear;

  OjosDetras.cadencia = 100;
  //Arrancar el sistema de configuracion y leer la configuracion inicial
  InitConfiguration();

  // Crear las tareas de lectura de sensores
  //xTaskCreate(TaskUltrasonicRead,"OjosDelante",128,(void*)&OjosDelante,ULTRASONIC_PRIORITY,NULL); 

  //Crear la tarea de control principal
  xTaskCreate(ControlTask,"Control",256,NULL,CONTROL_PRIORITY,NULL); 

}

void loop(){

  //En este proyecto el bucle loop no se utiliza
  //Es sustituido por la tarea del RTOS "ControlTask"
}

/*--------------------------------------------------*/
/*--------------------- Tareas ---------------------*/
/*--------------------------------------------------*/

/****************************************************************
 * Función ControlTask
 * Funcion pensada para ejecutarse como tarea.
 * Tarea de control principal de Moevious 
 * \param Ninguno
 ****************************************************************/
void ControlTask (void *pvParameters){

  TaskHandle_t OjosDetras_h = NULL;
  motors.MoverRecto(255, ALANTE);
  uint8_t count = 0;
  for(;;){
    
    if(++count > 10 && count < 40){
      motors.MoverRecto(255, ATRAS);
    }
    else if (count == 41){
      motors.MoverRecto(255, ALANTE);
    }

    if(Status.direccion == ATRAS){

      //Si vamos hacia atrás, hacer caso del sensor trasero
      if(OjosDetras_h == NULL){
          xTaskCreate(TaskUltrasonicRead,"OjosDetras",128,(void*)&OjosDetras,ULTRASONIC_PRIORITY,&OjosDetras_h); 
      }
      if(OjosDetras.distancia < 4){
        count = 40;
      }
    }
    else{ //Cuando dejemos de ir hacia atrás eliminamos el sensor trasero
      if(OjosDetras_h != NULL){
        vTaskDelete(OjosDetras_h);
        OjosDetras_h = NULL;
      }
    }
    
    
    duerme(500);
  }
}


