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
 * Escribe por el puerto seriañ esperando que ninguna otra tarea
 * esté utilzando el puerto
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
 * Escribe por el puerto seriañ esperando que ninguna otra tarea
 * esté utilzando el puerto
 * params: value(String) --> cadena de texto a printar
 ****************************************************************/
void escribe(String value){
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE ){
      Serial.println(value);
      xSemaphoreGive( xSerialSemaphore );
    }
}

/****************************************************************
 * Función escribe
 * Escribe por el puerto seriañ esperando que ninguna otra tarea
 * esté utilzando el puerto
 * params: value(float) --> Valor com coma a printar
 ****************************************************************/
void escribe(float value){
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE ){
      Serial.println(value);
      xSemaphoreGive( xSerialSemaphore );
    }
}