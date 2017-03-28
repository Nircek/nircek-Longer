#ifndef LONGER_H
#define LONGER_H
#include <iostream>


class Longer
{
    public:
        Longer();
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
};


std::ostream& operator << (const std::ostream&, const Longer&);
std::istream& operator >> (const std::istream&, const Longer&);

#endif // LONGER_H
