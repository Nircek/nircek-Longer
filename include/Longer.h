#ifndef LONGER_H
#define LONGER_H
#include <iostream>


class Longer
{
    static const int max1d=(uint8_t)-1;
    static const int bit1d=8;
    size_t datasize;
    uint8_t *data;
    public:

        void reserve(size_t);
        size_t size();
        size_t length();
        void delnulls();
        void null();

        Longer();
        template<class T>Longer(T a):
            datasize(0){
            T c(a);
            size_t nsize=1;
            if(!a)nsize=0;
            while(c>>=bit1d)++nsize;
            reserve(nsize);
            for(size_t i=0;i<nsize;++i){
                data[i]=a%(max1d+1);
                a-=data[i];
                a>>=bit1d;
            }
        }
        virtual ~Longer();
        Longer(const Longer&);
        //math
        virtual Longer  operator +  (const Longer&);
        virtual Longer  operator -  (const Longer&);
        virtual Longer  operator *  (const Longer&);
        virtual Longer  operator /  (const Longer&);
        virtual Longer  operator %  (const Longer&);

        //math returning this
        virtual Longer& operator += (const Longer&);
        virtual Longer& operator -= (const Longer&);
        virtual Longer& operator *= (const Longer&);
        virtual Longer& operator /= (const Longer&);
        virtual Longer& operator %= (const Longer&);
        virtual Longer& operator ++ ();
        virtual Longer& operator -- ();

        //bit
        virtual Longer  operator ^  (const Longer&);
        virtual Longer  operator &  (const Longer&);
        virtual Longer  operator |  (const Longer&);
        virtual Longer  operator ~  ();
        virtual Longer  operator << (const Longer&);
        virtual Longer  operator >> (const Longer&);

        //bit returning this
        virtual Longer& operator ^= (const Longer&);
        virtual Longer& operator &= (const Longer&);
        virtual Longer& operator |= (const Longer&);
        virtual Longer& operator <<=(const Longer&);
        virtual Longer& operator >>=(const Longer&);

        //bool
        virtual bool    operator !  ();
        virtual bool    operator <  (const Longer&);
        virtual bool    operator >  (const Longer&);
        virtual bool    operator == (const Longer&);
        virtual bool    operator != (const Longer&);
        virtual bool    operator <= (const Longer&);
        virtual bool    operator >= (const Longer&);
        virtual bool    operator && (const Longer&);
        virtual bool    operator || (const Longer&);


        /**//**//**//**//**//**//**//**//**/
        virtual Longer& operator =  (const Longer&);

		/********************************************/
		//math
		template <class T>
		Longer  operator +  (const T& a){return operator+(Longer(a));}
		template <class T>
		Longer  operator -  (const T& a){return operator-(Longer(a));}
		template <class T>
		Longer  operator *  (const T& a){return operator*(Longer(a));}
		template <class T>
		Longer  operator /  (const T& a){return operator/(Longer(a));}
		template <class T>
		Longer  operator %  (const T& a){return operator%(Longer(a));}

		//math returning this
		template <class T>
		Longer& operator += (const T& a){return operator+=(Longer(a));}
		template <class T>
		Longer& operator -= (const T& a){return operator-=(Longer(a));}
		template <class T>
		Longer& operator *= (const T& a){return operator*=(Longer(a));}
		template <class T>
		Longer& operator /= (const T& a){return operator/=(Longer(a));}
		template <class T>
		Longer& operator %= (const T& a){return operator%=(Longer(a));}

		//bit
		template <class T>
		Longer  operator ^  (const T& a){return operator^(Longer(a));}
		template <class T>
		Longer  operator &  (const T& a){return operator&(Longer(a));}
		template <class T>
		Longer  operator |  (const T& a){return operator|(Longer(a));}
		template <class T>
		Longer  operator << (const T& a){return operator<<(Longer(a));}
		template <class T>
		Longer  operator >> (const T& a){return operator>>(Longer(a));}

		//bit returning this
		template <class T>
		Longer& operator ^= (const T& a){return operator^=(Longer(a));}
		template <class T>
		Longer& operator &= (const T& a){return operator&=(Longer(a));}
		template <class T>
		Longer& operator |= (const T& a){return operator|=(Longer(a));}
		template <class T>
		Longer& operator <<=(const T& a){return operator<<=(Longer(a));}
		template <class T>
		Longer& operator >>=(const T& a){return operator>>=(Longer(a));}

		//bool
		template <class T>
		bool    operator <  (const T& a){return operator<(Longer(a));}
		template <class T>
		bool    operator >  (const T& a){return operator>(Longer(a));}
		template <class T>
		bool    operator == (const T& a){return operator==(Longer(a));}
		template <class T>
		bool    operator != (const T& a){return operator!=(Longer(a));}
		template <class T>
		bool    operator <= (const T& a){return operator<=(Longer(a));}
		template <class T>
		bool    operator >= (const T& a){return operator>=(Longer(a));}
		template <class T>
		bool    operator && (const T& a){return operator&&(Longer(a));}
		template <class T>
		bool    operator || (const T& a){return operator||(Longer(a));}


		/**//**//**//**//**//**//**//**//**/
		template <class T>
		Longer& operator =  (const T& a){return operator=(Longer(a));}
};


std::ostream& operator << (const std::ostream&, const Longer&);
std::istream& operator >> (const std::istream&, const Longer&);

#endif // LONGER_H
