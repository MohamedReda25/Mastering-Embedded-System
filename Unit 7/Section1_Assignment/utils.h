/*
 * utils.h
 *
 * Created: 9/11/2022 8:51:58 PM
 *  Author: redam
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SetBit(reg,bit)		reg |= (1<<bit)
#define ClearBit(reg,bit)	reg &= ~(1<<bit)
#define ToggleBit(reg,bit)		reg ^= (1<<bit)
#define ReadBit(reg,bit)		((reg>>bit)&1)




#endif /* UTILS_H_ */