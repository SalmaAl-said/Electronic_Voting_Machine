 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Author: Salma Al-said
 *
 * created date : 10/9/2023
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STD_Types.h"

/******************************************************************************
*                                Definitions                                  *
******************************************************************************/

#define STANDARD_KEYPAD

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_ROWS                   4
#define KEYPAD_NUM_COLS                   4

/* Keypad Port Configurations */
#define KEYPAD_ROW_PORT_ID                PORTB_ID
#define KEYPAD_ROW_PIN0_ID                PIN0_ID
#define KEYPAD_ROW_PIN1_ID                PIN1_ID
#define KEYPAD_ROW_PIN2_ID                PIN2_ID
#define KEYPAD_ROW_PIN3_ID                PIN3_ID

#define KEYPAD_COL_PORT_ID                PORTB_ID
#define KEYPAD_COL_PIN0_ID                PIN4_ID
#define KEYPAD_COL_PIN1_ID                PIN5_ID
#define KEYPAD_COL_PIN2_ID                PIN6_ID
#define KEYPAD_COL_PIN3_ID                PIN7_ID

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOW
#define KEYPAD_BUTTON_RELEASED           HIGH


/******************************************************************************
*                             FUNCTIONS PROTOTYPES                            *
******************************************************************************/

u8 KEYPAD_GetPressedKey( void ) ;


#endif /* KEYPAD_H_ */
