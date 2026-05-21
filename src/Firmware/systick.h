/*
 * systick.h
 *
 *  Created on: May 18, 2026
 *      Author: Nadir Mustafa
 */

#ifndef FIRMWARE_SYSTICK_H_
#define FIRMWARE_SYSTICK_H_

#include "LPC845.h"
#include "tipos.h"

//Systick CONTROL register positions
#define SYSTICK_CTRL_ENABLE_POS 0UL
#define SYSTICK_CTRL_TICKINT_POS 1UL
#define SYSTICK_CTRL_CLKSOURCE_POS 2UL
#define SYSTICK_CTRL_COUNTFLAG_POS 16UL

//Systick CONTROL register Masks
#define SYSTICK_CTRL_ENABLE_Msk (1UL<<SYSTICK_CTRL_ENABLE_POS)
#define SYSTICK_CTRL_TICKINT_Msk (1UL<<SYSTICK_CTRL_TICKINT_POS)
#define SYSTICK_CTRL_CLKSOURCE_Msk (1UL<<SYSTICK_CTRL_CLKSOURCE_POS)


uint32_t inicializar_systick(uint32_t t_ms);

#if defined(__cplusplus)
	extern "C"{
	void SysTick_Handler(void);
	}
#endif




#endif /* FIRMWARE_SYSTICK_H_ */
