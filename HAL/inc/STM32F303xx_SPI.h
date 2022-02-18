#ifndef _STM32F303XX_GPIO_H
#define	_STM32F303XX_GPIO_H
#include <stdint.h>
#include "stm32f303xx.h"
/***
	Programmer: Alireza Tabatabaee, 2022, http://github.com/alireza-tabatabaee
	
	This file is the SPI GPIO driver header. The register definitions & macros are defined 
	as well as the prototypes of functions.
***/


// GPIO Register defintion struct
// The reason an struct is used is because it puts data structures right behind each other in memory
// All register values are "volatile" because they may change at any point of the program
typedef struct {
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;
} SPI_RegDef;

#define SPI1	(SPI_RegDef*)(SPI1_BASEADDR)	//APB2
#define SPI2	(SPI_RegDef*)(SPI2_BASEADDR)	//APB1
#define SPI3	(SPI_RegDef*)(SPI3_BASEADDR)	//APB1

// macro for enabling SPIs
#include "STM32F303xx_RCC.h"
#define SPI1_CLK_ENABLE()	(RCC->APB2ENR |= (1<<12))
#define SPI2_CLK_ENABLE()	(RCC->APB1ENR |= (1<<14))
#define SPI3_CLK_ENABLE()	(RCC->APB1ENR |= (1<<15))

// macro for resetting SPIs. RCC's AHB reset register does this. It's set to 1, then back to 0.
#define SPI1_RESET()				(do{ RCC->APB2RSTR |= (1<<12);  RCC->APB2RSTR &= ~(1<<12); }while(0))
#define SPI2_RESET()				(do{ RCC->APB1RSTR |= (1<<14);  RCC->APB1RSTR &= ~(1<<14); }while(0))
#define SPI3_RESET()				(do{ RCC->APB1RSTR |= (1<<15);  RCC->APB1RSTR &= ~(1<<15); }while(0))

//function prototypes
void SPI_Init(SPI_RegDef* SPIx, uint8_t dataSize, uint8_t masterOrSlave, uint8_t CPOL, uint8_t CPHA,
							uint8_t baudRate);

//useful macros
#define		SPI_MASTER	1
#define		SPI_SLAVE		0

#define 	SPI_BAUD_DIV2		0
#define		SPI_BAUD_DIV4		1
#define 	SPI_BAUD_DIV8		2
#define		SPI_BAUD_DIV16	3
#define 	SPI_BAUD_DIV32	4
#define		SPI_BAUD_DIV64	5
#define 	SPI_BAUD_DIV128	6
#define		SPI_BAUD_DIV256	7
#endif
