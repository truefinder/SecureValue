/**
  * Secure Variable Module
  */

#ifndef SECUREVARIABLE_H_
#define SECUREVARIABLE_H_

#include "SecureCommon.h"
using namespace std; 

template <typename T>
class SecureVariable
{
	private :
		size_t size ; 
		T *secure ; 
		unsigned int randme ; 
		
	public:
		SecureVariable() ; 
		~SecureVariable() ;
		SecureVariable& operator=(const T input) ; 
		operator T() const ; 
		unsigned int Randomize(unsigned int max) ; 

#ifdef _DEBUG_ 
		void DebugPrint() ; 
		void PrintBits(size_t const size, void const * const ptr) ; 
		T GetSavedValue() ; 
#endif 

; 
};


#ifdef _DEBUG_
// check saved value while debugging 
template <typename T>
T SecureVariable<T>::GetSavedValue()
{
	return (T) *secure ; 
}


// debug print 
template <typename T>
void SecureVariable<T>::DebugPrint() 
{
	cout<< "sizeof : " << sizeof(T) << endl  ; 
	cout<< "saved value (secure) : " << (T)*secure << endl ; 
}

// print bits 
template <typename T>
void PrintBits(size_t const size, void const * const ptr)
{
	unsigned char *b = (unsigned char*) ptr;
	unsigned char byte;
	int i, j;

	for (i=size-1;i>=0;i--)
	{
		for (j=7;j>=0;j--)
		{
			byte = b[i] & (1<<j);
			byte >>= j;
			printf("%u", byte);
		}
	}
	puts("");
}
#endif // _DEBUG_ 

// initialize
template <typename T>
SecureVariable<T>::SecureVariable()
{
	size = sizeof(T) ; 
	secure = (T*) malloc( sizeof(T) ) ;

}

// destruct
template <typename T>
SecureVariable<T>::~SecureVariable<T>()
{
	free(secure) ; 
}


// randomize 
template <typename T>
unsigned int SecureVariable<T>::Randomize(unsigned int max)
{
	srand((unsigned int)time(NULL)); 
	return (unsigned int) SEC_RAND32_MIN + rand() % SEC_RAND32_MAX ; 
}

// pull value 
template <typename T>
SecureVariable<T>::operator T() const 
{
	unsigned char u8 ; 
	unsigned short int u16 ; 
	unsigned int u32 ;
	unsigned long long u64 ; 
	T x ; 

	switch( size ) {
		case SEC_UINT8 : 
			memcpy( &u8, secure, size) ;
			u8 = u8 ^ SEC_MASK8(randme) ; 
			memcpy( &x, &u8, size) ; 
			return x ; 
			
		case SEC_UINT16:
			memcpy( &u16, secure, size) ;
			u16 = u16 ^ SEC_MASK16(randme) ; 
			memcpy( &x, &u16, size) ; 
			return x ; 
		case SEC_UINT32:
			memcpy( &u32, secure, size) ; 
			u32 = u32 ^ randme ; 
			memcpy( &x, &u32, size) ;
			return x ; 
		case SEC_UINT64:
			memcpy( &u64, secure, size) ; 
			u64 = u64 ^ (long long) (SEC_RAND64_MIN + randme ) ; 
			memcpy( &x, &u64, size) ; 
			return x ; 
	
		default:
			return -1 ; 
	}
	return -1 ; 
}

// = opertator (input value) 
template <typename T>
SecureVariable<T>& SecureVariable<T>::operator=(const T input)
{
	unsigned char u8 ; 
	unsigned short int u16 ; 
	unsigned int u32 ;
	unsigned long long u64 ; 

	randme = Randomize(SEC_RAND32_MAX) ; 

	switch( size ) {
		case SEC_UINT8 : 
			memcpy( &u8, &input, size) ; 
			u8 = u8 ^ SEC_MASK8(randme) ; 
			memcpy( secure, &u8, size) ;
			break ;

		case SEC_UINT16:
			memcpy( &u16, &input, size) ; 
			u16 = u16 ^ SEC_MASK16(randme) ; 
			memcpy( secure, &u16, size) ;
			break ;

		case SEC_UINT32:
			memcpy( &u32, &input, size) ; 
			u32 = u32 ^ randme ; // SEC_MAGIC32 ; 
			memcpy( secure, &u32, size) ;
			break ;

		case SEC_UINT64:
			memcpy( &u64, &input, size) ; 
			u64 = u64 ^ (long long) (SEC_RAND64_MIN + randme) ; 
			memcpy( secure, &u64, size) ;
			break; 

		default:
			break ;
	}

	return *this ; 
}

#endif // SECUREVARIABLE_H_ 


