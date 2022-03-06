#include "motors.h"


Motores::Motores(){
    //Setup motor izquierdo
    pinMode(izda_dir, OUTPUT); 
    pinMode(izda_brake, OUTPUT); 

    //Setup motor derecho
    pinMode(dcha_dir, OUTPUT); 
    pinMode(dcha_brake, OUTPUT);  

    //Iniciar frenados
    Frenar();
}

/****************************************************************
 * Función Frenar
 * \brief Frenar los dos motores a la vez.
 * Aplica nivel de voltaje alto en los pines digitales de los frenos
 ****************************************************************/
void Motores::Frenar(){
    analogWrite(izda_vel, 0);  
    analogWrite(dcha_vel, 0); 
    FrenarIzda();
    FrenarDcha();
}
/****************************************************************
 * Función FrenarIzda
 * \brief Frenar el motor Izquierdo
 * Aplica nivel de voltaje alto en los pines digitales de los frenos
 ****************************************************************/
void Motores::FrenarIzda(){
    digitalWrite(izda_brake, HIGH); 
}
/****************************************************************
 * Función FrenarIzda
 * \brief Frenar el motor Derecho
 * Aplica nivel de voltaje alto en los pines digitales de los frenos
 ****************************************************************/
void Motores::FrenarDcha(){
    digitalWrite(dcha_brake, HIGH);  
}


/****************************************************************
 * Función QuitarFreno
 * \brief Quitar el freno a los dos motores a la vez.
 * Aplica nivel de voltaje bajo en los pines digitales de los frenos
 ****************************************************************/
void Motores::QuitarFreno(){
    QuitarFrenoIzda();
    QuitarFrenoDcha();
}
/****************************************************************
 * Función QuitarFrenoIzda
 * \brief Quitar el freno al motor Izquierdo
 * Aplica nivel de voltaje bajo en los pines digitales de los frenos
 ****************************************************************/
void Motores::QuitarFrenoIzda(){
    digitalWrite(izda_brake, LOW); 
}
/****************************************************************
 * Función QuitarFrenoDcha
 * \brief Quitar el freno al motor derecho.
 * Aplica nivel de voltaje bajo en los pines digitales de los frenos
 ****************************************************************/
void Motores::QuitarFrenoDcha(){
    digitalWrite(dcha_brake, LOW); 
}

/****************************************************************
 * Función VelocidadMotor
 * \brief Envia una velocidad especifica y una direccion a un motor
 * \param uint8_t Motor --> Identificador del motor a mover
 * \param uint8_t Speed --> Velocidad a la que irá el robot (0-255)
 * \param bool  Direccion --> direccion en la que se moverá
 ****************************************************************/
void Motores::VelocidadMotor(uint8_t Motor, uint8_t Speed, bool Direccion){
    if(Motor == IZQUIERDA){
        if(Speed > 0){ //Mandar un 0 como velocidad es lo mismo que frenar
            QuitarFrenoIzda();
            digitalWrite(izda_dir, !Direccion); 
            analogWrite(izda_vel, Speed); 
        }
        else{
            FrenarIzda();
        }
        
    }
    else{
        if(Speed > 0){
            QuitarFrenoDcha();
            digitalWrite(dcha_dir, Direccion);  
            analogWrite(dcha_vel, Speed);  
        }  
        else{
            FrenarDcha();
        }
    }
}

/****************************************************************
 * Función MoverRecto
 * \brief Mueve los dos motores para que el robot vaya recto
 * \param uint8_t Speed --> Velocidad a la que irá el robot (0-255)
 * \param bool  Direccion --> direccion en la que se moverá
 ****************************************************************/
void Motores::MoverRecto(uint8_t Speed, bool Direccion){
    QuitarFreno();

    digitalWrite(izda_dir, !Direccion); 
    digitalWrite(dcha_dir, Direccion);  
    analogWrite(izda_vel, Speed);  
    analogWrite(dcha_vel, Speed);  

    Status.direccion = Direccion;
    Status.speed = Speed;  
}


