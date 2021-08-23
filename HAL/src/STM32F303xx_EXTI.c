#include "../inc/STM32F303xx_EXTI.h"


void EXTI_Init(uint8_t Edge, GPIO_RegDef* GPIOx, uint16_t pinNum)
{
	// 1 - configuring Rising and Falling edge register in EXTI
	if(Edge==EXTI_RISING)
	{
		EXTI->RTSR1 |= (1<<pinNum);
		EXTI->FTSR1 &= ~(1<<pinNum);
	}
	else if(Edge==EXTI_FALLING)
	{
		EXTI->FTSR1 |= (1<<pinNum);
		EXTI->RTSR1 &= ~(1<<pinNum);
	}
	else
	{
		EXTI->RTSR1 |= (1<<pinNum);
		EXTI->FTSR1 |= (1<<pinNum);
	}
	
	// 2 - configuring the SYSCFG_EXTICRn, which denotes which port is it for each interrupt line.
	//     for example interrupt line 0 was PA0, PB0, or ...
	switch(pinNum)
	{
		case 0:
		case 1:
		case 2:
		case 3:
			SYSCFG->EXTICR1 = GPIO_TO_EXTICODE(GPIOx);
			break;
		case 4:
		case 5:
		case 6:
		case 7:
			SYSCFG->EXTICR2 = GPIO_TO_EXTICODE(GPIOx);
			break;
		case 8:
		case 9:
		case 10:
		case 11:
			SYSCFG->EXTICR3 = GPIO_TO_EXTICODE(GPIOx);
			break;
		default:
			SYSCFG->EXTICR4 = GPIO_TO_EXTICODE(GPIOx);
			break;
	}
	
	// 3 - Enabling in Interrupt Mask Register
	EXTI->IMR1 |= (1<<pinNum);
}

void NVIC_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t enable)
{
	switch(enable)
	{
		case 1:
			NVIC->ISER[IRQNumber>>5] |= (1<<IRQNumber);
			NVIC->IPR[IRQNumber>>2]  |= (IRQPriority<<((IRQNumber&3)*4));
		
			break;
		default: //disable
			NVIC->ICER[IRQNumber>>5] |= (1<<IRQNumber);
			break;
	}
}

void EXTI_Handling(uint8_t pinNum)
{
	if(EXTI->PR1 & (1<<pinNum))		//if pending bit set
		EXTI->PR1 |= (1<<pinNum);		//clear interrupt pending flag
}
