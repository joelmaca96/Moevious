#ifndef __SENSORS_H
#define __SENSORS_H

#include "tipos.h"
#include "Arduino.h"

//Generic sensors
void TaskReadAnalog( void *pvParameters);
void TaskReadDigital( void *pvParameters);

//Especial sensors
void TaskUltrasonicRead (void *pvParameters);


#endif