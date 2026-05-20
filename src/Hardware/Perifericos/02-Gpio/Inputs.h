/*
 * Inputs.h
 *
 *  Created on: May 18, 2026
 *      Author: Nadir Mustafa
 */

#ifndef HARDWARE_PERIFERICOS_02_GPIO_INPUTS_H_
#define HARDWARE_PERIFERICOS_02_GPIO_INPUTS_H_

#include "tipos.h"

class Inputs{
public:
	Inputs();
	virtual uint8_t SetDirInputs() = 0;
	virtual uint8_t GetPin() = 0;
	virtual uint8_t SetPinModeIn() = 0;

	virtual ~Inputs();
};



#endif /* HARDWARE_PERIFERICOS_02_GPIO_INPUTS_H_ */
