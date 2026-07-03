#include "Timer.h"
#include "InicializacionInfotronic.h"

Timer::Timer() {

	m_TmrRun = 0;
	m_TmrEvent = 0 ;
	m_TmrHandler = nullptr ;
	m_TmrStandBy = RUN ;
	m_TmrBase = DEC;

	// Lo engancho con el tick del sistema
	g_ListaDePerifericos.push_back(this);
}

Timer::Timer(const Timer_Handler handler , const bases_t base ):PerifericoTemporizado(nullptr) {
	m_TmrRun = 0;
	m_TmrEvent = 0 ;
	m_TmrHandler = handler ;
	m_TmrStandBy = 0 ;
	m_TmrBase = base;

	// Lo engancho con el tick del sistema
	g_ListaDePerifericos.push_back(this);
}


/**
	\fn void TimerStart( uint32_t time, const Timer_Handler handler , const uint8_t base )
	\brief Inicia un timer
 	\details Inicia el timer y al transcurrir el tiempo especificado por y time se llama a la funcion apuntada por handler
 	\param [in] time Tiempo del evento. Dependiente de la base de tiempos
 	\param [in] handler Callback del evento
 	\param [in] base de tiempo
	\return void
*/
void Timer::TimerStart( uint32_t time, const Timer_Handler handler , const bases_t base ) {

	switch ( base ) {

		case DEC:
			time *= DECIMAS;
			break;
		case SEG:
			time *= ( SEGUNDOS * DECIMAS );
			break;
		case MIN:
			time *= ( MINUTOS * SEGUNDOS * DECIMAS );
			break;
	}

	m_TmrBase = base;

	if( time != 0 )	{ //el tiempo no es 0, lo cargo
		m_TmrRun = time;
		m_TmrEvent = false ;
	} else {	//el tiempo es cero, el timer vence automáticamente
		m_TmrRun = 0;
		m_TmrEvent = true;
	}
	m_TmrHandler = handler;
}

void Timer::TimerStart(uint32_t time) {

	switch (m_TmrBase) {

		case DEC:
			time *= DECIMAS;
			break;

		case SEG:
			time *= ( SEGUNDOS * DECIMAS );
			break;

		case MIN:
			time *= ( MINUTOS * SEGUNDOS * DECIMAS );
			break;
	}

	if(time != 0) {//el tiempo no es 0, lo cargo
		m_TmrRun = time;
		m_TmrEvent = false ;
	} else {	//el tiempo es cero, el timer vence automáticamente
		m_TmrRun = 0;
		m_TmrEvent = true;
	}
}


/**
	\fn void SetTimer( timer_t t )
	\brief Inicia un timer
 	\details Reinicia el timer con el valor t (no lo resetea)
 	\param [in] time Tiempo del evento. Dependiente de la base de tiempos
 	\return void
*/
void Timer::SetTimer(uint32_t time) {

	switch (m_TmrBase) {

		case DEC:
			time *= DECIMAS;
			break;

		case SEG:
			time *= ( SEGUNDOS * DECIMAS );
			break;

		case MIN:
			time *= ( MINUTOS * SEGUNDOS * DECIMAS );
			break;
	}
	m_TmrRun = time;
}


/**
	\fn  GetTimer( uint32_t &time )
	\brief Toma el valor al vuelo del timer en cuestion
 	\details Lee el timer al vuelo
 	\param [in] time referencia para cargar el valor del timer
 	\return void
*/
void Timer::GetTimer(uint32_t &time) const {

	time = m_TmrRun;

	switch (m_TmrBase) {

		case DEC:
			time /= DECIMAS;
			break;
		case SEG:
			time /= ( SEGUNDOS * DECIMAS );
			break;
		case MIN:
			time /= ( MINUTOS * SEGUNDOS * DECIMAS );
			break;
	}
}


/**
	\fn  StandByTimer( uint8_t accion )
	\brief Detiene/Arranca el timer, NO lo resetea
 	\details lo pone o lo saca de stand by
 	\param [in] accion RUN lo arranca, PAUSE lo pone en stand by
 	\return void
*/
void Timer::StandByTimer(const standby_t accion) {
	m_TmrStandBy = accion;
}


/**
	\fn void Timer_Stop( )
	\brief Detiene el timer
 	\return void
*/
void Timer::TimerStop() {
	m_TmrRun = 0;
	m_TmrEvent = false ;
	m_TmrHandler = nullptr ;
	m_TmrStandBy = 0 ;
	m_TmrBase = 0;
	return ;
}


/**
	\fn void SWhandler(void)
	\brief Decremento periodico del timer. Debe ser llamada periodicamente con la base de tiempos
	\return void
*/
void Timer::handlerDelPeriferico(void) {

	if(m_TmrRun) {
		if (!m_TmrStandBy) {
			m_TmrRun--;
			if(!m_TmrRun) {
				m_TmrEvent = true ;
			}
		}
	}
}

/**
	\fn bool operator==( uint32_t t , timer &T)
	\brief Sobrecarga de del operador de comparacion
	\details compara un valor numerico contra el flag de finalizacion del timer
 	\param [in] ev valor de comparacion (para verificar si vencio el timer)
	\param [in] ev valor de comparacion (para verificar si vencio el timer)

	\return bool: true por coincidencia, false por no coincidencia
*/

bool Timer::operator==(uint32_t t) {
	if( (uint32_t) m_TmrRun == t) {
		return  true;
	}
	return false;
}

// Como esta definida una sobrecarga con explicit hace falta definir
// la sobrecarga doble en el orden de los parametros
// porque se perdio la promocion automatica de tipos

/**
	\fn bool operator==( uint32_t t , timer &T )
	\brief Sobrecarga de del operador de comparacion
	\details compara un valor numerico contra el flag de finalizacion del timer
	\return bool: true por coincidencia, false por no coincidencia
*/
bool operator==(uint32_t t ,Timer &T) {
	if( (uint32_t) T.m_TmrEvent == t) {
		return  true;
	}
	return false;
}
/**
	\fn timer& timer::operator=( uint32_t t )
	\brief Sobrecarga de del operador de asignacion
	\param  [in] time: Valor a asignar a la variable de teporizacion
	\return una referencia al proopio objeto
*/
Timer& Timer::operator=(uint32_t time){

	switch (m_TmrBase)
	{
		case DEC:
			time *= DECIMAS;
			break;

		case SEG:
			time *= (SEGUNDOS * DECIMAS);
			break;

		case MIN:
			time *= (MINUTOS * SEGUNDOS * DECIMAS);
			break;
	}
	m_TmrRun = time;
	m_TmrEvent = 0 ;
	return *this;
}

/**
	\fn bool  operator!( )
	\brief Sobrecarga de del operador de negacion
	\return true por timer no vencido y false por vencido
*/
bool Timer::operator!(){
	return (m_TmrEvent == 1) ? m_TmrEvent = 0, 1 : 0;
}

/**
	\fn bool  operator bool ()
	\brief Sobrecarga de del operador de contenido
	\return true por timer vencido y false por no vencido
*/
Timer::operator bool (){
	 return !m_TmrEvent;
}

void Timer::TmrEvent() {
	if (m_TmrEvent) {
		 m_TmrEvent = 0;
		 m_TmrHandler();
	}
}

Timer::~Timer() {
}
