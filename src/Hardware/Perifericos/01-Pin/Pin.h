/*
 * Pin.h
 *
 *  Created on: May 13, 2026
 *      Author: agustin
 */

#ifndef HARDWARE_PERIFERICOS_PIN_H_
#define HARDWARE_PERIFERICOS_PIN_H_

#include "tipos.h"

// Index for IOCON Register POrt 0
const uint8_t IOCON_INDEX_PIO0[] = {17,11,6,5,4,3,16,15,4,13,8,7,2,1,18,10,9,0,30,29,28,27,26,25,24,23,22,21,20,0,0,35};
//Index for IOCON Register Port 1
const uint8_t IOCON_INDEX_PIO1[] = { 36,37,3,41,42,43,46,49,31,32,55,54,33,34,39,40,44,45,47,48,52,53,0,0,0,0,0,0,0,50,51};

class Pin {
public:
	typedef enum port_t		{port0, port1} port_t;
	enum max_bits_port_t	{b_port0 = 31, b_port1 = 9};

	typedef enum error_t	{error = 2, ok} error_t;

	const port_t m_port;
	const uint8_t m_bit;
	int8_t m_error;

	Pin(port_t port, uint8_t bit);
	virtual ~Pin();
};

#endif /* HARDWARE_PERIFERICOS_PIN_H_ */
