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
typedef unsigned        	      uint32;
typedef signed long long    	  sint64;
typedef unsigned long long        uint64;

/* real data types */
typedef float float32;
typedef double float64;

/* Volatile data types */
typedef volatile int8_t     vint8_t;
typedef volatile uint8_t    vuint8_t;
typedef volatile int16_t    vint16_t;
typedef volatile uint16_t   vuint16_t;
typedef volatile int32_t    vint32_t;
typedef volatile uint32_t   vuint32_t;
typedef volatile int64_t    vint64_t;
typedef volatile uint64_t   vuint64_t;

#endif /* PLATFORM_TYPES_H_ */
