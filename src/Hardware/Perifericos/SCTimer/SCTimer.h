/*
 * SCTimer.h
 *
 *  Created on: May 19, 2026
 *      Author: Nadir Mustafa
 */

#ifndef HARDWARE_PERIFERICOS_SCTIMER_SCTIMER_H_
#define HARDWARE_PERIFERICOS_SCTIMER_SCTIMER_H_

#include "Pin.h"
#include "LPC845.h"
#include "tipos.h"

class SCTimer{
private:
	static constexpr uint32_t MATCHSEL = 0;
	static constexpr uint32_t MATCH_ONLY=(1 << 12);
private:
	typedef enum channel_t {CHANNEL1=0,CHANNEL2,CHANNEL3,CHANNEL4,CHANNEL5,CHANNEL6,CHANNEL7,CHANNEL8}channel_t;
public:
	SCTimer();
	void setUnify(bool a);
	void setAutoLimit(bool a);
	void StartTimer(void);
	void StopTimer(void);
	void SetMatch(uint32_t time, channel_t channel);
	void ConfigSwitchMatrixSCTOut(uint8_t port, uint8_t bit,uint8_t out_number);

	virtual ~SCTimer();
};

#endif /* HARDWARE_PERIFERICOS_SCTIMER_SCTIMER_H_ */
