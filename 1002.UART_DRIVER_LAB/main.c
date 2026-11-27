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

void Main(void)
{
	Sys_Init(115200);
	printf("\nUART1 Driver Test\n");

	Uart1_Init(115200);

	volatile int i;
	char x = 'A', y;

	printf("Uart1_Send_Byte, Uart1_Get_Char Test\n");

	for(i=0; i<10; i++)
	{
		Uart1_Send_Byte(x++);
		printf("*");
		y = Uart1_Get_Char();
		printf("y = %c\n", y);
	}

	printf("Uart1_Send_Byte, Uart1_Get_Pressed Test\n");
	printf("스위치를 누를때마다 글자 송, 수신 진행\n");

	Key_Poll_Init();

	int led = 0;
	int cnt = 0;
	
	x = 'A';

	for(;;)
	{
		if(Key_Get_Pressed() != 0)
		{
			Uart1_Send_Byte(x++);
			Key_Wait_Key_Released();
			if(cnt++ > 10) break;
		}
		
		if((y = Uart1_Get_Pressed()) != 0)
		{
			printf("[%d] %c\n", cnt, y);
		}
		else
		{
			LED_Display(led ^= 0x1);
			for(i=0; i<0x200000; i++);
		}
	}
}
