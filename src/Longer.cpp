#include "Longer.h"

std::string Longer::readbytes() const{
    std::string ret="";
    for(size_t i=datasize;i;--i){
        ret+=itoc[(data[i-1]>>4)&0xF];
        ret+=itoc[data[i-1]&0xF];
    }
    return ret;
}
std::string Longer::read(size_t base) const{
    //TODO: requires: % toull() -= /=
    std::string ret="";
    Longer copy(*this);
    while(length()){
        ret+=itoc[(copy%base).toull()];
        copy-=copy%base;
        copy/=base;
    }
    return std::string(ret.rbegin(),ret.rend());
}
void Longer::writebytes(std::string s){
    if(s.length()&1)s=std::string("0")+s;
    null();
    reserve(s.length()>>1);
    size_t last=s.length()-1;
    for(size_t i=0;i<datasize;++i)data[i]=(ctoi[(size_t)s.at(last-i*2-1)]<<4)+(ctoi[(size_t)s.at(last-i*2)]);

}
void Longer::write(std::string, size_t){
}

unsigned long long Longer::toull() const{
    unsigned long long ret=0;
    size_t l=(sizeof(unsigned long long)<length())?sizeof(unsigned long long):length();
    for(size_t i=0;i<l;++i){
        ret<<=bit1d;
        ret+=data[i];
    }
    return ret;
}


void Longer::reserve(size_t ile){
    size_t slength=length();
    if(slength>ile)throw std::string("Possible loss of data");
    uint8_t *copy=new uint8_t[ile];
    for(size_t i=0;i<ile;++i)copy[i]=(i<slength)?data[i]:0;
    datasize=ile;
    data=copy;
}
size_t Longer::size() const{
    return datasize;
}
size_t Longer::length() const{
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

uint8_t Longer::at(size_t a) const{
    return (a<datasize)?data[a]:0;
}


Longer::Longer():datasize(0){}

Longer::~Longer(){null();}

Longer::Longer(const Longer& other):datasize(0){operator=(other);}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

/******************************************************************/
//                           MATH
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator +  (const Longer& a) const{
Longer  Longer::operator -  (const Longer& a) const{
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator *  (const Longer& a) const{
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator /  (const Longer& a) const{
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator %  (const Longer& a) const{
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
Longer  Longer::operator ^  (const Longer& a) const{
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator &  (const Longer& a) const{
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator |  (const Longer& a) const{
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator ~  () const{
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator << (const Longer& a) const{
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}
Longer  Longer::operator >> (const Longer& a) const{
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
bool    Longer::operator !  () const{
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator <  (const Longer& a) const{
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator >  (const Longer& a) const{
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator == (const Longer& a) const{
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator != (const Longer& a) const{
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator <= (const Longer& a) const{
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator >= (const Longer& a) const{
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator && (const Longer& a) const{
	throw std::string("This function is unavailable!");
	return *((bool*)(NULL));
}
bool    Longer::operator || (const Longer& a) const{
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
