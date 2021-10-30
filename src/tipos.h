#ifndef __TIPOS_H
#define __TIPOS_H

#include "helpers.h"
#include "sensors.h"
#include "Arduino.h"
#include <Arduino_FreeRTOS.h>
#include <semphr.h> 

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

#endif