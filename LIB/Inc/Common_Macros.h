 /******************************************************************************
 *
 * Module: Common - Macros
 *
 * File Name: Common_Macros.h
 *
 * Author: Salma Al-said
 *
 * created date : 4/9/2023
 *
 *******************************************************************************/

#ifndef LIB_COMMON_MACROS_H_
#define LIB_COMMON_MACROS_H_


/******************************************************************************
*                                Definitions                                  *
******************************************************************************/

#define SET_BIT(var,bit_no) (var)|=(1<<(bit_no))

#define CLEAR_BIT(var,bit_no) (var)&=(~(1<<(bit_no)))

#define TOGGLE_BIT(var,bit_no) (var)^=(1<<(bit_no))

#define GET_BIT(var,bit_no) (((var)>>(bit_no))&(1))

#endif /* LIB_COMMON_MACROS_H_ */
