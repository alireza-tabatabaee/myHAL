#include "STM32F303xx_IWDG.h"


//choose prescaler and reloadval in a manner that PR*RL = 8*time(ms) - 1
void IWDG_Init(uint8_t IWDG_prescaler, uint16_t IWDG_reloadval)
{
	// These five steps are documented in page 759 of the user manual
	// 1. Enable the IWDG by writing 0x0000 CCCC in the IWDG_KR register
	IWDG->KR = 0x0000CCCC;
	// 2. Enable register access by writing 0x0000 5555 in the IWDG_KR register.
	IWDG->KR = 0x00005555;
	// 3. Write the IWDG prescaler by programming IWDG_PR from 0 to 7
	IWDG->PR = IWDG_prescaler;
	// 4. Write the reload register (IWDG_RLR)
	IWDG->RLR = IWDG_reloadval;
	// 5. Wait for the registers to be updated (IWDG_SR = 0x0000 0000)
	while (IWDG->SR == 0);
}

void IWDG_Refresh()
{
	IWDG->KR = 0x0000AAAA;
}
