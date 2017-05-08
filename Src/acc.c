/*
 * acc.c
 *
 *  Created on: 02.05.2017
 *      Author: mickl
 */

#include "acc.h"


uint8_t read_register(SPI_HandleTypeDef* hspi, uint8_t address){
	uint8_t data;

	address |=0x80;
	HAL_SPI_Transmit(hspi, &address, 1, 200);
	HAL_SPI_Receive(hspi, &data, 1, 200);

	return data;
}

void write_register(SPI_HandleTypeDef* hspi, uint8_t address, uint8_t data){
	HAL_SPI_Transmit(hspi, &address, 1, 200);
	HAL_SPI_Transmit(hspi, &data, 1, 200);
}
