 /******************************************************************************
 *
 * Module: DIO
 *
 * File Name: DIO_Types.h
 *
 * Author: Salma Al-said
 *
 * created date : 4/9/2023
 *
 *******************************************************************************/

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_



typedef enum
{
	PORTA_ID = 0 ,
	PORTB_ID = 1 ,
	PORTC_ID = 2 ,
	PORTD_ID = 3 ,
}GPIO_PortType;

typedef enum
{
	PIN0_ID = 0 ,
	PIN1_ID = 1 ,
	PIN2_ID = 2 ,
	PIN3_ID = 3 ,
	PIN4_ID = 4 ,
	PIN5_ID = 5 ,
	PIN6_ID = 6 ,
	PIN7_ID = 7 ,
}GPIO_PinType;

typedef enum
{
	INPUT = 0 ,
	OUTPUT = 1 ,
}GPIO_DirectionType;

typedef enum
{
	LOW = 0 ,
	HIGH = 1 ,
}GPIO_OutputValueType;




#endif /* DIO_TYPES_H_ */
