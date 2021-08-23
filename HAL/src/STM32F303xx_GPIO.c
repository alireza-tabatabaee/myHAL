#include "../inc/STM32F303xx_GPIO.h"

/*
** 	GPIO_Init	: Initializes a GPIO pin
** 	Inputs 		: GPIOx:	GPIOA, GPIOB, ...
**							pinNum: 0 to 15
**							mode:		@GPIO_Modes
**							type:		@GPIO_Types
**							speed:
**							pullupPulldown @GPIO_Pull
**
*/
void GPIO_InitPin(GPIO_RegDef* GPIOx, uint16_t pinNum, uint8_t mode, uint8_t type,
								uint8_t speed, uint8_t pullUpPullDown,	uint8_t altFunc)
{
	GPIOx->MODER &= ~(3<<pinNum);				//clear mode reg, 3 is 0b11 shifted because the value field to be cleard is 2 bits
	GPIOx->MODER |= (mode<<(2*pinNum));	//set mode reg
	
	GPIOx->OTYPER &= ~(1<<pinNum);
	GPIOx->OTYPER |= (type << pinNum);
	
	GPIOx->OSPEEDR &= ~(3 << pinNum);
	GPIOx->OSPEEDR |= (speed <<(2*pinNum));
	
	GPIOx->PUPDR &=  ~(3<<pinNum);
	GPIOx->PUPDR |= (pullUpPullDown<<(2*pinNum));
	if(mode==GPIO_MODE_ALTFN)
	{
		if(pinNum<8)
		{
			GPIOx->AFRL &= ~(0xF<<(4*pinNum));
			GPIOx->AFRL |= (altFunc<<(4*pinNum));
		}
		else
		{
			GPIOx->AFRH &= ~(0xF<<(4*(pinNum-8)));
			GPIOx->AFRH |= (altFunc<<(4*(pinNum-8)));
		}
	}
}

uint8_t GPIO_ReadPin(GPIO_RegDef* GPIOx, uint16_t pinNum)
{
	return (GPIOx->IDR >> pinNum) & 1;		//pick up the pinNumth bit from Input Data Register
}

void GPIO_WritePin(GPIO_RegDef* GPIOx, uint16_t pinNum, uint8_t val)
{
	if(val==1)
		GPIOx->BSRR |= (1<<pinNum);
	else
		GPIOx->BRR |= (1<<pinNum);	
}

void GPIO_TogglePin(GPIO_RegDef* GPIOx, uint16_t pinNum)
{
	GPIOx->ODR ^= (1<<pinNum);
}

uint16_t GPIO_ReadPort(GPIO_RegDef* GPIOx)
{
	return GPIOx->IDR;
}

void GPIO_WritePort(GPIO_RegDef* GPIOx, uint16_t value)
{
	GPIOx->ODR = value;
}
