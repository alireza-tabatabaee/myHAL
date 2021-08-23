#ifndef _STM32F303XX_EXTI_H
#define	_STM32F303XX_EXTI_H
/***
	Programmer: Alireza Tabatabaee, 2021, http://github.com/alireza-tabatabaee
	
	This file is the HAL EXTI driver header. The register definitions & macros are defined 
	as well as the prototypes of functions.
***/
#include "stm32f303xx.h"
#include <stdint.h>
typedef struct {
	volatile uint32_t IMR1;
	volatile uint32_t EMR1;
	volatile uint32_t RTSR1;
	volatile uint32_t FTSR1;
	volatile uint32_t SWIER1;
	volatile uint32_t PR1;
	volatile uint32_t IMR2;
	volatile uint32_t EMR2;
	volatile uint32_t EXTI_RTSR2;
	volatile uint32_t EXTI_FTSR2;
	volatile uint32_t SWIER2;
	volatile uint32_t PR2;
} EXTI_RegDef;

#define EXTI 			((EXTI_RegDef*)(EXTI_BASEADDR))

#define EXTI_RISING					0
#define EXTI_FALLING				1
#define	EXTI_RISINGFALLING	2

typedef struct {
	volatile uint32_t CFGR1;
	volatile uint32_t RCR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t CFGR2;
	volatile uint32_t RESERVED13[13];
	volatile uint32_t CFGR3;
} SYSCFG_RegDef;

#define SYSCFG	((SYSCFG_RegDef*)(SYSCFG_BASEADDR))	

#include "STM32F303xx_GPIO.h"

#define GPIO_TO_EXTICODE(G)		((G==GPIOA) ? 0 :\
															(G==GPIOB) ? 1 :\
															(G==GPIOC) ? 2 :\
															(G==GPIOD) ? 3 :\
															(G==GPIOE) ? 4 :\
															(G==GPIOF) ? 5 : 6)

#define IRQ_NUM_EXTI0				6
#define IRQ_NUM_EXTI1				7
#define IRQ_NUM_EXTI2				8
#define IRQ_NUM_EXTI3				9
#define IRQ_NUM_EXTI4				10
#define IRQ_NUM_EXTI5_9			23
#define IRQ_NUM_EXTI10_15		40

void EXTI_Init(uint8_t Edge, GPIO_RegDef* GPIOx, uint16_t pinNum);
void NVIC_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t enable);
void EXTI_Handling(uint8_t pinNum);


#endif
