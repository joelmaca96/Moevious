#ifndef __HELPERS_H
#define __HELPERS_H

#include "tipos.h"
#include "Arduino.h"

void duerme(int ms);

void FIFO(uint32_t * values, uint32_t new_value);

#endif