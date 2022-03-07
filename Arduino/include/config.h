#ifndef __CONFIG__H
#define __CONFIG__H

/*--------------------------------------------------*/
/*----------- Defines de configuracion -------------*/
/*--------------------------------------------------*/


#define DEBUG          (1) //Control de todo el output por el puerto serial
#define DEBUG_ERRORS   (1) //Control de errores por el puerto serial

#if DEBUG
    #define DEBUG_MEMO (1) //Control de mensajes de diagnostico de la libreria memo
#endif

#if DEBUG_ERRORS
    #define DEBUG_MEMO_ERRORS (1) //Control de mensajes de error de la libreria memo
#endif

//Configuracion de las prioridades de las tareas

#define ULTRASONIC_PRIORITY 3
#define CONFIG_PRIORITY     4
#define CONTROL_PRIORITY    2




#endif