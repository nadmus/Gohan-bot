#ifndef DIGITAL_INPUTS_H_
#define DIGITAL_INPUTS_H_

#include "systick.h"
#include "Gpio.h"
#include "PerifericoTemporizado.h"

#define MAX_BOUNCE	4

class DigitalInputs : protected Gpio , public PerifericoTemporizado {

private:
	uint8_t m_BufferEntrada ;
	uint32_t m_MaxBounce ;
	uint32_t m_CountBounce ;
public:
	DigitalInputs(Gpio::port_t puerto, uint8_t bit, uint8_t modo, activity_t actividad, uint32_t MaxBounce = MAX_BOUNCE);
	uint8_t get();
	explicit operator bool();
	bool operator!();

	// las virtuales puras deben ser si o si redefinidas
	void handlerDelPeriferico();
	virtual ~DigitalInputs();
};

#endif /* DIGITAL_INPUTS_H_ */
