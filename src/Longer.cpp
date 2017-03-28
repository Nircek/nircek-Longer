#include "Longer.h"
void Longer::reserve(size_t ile){
    size_t slength=length();
    if(slength>ile)throw std::string("Possible loss of data");
    uint8_t *copy=new uint8_t[ile];
    for(size_t i=0;i<ile;++i)copy[i]=(i<slength)?data[i]:0;
    datasize=ile;
    data=copy;
}
size_t Longer::size(){
    return datasize;
}
size_t Longer::length(){
    if(!datasize)return 0;
    size_t i=datasize;
    while(i)if(data[--i]!=0x00)break;
    return i+1;
}
void Longer::delnulls(){
    reserve(length());
}
void Longer::null(){
    if(datasize)delete[] data;
    datasize=0;
}


Longer::Longer():datasize(0){}

Longer::~Longer(){null();}

Longer::Longer(const Longer& other):datasize(0){operator=(other);}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

/******************************************************************/
//                           MATH
Longer  Longer::operator +  (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator -  (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator *  (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator /  (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator %  (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}


/******************************************************************/
//                          =MATH
Longer& Longer::operator += (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer& Longer::operator -= (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer& Longer::operator *= (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer& Longer::operator /= (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer& Longer::operator %= (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer& Longer::operator ++ (){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer& Longer::operator -- (){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}


/******************************************************************/
//                           BIT
Longer  Longer::operator ^  (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator &  (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator |  (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator ~  (){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator << (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator >> (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}


/******************************************************************/
//                          =BIT
Longer& Longer::operator ^= (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer& Longer::operator &= (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer& Longer::operator |= (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer& Longer::operator <<=(const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer& Longer::operator >>=(const Longer& a){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}


/******************************************************************/
//                           BOOL
bool    Longer::operator !  (){
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator <  (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator >  (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator == (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator != (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator <= (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator >= (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator && (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator || (const Longer& a){
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}


        /**//**//**//**//**//**//**//**//**/
Longer& Longer::operator =  (const Longer& a){
    null();
    datasize=a.datasize;
	if(datasize){
        data=new uint8_t[datasize];
        for(size_t i=0;i<datasize;++i){
            data[i]=a.data[i];
        }
    }
    return *this;
}

std::ostream& operator << (const std::ostream& str, const Longer& a){
	throw std::string("This function is unavailable!");
	return *((std::ostream*)(NULL));
}

std::istream& operator >> (const std::istream& str, const Longer& a){
	throw std::string("This function is unavailable!");
	return *((std::istream*)(NULL));
}
