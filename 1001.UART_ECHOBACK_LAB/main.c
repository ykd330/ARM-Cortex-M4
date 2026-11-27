#include "device_driver.h"
#include <stdio.h>

static void Sys_Init(int baud) 
{
	SCB->CPACR |= (0x3 << 10*2)|(0x3 << 11*2); 
	Clock_Init();
	Uart2_Init(baud);
	setvbuf(stdout, NULL, _IONBF, 0);
	LED_Init();
}

#if 1

void Main(void)
{
	Sys_Init(115200);
	printf("UART2 TX Test\n");
	
	// A, B, C를 차례로 UART로 출력하는 코드 구현

}

#endif

#if 0

void Main(void)
{
	Sys_Init(115200);
	printf("\nUART2 Echo-Back Test\n");

	for(;;)
	{
		unsigned char x;

		// PC에서 받은 글자를 다시 되돌려 보내는 코드 구현

		
	}
}

#endif
