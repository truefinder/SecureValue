/**
  * Secure Fixed Variable Module 
  */ 

#ifndef SECUREFIXED_H_
#define SECUREFIXED_H_

#include "SecureCommon.h" 
using namespace std; 

template <typename T>
class SecureFixed
{
	private :
		size_t size ; 
		T *secure ; 
	public:
		SecureFixed() ; 
		~SecureFixed() ;
		SecureFixed& operator=(const T input) ; 
		operator T() const ; 
#ifdef _DEBUG_
		void DebugPrint() ; 
		void PrintBits(size_t const size, void const * const ptr) ; 
		T GetSavedValue() ; 
#endif

};

#ifdef _DEBUG_
// check saved value while debugging 
template <typename T> 
T SecureFixed<T>::GetSavedValue()
{
	return (T) *secure ; 

}

// print bits 
template <typename T> 
void SecureFixed<T>::PrintBits(size_t const size, void const * const ptr)
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

// debug print 
template <typename T>
void SecureFixed<T>::DebugPrint() 
{

	cout<< "typeinfo : " << typeid(T).name() << ", sizeof : " << sizeof(T) << endl  ; 
	cout<< "saved value (secure) : " << (T)*secure << endl ; 
}
#endif

// initialize
template <typename T>
SecureFixed<T>::SecureFixed()
{
	size = sizeof(T) ; 
	secure = (T*) malloc( sizeof(T) ) ;

}

// destruct 
template <typename T>
SecureFixed<T>::~SecureFixed<T>()
{
	free(secure) ; 
}

// pull value 
template <typename T>
SecureFixed<T>::operator T() const 
{
	unsigned char u8 ; 
	unsigned short int u16 ; 
	unsigned int u32 ;
	unsigned long long u64 ; 
	T x ; 

	switch( size ) {
		case SEC_UINT8 : 
			memcpy( &u8, secure, size) ;
			u8 = u8 ^ SEC_MAGIC8 ; 
			memcpy( &x, &u8, size) ; 
			return x ; 
			
		case SEC_UINT16:
			memcpy( &u16, secure, size) ;
			u16 = u16 ^ SEC_MAGIC16 ; 
			memcpy( &x, &u16, size) ; 
			return x ; 
		case SEC_UINT32:
			memcpy( &u32, secure, size) ; 
			u32 = u32 ^ SEC_MAGIC32 ; 
			memcpy( &x, &u32, size) ;
			return x ; 
		case SEC_UINT64:
			memcpy( &u64, secure, size) ; 
			u64 = u64 ^ SEC_MAGIC64 ; 
			memcpy( &x, &u64, size) ; 
			return x ; 
	
		default:
			return -1 ; 
	}
	return -1 ; 
}


// = operation  ( input value ) 
template <typename T>
SecureFixed<T>& SecureFixed<T>::operator=(const T input)
{
	unsigned char u8 ; 
	unsigned short int u16 ; 
	unsigned int u32 ;
	unsigned long long u64 ; 

	switch( size ) {
		case SEC_UINT8 : 
			memcpy( &u8, &input, size) ; 
			u8 = u8 ^ SEC_MAGIC8 ; 
			memcpy( secure, &u8, size) ;
			break ;

		case SEC_UINT16:
			memcpy( &u16, &input, size) ; 
			u16 = u16 ^ SEC_MAGIC16 ; 
			memcpy( secure, &u16, size) ;
			break ;

		case SEC_UINT32:
			memcpy( &u32, &input, size) ; 
			u32 = u32 ^ SEC_MAGIC32 ; 
			memcpy( secure, &u32, size) ;
			break ;

		case SEC_UINT64:
			memcpy( &u64, &input, size) ; 
			u64 = u64 ^ SEC_MAGIC64 ; 
			memcpy( secure, &u64, size) ;
			break; 

		default:
			break ;
	}

	return *this ; 
}


#endif // SECUREFIXED_H_ 

