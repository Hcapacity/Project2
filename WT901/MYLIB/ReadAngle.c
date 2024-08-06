#include "ReadAngle.h"

void ControlRXData_init(CONTROL_RXDATA* control){
	control->count = 0;
	control->flag = 0;
	control->signal = 0;
}
void Fill_FullData(CONTROL_RXDATA* control){
	if(control->Rxdata == 0x55){
		 control->signal = 1;
	 }
	 if(control->signal){
		 control->Rx_AngleData[control->count++] = control->Rxdata;
	   if(control->count == lengthdata){
			 control->count = 0;
			 control->signal = 0;
			 if(control->Rx_AngleData[1] == 0x53){ 
				 control->flag = 1; 
			 }
		 }
	 }
}

float ConvertToAngle(uint8_t HighData, uint8_t LowData){
	return (float)((short)((short)HighData << 8 | LowData)) / 32768.0 * 180.0;
}

