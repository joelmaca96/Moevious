#include "tipos.h"

//Declarar los objetos de los sensores
SensorU_t OjosDelante, OjosDetras;

//Declarar la clase de los motores
Motores motors;

//Declarar el objeto para la configuracion
ConfigData Configuracion;

//Objeto para el zumbador
beep pitido;

// Prototipos de funciones
void ControlTask (void *pvParameters);

void setup() {

  Serial.begin(9600);
  
  OjosDelante.direccionEcho = 6;
  OjosDelante.direccionTrig = 7;
  OjosDetras.direccionEcho  = 5;
  OjosDetras.direccionTrig  = 4;

  OjosDetras.cadencia = 100;
  //Arrancar el sistema de configuracion y leer la configuracion inicial
  InitConfiguration();

  // Crear las tareas de lectura de sensores
  //xTaskCreate(TaskUltrasonicRead,"OjosDelante",128,(void*)&OjosDelante,ULTRASONIC_PRIORITY,NULL); 
  //xTaskCreate(TaskUltrasonicRead,"OjosDetras",128,(void*)&OjosDetras,ULTRASONIC_PRIORITY,NULL); 

  //Crear la tarea de control principal
  xTaskCreate(ControlTask,"Control",256,NULL,CONTROL_PRIORITY,NULL); 

  pitido.init();
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
  motors.VelocidadMotor(DERECHA, 255, ATRAS);
  for(;;){
        //Serial.println(OjosDetras.distancia);
    
    duerme(500);
  }
}


