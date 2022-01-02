#ifndef __BEEP_H
#define __BEEP_H

#include "../tipos.h"
#include "Arduino.h"

/****************************************************************
 * Clase beep
 * Clase para controlar un zumbador.
 ****************************************************************/
class beep {
    private:
        uint8_t _pin = 3;
        
    public:
        //constructores
        beep(){pinMode(
            _pin,OUTPUT);
            analogWrite(_pin, 0);
            };

        beep(uint8_t pin){
            _pin = pin;
            pinMode(_pin,OUTPUT);
            analogWrite(_pin, 0);
        };

        void init();
        void wave();
};

#endif