/*
 * sai.c
 *
 *  Created on: Aug 4, 2025
 *      Author: prate
 */

#include "sai.h"
#include "stm32f4xx.h"
#include "stm32f446xx.h"

#define MASTER_TRANSMITTER (0U << 0)
#define MASTER_RECEIVER    (1U << 0)
#define SLAVE_TRANSMITTER  (2U << 0)
#define SLAVE_RECEIVER     (3U << 0)

#define DATA_SIZE_8  (0x2)
#define DATA_SIZE_10 (0x3)
#define DATA_SIZE_16 (0x4)
#define DATA_SIZE_20 (0x5)
#define DATA_SIZE_24 (0x6)
#define DATA_SIZE_32 (0x7)



void sai_mode_config(SAI_Block_TypeDef *sai, uint8_t mode){

	sai->CR1 &= ~SAI_xCR1_MODE_Msk;
	sai->CR1 |= (SAI_xCR1_MODE_Msk & (mode << SAI_xCR1_MODE_Pos));
}

void sai_master_tx_config(SAI_Block_TypeDef *sai){

	sai_mode_config(sai, MASTER_TRANSMITTER);
}

void sai_master_rx_config(SAI_Block_TypeDef *sai){

	sai_mode_config(sai, MASTER_RECEIVER);
}

void sai_slave_tx_config(SAI_Block_TypeDef *sai){

	//Write into the SAI_xDR (by software or by DMA)
	sai->DR |= 0x00;

	//Wait until the FIFO threshold (FLH) flag is different from 0b000 (FIFO empty)
	while(!(sai->SR & SAI_xSR_FLVL_Msk));

	sai_mode_config(sai, SLAVE_TRANSMITTER);
}

void sai_slave_rx_config(SAI_Block_TypeDef *sai){

	sai_mode_config(sai, SLAVE_RECEIVER);
}

void sai_audioblock_off(SAI_Block_TypeDef *sai){

	sai->CR1 &= ~SAI_xCR1_SAIEN;
	while(sai->CR1 & SAI_xCR1_SAIEN);
}

void sai_audioblock_on(SAI_Block_TypeDef *sai){

	if(!(sai->CR1 & SAI_xCR1_SAIEN)){

		sai->CR1 |= SAI_xCR1_SAIEN;
	}
}

void sai_datasize_config(SAI_Block_TypeDef *sai, uint8_t datasize){
	//***************Audio block should be disabled
	sai->CR1 |= ((datasize << SAI_xCR1_DS_Pos) & SAI_xCR1_DS_Msk);
}

void sai_8bit_config(SAI_Block_TypeDef *sai){

	sai_datasize_config(sai, DATA_SIZE_8);
}

void sai_10bit_config(SAI_Block_TypeDef *sai){

	sai_datasize_config(sai, DATA_SIZE_10);
}

void sai_16bit_config(SAI_Block_TypeDef *sai){

	sai_datasize_config(sai, DATA_SIZE_16);
}

void sai_20bit_config(SAI_Block_TypeDef *sai){

	sai_datasize_config(sai, DATA_SIZE_20);
}

void sai_24bit_config(SAI_Block_TypeDef *sai){

	sai_datasize_config(sai, DATA_SIZE_24);
}

void sai_32bit_config(SAI_Block_TypeDef *sai){

	sai_datasize_config(sai, DATA_SIZE_32);
}
