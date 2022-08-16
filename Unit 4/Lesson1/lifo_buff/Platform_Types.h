#ifndef _PLATFORM_TYPES_H
#define _PLATFORM_TYPES_H


#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>

/*false=0, true=1*/

typedef unsigned char 			  boolean;
#ifndef FALSE
#define FALSE		(boolean)false
#endif
#ifndef TRUE
#define TRUE		(boolean)true
#endif

/* Symbols */
#define CPU_TYPE				CPU_TYPE_32
#define CPU_BIT_ORDER 			LSB_FIRST
#define CPU_BYTE_ORDER 			LOW_BYTE_FIRST

/* integer data types */
typedef signed char	              sint8;
typedef unsigned char          	  uint8;
typedef signed short       		  sint16;
typedef unsigned short            uint16;
typedef signed int        	      sint32;
typedef unsigned int        	  uint32;
typedef signed long long    	  sint64;
typedef unsigned long long        uint64;

/* real data types */
typedef float float32;
typedef double float64;

/* Volatile data types */
typedef volatile sint8     vint8_t;
typedef volatile uint8    vuint8_t;
typedef volatile sint16    vint16_t;
typedef volatile uint16   vuint16_t;
typedef volatile sint32    vint32_t;
typedef volatile uint32   vuint32_t;
typedef volatile sint64    vint64_t;
typedef volatile uint64   vuint64_t;

#endif /* PLATFORM_TYPES_H_ */
