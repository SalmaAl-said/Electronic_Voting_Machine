 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.C
 *
 * Author: Salma Al-said
 *
 * created date : 10/9/2023
 *
 *******************************************************************************/

#include<avr/io.h>
#include"keypad.h"
#include"common_Macros.h"
#include"STD_Types.h"
#include"DIO.h"


/******************************************************************************
*                             FUNCTIONS IMPLEMENTATION                        *
******************************************************************************/


/*
 * Description :
 * Get the Keypad pressed button
 */
u8 KEYPAD_GetPressedKey( void )
{
	u8 row = 0 , col = 0 ;

	/* configure both of row and col pins as input */

	GPIO_SetupPinDirection( KEYPAD_ROW_PORT_ID , KEYPAD_ROW_PIN0_ID , INPUT ) ;
	GPIO_SetupPinDirection( KEYPAD_ROW_PORT_ID , KEYPAD_ROW_PIN1_ID , INPUT ) ;
	GPIO_SetupPinDirection( KEYPAD_ROW_PORT_ID , KEYPAD_ROW_PIN2_ID , INPUT ) ;
	GPIO_SetupPinDirection( KEYPAD_ROW_PORT_ID , KEYPAD_ROW_PIN3_ID , INPUT ) ;

	GPIO_SetupPinDirection( KEYPAD_COL_PORT_ID , KEYPAD_COL_PIN0_ID , INPUT ) ;
	GPIO_SetupPinDirection( KEYPAD_COL_PORT_ID , KEYPAD_COL_PIN1_ID , INPUT ) ;
	GPIO_SetupPinDirection( KEYPAD_COL_PORT_ID , KEYPAD_COL_PIN2_ID , INPUT ) ;
#if( KEYPAD_NUM_COLS == 4 )
	GPIO_SetupPinDirection( KEYPAD_COL_PORT_ID , KEYPAD_COL_PIN3_ID , INPUT ) ;
#endif

	while(1)
	{
		for ( row = 0 ; row < KEYPAD_NUM_ROWS ; row++)
		{
			GPIO_SetupPinDirection( KEYPAD_ROW_PORT_ID , KEYPAD_ROW_PIN0_ID+row , OUTPUT ) ;
			GPIO_WritePin( KEYPAD_ROW_PORT_ID , KEYPAD_ROW_PIN0_ID+row , KEYPAD_BUTTON_PRESSED ) ;

			for ( col = 0 ; col < KEYPAD_NUM_COLS ; col++ )
			{
				if ( GPIO_ReadPin( KEYPAD_COL_PORT_ID , KEYPAD_COL_PIN0_ID +col ) == KEYPAD_BUTTON_PRESSED )
				{
					return ( ( row * KEYPAD_NUM_COLS ) + col + 1 ) ;
				}
			}

			GPIO_SetupPinDirection( KEYPAD_ROW_PORT_ID , KEYPAD_ROW_PIN0_ID+row , INPUT ) ;

		}
	}




}

