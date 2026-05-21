/*
 * systick.cpp
 *
 *  Created on: May 18, 2026
 *      Author: Nadir Mustafa
 */
#include "systick.h"

#define MAX_TICKS 0xffffff

uint32_t inicializar_systick(uint32_t t_ms)
{
	uint32_t TSystick, ticks;
	TSystick = t_ms / 1000; //t_ms to seconds
	ticks = FREQ_PRINCIPAL/TSystick;
	if (ticks > MAX_TICKS){
		return 1;
	}

	SYST_RELOAD = ticks - 1;

	SYST_CURRENT = 0;

	SYST_CONTROL = SYSTICK_CTRL_ENABLE_Msk | SYSTICK_CTRL_TICKINT_Msk | SYSTICK_CTRL_CLKSOURCE_Msk;

	return 0;
}


