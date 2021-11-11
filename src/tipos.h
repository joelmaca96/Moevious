#ifndef __TIPOS_H
#define __TIPOS_H

#include "helpers.h"
#include "sensors.h"
#include "Arduino.h"
#include <Arduino_FreeRTOS.h>
#include <semphr.h> 
#include "motors.h"

typedef struct SensorA_t{
    uint8_t  direccion;
    uint16_t cadencia = 100;
    uint32_t valor;

} SensorA_t;

typedef struct SensorD_t{
    uint8_t  direccion;
    uint16_t cadencia = 100;
    bool valor;
} SensorD_t;

typedef struct SensorU_t{
    uint8_t  direccionTrig;
    uint8_t  direccionEcho;
    uint16_t cadencia = 500;
    uint32_t distancia;
} SensorU_t;

#endif