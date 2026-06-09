#include "inicializar.h"

//Frecuencia Principal 12MHz
//servo 500 1500 2500

int main(){

	SCTimer sct;
	PWM pwm(sct, Pin::port0, 14, SCTimer::OUTPUT0);
	pwm.SetPeriod(PWM::MILISEG, 0, 20);
	pwm.SetTon(PWM::MICROSEG, 2500);
	pwm.StartPWM();

	while(1)
	{

	}

}
