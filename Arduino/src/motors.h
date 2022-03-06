#ifndef __MOTORS_H
#define __MOTORS_H

#include "tipos.h"
#include "Arduino.h"

#define izda_brake  8
#define dcha_brake  9
#define izda_dir   12
#define dcha_dir   13
#define izda_vel   11
#define dcha_vel    3

#define IZQUIERDA 1
#define DERECHA   2

#define ALANTE    0
#define ATRAS     1

class Motores {    
  private:

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