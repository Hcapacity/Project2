#ifndef RESETZAXIS_H
#define RESETZAXIS_H
#include "main.h"
#include <stdio.h>


typedef struct{
	uint8_t enable;
	uint8_t Step;
	uint16_t CurrentTime;
} CONTROL_Zaxis;


void ControlZ_init(CONTROL_Zaxis* control);
void Reset_Zaxis(UART_HandleTypeDef* huart1, CONTROL_Zaxis* ControlStep);

#endif
