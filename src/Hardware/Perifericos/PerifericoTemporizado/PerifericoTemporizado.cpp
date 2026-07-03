/*******************************************************************************************************************************//**
 *
 * @file		PerifericoTemporizado.cpp
 * @brief		Descripcion del modulo
 * @date		Jun 11, 2024
 * @author
 *
 **********************************************************************************************************************************/
#include "PerifericoTemporizado.h"
#include "InicializacionInfotronic.h"

PerifericoTemporizado::PerifericoTemporizado (void (*CallBack)(void)) {

	m_HandlerDelPeriferico=CallBack;
	if(m_HandlerDelPeriferico) {
		g_ListaDePerifericos.push_back(this);
	}
}

void PerifericoTemporizado:: handlerDelPeriferico(void) {
  if(m_HandlerDelPeriferico) {
	  m_HandlerDelPeriferico();
  }
}

PerifericoTemporizado::~PerifericoTemporizado() {
}
