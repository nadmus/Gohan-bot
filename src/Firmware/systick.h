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
#include "LPC845.h"

using namespace std;

void Instalar_Callback_Systick ( void (*miCallbackSystick) (void) );
void Inicializar_Systick ();
void Install_SysTickCallback (void (*MyApp_SysTickCallback)(void));

#if defined  (__cplusplus)
extern "C" {
	void SysTick_Handler (void);
}
#endif




#endif /* FIRMWARE_SYSTICK_H_ */
