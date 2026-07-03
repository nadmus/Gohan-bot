#include "InicializacionInfotronic.h"
#include "systick.h"

list <PerifericoTemporizado*> g_ListaDePerifericos;

Timer Timer_Semaforo_Verde;
Timer Timer_Semaforo_Amarillo;
Timer Timer_Semaforo_Rojo;

//Gpio LedVerde(Gpio::PORT1, 0, Gpio::PUSHPULL, Gpio::OUTPUT, Gpio::LOW);/*P1_0  PIN 31*/
//Gpio LedAzul (Gpio::PORT1, 1, Gpio::PUSHPULL, Gpio::OUTPUT, Gpio::LOW);/*P1_1  PIN 30*/
Gpio LedRojo (Gpio::PORT1, 2, Gpio::PUSHPULL, Gpio::OUTPUT, Gpio::LOW);/*P1_2  PIN 29*/

//Gpio Motor1(Gpio::PORT1, 0, Gpio::PUSHPULL, Gpio::OUTPUT, Gpio::LOW);
//Gpio Motor2(Gpio::PORT1, 1, Gpio::PUSHPULL, Gpio::OUTPUT, Gpio::LOW);
//Gpio Piston(Gpio::PORT1, 2, Gpio::PUSHPULL, Gpio::OUTPUT, Gpio::LOW);

//Gpio Led_heartbeat(Gpio::port0, 17, Gpio::pushpull, Gpio::output, Gpio::HIGH);


Timer T2;

Timer Tm1;
Timer Tm2;;

Timer Tp;

SCTimer sct;

PWM pwm(sct, Pin::port0, 14, SCTimer::OUTPUT0);



//Gpio Pulsador (Gpio::PORT0, 4, Gpio::PULLUP, Gpio::INPUT, Gpio::LOW);/*P0_4  User switch*/
//DigitalInputs Pulsador(Gpio::PORT0, 4, Gpio::PULLUP, Gpio::LOW, 1000);

void MyApp_SysTickCallback (void) {

	for (PerifericoTemporizado* p : g_ListaDePerifericos) {
		p->handlerDelPeriferico();
	}
}

void Inicializar_Infotronic (void) {
	//Inic_Osc();
	Install_SysTickCallback(MyApp_SysTickCallback);
	Inicializar_Systick();
  //  LedVerde.ClrPin();
   // LedAzul.ClrPin( );
   // LedRojo.ClrPin( );

}


