#include "DigitalInputs.h"
#include "InicializacionInfotronic.h"

DigitalInputs::DigitalInputs(Gpio::port_t puerto, uint8_t bit, uint8_t modo,
		activity_t actividad, uint32_t MaxBounce):
		Gpio(puerto, bit, modo, Gpio::INPUT, actividad),
		m_MaxBounce{MaxBounce} {

	// Lo engancho con el tick del sistema
	m_CountBounce = 0;
	m_BufferEntrada = GetPin();
	g_ListaDePerifericos.push_back(this);
}

DigitalInputs::~DigitalInputs() {
	// TODO Auto-generated destructor stub
}

void DigitalInputs::handlerDelPeriferico() {

	uint8_t BufferEntradasInstantaneo = 0 ;

	BufferEntradasInstantaneo = GetPin( );

	if (BufferEntradasInstantaneo != m_BufferEntrada) {
		m_CountBounce++;
		if (m_CountBounce  >= m_MaxBounce)
				m_BufferEntrada = !m_BufferEntrada;
	}
	else
		m_CountBounce = 0 ;
}


uint8_t DigitalInputs::get() {
	return m_BufferEntrada;
}

DigitalInputs::operator bool() {
	 return m_BufferEntrada;
}

bool DigitalInputs::operator!() {
	return !m_BufferEntrada;
}
