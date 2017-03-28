#ifndef LONGER_H
#define LONGER_H
#include <iostream>


class Longer
{
    public:
        Longer();
        virtual ~Longer();
        Longer(const Longer&);
        template<class T>
        Longer(T a);
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
