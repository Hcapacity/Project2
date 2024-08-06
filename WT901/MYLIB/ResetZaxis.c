#include "ResetZaxis.h"


void ControlZ_init(CONTROL_Zaxis* control){
	control->enable = 1;
	control->Step = 0;
}

void Reset_Zaxis(UART_HandleTypeDef* huart1, CONTROL_Zaxis* ControlStep){
	uint8_t Unlock_Data[] = {0xFF, 0xAA, 0x69, 0x88, 0xB5};
	uint8_t Command_Data[] = {0xFF, 0xAA, 0x01, 0x04, 0x00};
	uint8_t Save_Data[] = {0xFF, 0xAA, 0x00, 0x00, 0x00};
	if(ControlStep->enable){
	if(ControlStep->Step == 0){
		ControlStep->CurrentTime = HAL_GetTick();
	  HAL_UART_Transmit(huart1, Unlock_Data, 5, 2000);
		ControlStep->Step++;
	}
	if(HAL_GetTick() - ControlStep->CurrentTime > 1000 && ControlStep->Step == 1){ 
	     HAL_UART_Transmit(huart1, Command_Data, 5, 2000);
			 ControlStep->CurrentTime = HAL_GetTick();
	     ControlStep->Step++;
		}
	if(HAL_GetTick() - ControlStep->CurrentTime > 1000 && ControlStep->Step == 2){ 
	     HAL_UART_Transmit(huart1, Save_Data, 5, 2000);
		   ControlStep->Step = 0;
       ControlStep->enable = 0;
		}
	}
}
