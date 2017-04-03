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
uint8_t& Longer::getdata(size_t s){
    if(s>=datasize)reserve(s+1);
    return data[s];
}
void Longer::setdata(size_t s,uint8_t d){
    if(s>=datasize)reserve(s+1);
    data[s]=d;
}

void Longer::setpart(size_t s,uint16_t &d){
    if(s>=datasize)reserve(s+1);
    data[s]=d&max1d;
    d>>=bit1d;
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
    while(i)if(data[--i]!=0x00)return i+1;
    return 0;
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
Longer  Longer::operator +  (const Longer& a) const{
	Longer ret;

	size_t l=(this->datasize>a.datasize)?this->datasize:a.datasize;
	ret.reserve(l);
	uint16_t step=0;
	for(size_t i=0;i<l;++i){
        step+=at(i);
        step+=a.at(i);
        ret.setpart(i,step);
	}
	while(step)ret.setpart(ret.size(),step);
	return ret;
}
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
    size_t i=(size_t)-1;
	while(!(++getdata(++i)));
	return *this;
}
Longer& Longer::operator -- (){
	throw std::string("This function is unavailable!");
	return *((Longer*)(NULL));
}


/******************************************************************/
//                           BIT
Longer  Longer::operator ^  (const Longer& a) const{
	Longer ret;
	ret.reserve(std::max(length(),a.length()));
	for(size_t i=0;i<ret.size();++i)ret.data[i]=at(i)^a.at(i);
	return ret;
}
Longer  Longer::operator &  (const Longer& a) const{
	Longer ret;
	ret.reserve(std::min(length(),a.length()));
	for(size_t i=0;i<ret.size();++i)ret.data[i]=at(i)&a.at(i);
	return ret;
}
Longer  Longer::operator |  (const Longer& a) const{
    Longer ret;
	ret.reserve(std::max(length(),a.length()));
	for(size_t i=0;i<ret.size();++i)ret.data[i]=at(i)|a.at(i);
	return ret;
}
Longer  Longer::operator ~  () const{
	Longer ret;
	ret.reserve(length());
	for(size_t i=0;i<ret.size();++i)ret.data[i]=~at(i);
	return ret;
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
	reserve(std::max(length(),a.length()));
	for(size_t i=0;i<size();++i)data[i]^=a.at(i);
	return *this;
}
Longer& Longer::operator &= (const Longer& a){
	reserve(std::min(length(),a.length()));
	for(size_t i=0;i<size();++i)data[i]&=a.at(i);
	return *this;
}
Longer& Longer::operator |= (const Longer& a){
	reserve(std::max(length(),a.length()));
	for(size_t i=0;i<size();++i)data[i]|=a.at(i);
	return *this;
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
	return !length();
}
bool    Longer::operator <  (const Longer& a) const{
	if(length()<a.length())return true;
	if(length()>a.length())return false;
	for(size_t i=length();i;--i){if(at(i-1)<a.at(i-1))return true;else if(at(i-1)>a.at(i-1))return false;}
	return false;
}
bool    Longer::operator >  (const Longer& a) const{
	if(length()>a.length())return true;
	if(length()<a.length())return false;
	for(size_t i=length();i;--i){if(at(i-1)>a.at(i-1))return true;else if(at(i-1)<a.at(i-1))return false;}
	return false;
}
bool    Longer::operator == (const Longer& a) const{
	if(length()!=a.length())return false;
	for(size_t i=0;i<length();++i)if(at(i)!=a.at(i))return false;
	return true;
}
bool    Longer::operator != (const Longer& a) const{
	return !((*this)==a);
}
bool    Longer::operator <= (const Longer& a) const{
	return !((*this)>a);
}
bool    Longer::operator >= (const Longer& a) const{
	return !((*this)<a);
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
