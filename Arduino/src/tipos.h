#ifndef __TIPOS_H
#define __TIPOS_H

#include "helpers.h"
#include "sensors.h"
#include "Arduino.h"
#include <Arduino_FreeRTOS.h>
#include <semphr.h> 
#include "motors.h"
#include "Memo/Memo.h"
#include "actuators/beep.h"

/*--------------------------------------------------*/
/*----------- Defines de configuracion -------------*/
/*--------------------------------------------------*/


#define DEBUG          1//Control de todo el output por el puerto serial
#define DEBUG_ERRORS   2//Control de errores por el puerto serial

//Cponfiguracion de las prioridades de las tareas

#define ULTRASONIC_PRIORITY 3
#define CONFIG_PRIORITY     4
#define CONTROL_PRIORITY    3

/*--------------------------------------------------*/
/*------------- Estructuras de datos ---------------*/
/*--------------------------------------------------*/

//Estructuras para los sensores

/*SensorA_t
Estructura generica para sensores analogicos
*/
typedef struct SensorA_t{
    uint8_t  direccion;
    uint16_t cadencia = 100;
    uint32_t valor;

} SensorA_t;

/*SensorD_t
Estructura generica para sensores digitales
*/
typedef struct SensorD_t{
    uint8_t  direccion;
    uint16_t cadencia = 100;
    bool valor;
} SensorD_t;

/*SensorA_t
Estructura especifica para sensores de ultrasonidos
*/
typedef struct SensorU_t{
    uint8_t  direccionTrig;
    uint8_t  direccionEcho;
    uint16_t cadencia = 500;
    uint32_t distancia;

    uint32_t distancias[10] = {0};
} SensorU_t;


//Estructuras para la configuracion

/*Uint8_t_Type
Tipo de datos para el almacenado en la memoria
*/
typedef struct Uint8_t_Type{
    uint8_t Value = 0;
    uint8_t Direction = 255;
}Uint8_t_Type;

/*Uint8_t_Array_Type
Tipo de datos para el almacenado en la memoria
*/
typedef struct Uint8_t_Array_Type{
    uint8_t *Value = 0;
    uint8_t Direction = 255;
    uint8_t size = 0;
}Uint8_t_Array_Type;


/*ConfigData
Estructura para los valores de configuracion
*/
typedef struct ConfigData{
    Uint8_t_Type        fw_version;
}ConfigData;

#endif