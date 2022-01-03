#include "helpers.h"

#ifdef DEBUG
// Semaforo para que dos tareas no accedan al serial a la vez
SemaphoreHandle_t xSerialSemaphore;
#endif

/*--------------------------------------------------*/
/*-------------- Funciones privadas ----------------*/
/*--------------------------------------------------*/

void start_semaphore(){
  #ifdef DEBUG
  //Arrancar el semaforo
  if ( xSerialSemaphore == NULL ){
    xSerialSemaphore = xSemaphoreCreateMutex();
    if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );  
  }
  #endif
}

/*--------------------------------------------------*/
/*-------------- Funciones publicas ----------------*/
/*--------------------------------------------------*/

/****************************************************************
 * Función duerme
 * Esta funcion detiene la ejecucion de la tarea
 * durante un tiempo determinado.
 * params: ms(int) --> Milisegundos que se detiene la ejecucion
 ****************************************************************/
void duerme (int ms){
    vTaskDelay(pdMS_TO_TICKS(ms));
}

/****************************************************************
 * Función escribe
 * Escribe por el puerto serial esperando que ninguna otra tarea
 * esté utilzando el puerto. Si tras 5 milisegundos el puerto no
 * queda libre, vuelve sin escribir. 
 * params: value(int) --> valor a printar
 ****************************************************************/
void escribe(int value){
  #ifdef DEBUG
    if ( xSerialSemaphore == NULL )start_semaphore();
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE ){
      Serial.println(value);
      xSemaphoreGive( xSerialSemaphore );
    }
  #endif
}
void escribe(uint8_t value){
  #ifdef DEBUG
    if ( xSerialSemaphore == NULL )start_semaphore();
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE ){
      Serial.println(value);
      xSemaphoreGive( xSerialSemaphore );
    }
  #endif
}
void escribe(uint16_t value){
  #ifdef DEBUG
    if ( xSerialSemaphore == NULL )start_semaphore();
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE ){
      Serial.println(value);
      xSemaphoreGive( xSerialSemaphore );
    }
  #endif
}
void escribe(uint32_t value){
  #ifdef DEBUG
    if ( xSerialSemaphore == NULL )start_semaphore();
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE ){
      Serial.println(value);
      xSemaphoreGive( xSerialSemaphore );
    }
  #endif
}

/****************************************************************
 * Función escribe
 * Escribe por el puerto serial esperando que ninguna otra tarea
 * esté utilzando el puerto. Si tras 5 milisegundos el puerto no
 * queda libre, vuelve sin escribir. 
 * params: value(String) --> Cadena de texto a printar
 ****************************************************************/
void escribe(String value){
  #ifdef DEBUG
    if ( xSerialSemaphore == NULL )start_semaphore();
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 20 ) == pdTRUE ){
      Serial.println(value);
      xSemaphoreGive( xSerialSemaphore );
    }
  #endif
}

/****************************************************************
 * Función escribe
 * Escribe por el puerto serial esperando que ninguna otra tarea
 * esté utilzando el puerto. Si tras 5 milisegundos el puerto no
 * queda libre, vuelve sin escribir. 
 * params: value(float) --> Numero de coma flotante a printar
 ****************************************************************/
void escribe(float value){
  #ifdef DEBUG
    if ( xSerialSemaphore == NULL )start_semaphore();
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 20 ) == pdTRUE ){
      Serial.println(value);
      xSemaphoreGive( xSerialSemaphore );
    }
  #endif
}

/****************************************************************
 * Función FIFO
 * coje un array de valores y lo trata como un FIFO, es decir, 
 * el valor que le pasamos lo añade al principio y borra el ultimo
 * params: values(uint32_t*) --> Cola FIFO
 *         new_value(uint32_t) --> numero a añadir al fifo
 ****************************************************************/
void FIFO(uint32_t * values, uint32_t new_value){
    size_t tamaino = sizeof(values);

    for(uint8_t index = tamaino-1;index > 0;index--){
      values[index] = values[index-1];
    }

    values[0]= new_value;

}