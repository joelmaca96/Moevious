#include "helpers.h"

/*--------------------------------------------------*/
/*-------------- Funciones publicas ----------------*/
/*--------------------------------------------------*/

/****************************************************************
 * Función duerme
 * \brief Esta funcion detiene la ejecucion de la tarea
 * durante un tiempo determinado.
 * \param ms(int) --> Milisegundos que se detiene la ejecucion
 ****************************************************************/
void duerme (int ms){
    vTaskDelay(pdMS_TO_TICKS(ms));
}

/****************************************************************
 * Función FIFO
 * \brief coje un array de valores y lo trata como un FIFO, es decir, 
 * el valor que le pasamos lo añade al principio y borra el ultimo
 * \param values(uint32_t*) --> Cola FIFO
 *         new_value(uint32_t) --> numero a añadir al fifo
 ****************************************************************/
void FIFO(uint32_t * values, uint32_t new_value){
    size_t tamaino = sizeof(values);

    for(uint8_t index = tamaino-1;index > 0;index--){
      values[index] = values[index-1];
    }

    values[0]= new_value;

}