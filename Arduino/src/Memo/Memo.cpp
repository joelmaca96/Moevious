#include "Memo.h"

extern ConfigData Configuracion;

//Funciones privadas
Uint8_t_Type check_uint8(const ConfigData Data1, const ConfigData Data2){
    if(Data1.fw_version.Value != Data2.fw_version.Value){
        
        return Data2.fw_version;
    }
    Uint8_t_Type empty;
    return empty;
}

//Guardar un único valor en la eeprom
void Store(Uint8_t_Type data){
    if (data.Direction >= EEPROM.length()){
        #ifdef DEBUG_ERRORS
        printf("Error en el almacenado en configuracion. Direccion = %i\n", data.Direction);
        #endif
        return;
    }
    EEPROM.write(data.Direction, data.Value);
}

//Leer un único valor desde la eeprom
void Read(Uint8_t_Type *data){
    if (data->Direction >= EEPROM.length()){
        #ifdef DEBUG_ERRORS
        printf("Error en la lectura en configuracion. Direccion = %i\n", data->Direction);
        #endif
        return;
    }
    data->Value = EEPROM.read(data->Direction);
}

//Limpiar la eemprom
void clear_eeprom(){
   for (int E = 0; E < EEPROM.length(); E++){
    EEPROM.write(E, 0);   // Itera por toda la EEPROM y reemplaza cualquier valor que esté en algún byte por cero
  }
}

//Tarea para el almacenado automatico de la configuracion
void ConfigLoop(void *p){

    ConfigData OldConfig = Configuracion;

    //Comprobar si ya se ha almacenado algo alguna vez
    //sino almacenar valores por defecto
    Read(&Configuracion.fw_version);

    escribe("Version de firmware actual:");
    escribe(Configuracion.fw_version.Value);


    if(Configuracion.fw_version.Value == 0 || Configuracion.fw_version.Value == 255){
        escribe("La eeprom no esta arrancada, inicializando...");
        Configuracion.fw_version.Value = 1;
    }

    //Leer el resto de valores
    else{
        OldConfig = Configuracion;
    }

    //Bucle para las comprobaciones
    for(;;){

        Uint8_t_Type cambiado = check_uint8(OldConfig, Configuracion);
        if(cambiado.Direction != 255){
            escribe("Guardando datos!\n");
            Store(cambiado);
        }

        OldConfig = Configuracion;
        duerme(100);
    }
    vTaskDelete(NULL);
}

//Funciones publicas

/****************************************************************
 * Función InitConfoguration
 * Lee la configuracion inicial y arranca la tarea de configuracion
 * \param NULL
 ****************************************************************/
void InitConfiguration(){

    //clear_eeprom();

    //Iniciar las direcciones fijas de la memoria
    Configuracion.fw_version.Direction = 1;


    //Arrancar la tarea de control de cambios en la configuracion
    TaskHandle_t handle;
    
    xTaskCreate(ConfigLoop, "CFGTASK", 128, NULL, CONFIG_PRIORITY, &handle);

}