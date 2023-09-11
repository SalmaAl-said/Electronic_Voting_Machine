 /******************************************************************************
 *
 * Module: DIO
 *
 * File Name: DIO.c
 *
 * Author: Salma Al-said
 *
 * created date : 4/9/2023
 *
 *******************************************************************************/


#include "DIO_Types.h"
#include <avr/io.h>
#include <Common_Macros.h>
#include "STD_Types.h"

/******************************************************************************
*                             FUNCTIONS IMPLEMENTATION                        *
******************************************************************************/

/*
 * Description :
 * A function to set pin direction if it was input pin or output pin
 */
void GPIO_SetupPinDirection( GPIO_PortType port , GPIO_PinType pin , GPIO_DirectionType direction )
{
	switch(port)
	{
	case PORTA_ID :

		if(direction == OUTPUT )
		{
			SET_BIT( DDRA ,pin);
		}
		else if (direction == INPUT )
		{
			CLEAR_BIT( DDRA , pin);
		}

		break ;

	case PORTB_ID :

		if(direction == OUTPUT )
				{
					SET_BIT( DDRB ,pin);
				}
				else if (direction == INPUT )
				{
					CLEAR_BIT( DDRB , pin);
				}

		break ;

	case PORTC_ID :

		if(direction == OUTPUT )
				{
					SET_BIT( DDRC ,pin);
				}
				else if (direction == INPUT )
				{
					CLEAR_BIT( DDRC , pin);
				}

		break ;

	case PORTD_ID :

		if(direction == OUTPUT )
				{
					SET_BIT( DDRD ,pin);
				}
				else if (direction == INPUT )
				{
					CLEAR_BIT( DDRD , pin);
				}

		break ;

	}


}


/*
 * Description :
 * A function to Write pin with 1 or 0
 */
void GPIO_WritePin( GPIO_PortType port , GPIO_PinType pin , GPIO_OutputValueType value )
{
	switch(port)
		{
		case PORTA_ID :

					if(value == HIGH )
					{
						SET_BIT( PORTA ,pin);
					}
					else if (value == LOW )
					{
						CLEAR_BIT( PORTA , pin);
					}

			break ;

		case PORTB_ID :

			        if(value == HIGH )
					{
						SET_BIT( PORTB ,pin);
					}
					else if (value == LOW )
					{
						CLEAR_BIT( PORTB , pin);
					}

			break ;

		case PORTC_ID :

			        if(value == HIGH  )
					{
						SET_BIT( PORTC ,pin);
					}
					else if (value == LOW)
					{
						CLEAR_BIT( PORTC , pin);
					}

			break ;

		case PORTD_ID :

			       if(value == HIGH  )
					{
						SET_BIT( PORTD ,pin);
					}
					else if (value == LOW )
					{
						CLEAR_BIT( PORTD , pin);
					}

			break ;

		default :

			break;
		}
}


/*
 * Description :
 * A function to read pin if it is 1 or 0
 */
u8 GPIO_ReadPin( GPIO_PortType port , GPIO_PinType pin )
{
	u8 Reading = 0x00;
	switch(port)
	{
	case PORTA_ID :
		Reading = GET_BIT( PINA , pin ) ;
		break ;
	case PORTB_ID :
		Reading = GET_BIT( PINB , pin ) ;
		break ;
	case PORTC_ID :
		Reading = GET_BIT( PINC , pin ) ;
		break ;
	case PORTD_ID :
		Reading = GET_BIT( PIND , pin ) ;
		break ;
	}
	return Reading ;


}


/*
 * Description :
 * A function to set whole port direction
 */
void GPIO_SetupPortDirection( GPIO_PortType port , u8 direction )
{
	switch(port)
	{
	case PORTA_ID :
		DDRA = direction ;
	 break ;

	case PORTB_ID :
		DDRB = direction ;
		 break ;

	case PORTC_ID :
		DDRC = direction ;
		 break ;

	case PORTD_ID :
		DDRD = direction ;
		 break ;
	default :
		break;

	}
}


/*
 * Description :
 * A function to write whole port with any value
 */
void GPIO_WritePort( GPIO_PortType port , u8 value )
{
	switch(port)
			{
			case PORTA_ID :
					PORTA = value ;
				break ;

			case PORTB_ID :
				PORTB = value ;
				break ;

			case PORTC_ID :
				PORTC = value ;
				break ;

			case PORTD_ID :
				PORTD = value ;
				break ;

			default :
				break;
			}
}


/*
 * Description :
 * A function to read whole port
 */
u8 GPIO_ReadPort( GPIO_PortType port )
{
	u8 Reading = 0x00;
		switch(port)
		{
		case PORTA_ID :
			Reading = PINA ;
			break ;
		case PORTB_ID :
			Reading = PINB ;
			break ;
		case PORTC_ID :
			Reading = PINC ;
			break ;
		case PORTD_ID :
			Reading = PIND ;
			break ;
		}
		return Reading ;
}




