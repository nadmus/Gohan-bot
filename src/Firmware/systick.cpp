
#include "systick.h"

volatile void (*pf_SysTickCallback)(void) = nullptr ;

void Install_SysTickCallback (void (*MyCallback)(void)) {
  if(MyCallback != nullptr) {
	pf_SysTickCallback= (volatile void (*)(void) ) MyCallback;
  }
}

void SysTick_Handler(void) {
  if (pf_SysTickCallback) {
	pf_SysTickCallback();
  }
}

void Inicializar_Systick () {
	SysTick->RELOAD = 11999;
	SysTick->CURR = 0;
	SysTick->CTRL = 7;}
