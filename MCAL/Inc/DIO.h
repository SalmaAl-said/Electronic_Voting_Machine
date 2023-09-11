 /******************************************************************************
 *
 * Module: DIO
 *
 * File Name: DIO.h
 *
 * Author: Salma Al-said
 *
 * created date : 4/9/2023
 *
 *******************************************************************************/

#ifndef DIO_H_
#define DIO_H_

#include "DIO_Types.h"
#include "STD_Types.h"

/******************************************************************************
*                             FUNCTIONS PROTOTYPES                            *
******************************************************************************/

void GPIO_SetupPinDirection( GPIO_PortType port , GPIO_PinType pin , GPIO_DirectionType direction ) ;

void GPIO_WritePin( GPIO_PortType port , GPIO_PinType pin , GPIO_OutputValueType value ) ;

u8 GPIO_ReadPin( GPIO_PortType port , GPIO_PinType pin ) ;

void GPIO_SetupPortDirection( GPIO_PortType port , u8 direction ) ;

void GPIO_WritePort( GPIO_PortType port , u8 value ) ;

u8 GPIO_ReadPort( GPIO_PortType port ) ;




#endif /* DIO_H_ */
