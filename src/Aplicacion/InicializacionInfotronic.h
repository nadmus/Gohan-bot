
#ifndef INICIALIZAR_H_
#define INICIALIZAR_H_

#include <list>
#include "Timer.h"
#include "Gpio.h"
#include "DigitalInputs.h"
#include "PerifericoTemporizado.h"
#include "SCTimer.h"
#include "PWM.h"

using namespace std;

extern list <PerifericoTemporizado*> g_ListaDePerifericos;

//extern Gpio LedAzul;
//extern Gpio LedVerde;
extern Gpio LedRojo;

extern Gpio Motor1;
extern Gpio Motor2;
extern Gpio Piston;
extern Gpio Led_heartbeat;

extern Timer Tm1;


extern Timer Tm2;


extern Timer Tp;

extern SCTimer sct;

extern PWM pwm;


//extern Gpio Pulsador;
extern DigitalInputs Pulsador;


void Inicializar_Infotronic (void);
void MyApp_SysTickCallback(void);


#endif /* INICIALIZAR_H_ */
