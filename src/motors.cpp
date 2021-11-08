#include "motors.h"


Motores::Motores(){
    //Setup Channel A
    pinMode(12, OUTPUT); //Initiates Motor Channel A pin
    pinMode(9, OUTPUT); //Initiates Brake Channel A pin

    //Setup Channel B
    pinMode(13, OUTPUT); //Initiates Motor Channel A pin
    pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
}

/****************************************************************
 * Función Frenar
 * Frenar los dos motores a la vez.
 * Aplica nivel de voltaje alto en los pines digitales de los frenos
 * params: none
 ****************************************************************/
void Motores::Frenar(){
    digitalWrite(9, HIGH);  //Engage the Brake for Channel A
    digitalWrite(8, HIGH);  //Engage the Brake for Channel B
}
/****************************************************************
 * Función FrenarIzda
 * Frenar el motor Izquierdo
 * Aplica nivel de voltaje alto en los pines digitales de los frenos
 * params: none
 ****************************************************************/
void Motores::FrenarIzda(){
    digitalWrite(9, HIGH);  //Engage the Brake for Channel A
}
/****************************************************************
 * Función FrenarIzda
 * Frenar el motor Derecho
 * Aplica nivel de voltaje alto en los pines digitales de los frenos
 * params: none
 ****************************************************************/
void Motores::FrenarDcha(){
    digitalWrite(8, HIGH);  //Engage the Brake for Channel B
}


/****************************************************************
 * Función QuitarFreno
 * Quitar el freno a los dos motores a la vez.
 * Aplica nivel de voltaje bajo en los pines digitales de los frenos
 * params: none
 ****************************************************************/
void Motores::QuitarFreno(){
    digitalWrite(9, LOW);  //Engage the Brake for Channel A
    digitalWrite(8, LOW);  //Engage the Brake for Channel B
}
/****************************************************************
 * Función QuitarFrenoIzda
 * Quitar el freno al motor Izquierdo
 * Aplica nivel de voltaje bajo en los pines digitales de los frenos
 * params: none
 ****************************************************************/
void Motores::QuitarFrenoIzda(){
    digitalWrite(9, LOW);  //Engage the Brake for Channel A
}
/****************************************************************
 * Función QuitarFrenoDcha
 * Quitar el freno al motor derecho.
 * Aplica nivel de voltaje bajo en los pines digitales de los frenos
 * params: none
 ****************************************************************/
void Motores::QuitarFrenoDcha(){
    digitalWrite(8, LOW);  //Engage the Brake for Channel A
}

/****************************************************************
 * Función MoverRecto
 * Mueve los dos motores para que el robot vaya recto
 * params: uint8_t Speed --> Velocidad a la que irá el robot (0-255)
 *         bool  Direccion --> direccion en la que se moverá
 ****************************************************************/
void Motores::MoverRecto(uint8_t Speed, bool Direccion){
    QuitarFreno();

    digitalWrite(12, !Direccion); //Establishes forward direction of Channel A
    digitalWrite(13, Direccion);  //Establishes backward direction of Channel B
    analogWrite(3, Speed);   //Spins the motor on Channel A at full speed
    analogWrite(11, Speed);    //Spins the motor on Channel B at half speed 
}

/****************************************************************
 * Función VelocidadMotor
 * Envia una velocidad especifica y una direccion a un motor
 * params: uint8_t Motor --> Identificador del motor a mover
 *         uint8_t Speed --> Velocidad a la que irá el robot (0-255)
 *         bool  Direccion --> direccion en la que se moverá
 ****************************************************************/
void Motores::VelocidadMotor(uint8_t Motor, uint8_t Speed, bool Direccion){
    if(Motor == 1){
        QuitarFrenoIzda();
        digitalWrite(12, !Direccion); //Establishes forward direction of Channel A
        analogWrite(3, Speed);   //Spins the motor on Channel A at full speed
    }
    else{
        QuitarFrenoDcha();

        digitalWrite(13, Direccion);  //Establishes backward direction of Channel B
        analogWrite(11, Speed);    //Spins the motor on Channel B at half sp
    }
}
