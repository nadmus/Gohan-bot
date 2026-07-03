#include "DigitalOutputs.h"
#include "Gpio.h"
#include "InicializacionInfotronic.h"

DigitalOutputs::DigitalOutputs(Gpio::port_t puerto , uint8_t bit , uint8_t modo , activity_t actividad , uint8_t estado ):
					Gpio(puerto , bit , modo , Gpio::OUTPUT , actividad)
{
	m_buffer = estado;
	SetDirOutputs();
	g_ListaDePerifericos.push_back(this);
}

int8_t DigitalOutputs::set() {
	m_buffer = 1;
	return Gpio::OK;
}

int8_t DigitalOutputs::clr() {
	m_buffer =  0;
	return Gpio::OK;
}


DigitalOutputs& DigitalOutputs::operator=(uint8_t estado) {
	m_buffer =  estado ;
	return *this;
}

void DigitalOutputs::handlerDelPeriferico() {
	if (m_buffer)
		SetPin();
	else
		ClrPin();
}
