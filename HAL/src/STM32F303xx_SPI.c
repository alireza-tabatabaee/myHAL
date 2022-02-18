#include "STM32F303xx_SPI.h"

void SPI_Init(SPI_RegDef* SPIx, uint8_t dataSize, uint8_t masterOrSlave, uint8_t CPOL, uint8_t CPHA,
							uint8_t baudRate)
{
			// to be implemented, CRC functionality, Half duplex and Simplex modes, Slave select management
			SPIx->CR1 = ((dataSize>8)<<11) | (1<<6) | (baudRate<<3) | (masterOrSlave<<2) | (CPOL<<1) | CPHA;
			SPIx->CR2 = (dataSize-1)<<8;
}

void SPI_SendData(SPI_RegDef* SPIx, uint8_t* Buf, uint8_t Len)
{
		while(Len>0)
		{
				//1. wait until the TXE flag is set
				while(!(SPIx->SR & (1<<1)));
				//2. check DFF in CR1, 16 bit frame or 8 bit?
				if(SPIx->CR1 & (1<<11)) //16-bit
				{
					SPIx->DR = *((uint16_t*)Buf);
					Len -= 2;
					Buf += 2;
				}
				else //8-bit
				{
					SPIx->DR = *((uint8_t*)Buf);
					Len--;
					Buf++;
				}
		}
}