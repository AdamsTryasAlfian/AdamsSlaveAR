/*
 * motor_omni.h
 *
 *  Created on: Nov 14, 2019
 *      Author: ITSRobocon 2020
 */

#ifndef MOTOR_OMNI_H_
#define MOTOR_OMNI_H_


#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"


short int enc_omni			[4];
short int Motor_Speed_Target	[4];
short int Motor_Omni_PWM		[4];
int motor_omni_speed_kontrol [4];
extern short int  motor_speed_target_1[4];
short int  motor_speed_target[4];
int global_motor_speed_target[4];
//int motor_speed_target;

void motor_omni_set_pwm(short int outputPWM[4]);
void motor_omni_kontrol(short int output_motor[4], short int motor_speed_target[4], short int motor_speed[4]);
void motor_omni_kinematik(int kecepatan_omni_kine[3]);
void motor_omni_kinematik1(int kecepatan_x, int kecepatan_y, int kecepatan_sudut);
void MotorWheelsSP(short int motor_speed_target[4], short int localSpeedVector[3]);
void MotorLocalSpeed(int localSpeedVector[3], int globalSpeedVector[3], float thetaRad);



#ifdef __cplusplus
}
#endif


#endif /* MOTOR_OMNI_H_ */
