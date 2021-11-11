#ifndef __SENSORS_H
#define __SENSORS_H

#include "tipos.h"
#include "Arduino.h"


void TaskReadAnalog( void *pvParameters);
void TaskReadDigital( void *pvParameters);

void TaskUltrasonicRead (void *pvParameters);


#endif