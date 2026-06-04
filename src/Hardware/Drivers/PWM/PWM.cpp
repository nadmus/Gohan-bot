/*
 * PWM.cpp
 *
 *  Created on: May 21, 2026
 *      Author: Nadir Mustafa
 */

#include "PWM.h"

PWM::PWM(SCTimer &sct, uint8_t port, uint8_t bit, SCTimer::output_t out):
Pin(port,bit),m_output(out),m_sct(sct)
{
	m_ton =0;
	m_toff=0;
	m_period=0;

	m_sct.setUnify(true);
	m_sct.setAutoLimit(true);
	m_sct.ConfigSwitchMatrixSCTOut(port, bit, out);


	m_sct.CreateMatchEvent(SCTimer::MATCH0,  SCTimer::EVENT0);
	m_sct.CreateMatchEvent(SCTimer::MATCH1,	SCTimer::EVENT1);

	m_sct.SetOutput(out, SCTimer::EVENT0);
	m_sct.ClrOutput(out,SCTimer::EVENT1);



}

void PWM::SetTon(base_t base, uint32_t t){

	if(m_period == 0) return;

	m_ton = t;

	if(base == SEG){
		m_ton *= 1000000;
	}
	if(base == MILISEG){
		m_ton *= 1000;
	}

	m_sct.SetMatch(m_ton * FREQ_PRINCIPAL/1000000, SCTimer::MATCH1);
}

void PWM::SetPeriod(base_t base, uint32_t ton, uint32_t toff){
	m_ton = ton;
	m_toff = toff;

	if(base == SEG){
		m_ton *= 1000000;
		m_toff*= 1000000;
	}
	if(base == MILISEG){
		m_ton *= 1000;
		m_toff *= 1000;
	}
	m_period = (m_ton+m_toff) * FREQ_PRINCIPAL/1000000;
	m_sct.SetMatch(m_period, SCTimer::MATCH0);
	//sct.CreateMatchEvent(SCTimer::MATCH0,  SCTimer::EVENT0);
}

void PWM::setDutyCycle(uint32_t duty){
	uint32_t ton;

	ton = (m_period * duty) / 100;

	m_sct.SetMatch(ton , SCTimer::MATCH1);
}

void PWM::StartTimer(void){
	m_sct.StartTimer();
}

void PWM::StopTimer(void){
	m_sct.StopTimer();
}

PWM::~PWM() {
	// TODO Auto-generated destructor stub
}

