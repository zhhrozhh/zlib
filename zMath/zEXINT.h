#ifndef ZEXTENTINT
#define ZEXTENTINT
#include"../zPreq.h"
#define MAXM ((2UL<<(sizeof(unsigned long)*4))-1)
#define MAXL 50
class Extint{
    public:
        unsigned long*val;
        int NumOfSegments;
        bool inf;
        Extint();
        Extint(const Extint&oth);
        void set(int pos,unsigned long data);
        void rerange(unsigned long scale);
        Extint&sinf();
        bool operator>(Extint oth);
        bool operator<(Extint oth);
        bool operator==(Extint oth);
        Extint operator+(Extint oth);
        Extint operator-(Extint oth);
        Extint operator*(Extint oth);
        Extint operator/(Extint oth);
        friend ostream&operator<<(ostream&o,Extint oth);
};
#endif
