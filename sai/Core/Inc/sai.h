/*
 * sai.h
 *
 *  Created on: Aug 4, 2025
 *      Author: prate
 */

#ifndef INC_SAI_H_
#define INC_SAI_H_

void sai_mode_config(SAI_Block_TypeDef *sai, uint8_t mode);
void sai_audioblock_off(SAI_Block_TypeDef *sai);
void sai_audioblock_on(SAI_Block_TypeDef *sai);
void sai_datasize_config(SAI_Block_TypeDef *sai, uint8_t datasize);

//Wrap Around Functions
void sai_master_tx_config(SAI_Block_TypeDef *sai);
void sai_master_rx_config(SAI_Block_TypeDef *sai);
void sai_slave_tx_config(SAI_Block_TypeDef *sai);
void sai_slave_rx_config(SAI_Block_TypeDef *sai);

void sai_8bit_config(SAI_Block_TypeDef *sai);
void sai_10bit_config(SAI_Block_TypeDef *sai);
void sai_16bit_config(SAI_Block_TypeDef *sai);
void sai_20bit_config(SAI_Block_TypeDef *sai);
void sai_24bit_config(SAI_Block_TypeDef *sai);
void sai_32bit_config(SAI_Block_TypeDef *sai);


#endif /* INC_SAI_H_ */
