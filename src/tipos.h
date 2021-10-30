#ifndef __TIPOS_H
#define __TIPOS_H

#include "helpers.h"
#include "sensors.h"
#include "Arduino.h"
#include <Arduino_FreeRTOS.h>
#include <semphr.h> 

typedef struct Sensor_t{
    uint8_t direccion;
    uint32_t valor;
} Sensor_t;

#endif