#ifndef _STM32F303XX_GPIO_H
#define	_STM32F303XX_GPIO_H
/***
	Programmer: Alireza Tabatabaee, 2021, http://github.com/alireza-tabatabaee
	
	This file is the HAL GPIO driver header. The register definitions & macros are defined 
	as well as the prototypes of functions.
***/
#include "stm32f303xx.h"
#include <stdint.h>		//has uint32_t and ... in it


// GPIO Register defintion struct
// The reason an struct is used is because it puts data structures right behind each other in memory
// All register values are "volatile" because they may change at any point of the program
typedef struct {
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;
	volatile uint32_t BRR;
} GPIO_RegDef;

// defining GPIO pointer structures. Now you can access with GPIOA->MODER
#define GPIOA (GPIO_RegDef*)(GPIOA_BASEADDR)
#define GPIOB (GPIO_RegDef*)(GPIOB_BASEADDR)
#define GPIOC (GPIO_RegDef*)(GPIOC_BASEADDR)
#define GPIOD (GPIO_RegDef*)(GPIOD_BASEADDR)
#define GPIOE (GPIO_RegDef*)(GPIOE_BASEADDR)
#define GPIOF (GPIO_RegDef*)(GPIOF_BASEADDR)

// macro for enabling GPIO clock. The AHB enable register of RCC does this.
#include "STM32F303xx_RCC.h"
#define GPIOA_CLK_ENABLE()	(RCC->AHBENR |= (1<<17))
#define GPIOB_CLK_ENABLE()	(RCC->AHBENR |= (1<<18))
#define GPIOC_CLK_ENABLE()	(RCC->AHBENR |= (1<<19))
#define GPIOD_CLK_ENABLE()	(RCC->AHBENR |= (1<<20))
#define GPIOE_CLK_ENABLE()	(RCC->AHBENR |= (1<<21))
#define GPIOF_CLK_ENABLE()	(RCC->AHBENR |= (1<<22))

// macro for resetting GPIOs. RCC's AHB reset register does this. It's set to 1, then back to 0.
#define GPIOA_RESET()				(do{ RCC->AHBRSTR |= (1<<17);  RCC->AHBRSTR &= ~(1<<17); }while(0))
#define GPIOB_RESET()				(do{ RCC->AHBRSTR |= (1<<18);  RCC->AHBRSTR &= ~(1<<18); }while(0))
#define GPIOC_RESET()				(do{ RCC->AHBRSTR |= (1<<19);  RCC->AHBRSTR &= ~(1<<19); }while(0))
#define GPIOD_RESET()				(do{ RCC->AHBRSTR |= (1<<20);  RCC->AHBRSTR &= ~(1<<20); }while(0))
#define GPIOE_RESET()				(do{ RCC->AHBRSTR |= (1<<21);  RCC->AHBRSTR &= ~(1<<21); }while(0))
#define GPIOF_RESET()				(do{ RCC->AHBRSTR |= (1<<22);  RCC->AHBRSTR &= ~(1<<22); }while(0))

// the function prototypes for the GPIO
void GPIO_InitPin(GPIO_RegDef*,uint16_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t);
uint8_t GPIO_ReadPin(GPIO_RegDef* GPIOx, uint16_t pinNum);
void GPIO_WritePin(GPIO_RegDef* GPIOx, uint16_t pinNum, uint8_t val);
void GPIO_WritePin(GPIO_RegDef* GPIOx, uint16_t pinNum, uint8_t val);
void GPIO_TogglePin(GPIO_RegDef* GPIOx, uint16_t pinNum);
uint16_t GPIO_ReadPort(GPIO_RegDef*);
void GPIO_WritePort(GPIO_RegDef* , uint16_t);

/* macros that make our life easier */
// GPIOx_MODER @GPIO_Modes
#define GPIO_MODE_INPUT		0
#define GPIO_MODE_OUTPUT	1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG	3
// GPIO_OTYPER
#define GPIO_TYPE_PUSHPULL	0
#define GPIO_TYPE_OPENDRAIN	1
// GPIOx_OSPEEDR
#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MED		1
#define GPIO_SPEED_HIGH		3
// GPIOx_PUPDR
#define GPIO_PULL_NONE		0
#define GPIO_PULLUP				1	
#define GPIO_PULLDOWN			2

#define GPIO_PIN_0				0x0001
#define GPIO_PIN_1				0x0002
#define GPIO_PIN_2				0x0004
#define GPIO_PIN_3				0x0008
#define GPIO_PIN_4				0x0010
#define GPIO_PIN_5				0x0020
#define GPIO_PIN_6				0x0040
#define GPIO_PIN_7				0x0080
#define GPIO_PIN_8				0x0100
#define GPIO_PIN_9				0x0200
#define GPIO_PIN_10				0x0400
#define GPIO_PIN_11				0x0800
#define GPIO_PIN_12				0x1000
#define GPIO_PIN_13				0x2000
#define GPIO_PIN_14				0x4000
#define GPIO_PIN_15				0x8000

#endif
