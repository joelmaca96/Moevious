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

Uint8_t_Array_Type check_uint8_array(const ConfigData Data1, const ConfigData Data2){

    if(memcmp(Data1.name.Value,Data2.name.Value, Data2.name.size)){
        return Data2.name;
    }
    Uint8_t_Array_Type empty;
    return empty;
}

static bool operator!=(const ConfigData Data1, const ConfigData Data2){
    return!(Data1==Data2);
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

//Guardar un array en la eeprom
void Store(Uint8_t_Array_Type data){
    if (data.Direction >= EEPROM.length()){
        #ifdef DEBUG_ERRORS
        printf("Error en el almacenado en configuracion. Direccion = %i\n", data.Direction);
        #endif
        return;
    }
    EEPROM.write(data.Direction, data.size);
    for(uint8_t size=1;size < data.size;size++){
        EEPROM.write(data.Direction + size, data.Value[size-1]);
    }
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

//Leer un array desde la eeprom
void Read(Uint8_t_Array_Type *data){
    if (data->Direction >= EEPROM.length()){
        #ifdef DEBUG_ERRORS
        printf("Error en la lectura en configuracion. Direccion = %i\n", data->Direction);
        #endif
        return;
    }

    data->size = EEPROM.read(data->Direction);
    for(uint8_t size=1;size < data->size;size++){
        data->Value[size-1] = EEPROM.read(data->Direction+ size);
    }
}

//Tarea para el almacenado automatico de la configuracion
void ConfigLoop(void *pvParameters){
    ConfigData OldConfig = Configuracion;

    for(;;){
        Uint8_t_Type cambiado = check_uint8(OldConfig, Configuracion);
        if(cambiado.Value != 0 && cambiado.Direction != 0){
            Store(cambiado);
        }

        Uint8_t_Array_Type cambiado = check_uint8_array(OldConfig, Configuracion);
        if(cambiado.Value != 0 && cambiado.Direction != 0){
            Store(cambiado);
        }

        OldConfig = Configuracion;
        duerme(500);
    }
}

//Funciones publicas

/****************************************************************
 * Función InitConfoguration
 * Lee la configuracion inicial y arranca la tarea de configuracion
 * params: NULL
 ****************************************************************/
void InitConfiguration(){

    //Iniciar las direcciones fijas de la memoria
    Configuracion.fw_version.Direction = 0;
    Configuracion.name.Direction = 0;

    //Arrancar la tarea de control de cambios en la configuracion
    xTaskCreate(ConfigLoop, "CONFIG_TASK", 256, NULL, CONFIG_PRIORITY, NULL );

    //Comprobar si ya se ha almacenado algo alguna vez
    //sino almacenar valores por defecto
    Read(&Configuracion.fw_version);

    if(Configuracion.fw_version.Value == 0 || Configuracion.fw_version.Value == 255){
        escribe("La eeprom no esta arrancada, inicializando... \n");
        Configuracion.fw_version.Value = 1;
        memcpy(Configuracion.name.Value, "Moevious1", 10);
    }

    //Leer el resto de valores
    else{
        Read(&Configuracion.name);
    }

    escribe(Configuracion.fw_version.Value);
    escribe((char*)Configuracion.name.Value);
}