/*
 * Outputs.h
 *
 *  Created on: May 5, 2026
 *      Author: mariano
 */

#ifndef MODULOS_OUTPUTS_OUTPUTS_H_
#define MODULOS_OUTPUTS_OUTPUTS_H_

#include "tipos.h"

class Outputs {
public:
	Outputs() {};
	virtual uint8_t SetPin() = 0;
	virtual uint8_t ClrPin() = 0;
	virtual uint8_t SetTogglePin() = 0;
	virtual uint8_t SetDirOutputs() = 0;
	virtual uint8_t SetPinModeOut() = 0;
	virtual ~Outputs() {};
};

#endif /* MODULOS_OUTPUTS_OUTPUTS_H_ */
