#include "beep.h"

void beep::init(){
    
    //sonidito de arranque
    analogWrite(_pin, 150);
    delay(200);
    analogWrite(_pin, 50);
    delay(200);
    analogWrite(_pin, 200);
    delay(300);
    analogWrite(_pin, 0);
}

void beep::wave(){
    for(uint8_t i = 0 ;i< 254;i+=2){
        analogWrite(_pin, i);
        delay(3);
    }

    for(uint8_t i = 254;i> 0;i-=2){
        analogWrite(_pin, i);
        delay(3);
    }
    analogWrite(_pin, 0);
}