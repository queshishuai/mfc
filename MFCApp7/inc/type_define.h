/******************************************************************
 * @file  type_define.h
 * @brief:    ucp common type define 
 * @author: guicheng.liu
 * @Date 2022年1月10日
 * COPYRIGHT NOTICE: (c) smartlogictech. All rights reserved. 
 * Change_date         Owner         Change_content
 * 2022年1月10日        guicheng.liu       create file

*****************************************************************/

#ifndef     UCP_DEFINE_H
#define     UCP_DEFINE_H

//#include <ucps2.h>
#include <stdlib.h>
//#include <math.h>
#include <string.h>
//#include <ucps2-intrin.h>
#include <malloc.h>
#include <stdio.h>

typedef signed char		int8_t;
typedef unsigned char	uint8_t;
typedef signed short	int16_t;
typedef unsigned short	uint16_t;
typedef signed int		int32_t;
typedef unsigned int	uint32_t;
typedef unsigned long long uint64_t;
typedef signed long long   int64_t;

//typedef (unsigned int)  bool;

#define false 0
#define true 1

#define INVALID_VALUE_U32 0xFFFFFFFF
#define INVALID_VALUE_U16 0xFFFF
#define INVALID_VALUE_U8  0xFF

#define  NULLPTR   (void *)(0)    //!NULL pointer 
//#define  NULL       0

#define	BIT(x)		(1 << x)

#endif
