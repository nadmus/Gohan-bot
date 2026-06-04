/*
 * SCTimer.cpp
 *
 *  Created on: May 19, 2026
 *      Author: Nadir Mustafa
 */

#include "SCTimer.h"

SCTimer::SCTimer() {
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 8);

	for(uint8_t i=0;i<8;i++){
		event_type[i] = EventSource::UNUSED;
	}
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

void SCTimer::SetMatch(uint32_t time, match_t match){

	SCT->REGMODE &= ~(1 << match); //if regmode bit is 0 act as a match

	SCT->MATCH[match] = time;
	SCT->MATCHREL[match] = time;

}

void SCTimer::SetCapture(capture_t capture, event_t event){

	if(event_type[event] == EventSource::UNUSED)
		return;

	SCT->REGMODE |= (1 << capture);

	SCT->CAPCTRL[capture] = (1 << event);
}

uint32_t SCTimer::ReadCapture(capture_t capture)
{
	return SCT->CAP[capture];
}



void SCTimer::CreateMatchEvent(match_t match, event_t event){


	if(event_type[event] != EventSource::UNUSED){
		return;
	}

	event_type[event] = EventSource::MATCH;


	SCT->EV[event].STATE = STATE_EVENT_ALL;
	SCT->EV[event].CTRL = (match << MATCHSEL) | MATCH_ONLY;
}

void SCTimer::CreateInputEvent(input_t input, event_t event, edge_t edge){

	if(event_type[event] != EventSource::UNUSED)
		return;

	event_type[event] = EventSource::INPUT;

	SCT->EV[event].STATE = STATE_EVENT_ALL;

	SCT->EV[event].CTRL = INPUT_SELECT | (input << IOSEL_POS) | (edge << IOCOND_POS);
}

void SCTimer::CreateOutputEvent(output_t output, event_t event, edge_t edge){
	if(event_type[event] != EventSource::UNUSED)
		return;

	event_type[event] = EventSource::OUTPUT;

	SCT->EV[event].STATE = STATE_EVENT_ALL;

	SCT->EV[event].CTRL = OUTPUT_SELECT | (output << IOSEL_POS) | (edge << IOCOND_POS);
}

void SCTimer::SetOutput(output_t out, event_t event){
	SCT->OUT[out].SET |= (1 << event);
}

void SCTimer::ClrOutput(output_t out, event_t event){
	SCT->OUT[out].CLR |= (1 << event);
}




void SCTimer::ConfigSwitchMatrixSCTOut(uint8_t port, uint8_t bit,uint8_t out_number){
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 7);

	uint8_t aux = (bit + port * 0x20);	/*	EL REGISTRO POR DEFECTO ESTA EN 0xFF	*/

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

