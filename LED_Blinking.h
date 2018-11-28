/************************************************
 *	 File Name: IO_Challenge3.h					*
 * Description: 								*
 *  Created on: Sep 20, 2018					*
 *      Author: Khalid Tarek					*
 ************************************************/
#ifndef IO_CHALLENGE3_H_
#define IO_CHALLENGE3_H_

#include"micro_config.h"
#include"std_types.h"
#include"common_macros.h"

#define BUTTON_CTRL_PORT_DIR DDRA
#define BUTTON_CTRL_PORT_IN PINA
#define BUTTON_CTRL_PORT_OUT PORTA

#define LED_CTRL_PORT_DIR DDRB
#define LED_CTRL_PORT_OUT PORTB

#define SEG_CTRL_PORT_DIR DDRC
#define SEG_CTRL_PORT_OUT PORTC

#define DEBOUNCE_DELAY 50
#define TOGGLE_DELAY 500


#endif /* IO_CHALLENGE3_H_ */
