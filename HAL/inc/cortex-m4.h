#ifndef _CORTEXM4_H
#define _CORTEXM4_H
/***
	Programmer: Alireza Tabatabaee, 2021, http://github.com/alireza-tabatabaee
	
	This file is the processor specific file. It stores the values of CORTEX-M4 registers.
	This information was extracted from the Cortex-M4 generic user guide.
***/

#include <stdint.h>

#define NVIC_BASEADDR           0xE000E100U

typedef struct
{
  volatile  uint32_t ISER[8];               // Interrupt Set Enable Register 
						uint32_t RESERVED0[24];
  volatile  uint32_t ICER[8U];              //Interrupt Clear Enable Register
						uint32_t RSERVED1[24];
  volatile  uint32_t ISPR[8];               //Interrupt Set Pending Register 
						uint32_t RESERVED2[24];
  volatile  uint32_t ICPR[8];               //Interrupt Clear Pending Register 
						uint32_t RESERVED3[24];
  volatile  uint32_t IABR[8];           	   //Interrupt Active bit Register 
						uint32_t RESERVED4[56];
  volatile  uint8_t  IPR[240];               //Interrupt Priority Register (8 Bit)
						uint32_t RESERVED5[644];
  volatile  uint32_t STIR;                   //Software Trigger Interrupt Register
}  NVIC_RegDef;

#define NVIC				((NVIC_RegDef*)NVIC_BASEADDR)

#endif
