#ifndef __TIPOS__H__
#define __TIPOS__H__

#include <Arduino.h>

//Configuracion de los logs
#define DEBUG_CONFIG 0

//Redefinicion de tipos de datos para que sea mas comodos utilizarlos
typedef	uint8_t			uint8;
typedef	uint16_t		uint16;
typedef	uint32_t		uint32;

//Caracteristica para almacenar la configuracion del equipo
typedef struct{
	//Para cuando se quiera almacenar el part number
	//String Part_Number  = "LU320111250";
	char device_ID[12]    = {'V','C','D','1','7','0','1','0','0','0','1',0};
	char deviceSerNum[30] = {'0'};
	char autentication_mode[3] = {'W', 'A', 0};
	char actualization_mode[3] = {'A', 'A', 0};
	char policy[4] = {'A', 'L', 'L',0};

	uint16_t Firmware     = 500;
	uint16_t FirmwarePSOC = 500;

	uint8  Data_cleared = 0;
	uint8  CDP  = 0;
	uint8  inst_current_limit = 32;
	uint8  count_reinicios_malos = 0;

	uint16 potencia_contratada1 = 32;
	uint16 potencia_contratada2 = 32;
	
} carac_config;



#endif