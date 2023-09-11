 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Author: Salma Al-said
 *
 * created date : 9/9/2023
 *
 *******************************************************************************/


#include<avr/io.h>
#include<util/delay.h>
#include"common_Macros.h"
#include"LCD.h"



/******************************************************************************
*                             FUNCTIONS IMPLEMENTATION                        *
******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the DIO driver.
 * 2. Setup the LCD Data Mode
 */
void LCD_Init(void)
{

	/* Configure the Enable and RS as output ports */
	GPIO_SetupPinDirection( LCD_RS_PORT_ID , LCD_RS_PIN_ID , OUTPUT );
	GPIO_SetupPinDirection( LCD_E_PORT_ID , LCD_E_PIN_ID , OUTPUT );

#if( LCD_BIT_MODE == 8 )

	/*  Configure the data port as output port */
	GPIO_SetupPortDirection( LCD_DATA_PORT_ID , 0xff ) ;
	_delay_ms(20);

	/* send command with mode 8 */
	LCD_SendCommand( LCD_TWO_LINES_EIGHT_BITS_MODE );

#elif(LCD_BIT_MODE == 4)

	/* Configure the data pins as output port */
	GPIO_SetupPinDirection( LCD_DATA_PORT_ID , LCD_DATA_PIN0_ID , OUTPUT ) ;
	GPIO_SetupPinDirection( LCD_DATA_PORT_ID , LCD_DATA_PIN1_ID , OUTPUT ) ;
	GPIO_SetupPinDirection( LCD_DATA_PORT_ID , LCD_DATA_PIN2_ID , OUTPUT ) ;
	GPIO_SetupPinDirection( LCD_DATA_PORT_ID , LCD_DATA_PIN3_ID , OUTPUT ) ;

	_delay_ms(20);

	/* send command with mode 4 */
	LCD_SendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_SendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);
	LCD_SendCommand( LCD_TWO_LINES_FOUR_BITS_MODE );

#endif

	/* send command cursor off */
	LCD_SendCommand( LCD_CURSOR_OFF );

	/* send command clear screen */
	LCD_SendCommand( LCD_CLEAR_SCREEN );

}






/*
 * Description :
 * Send the required command to the screen
 */
void LCD_SendCommand(u8 command)
{
	/* - Clear RS pin */
	GPIO_WritePin( LCD_RS_PORT_ID  , LCD_RS_PIN_ID , LOW ) ;

	/* - delay */
	_delay_us(1);

	/* - set enable */
	GPIO_WritePin( LCD_E_PORT_ID , LCD_E_PIN_ID , HIGH );

	/* - delay  */
	_delay_us(1);

#if (LCD_BIT_MODE == 8 )

	/* - send our command */
	GPIO_WritePort( LCD_DATA_PORT_ID , command );

	/* - delay  */
	_delay_us(1);

#elif ( LCD_BIT_MODE == 4 )

		/*  send the 4 MSBs of command*/
	    GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN0_ID , GET_BIT(command,4) );
		GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN1_ID , GET_BIT(command,5) );
		GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN2_ID , GET_BIT(command,6) );
		GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN3_ID , GET_BIT(command,7) );

		/*  delay */
		_delay_us(1);

		/*  clear enable */
		GPIO_WritePin ( LCD_E_PORT_ID , LCD_E_PIN_ID , LOW );

		/*  delay */
		_delay_us(1);

		/*  set enable */
		GPIO_WritePin ( LCD_E_PORT_ID , LCD_E_PIN_ID , HIGH );

		/*  delay */
		_delay_us(1);

		/*  send the 4 LSBs of command*/
		GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN0_ID , GET_BIT(command,0) );
		GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN1_ID , GET_BIT(command,1) );
		GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN2_ID , GET_BIT(command,2) );
		GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN3_ID , GET_BIT(command,3) );

		/* delay */
		_delay_us(1);

#endif
		/* clear enable */
		 GPIO_WritePin ( LCD_E_PORT_ID , LCD_E_PIN_ID , LOW );

		 /*  delay */
		 _delay_us(1);

}



/*
 * Description :
 * Send the required data to the screen
 */
void LCD_DisplayCharacter( u8 data )
{
	/* - set RS pin */
		GPIO_WritePin( LCD_RS_PORT_ID  , LCD_RS_PIN_ID , HIGH ) ;

		/* - delay */
		_delay_us(1);

		/* - set enable */
		GPIO_WritePin( LCD_E_PORT_ID , LCD_E_PIN_ID , HIGH );

		/* - delay  */
		_delay_us(1);

	#if (LCD_BIT_MODE == 8 )

		/* - send our data */
		GPIO_WritePort( LCD_DATA_PORT_ID , data );

		/* - delay  */
		_delay_us(1);

	#elif ( LCD_BIT_MODE == 4 )


			/* 5 - send the 4 MSBs of data*/
		    GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN0_ID , GET_BIT(data,4) );
			GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN1_ID , GET_BIT(data,5) );
			GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN2_ID , GET_BIT(data,6) );
			GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN3_ID , GET_BIT(data,7) );

			/* 6 - delay */
			_delay_us(1);

			/* 7 - clear enable */
			GPIO_WritePin ( LCD_E_PORT_ID , LCD_E_PIN_ID , LOW );

			/* 8 - delay */
			_delay_us(1);

			/* 9 - set enable */
			GPIO_WritePin ( LCD_E_PORT_ID , LCD_E_PIN_ID , HIGH );

			/* 10 - delay */
			_delay_us(1);

			/* 11 - send the 4 LSBs of data*/
			GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN0_ID , GET_BIT(data,0) );
			GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN1_ID , GET_BIT(data,1) );
			GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN2_ID , GET_BIT(data,2) );
			GPIO_WritePin( LCD_DATA_PORT_ID , LCD_DATA_PIN3_ID , GET_BIT(data,3) );

			/* 12 delay */
			_delay_us(1);

	#endif

			/*  clear enable */
			 GPIO_WritePin ( LCD_E_PORT_ID , LCD_E_PIN_ID , LOW );

			 /*  delay */
			 _delay_us(1);


}


/*
 * Description :
 * Display the required string on the screen
 */
void LCD_DisplayString( const char *str )
{
	u8 i ;
	for( i=0 ; str[i]!='\0' ; i++ )
		LCD_DisplayCharacter( str[i] );
}

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_IntegerToString( int data )
{
   char arr[16];

   /* store the integer number to arr & 10 is for decimal numbering system*/
   itoa(data,arr,10);

   LCD_DisplayString(arr);
}

/*
 * Description :
 * A function which change the cursor position according to given row and column
 */
void LCD_MoveCursor( u8 row , u8 column )
{
	if( row == 0 )
	{
		LCD_SendCommand( LCD_SET_CURSOR_LOCATION_FIRST_LINE | column ) ;
	}
	else if ( row == 1 )
	{
		LCD_SendCommand( LCD_SET_CURSOR_LOCATION_SECOND_LINE | column ) ;
	}
}


/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_DisplayStringRowColumn( u8 row , u8 col , const char *Str )
{
	/*Move cursor to that position*/
	LCD_MoveCursor( row , col );

	/* Display the string*/
	LCD_DisplayString ( Str );
}


/*
 * Description :
 * remove the text displayed on the screen
 */
void LCD_ClearScreen( )
{
	LCD_SendCommand( LCD_CLEAR_SCREEN );
}
