/*
 * motor_omni.c
 *
 *  Created on: Apr 11, 2022
 *      Author: adams
 */
#include "motor_omni.h"
#include "math.h"
#include "stdlib.h"

extern short int print_outputPWM[4];

float kp_kontrol_motor[4] =
{8 , 8 , 8 , 8 };
float ki_kontrol_motor[4] =
{0.1  , 0.1  , 0.1  , 0.1 };
float kd_kontrol_motor[4] =
{ 0, 0, 0, 0};

short int error_motor 			[4];
short int sum_error_motor 		[4];
short int previous_error_motor 	[4];

float proportional_motor		[4];
float integral_motor			[4];
float derivative_motor			[4];

float offsetRad;

float kineMatrix[4][3] = {
						 {    0.707,   -0.707,   -1},
						 {    -0.707,    -0.707,   -1},
						 {    -0.707,     0.707,   -1},
						 {    0.707,    0.707,   -1},
						 };

void MotorWheelsSP(short int motor_speed_target[4], short int localSpeedVector[3])
{

	for(int l = 0; l < 4; l++){
		motor_speed_target[l] = 0;
	}

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 3; j++){
			motor_speed_target[i] += kineMatrix[i][j] * localSpeedVector[j];
		}
	}
//	motor_omni_set_pwm(global_motor_speed_target);

}

void motor_omni_kontrol(short int output_motor[4], short int motor_speed_target[4], short int motor_speed[4])
{
	for (int i = 0; i < 4; i++)
	{
		error_motor			[i] = motor_speed_target [i] - motor_speed [i];
			 //diberi batas
			if (error_motor[i] > 499)
				error_motor[i] = 499;
			else if (error_motor[i]< -499)
				error_motor[i] = -499;
		sum_error_motor 	[i] += error_motor[i];
			//diberi batas
		if (integral_motor [i] > 200 ) integral_motor [i] = 200 ;
		if (integral_motor [i] < -200 ) integral_motor [i] = -200 ;

		if (motor_speed_target [i] == 0 ) {
			integral_motor [i] = 0 ;
			sum_error_motor[i] = 0 ;
		}

		proportional_motor 	[i] = kp_kontrol_motor [i]*error_motor[i];
		integral_motor 		[i] = ki_kontrol_motor [i]*sum_error_motor[i];
		derivative_motor 	[i] = kd_kontrol_motor [i]*(motor_speed[i] - previous_error_motor [i]);

		previous_error_motor[i] = motor_speed [i];

		output_motor		[i] = (short int )(proportional_motor [i] + integral_motor [i] + derivative_motor [i]);

			if(output_motor[i]>499)
				output_motor[i]=499;
			else if(output_motor[i]<-499)
				output_motor[i]=-499;
//
//		if(joystick_analog)
//				{
//					sum_error_motor[i] = 0; previous_error_motor[i] = 0; output_motor[i] = 0;
//				}
	}

	motor_omni_set_pwm(output_motor); //nilai pid dimasukan ke set pwm
	for(int i=0;i<4;i++){
		print_outputPWM [i] = output_motor[i];
	}
}


//////////////////////
//buat set pwm motor omni
/////////////////////
void motor_omni_set_pwm(short int outputPWM[4])
{
    //motor omni 0
    if (outputPWM[0] < 0)
        {
    		HAL_GPIO_WritePin(portDir1Motor0_GPIO_Port, portDir1Motor0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(portDir2Motor0_GPIO_Port, portDir2Motor0_Pin, GPIO_PIN_RESET);
        }
    else if (outputPWM[0] > 0)
        {
            HAL_GPIO_WritePin(portDir1Motor0_GPIO_Port, portDir1Motor0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(portDir2Motor0_GPIO_Port, portDir2Motor0_Pin, GPIO_PIN_SET);
        }
    //motor omni 1
    if (outputPWM[1] > 0)
        {
            HAL_GPIO_WritePin(portDir1Motor1_GPIO_Port, portDir1Motor1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(portDir2Motor1_GPIO_Port, portDir2Motor1_Pin, GPIO_PIN_SET);
        }
    else if (outputPWM[1] < 0)
        {
            HAL_GPIO_WritePin(portDir1Motor1_GPIO_Port, portDir1Motor1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(portDir2Motor1_GPIO_Port, portDir2Motor1_Pin, GPIO_PIN_RESET);
        }
    //motor omni 2
    if (outputPWM[2] > 0)
        {
            HAL_GPIO_WritePin(portDir1Motor2_GPIO_Port, portDir1Motor2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(portDir2Motor2_GPIO_Port, portDir2Motor2_Pin, GPIO_PIN_SET);
        }
    else if (outputPWM[2] < 0)
        {
            HAL_GPIO_WritePin(portDir1Motor2_GPIO_Port, portDir1Motor2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(portDir2Motor2_GPIO_Port, portDir2Motor2_Pin, GPIO_PIN_RESET);
        }
    //motor omni 3
    if (outputPWM[3] < 0)
        {
            HAL_GPIO_WritePin(portDir1Motor3_GPIO_Port, portDir1Motor3_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(portDir2Motor3_GPIO_Port, portDir2Motor3_Pin, GPIO_PIN_RESET);
        }
    else if (outputPWM[3] > 0)
        {
            HAL_GPIO_WritePin(portDir1Motor3_GPIO_Port, portDir1Motor3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(portDir2Motor3_GPIO_Port, portDir2Motor3_Pin, GPIO_PIN_SET);
        }

    //set timer
    TIM11->CCR1 = abs(outputPWM[0]);
    TIM13->CCR1 = abs(outputPWM[1]);
    TIM14->CCR1 = abs(outputPWM[2]);
    TIM9->CCR2 = abs(outputPWM[3]);
}


