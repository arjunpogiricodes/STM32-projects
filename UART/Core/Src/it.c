/*
 * it.c
 *
 *  Created on: 15-May-2023
 *      Author: ARJUN POGIRI
 */
//#include "stm32f4xx_hal.h"
//void SysTick_Handler();

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}
