/************************************************************************
 *	 File Name: IO_Challenge3.c											*
 * Description: choose led and select number of blinks using buttons	*
 *  Created on: Sep 20, 2018											*
 *      Author: Khalid Tarek											*
 ************************************************************************/

#include"LED_Blinking.h"

void main(){
	//PA0, PA1 are +, - to select led form 1 to 8
	//PA2, PA3 are +, - to select number of blinks off the led
	//PA4 to start
	char led=0,blinks=0,i;

	BUTTON_CTRL_PORT_DIR &=0xE0;	//Configure first 5 pins of Port A as input for 4 Push buttons and start
	LED_CTRL_PORT_DIR |=0xFF;	//Configure Port B as output for 8 LEDs
	SEG_CTRL_PORT_DIR |=0xFF;	//Configure Port B as output for 2 7-Segment

	BUTTON_CTRL_PORT_OUT |=0x1F;	//Enable internal pull up resistors for buttons
	LED_CTRL_PORT_OUT &=0x00;	//Initialize LEDs to OFF
	SEG_CTRL_PORT_OUT &=0x00;	//Initialize 7-segment to 0

	while(1){
		if(BIT_IS_CLEAR(BUTTON_CTRL_PORT_IN,PA0)){
			_delay_ms(DEBOUNCE_DELAY);
			//Second check due to switch bouncing
			if(BIT_IS_CLEAR(BUTTON_CTRL_PORT_IN,PA0))
			{
				//Increment LED number if it is not 7 and set to 7 if 7
				(led==7)?led=7:led++;
			}
			//Hold until button is not pressed
			while(BIT_IS_CLEAR(BUTTON_CTRL_PORT_IN,PA0)){}

		}else if(BIT_IS_CLEAR(BUTTON_CTRL_PORT_IN,PA1)){
			_delay_ms(DEBOUNCE_DELAY);
			//Second check due to switch bouncing
			if(BIT_IS_CLEAR(BUTTON_CTRL_PORT_IN,PA1))
			{
				//Decrement LED number if it is not 0 and set to 0 if 0
				(led==0)?led=0:led--;
			}
			//Hold until button is not pressed
			while(BIT_IS_CLEAR(BUTTON_CTRL_PORT_IN,PA1)){}

		}else if(BIT_IS_CLEAR(BUTTON_CTRL_PORT_IN,PA2)){
			_delay_ms(DEBOUNCE_DELAY);
			//Second check due to switch bouncing
			if(BIT_IS_CLEAR(BUTTON_CTRL_PORT_IN,PA2))
			{
				//Increment blinks number if it is not 9 and set to 9 if 9
				(blinks==9)?blinks=9:blinks++;
			}
			//Hold until button is not pressed
			while(BIT_IS_CLEAR(BUTTON_CTRL_PORT_IN,PA2)){}

		}else if(BIT_IS_CLEAR(BUTTON_CTRL_PORT_IN,PA3)){
			_delay_ms(DEBOUNCE_DELAY);
			//Second check due to switch bouncing
			if(BIT_IS_CLEAR(BUTTON_CTRL_PORT_IN,PA3))
			{
				//Decrement blinks number if it is not 0 and set to 0 if 0
				(blinks==0)?blinks=0:blinks--;
			}
			//Hold until button is not pressed
			while(BIT_IS_CLEAR(BUTTON_CTRL_PORT_IN,PA3)){}

		}else if(BIT_IS_CLEAR(BUTTON_CTRL_PORT_IN,PA4)){
			_delay_ms(DEBOUNCE_DELAY);
			//Second check due to switch bouncing
			if(BIT_IS_CLEAR(BUTTON_CTRL_PORT_IN,PA4))
			{
				//Loop to toggle led according to blinks
				for(i=0;i<2*blinks;i++){
					LED_CTRL_PORT_OUT ^= (1<<led); // Toggle LED
					_delay_ms(TOGGLE_DELAY);
				}
			}
			//Hold until button is not pressed
			while(BIT_IS_CLEAR(BUTTON_CTRL_PORT_IN,PA4)){}

		}
		SEG_CTRL_PORT_OUT = (SEG_CTRL_PORT_OUT & 0xF0) | (led & 0x0F);
		SEG_CTRL_PORT_OUT = (SEG_CTRL_PORT_OUT & 0x0F) | ((blinks & 0x0F)<<4);

	}
}
