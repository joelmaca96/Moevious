#ifndef __HELPERS_H
#define __HELPERS_H

#include "tipos.h"
#include "Arduino.h"

void duerme(int ms);

void escribe(int value);
void escribe(uint8_t value);
void escribe(uint16_t value);
void escribe(uint32_t value);
void escribe(float value);
void escribe(String value);


void FIFO(uint32_t * values, uint32_t new_value);

#endif