/*
 * joystick.c
 *
 *  Created on: Nov 5, 2019
 *      Author: ITSRobocon 2020
 */

#include "joystick.h"
 
char uart4_status = 0;
char uart4_data;
char flag_uart4 = 0;

short  joystick_status =0;

char joystick_select = 1;
char joystick_start = 1;
char joystick_l3 = 1;
char joystick_l2 = 1;
char joystick_l1 = 1;
char joystick_r3 = 1;
char joystick_r2 = 1;
char joystick_r1 = 1;
char joystick_bawah = 1;
char joystick_kiri = 1;
char joystick_atas = 1;
char joystick_kanan = 1;
char joystick_x = 1;
char joystick_kotak = 1;
char joystick_segitiga = 1;
char joystick_bulat = 1;
char joystick_analog = 1;

char joystick_getar_status = 0;

short int joystick_x1_buffer;
short int joystick_x2_buffer; 
short int joystick_y1_buffer; 
short int joystick_y2_buffer;
short int joystick_x1;
short int joystick_x2;
short int joystick_y1;
short int joystick_y2;

short int joystick_getar_iterasi = 0;
short int joystick_getar_waktu = 0;
short int joystick_getar_jumlah = 0;

short int delay_joystick_r3 = 0;
short int delat_joystick_l3 = 0;

char joystick_kirim[5] = {'i','t','s'};
char joystick_terima[9] = {'i', 't', 's', 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
char joystick_terimaDefault[9] = {'i', 't', 's', 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

void joystick_tahap_1(void)
{
    joystick_select = (joystick_terima[3] & 0x01) >> 0;
	joystick_l3 = (joystick_terima[3] & 0x02) >> 1;
	joystick_r3 = (joystick_terima[3] & 0x04) >> 2;
	joystick_start = (joystick_terima[3] & 0x08) >> 3;
	joystick_atas = (joystick_terima[3] & 0x10) >> 4;
	joystick_kanan = (joystick_terima[3] & 0x20) >> 5;
	joystick_bawah = (joystick_terima[3] & 0x40) >> 6;
	joystick_kiri = (joystick_terima[3] & 0x80) >> 7;
	joystick_l2 = (joystick_terima[4] & 0x01) >> 0;
	joystick_r2 = (joystick_terima[4] & 0x02) >> 1;
	joystick_l1 = (joystick_terima[4] & 0x04) >> 2;
	joystick_r1 = (joystick_terima[4] & 0x08) >> 3;
	joystick_segitiga = (joystick_terima[4] & 0x10) >> 4;
	joystick_bulat = (joystick_terima[4] & 0x20) >> 5;
	joystick_x = (joystick_terima[4] & 0x40) >> 6;
	joystick_kotak = (joystick_terima[4] & 0x80) >> 7;

	if(joystick_terima[5] == 255 && joystick_terima[6] == 255 && joystick_terima[7] == 255 && joystick_terima[8] == 255)
		joystick_analog = 1;
	else
		joystick_analog = 0;
}

void joystick_tahap_2(void)
{
     short int deadzone_min[4] = {-25, -25, -25, -25};
	 short int deadzone_max[4] = {25, 25, 25, 25};

	joystick_x1_buffer = joystick_terima[7] - 127;
	joystick_y1_buffer = 127 - joystick_terima[8];
	joystick_x2_buffer = joystick_terima[5] - 127;
	joystick_y2_buffer = 127 - joystick_terima[6];

	if(joystick_analog == 0)
	{
		if(joystick_x1_buffer > deadzone_min[0] && joystick_x1_buffer < deadzone_max[0])joystick_x1 = 0;
		else if(joystick_x1_buffer < deadzone_min[0])joystick_x1 = (int)((float)(joystick_x1_buffer - deadzone_min[0]) / (float)(-127 - deadzone_min[0]) * -127);
		else if(joystick_x1_buffer > deadzone_max[0])joystick_x1 = (int)((float)(joystick_x1_buffer - deadzone_max[0]) / (float)(127 - deadzone_max[0]) * 127);

		if(joystick_y1_buffer > deadzone_min[1] && joystick_y1_buffer < deadzone_max[1])joystick_y1 = 0;
		else if(joystick_y1_buffer < deadzone_min[1])joystick_y1 = (int)((float)(joystick_y1_buffer - deadzone_min[1]) / (float)(-127 - deadzone_min[1]) * -127);
		else if(joystick_y1_buffer > deadzone_max[1])joystick_y1 = (int)((float)(joystick_y1_buffer - deadzone_max[1]) / (float)(127 - deadzone_max[1]) * 127);

		if(joystick_x2_buffer > deadzone_min[2] && joystick_x2_buffer < deadzone_max[2])joystick_x2 = 0;
		else if(joystick_x2_buffer < deadzone_min[2])joystick_x2 = (int)((float)(joystick_x2_buffer - deadzone_min[2]) / (float)(-127 - deadzone_min[2]) * -127);
		else if(joystick_x2_buffer > deadzone_max[2])joystick_x2 = (int)((float)(joystick_x2_buffer - deadzone_max[2]) / (float)(127 - deadzone_max[2]) * 127);

		if(joystick_y2_buffer > deadzone_min[3] && joystick_y2_buffer < deadzone_max[3])joystick_y2 = 0;
		else if(joystick_y2_buffer < deadzone_min[3])joystick_y2 = (int)((float)(joystick_y2_buffer - deadzone_min[3]) / (float)(-127 - deadzone_min[3]) * -127);
		else if(joystick_y2_buffer > deadzone_max[3])joystick_y2 = (int)((float)(joystick_y2_buffer - deadzone_max[3]) / (float)(127 - deadzone_max[3]) * 127);
	}
	else
	{
		joystick_x1 = 0;
		joystick_y1 = 0;
		joystick_x2 = 0;
		joystick_y2 = 0;
	}
}

