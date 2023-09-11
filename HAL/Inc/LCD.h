 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Author: Salma Al-said
 *
 * created date : 9/9/2023
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "STD_Types.h"
#include "DIO.h"


/******************************************************************************
*                                Definitions                                  *
******************************************************************************/

#define LCD_BIT_MODE				   4

/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 PORTA_ID
#define LCD_RS_PIN_ID                  PIN1_ID

#define LCD_E_PORT_ID                  PORTA_ID
#define LCD_E_PIN_ID                   PIN2_ID

#if(LCD_BIT_MODE==4)
#define LCD_DATA_PORT_ID               PORTA_ID
#define LCD_DATA_PIN0_ID			   PIN3_ID
#define LCD_DATA_PIN1_ID			   PIN4_ID
#define LCD_DATA_PIN2_ID			   PIN5_ID
#define LCD_DATA_PIN3_ID			   PIN6_ID

#elif(LCD_BIT_MODE==8)
#define LCD_DATA_PORT_ID               PORTC_ID
#endif
/* LCD Commands */
#define LCD_CLEAR_SCREEN               		 0x01
#define LCD_GO_TO_HOME                 		 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  		 0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   		 0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                 		 0x0C
#define LCD_CURSOR_ON                  		 0x0E
#define LCD_SET_CURSOR_LOCATION_FIRST_LINE   0x80
#define LCD_SET_CURSOR_LOCATION_SECOND_LINE  0xC0



/******************************************************************************
*                             FUNCTIONS PROTOTYPES                            *
******************************************************************************/

void LCD_Init(void) ;

void LCD_SendCommand( u8 command );

void LCD_DisplayCharacter( u8 data ) ;

void LCD_DisplayString( const char *str ) ;

void LCD_IntegerToString( int data ) ;

void LCD_MoveCursor( u8 row , u8 column ) ;

void LCD_DisplayStringRowColumn( u8 row , u8 col , const char *Str ) ;

void LCD_ClearScreen( ) ;







#endif /* LCD_H_ */
