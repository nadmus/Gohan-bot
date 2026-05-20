/*
 * SCTimer.cpp
 *
 *  Created on: May 19, 2026
 *      Author: Nadir Mustafa
 */

#include <SCTimer/SCTimer.h>

SCTimer::SCTimer() {
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 8);
}

void SCTimer::setUnify(bool a){
	if(a){
		SCT->CONFIG |= (1 << 0);
	}else{
		SCT->CONFIG &= ~(1 << 0);
	}
}

void SCTimer::setAutoLimit(bool a)
{
	if(a){
		SCT->CONFIG |= (1 << 17);
	}else{
		SCT->CONFIG &= ~(1 << 17);
	}
}

void SCTimer::StartTimer(void){
	SCT->CTRL &= ~(1 << 2);
}

void SCTimer::StopTimer(void){
	SCT->CTRL |= (1 << 2);
}

void SCTimer::SetMatch(uint32_t time, channel_t channel){
	SCT->MATCH[channel] = time;
	SCT->MATCHREL[channel] = time;

	SCT->EV[channel].STATE = 0xFFFFFFFF;
	SCT->EV[channel] = (channel << 0) | (1 << 12);
}

void SCTimer::ConfigSwitchMatrixSCTOut(uint8_t port, uint8_t bit,uint8_t out_number){
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 7);

	uint8_t aux = ~(bit + port * 0x20);	/*	EL REGISTRO POR DEFECTO ESTA EN 0xFF	*/

	switch(out_number)
	{
	case 0:
		SWM->PINASSIGN_DATA[7] &= ~(aux << 24);
		break;
	case 1:
		SWM->PINASSIGN_DATA[8] &= ~(aux << 0);
		break;
	case 2:
		SWM->PINASSIGN_DATA[8] &= ~(aux << 8);
		break;
	case 3:
		SWM->PINASSIGN_DATA[8] &= ~(aux << 16);
		break;
	case 4:
		SWM->PINASSIGN_DATA[8] &= ~(aux << 24);
		break;
	case 5:
		SWM->PINASSIGN_DATA[9] &= ~(aux << 0);
		break;
	case 6:
		SWM->PINASSIGN_DATA[9] &= ~(aux << 8);
		break;
	}
	SYSCON->PRESETCTRL0 |= (1 << 8);	//Reset of SCT CONTROL
	SYSCON->SYSAHBCLKCTRL0 &= ~(1 << 7);

}




SCTimer::~SCTimer() {
	// TODO Auto-generated destructor stub
}

