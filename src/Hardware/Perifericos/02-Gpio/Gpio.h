/*
 * Gpio.h
 *
 *  Created on: May 13, 2026
 *      Author: Nadir Mustafa
 */

#include "tipos.h"
#include "Inputs.h"
#include "Outputs.h"

#ifndef MODULOS_GPIOS_GPIO_H_
#define MODULOS_GPIOS_GPIO_H_


class Gpio : public Inputs, public Outputs {

private:
	const uint8_t m_port;
	const uint8_t m_bit;
	const uint8_t m_mode;
		  uint8_t m_direction;
	const uint8_t m_activity;
	      uint8_t m_error;

public:

	enum port_t {PORT0 = 0, PORT1};
	static constexpr uint8_t MAX_BITS_PORT0 = 31;
	static constexpr uint8_t MAX_BITS_PORT1 = 9;
	enum direction_t {INPUT=0, OUTPUT};
	enum mode_output_t {PUSHPULL = 0, OPENDRAIN};
	enum mode_input_t {INACTIVE=0, PULLDOWN, PULLUP, REPEATER};
	enum activity_t {LOW = 0, HIGH};
	enum error_t {ERROR = 2, OK};

	Gpio(port_t port, uint8_t bit, uint8_t mode,
			direction_t direction, activity_t activity);

	uint8_t SetPin();
	uint8_t ClrPin();
	uint8_t SetTogglePin();
	uint8_t SetToggleDir();
	uint8_t SetDirOutputs();
	uint8_t SetPinModeOut();
	uint8_t SetDirInputs();
	uint8_t GetPin() const override;
	uint8_t SetPinModeIn();

	// Sobrecarga de operadores
	Gpio& operator=(bool estado);
	bool operator==(const Gpio& pin);
	explicit operator bool() const;

	// Destructor
	virtual ~Gpio();
};

#endif /* MODULOS_GPIOS_GPIO_H_ */
