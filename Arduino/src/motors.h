#ifndef __MOTORS_H
#define __MOTORS_H

#include "tipos.h"
#include "Arduino.h"

class Motores {       
  public:             
    void MoverRecto(uint8_t Speed, bool Direccion); 
    void Frenar();
    void FrenarIzda();
    void FrenarDcha();
    void QuitarFreno();
    void QuitarFrenoIzda();
    void QuitarFrenoDcha();
    void VelocidadMotor(uint8_t Motor, uint8_t Speed, bool Direccion);

    Motores();
};

#endif