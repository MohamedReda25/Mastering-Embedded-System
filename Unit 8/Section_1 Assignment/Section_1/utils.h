/*
 * utils.h
 *
 * Created: 10/2/2022 4:44:24 AM
 *  Author: redam
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SetBit(reg,bit)		reg |= (1<<bit)
#define ClearBit(reg,bit)	reg &= ~(1<<bit)
#define ToggleBit(reg,bit)		reg ^= (1<<bit)
#define ReadBit(reg,bit)		((reg>>bit)&1)






#endif /* UTILS_H_ */