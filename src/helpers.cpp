#include "helpers.h"


extern SemaphoreHandle_t xSerialSemaphore;

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
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE ){
      Serial.println(value);
      xSemaphoreGive( xSerialSemaphore );
    }
}
void escribe(uint8_t value){
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE ){
      Serial.println(value);
      xSemaphoreGive( xSerialSemaphore );
    }
}
void escribe(uint16_t value){
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE ){
      Serial.println(value);
      xSemaphoreGive( xSerialSemaphore );
    }
}
void escribe(uint32_t value){
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE ){
      Serial.println(value);
      xSemaphoreGive( xSerialSemaphore );
    }
}

/****************************************************************
 * Función escribe
 * Escribe por el puerto serial esperando que ninguna otra tarea
 * esté utilzando el puerto. Si tras 5 milisegundos el puerto no
 * queda libre, vuelve sin escribir. 
 * params: value(int) --> valor a printar
 ****************************************************************/
void escribe(String value){
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE ){
      Serial.println(value);
      xSemaphoreGive( xSerialSemaphore );
    }
}

/****************************************************************
 * Función escribe
 * Escribe por el puerto serial esperando que ninguna otra tarea
 * esté utilzando el puerto. Si tras 5 milisegundos el puerto no
 * queda libre, vuelve sin escribir. 
 * params: value(int) --> valor a printar
 ****************************************************************/
void escribe(float value){
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE ){
      Serial.println(value);
      xSemaphoreGive( xSerialSemaphore );
    }
}