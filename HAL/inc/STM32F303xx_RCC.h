#ifndef _STM32F3XX_RCC_H
#define	_STM32F3XX_RCC_H
/***
	Programmer: Alireza Tabatabaee, 2021, http://github.com/alireza-tabatabaee
	
	This file is the HAL RCC driver header. The register definitions & macros are defined 
	as well as the prototypes of functions.
***/
#include <stdint.h>		//has uint32_t and ... in it

// GPIO Register defintion struct
// The reason an struct is used is because it puts data structures right behind each other in memory
// All register values are "volatile" because they may change at any point of the program
typedef struct {
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBRSTR;
	volatile uint32_t CFGR2;
	volatile uint32_t CFGR3;
} RCC_TypeDef;

#define RCC				((RCC_TypeDef*)(RCC_BASEADDR))

#endif
