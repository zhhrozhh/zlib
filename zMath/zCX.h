#ifndef ZCX
#define ZCX
#include"../zPreq.h"
class CX{
    private:
    public:
        double re;
        double im;
        CX(double re,double im);
        CX operator+(CX oth);
        CX operator*(CX oth);
        CX operator+(double oth);
        CX operator*(double oth);
        CX operator-(CX oth);
        CX operator-(double oth);
        CX operator~();
        CX operator/(CX oth);
        CX operator/(double oth);
        CX operator-();
        
        friend ostream& operator<<(ostream&o,CX thi);

        friend CX operator+(double oth,CX thi);
        friend CX operator-(double oth,CX thi);
        friend CX operator*(double oth,CX thi);
        friend CX operator/(double oth,CX thi);
};
#endif
