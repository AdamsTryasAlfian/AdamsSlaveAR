/*
 * buzzer.c
 *
 *  Created on: Oct 30, 2019
 *      Author: itsrobocon
 */

#include "buzzer.h"
#include "main.h"

char buzzerStatus = 0;
short int buzzerIteration = 0, buzzerTime = 0, buzzerNumber = 0;

uint8_t prescCounterMotor = 0;
unsigned int VmaxCounter, VminCounter;


uint8_t onOffTimer = 0;
uint16_t timerCounter = 0;

void BuzzerBuzz(int time, int number){

	buzzerStatus = 1;
	buzzerIteration = 0;
	buzzerTime = time;
	buzzerNumber = number * 2;
}

void BuzzerRoutine(void){

	if(buzzerStatus == SET && buzzerNumber != 0)
	{
		//GPIO_ResetBits(GPIOD, GPIO_Pin_0);
		HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin,GPIO_PIN_SET);
		if(buzzerIteration++ == buzzerTime){
			buzzerIteration = 0;
			buzzerStatus = RESET;
			buzzerNumber--;
		}
	}
	else if(buzzerStatus == RESET && buzzerNumber != 0)
	{
		//GPIO_SetBits(GPIOD, GPIO_Pin_0);
		HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin,GPIO_PIN_RESET);
		if(buzzerIteration++ == buzzerTime){
			buzzerIteration = 0;
			buzzerStatus = SET;
			buzzerNumber--;
		}
	}
}
