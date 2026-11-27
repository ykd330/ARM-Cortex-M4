// 여기에 사용자 임의의 define을 작성하시오

#define GPIOA_MODER (*((int *)0x4002 0000))		
#define GPIOA_OTYPER (*((int *)0x4002 0004))		
#define GPIOA_ODR (*((int *)0x4002 0014))
#define PA5 5



void Main(void)
{
	// LED GPA[5]를 출력(General Push Pull) 모드로 설정하시오

	GPIOA_MODER |= 1 << PA5 * 2
	GPIOA_OTYPER &= ~(1 << PA5)

	// GPA[5] LED를 ON 시키도록 설정하시오

	GPIOA_ODR |= 1 << PA5
}
