/*
 * main.c
 *
 *  Created on: 15-May-2023
 *      Author: ARJUN POGIRI
 */

#include "string.h"
#include "stm32f4xx_hal.h"
#include "main.h"
void Systemclockconfig();
void UART2_Init();
UART_HandleTypeDef huart2;
void Error_Handler();
char *user_data = "the application is running\r\n";


int main(void)
{
	HAL_Init();
	Systemclockconfig();
	UART2_Init();
	uint8_t rcvd_data;
	uint8_t data_buffer [100];
	uint32_t count=0;
	uint16_t  len_of_data=strlen(user_data);
	HAL_UART_Transmit(&huart2, (uint8_t*)user_data, len_of_data , HAL_MAX_DELAY);

	while(1)

    {
		 HAL_UART_Receive(&huart2,&rcvd_data, 1, HAL_MAX_DELAY);
		 if(rcvd_data=='\r')
		 {
			 break;
		 }
		 else
		 {
			 data_buffer[count++]=rcvd_data;
		 }

    }
	data_buffer[count++]='\r';
    HAL_UART_Transmit(&huart2, (uint8_t*)user_data, len_of_data , HAL_MAX_DELAY);


	return 0;

}





void UART2_Init(void)
{
	huart2.Instance=USART2;
	huart2.Init.BaudRate =115200;
	huart2.Init.WordLength=UART_WORDLENGTH_8B  ;
	huart2.Init.StopBits=UART_STOPBITS_1 ;
	huart2.Init.Parity=UART_PARITY_NONE  ;
	huart2.Init.HwFlowCtl =UART_HWCONTROL_NONE;
	huart2.Init.Mode=UART_MODE_TX_RX    ;
	HAL_UART_Init(&huart2);

	if (HAL_UART_Init(&huart2)!=HAL_OK )
	{
		Error_Handler();
	}

}

void Systemclockconfig(void)
{
__HAL_RCC_GPIOA_CLK_ENABLE();
__HAL_RCC_USART2_CLK_ENABLE();
}
void Error_Handler(void)
{
	while(1);

}
