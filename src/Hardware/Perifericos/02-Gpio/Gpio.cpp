/*
 * Gpio.cpp
 *
 *  Created on: May 13, 2026
 *      Author: Nadir Mustafa
 */

#include "../02-Gpio/Gpio.h"

Gpio::Gpio(port_t port, uint8_t bit, mode_t mode, direction_t direction, activity_t activity):
Pin(port,bit),m_mode(mode), m_direction(direction), m_activity(activity)
{
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 6) | (1 << 8) | (1 << 20);
	if(m_direction == input){
		SetDirInputs();
		SetPinModeIn();
	}else{
		SetDirOutputs();
		SetPinModeOut();
	}
}

uint8_t Gpio::SetPin(void)
{
	if(m_error == ok && m_direction == output)
	{
		if(m_activity == high)
		{
			GPIO->SET[m_port] = 1 << m_bit;
		}
		else
		{
			GPIO->CLR[m_port] = 1 << m_bit;
		}
	}
	return m_error;
}

uint8_t Gpio::ClrPin(void)
{
	if(m_error == ok && m_direction == output)
	{
		if(m_activity == high)
		{
			GPIO->CLR[m_port] = 1 << m_bit;
		}
		else
		{
			GPIO->SET[m_port] = 1 << m_bit;
		}
	}
	return m_error;
}

uint8_t Gpio::SetDirInputs(void)
{
	if(m_error == ok)
	{
		m_direction = input;
		GPIO->DIRCLR[m_port] = 1 << m_bit;
	}
	return m_error;
}

uint8_t Gpio::SetDirOutputs(void)
{
	if(m_error==ok)
	{
		m_direction = output;
		GPIO->DIRSET[m_port] = 1 << m_bit;
	}
	return m_error;
}

uint8_t Gpio::SetTogglePin(void)
{
	if(m_error == ok && m_direction == output)
	{
		GPIO->NOT[m_port] = 1 << m_bit;
	}
	return m_error;
}

uint8_t Gpio::SetToggleDir(void)
{
	if(m_error == ok)
	{
		GPIO->DIRNOT[m_port] = 1 << m_bit;
	}
	return m_error;
}

uint8_t Gpio::SetPinModeIn(void)
{
	uint8_t IndicePortPin;

	if(m_error == ok)
	{
		IndicePortPin = IOCON_INDEX_PIO0[m_bit];
		if(m_port)
		{
			IndicePortPin = IOCON_INDEX_PIO1[m_bit];
		}
		IOCON->PIO[IndicePortPin] = ~(3 << 3);
		IOCON->PIO[IndicePortPin] = (m_mode << 3);
	}
	return m_error;
}

uint8_t Gpio::SetPinModeOut(void)
{
	uint8_t IndicePortPin;

	if(m_error == ok)
	{
		IndicePortPin = IOCON_INDEX_PIO0[m_bit];
		if(m_port)
		{
			IndicePortPin = IOCON_INDEX_PIO1[m_bit];
		}
		IOCON->PIO[IndicePortPin] = ~(1 << 10);
		IOCON->PIO[IndicePortPin] = ~(m_mode << 10);
	}
	return m_error;
}

Gpio::~Gpio() {
	// TODO Auto-generated destructor stub
}

