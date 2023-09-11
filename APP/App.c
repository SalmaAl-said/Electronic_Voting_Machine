 /******************************************************************************
 *
 * Module: Application
 *
 * File Name: App.c
 *
 * Author: Salma Al-said
 *
 * created date : 9/9/2023
 *
 *******************************************************************************/

#include<util/delay.h>
#include"LCD.h"
#include"Keypad.h"
#include"App.h"


/******************************************************************************
*                             FUNCTIONS IMPLEMENTATION                        *
******************************************************************************/

/* default voting */
static u8 vote1=0 ;
static u8 vote2=0 ;
static u8 vote3=0 ;
static u8 vote4=0 ;


/*
 * Description :
 * set up Application
 */
void APP_Init()
{
	LCD_Init();
}


/*
 * Description :
 * display when screen turns on
 */
void APP_FirstDisplayScreen()
{
	LCD_ClearScreen();
	LCD_DisplayStringRowColumn( 0 , 3 , "Electronic" ) ;
	LCD_DisplayStringRowColumn( 1 , 1 , "Voting Machine" ) ;
	_delay_ms(1000);

	APP_MainMenuScrean();
}


/*
 * Description :
 * display Candidates by number of votes as default
 */
void APP_MainMenuScrean()
{
		LCD_ClearScreen();


	    LCD_DisplayStringRowColumn( 0 , 1 , "A" ) ;
		LCD_MoveCursor(1,1);
		LCD_IntegerToString(vote1);

		LCD_DisplayStringRowColumn( 0 , 5 , "B" ) ;
		LCD_MoveCursor(1,5);
		LCD_IntegerToString(vote2);

		LCD_DisplayStringRowColumn( 0 , 9 , "C" ) ;
		LCD_MoveCursor(1,9);
		LCD_IntegerToString(vote3);

		LCD_DisplayStringRowColumn( 0 , 13 , "D" ) ;
		LCD_MoveCursor(1,13);
		LCD_IntegerToString(vote4);

		DisplayVote() ;
}


/*
 * Description :
 * display Candidates by number of votes when user enter vote
 */
void DisplayVote()
{
	u32 vote = vote1 + vote2 + vote3 + vote4 ;
	u8 PressKey = KEYPAD_GetPressedKey( ) ;

	if ( PressKey == 1 )
	{
		_delay_ms(300);
		vote1++;
		LCD_MoveCursor(1,1);
		LCD_IntegerToString(vote1);

	}

	else if ( PressKey == 2 )
	{
		_delay_ms(300);
		vote2++;
		LCD_MoveCursor(1,5);
		LCD_IntegerToString(vote2);
	}
	else if ( PressKey == 3 )
	{
		_delay_ms(300);
		vote3++;
		LCD_MoveCursor(1,9);
		LCD_IntegerToString(vote3);
	}
	else if ( PressKey == 4 )
	{
		_delay_ms(300);
		vote4++;
		LCD_MoveCursor(1,13);
		LCD_IntegerToString(vote4);
	}
	else if( PressKey == 5 )
	{
		_delay_ms(300);
		if(vote)
		{
			if( vote1>vote2 && vote1>vote3 && vote1>vote4 )
			{

				LCD_ClearScreen();
				LCD_DisplayString("A is winner");

			}
			else if ( vote2>vote1 && vote2>vote3 && vote2>vote4 )
			{

				LCD_ClearScreen();
				LCD_DisplayString("B is winner");

			}
			else if ( vote3>vote1 && vote3>vote2 && vote3>vote4 )
			{

				LCD_ClearScreen();
				LCD_DisplayString("C is winner");

			}
			else if ( vote4>vote1 && vote4>vote2 && vote4>vote3)
			{

				LCD_ClearScreen();
				LCD_DisplayString("D is winner");

			}
			else
			{

				LCD_ClearScreen();
				LCD_DisplayStringRowColumn( 0 , 1 , "NO Result" ) ;
				LCD_DisplayStringRowColumn( 1 , 1 , "RE-VOTE" ) ;
				_delay_ms(1000);
				APP_Reset ();
				APP_MainMenuScrean();

			}
		}
		else
		{
			LCD_ClearScreen();
			LCD_DisplayString("NO Voting");
		}

	}

	else if ( PressKey == 6 )
	{


		    LCD_ClearScreen();
		    APP_Reset ();
		    LCD_DisplayStringRowColumn( 0 , 1 , " System Reset" ) ;
		    _delay_ms(1000);
		    APP_FirstDisplayScreen();
	}
	else
	{
		 LCD_ClearScreen();
		 LCD_DisplayStringRowColumn( 0 , 2 , "Wrong Input" ) ;
		 _delay_ms(1000);
		 APP_Reset ();
		 APP_MainMenuScrean();

	}

	DisplayVote();



}

/*
 * Description :
 * return votes as default
 */
void APP_Reset ()
{
	vote1=0 ;
	vote2=0 ;
	vote3=0 ;
	vote4=0 ;
}
