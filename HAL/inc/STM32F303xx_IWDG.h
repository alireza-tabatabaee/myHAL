#include "stm32f303xx.h"
#include <stdint.h>

typedef struct {
		volatile uint32_t KR;
		volatile uint32_t PR;
		volatile uint32_t RLR;
		volatile uint32_t SR;
		volatile uint32_t WINR;
} IWDG_RegDef;

//defining an instance of IWDG
#define IWDG		((IWDG_RegDef*)(IWDG_BASEADDR))

void IWDG_Init(uint8_t IWDG_prescaler, uint16_t IWDG_reloadval);
void IWDG_Refresh(void);

#define IWDG_PRESCALER4			0
#define IWDG_PRESCALER8			1
#define IWDG_PRESCALER16		2
#define IWDG_PRESCALER32		3
#define IWDG_PRESCALER64		4
#define IWDG_PRESCALER128		5
#define IWDG_PRESCALER256		6
#define IWDG_PRESCALER512		7
