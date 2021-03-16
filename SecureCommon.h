/**
  * common header for SecureVariable, SecureFixed 
  */

#ifndef SECURECOMMON_H_
#define SECURECOMMON_H_

#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEC_UINT8	1
#define SEC_UINT16	2
#define SEC_UINT32	4
#define SEC_UINT64	8
/*
#define SEC_MASK8(a)	(a>>24)&0xff
#define SEC_MASK16(a)	(a>>16)&0xffff 
*/
#define SEC_MASK8(a)	a&0xff
#define SEC_MASK16(a)	a&0xffff 


const unsigned char	SEC_RAND8_MAX  = 255; 
const unsigned short	SEC_RAND16_MAX = 65535; 
const unsigned short	SEC_RAND16_MIN = 20291; 
const unsigned int	SEC_RAND32_MAX = 4294967294UL;
const unsigned int	SEC_RAND32_MIN = 1367294UL;
const unsigned long long	SEC_RAND64_MAX = 18446744073709551615ULL;
const unsigned long long	SEC_RAND64_MIN =  9194801837098603971ULL;

// Warning :
//  set the follwing magic values as you want in the specific range 
//	these numbers are not actually magical :)

const unsigned char	SEC_MAGIC8	 = 221; 		// 0 ~ 255
const unsigned short	SEC_MAGIC16 = 63982; 		// 0 ~ 65,535
const unsigned int	SEC_MAGIC32 = 301414810UL;	// 0 ~ 4,294,967,295
const unsigned long long	SEC_MAGIC64 = 141209843010487ULL;	// 0 ~ 18,446,744,073,709,551,615 
#endif // SECURECOMMON_H_ 



