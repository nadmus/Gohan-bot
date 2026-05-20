/*
 * Pin.cpp
 *
 *  Created on: May 13, 2026
 *      Author: Nadir Mustafa
 */

#include "../01-Pin/Pin.h"

Pin::Pin(port_t port, uint8_t bit) : m_port(port), m_bit(bit)
{
	m_error = ok;
	if(m_port > port1)
		m_error = error;
	if(m_port == port0 && m_bit > b_port0)
		m_error = error;
	if(m_port == port1 && m_bit > b_port1)
		m_error = error;
}

Pin::~Pin() {
	// TODO Auto-generated destructor stub
}

