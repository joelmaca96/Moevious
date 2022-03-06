#ifndef __COMS__H
#define __COMS__H

#include "../tipos.h"
#include <WiFi.h>

//Clase para gestionar las comunicaciones del equipo, 
class Coms {
    private:
        void WiFiEvent(WiFiEvent_t event);
        void WiFiGotIP(WiFiEvent_t event, WiFiEventInfo_t info);  
        void init();
    
    public:
        //ordenes de guardado y carga de datos
        bool Guardar = false, Cargar = false;

        //Inicializador
        void init();

        //Atributos
        carac_config data;
        
        //Acciones sobre el archivo al completo
        bool Load();
        bool Store();
        bool Erase();

        //Acciones sobre claves unitarias
        bool ModifyKey();
        bool DeleteKey();
        bool AddKey();

};

extern Coms Comunicacion;
#endif