/*
 * josotick.h
 *
 *  Created on: Nov 5, 2019
 *      Author: ITSRobocon 2020
 */

#ifndef JOYSTICK_H_
#define JOYSTICK_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"

extern char uart4_status;
extern char uart4_data;
extern char flag_uart4;

extern char joystick_select;
extern char joystick_start;
extern char joystick_l3;
extern char joystick_l2;
extern char joystick_l1;
extern char joystick_r3;
extern char joystick_r2;
extern char joystick_r1;
extern char joystick_bawah;
extern char joystick_kiri;
extern char joystick_atas;
extern char joystick_kanan;
extern char joystick_x;
extern char joystick_kotak;
extern char joystick_segitiga;
extern char joystick_bulat;
extern char joystick_analog;

extern short int joystick_x1_buffer;
extern short int joystick_x2_buffer; 
extern short int joystick_y1_buffer; 
extern short int joystick_y2_buffer;
extern short int joystick_x1;
extern short int joystick_x2;
extern short int joystick_y1;
extern short int joystick_y2;

extern char joystick_kirim[5];
extern char joystick_terima[9];
extern char joystick_terimaDefault[9];

extern short int joystick_status;

void joystick_tahap_1(void);
void joystick_tahap_2(void);

#ifdef __cplusplus
}
#endif

#endif /* JOYSTICK_H_ */
