/*
 * Outputs.h
 *
 *  Created on: May 18, 2026
 *      Author: Nadir Mustafa
 */

#ifndef HARDWARE_PERIFERICOS_02_GPIO_OUTPUTS_H_
#define HARDWARE_PERIFERICOS_02_GPIO_OUTPUTS_H_

#include "tipos.h"

class Outputs
{
public:
	Outputs(){};
	virtual uint8_t SetPin() = 0;
	virtual uint8_t ClrPin() = 0;
	virtual uint8_t SetTogglePin() = 0;
	virtual uint8_t SetDirOutputs() = 0;
	virtual uint8_t SetPinModeOut() = 0;
	virtual ~Outputs();
};



#endif /* HARDWARE_PERIFERICOS_02_GPIO_OUTPUTS_H_ */
