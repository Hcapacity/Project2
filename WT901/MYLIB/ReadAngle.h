#ifndef READANGLE_H
#define READANGLE_H
#include "main.h"

#define lengthdata 11

typedef struct{
uint8_t flag;
uint8_t signal;
uint8_t Rxdata;
uint8_t Rx_AngleData[lengthdata];
uint8_t count;
} CONTROL_RXDATA;

void ControlRXData_init(CONTROL_RXDATA* control);
void Fill_FullData(CONTROL_RXDATA* control);
float ConvertToAngle(uint8_t HighData, uint8_t LowData);
#endif

