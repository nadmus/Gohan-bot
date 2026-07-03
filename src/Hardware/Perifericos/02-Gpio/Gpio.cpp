#include "Gpio.h"
#include "LPC845.h"

const uint8_t IOCON_INDEX_PIO0[] = {17,11,6,5,4,3,16,15,4,13,8,7,2,1,18,10,9,0,30,29,28,27,26,25,24,23,22,21,20,0,0,35};
const uint8_t IOCON_INDEX_PIO1[] = {36,37,38,41,42,43,46,49,31,32};

Gpio::Gpio(port_t port, uint8_t bit, uint8_t mode,
		direction_t direction, activity_t activity) :

		m_port{port},
		m_bit{bit},
		m_mode{mode},
		m_direction{direction},
		m_activity{activity} {

	m_error = OK;

	if (m_port > PORT1) {
		m_error = ERROR;
		return;
	}
	if (m_port == PORT0 && m_bit > MAX_BITS_PORT0) {
		m_error = ERROR;
		return;
	}
	if (m_port == PORT1 && m_bit > MAX_BITS_PORT1) {
		m_error = ERROR;
		return;
	}

	SYSCON->SYSAHBCLKCTRL0 |= (1 << 6) | (1 << 20) | (1 << 18);	// 6=GPIO0,	20=GPIO1, 18=IOCON

	if (m_direction == INPUT) {
		SetDirInputs();
		SetPinModeIn();
	}
	else {
		SetDirOutputs();
		SetPinModeOut();
	}
}

uint8_t Gpio::SetPin() {

	if (m_error == OK && m_direction == OUTPUT) {
		if (m_activity == HIGH) {
			GPIO->SET[m_port] = 1 << m_bit;
		}
		else {
			GPIO->CLR[m_port] = 1 << m_bit;
		}
	}
	return m_error;
}

uint8_t Gpio::ClrPin() {

	if (m_error == OK && m_direction == OUTPUT) {
		if (m_activity == HIGH) {
			GPIO->CLR[m_port] = 1 << m_bit;
		}
		else {
			GPIO->SET[m_port] = 1 << m_bit;
		}
	}
	return m_error;
}

uint8_t Gpio::SetTogglePin() {

	if (m_error == OK && m_direction == OUTPUT) {
		GPIO->NOT[m_port] = (1 << m_bit);
	}
	return m_error;
}

uint8_t Gpio::SetToggleDir() {

	if (m_error == OK) {
		GPIO->DIRNOT[m_port] = (1 << m_bit);
	}
	return m_error;
}

uint8_t Gpio::SetDirOutputs() {

	if (m_error == OK) {
		m_direction = OUTPUT;
		GPIO->DIRSET[m_port] = (1 << m_bit);
	}
	return m_error;

}

uint8_t Gpio::SetDirInputs() {

	if (m_error == OK) {
		m_direction = INPUT;
		GPIO->DIRCLR[m_port] = (1 << m_bit);
	}
	return m_error;

}

uint8_t Gpio::SetPinModeIn() {

	uint8_t IndicePortPin;

	if (m_error == OK) {
		IndicePortPin = IOCON_INDEX_PIO0[m_bit];
		if (m_port) {
			IndicePortPin = IOCON_INDEX_PIO1[m_bit];
		}
		IOCON->PIO[IndicePortPin] = ~(3 << 3);
		IOCON->PIO[IndicePortPin] = m_mode << 3;
	}
	return 0;
}

uint8_t Gpio::SetPinModeOut() {

	uint8_t IndicePortPin;

	if (m_error == OK) {
		IndicePortPin = IOCON_INDEX_PIO0[m_bit];
		if (m_port) {
			IndicePortPin = IOCON_INDEX_PIO1[m_bit];
		}
		IOCON->PIO[IndicePortPin] = ~(1 << 10);
		IOCON->PIO[IndicePortPin] = m_mode << 10;
	}
	return 0;
}


uint8_t Gpio::GetPin() const {

	if (m_error==OK && m_activity==HIGH) {
		return (GPIO->PIN[m_port] & (1<<m_bit) ? 1 : 0);
	}

	if (m_error==OK && m_activity==LOW) {
		return (GPIO->PIN[m_port] & (1<<m_bit) ? 0 : 1);
	}

	return m_error;
}

Gpio& Gpio::operator=(bool estado) {
	if (this->m_error == OK && this->m_direction == OUTPUT) {
		if (estado) { SetPin(); }
		else { ClrPin(); }
	}
	return *this;
}

bool Gpio::operator==(const Gpio& pin) {
	return (this->GetPin() == pin.GetPin());
}

Gpio::operator bool() const {
	return GetPin();
}

Gpio::~Gpio() {
	// TODO Auto-generated destructor stub
}
