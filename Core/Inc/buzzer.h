/*
 * buzzer.h
 *
 *  Created on: Oct 30, 2019
 *      Author: itsrobocon
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f4xx_hal.h"

void BuzzerBuzz(int time, int number);
void BuzzerRoutine(void);


#ifdef __cplusplus
}
#endif

#endif /* BUZZER_H_ */
