/*******************************************************************************************************************************//**
 *
 * @file		timers.h
 * @brief		Clase para creacion de temporizadores
 * @date		4 may. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

#ifndef TIMER_H
#define TIMER_H

#include "tipos.h"
#include "PerifericoTemporizado.h"

typedef void (*Timer_Handler)(void);


class Timer : public PerifericoTemporizado {
	protected:
		volatile uint32_t 	m_TmrRun;
		volatile bool  		m_TmrEvent;
		void   				(*m_TmrHandler) (void);
		volatile bool  		m_TmrStandBy ;
		volatile uint8_t  	m_TmrBase;
	public:
		enum 		bases_t 			{DEC ,SEG ,MIN};
		enum 		ticks_t 			{DECIMAS=100, SEGUNDOS=10, MINUTOS=60};
		enum 		erroresTimers_t 	{errorTimer, OKtimers};
		enum 		standby_t 			{RUN, PAUSE};

		Timer() ;
		Timer(const Timer_Handler handler, const bases_t base);

		void 		TimerStart(uint32_t time, const Timer_Handler handler, const bases_t base);
		void 		SetTimer(uint32_t time);
		void 		GetTimer(uint32_t &time) const;
		void 		StandByTimer(const standby_t accion);
		void 		TimerStop();
		void  		SetmrStandBy(uint8_t accion) {m_TmrStandBy = accion ;}
		void 		TimerStart(uint32_t time);
		void 		TmrEvent();

		Timer& 		operator=(uint32_t t);
		bool 		operator!();
		bool 		operator==(uint32_t t);

		friend bool operator==(uint32_t t ,Timer &T);

		// por el hecho de haber convertido el operador bool como explicit
		// me obligo a realizar las funciones amigas del operador==
		// con sus dos prototipos, porque dejo de aceptar
		// la promocion automatica de tipos
		explicit 	operator bool();

		void 		handlerDelPeriferico();

		virtual 	~Timer();
};

#endif /* TIMER_H */
