#ifndef _STM32F303XX_H
#define	_STM32F303XX_H
/***
	Programmer: Alireza Tabatabaee, 2021, http://github.com/alireza-tabatabaee
	
	This file is the MCU-specific header file. It stores the values of the addresses
	of the memories, buses, and peripherals. This information was extracted from the
	"Memory Map" table in the reference manual of the microcontroller.
***/

#include "cortex-m4.h"	//processor-specific header file

// Base addresses of Flash and SRAM, U means unsigned
#define FLASH_BASEADDR			0x08000000U
#define SRAM_BASEADDR				0x20000000U
#define ROM_BASEADDR				

// Base addresses of Buses of MCU
#define APB1_BASEADDR				0x40000000U
#define APB2_BASEADDR				0x40010000U
#define AHB1_BASEADDR				0x40020000U
#define AHB2_BASEADDR				0x48000000U
#define AHB3_BASEADDR				0x50000000U

// Base addresses of peripherals on the APB1 bus. 
// Defined as base address + offset to make it easier to edit this file for other microcontrollers.
#define TIM2								(APB1_BASEADDR+0x0000U)
#define TIM3								(APB1_BASEADDR+0x0400U)
#define TIM4								(APB1_BASEADDR+0x0800U)
#define RESERVED_40000C00		(APB1_BASEADDR+0x0C00U)
#define TIM6								(APB1_BASEADDR+0x1000U)
#define TIM7								(APB1_BASEADDR+0x1400U)
#define RESERVED_40001800		(APB1_BASEADDR+0x1800U)
#define RTC									(APB1_BASEADDR+0x2800U)
#define WWDG								(APB1_BASEADDR+0x2C00U)
#define IWDG_BASEADDR				(APB1_BASEADDR+0x3000U)
#define I2S2ext							(APB1_BASEADDR+0x3400U)
#define SPI2_BASEADDR				(APB1_BASEADDR+0x3800U)
#define I2S2								(APB1_BASEADDR+0x3800U)
#define SPI3_BASEADDR				(APB1_BASEADDR+0x3C00U)
#define I2S3								(APB1_BASEADDR+0x3C00U)
#define I2S3ext							(APB1_BASEADDR+0x4000U)
#define USART2							(APB1_BASEADDR+0x4400U)
#define USART3							(APB1_BASEADDR+0x4800U)
#define UART4								(APB1_BASEADDR+0x4C00U)
#define UART5								(APB1_BASEADDR+0x5000U)
#define I2C1								(APB1_BASEADDR+0x5400U)
#define I2C2								(APB1_BASEADDR+0x5800U)
#define USB_FS							(APB1_BASEADDR+0x5C00U)
#define USB_SRAM						(APB1_BASEADDR+0x6000U)
#define bxCAN								(APB1_BASEADDR+0x6400U)
#define RESERVED_40006800		(APB1_BASEADDR+0x6800U)
#define RESERVED_40006C00		(APB1_BASEADDR+0x6C00U)
#define PWR									(APB1_BASEADDR+0x7000U)
#define DAC1								(APB1_BASEADDR+0x7400U)
#define RESERVED_40007800		(APB1_BASEADDR+0x7800U)

// Base addresses of peripherals on the APB2 bus.
#define SYSCFG_BASEADDR			(APB2_BASEADDR+0x0000U)
#define COMP								(APB2_BASEADDR+0x0000U)
#define OPAMP								(APB2_BASEADDR+0x0000U)
#define EXTI_BASEADDR				(APB2_BASEADDR+0x0400U)
#define RESERVED_40010800		(APB2_BASEADDR+0x0800U)
#define TIM1								(APB2_BASEADDR+0x2C00U)
#define SPI1_BASEADDR				(APB2_BASEADDR+0x3000U)
#define TIM8								(APB2_BASEADDR+0x3400U)
#define USART1							(APB2_BASEADDR+0x3800U)
#define RESERVED_40013C00		(APB2_BASEADDR+0x3C00U)
#define TIM15								(APB2_BASEADDR+0x4000U)
#define TIM16								(APB2_BASEADDR+0x4400U)
#define TIM17								(APB2_BASEADDR+0x4800U)

// Base addresses of peripherals on the AHB1 bus.
#define DMA1								(AHB1_BASEADDR+0x0000U)
#define DMA2								(AHB1_BASEADDR+0x0400U)
#define RESERVED_40020800		(AHB1_BASEADDR+0x0800U)
#define RCC_BASEADDR				(AHB1_BASEADDR+0x1000U)
#define RESERVED_40021400		(AHB1_BASEADDR+0x1400U)
#define FlashInterface			(AHB1_BASEADDR+0x2000U)
#define RESERVED_40022400		(AHB1_BASEADDR+0x2400U)
#define CRC									(AHB1_BASEADDR+0x3000U)
#define RESERVED_40023400		(AHB1_BASEADDR+0x3400U)
#define TSC									(AHB1_BASEADDR+0x4000U)
#define RESERVED_40024400		(AHB1_BASEADDR+0x4400U)

// Base addresses of peripherals on the AHB2 bus.
#define GPIOA_BASEADDR			(AHB2_BASEADDR+0x0000U)
#define GPIOB_BASEADDR			(AHB2_BASEADDR+0x0400U)
#define GPIOC_BASEADDR			(AHB2_BASEADDR+0x0800U)
#define GPIOD_BASEADDR			(AHB2_BASEADDR+0x0C00U)
#define GPIOE_BASEADDR			(AHB2_BASEADDR+0x1000U)
#define GPIOF_BASEADDR			(AHB2_BASEADDR+0x1400U)

// Base addresses of peripherals on the AHB3 bus.
#define ADC1								(AHB3_BASEADDR+0x0000U)
#define ADC2								(AHB3_BASEADDR+0x0000U)
#define ADC3								(AHB3_BASEADDR+0x0400U)
#define ADC4								(AHB3_BASEADDR+0x0400U)


// macros that improve the readability of the code
#define ENABLE							1
#define DISABLE							0

#endif
