#ifndef DIGITAL_OUTPUTS_H_
#define DIGITAL_OUTPUTS_H_

#include "systick.h"
#include "Gpio.h"
#include "PerifericoTemporizado.h"

class DigitalOutputs : protected Gpio , public PerifericoTemporizado {
	uint8_t m_buffer;

	public:
		DigitalOutputs(Gpio::port_t puerto , uint8_t bit , uint8_t modo , activity_t actividad , uint8_t estado );//:
		int8_t set ();
		int8_t clr ();

		DigitalOutputs& operator=(uint8_t estado);
		void handlerDelPeriferico();

		virtual ~DigitalOutputs() {};
};

#endif /* DIGITAL_OUTPUTS_H_ */
