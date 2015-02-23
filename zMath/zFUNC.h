#ifndef FUNCTIONCOVER
#define FUNCTIONCOVER
#include"zFUN.h"
#undef x0
#undef x1
#undef x2
#undef dd
#undef Add
#undef Sub
#undef Mul
#undef Div
class fCover{
    public:
        Func*f;
        fCover(Func*v):f(v){}
        fCover(double v):f(new FuncConst(v)){}
        fCover(const fCover&oth);
        fCover operator+(fCover oth);
        fCover operator-(fCover oth);
        fCover operator*(fCover oth);
        fCover operator/(fCover oth);
        fCover operator^(fCover oth);
        fCover operator+(double oth);
        fCover operator-(double oth);
        fCover operator*(double oth);
        fCover operator/(double oth);
        fCover operator^(double oth);
        fCover operator+();
        fCover operator-();
        fCover operator=(const fCover&oth);
        bool operator==(fCover oth);
        string str(){return this->f->expr();}
        friend ostream&operator<<(ostream&o,fCover oth);
        fCover simplify();
};
fCover LOG(fCover F);
fCover SIN(fCover F);
fCover COS(fCover F);
fCover TAN(fCover F);
fCover COT(fCover F);
fCover SEC(fCover F);
fCover CSC(fCover F);
fCover X();
fCover X(double d);
fCover DDX(fCover F);
#endif

