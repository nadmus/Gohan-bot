/*
 * PWM.h
 *
 *  Created on: May 21, 2026
 *      Author: Nadir Mustafa
 */

#ifndef HARDWARE_DRIVERS_PWM_PWM_H_
#define HARDWARE_DRIVERS_PWM_PWM_H_

#include "SCTimer.h"



class PWM:public Pin{
private:
	SCTimer &m_sct;
	SCTimer::output_t m_output;
	SCTimer::match_t m_matchDuty;
	SCTimer::match_t m_matchPeriod;



	uint32_t m_ton;
	uint32_t m_toff;

	uint32_t m_period;
	uint32_t m_duty;


public:
	enum base_t {MICROSEG, MILISEG,SEG, MIN};



	PWM(SCTimer &m_sct, port_t port, uint8_t bit, SCTimer::output_t out);


	void SetDutyCycle(uint32_t duty);
	void SetPeriod(base_t base, uint32_t ton, uint32_t toff);
	void SetTon(base_t base, uint32_t ton);
	void SeToff(base_t base,uint32_t toff);
	void SetPeriod(base_t base, uint32_t period);

	void StartPWM(void);
	void StopPWM(void);


	virtual ~PWM();
};

#endif /* HARDWARE_DRIVERS_PWM_PWM_H_ */
