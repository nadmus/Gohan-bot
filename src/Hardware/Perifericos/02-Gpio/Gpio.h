/*
 * Gpio.h
 *
 *  Created on: May 13, 2026
 *      Author: Nadir Mustafa
 */

#ifndef HARDWARE_PERIFERICOS_GPIO_H_
#define HARDWARE_PERIFERICOS_GPIO_H_

#include "LPC845.h"
#include "tipos.h"
#include "Pin.h"
#include "Inputs.h"
#include "Outputs.h"


class Gpio: public Pin, public Inputs, public Outputs {

public:

	typedef enum direction_t    {input, output} direction_t;
	enum power_t				{off,on};
	typedef enum mode_t	{pushpull = 0, opendrain, inactive = 0, pulldown, pullup, repeater} mode_t;
	typedef enum activity_t 	{low, high} activity_t;

protected:
	const mode_t m_mode = pushpull;
	direction_t m_direction;
	const activity_t m_activity = high;

public:

	Gpio(port_t port, uint8_t bit, mode_t mode, direction_t direction, activity_t activity);
	uint8_t SetPin(void) override;
	uint8_t ClrPin(void) override;
	uint8_t SetTogglePin(void) override;
	uint8_t SetToggleDir(void) ;
	uint8_t SetDirInputs(void) override;
	uint8_t SetDirOutputs(void) override;
	uint8_t SetPinModeOut(void) override;
	uint8_t SetPinModeIn(void) override;
	uint8_t GetPin(void) override;
	virtual ~Gpio();
};

#endif /* HARDWARE_PERIFERICOS_GPIO_H_ */
