#ifndef ZFUNCTION
#define ZFUNCTION
#include<sstream>
#include"../zPreq.h"
                
#define x0 (this->var)
#define x1 (this->var1)
#define x2 (this->var2)
#define dd(x) (x->d())
#define Add new FuncAdd
#define Sub new FuncSub
#define Mul new FuncMul
#define Div new FuncDiv
#define Pow new FuncPow
#define Log new FuncLog
//
//    / FuncUnary(sin,cos,tan,cot)
//Func- FuncConst(x)
//    \ FuncBinary(+-*/)
//
class Func{
    public:
        virtual Func*d(){return nullptr;}
        virtual string expr(){return "";}
        bool equ(Func*oth);
        virtual double gco();
        virtual Func*gx1();
        virtual Func*gx2();
        string type;
        Func(string t):type(t){}
};
class FuncConst:public Func{
    public:
        virtual string expr();
        using Func::equ;//ndd
        bool equ(FuncConst*oth);
        virtual double gco();
        virtual Func*d();
        FuncConst(double c):Func("c"),con(c){}
        double con;
};
class FuncX:public Func{
    public:
        virtual double gco();
        virtual string expr();
        using Func::equ;//ndd
        bool equ(FuncX*oth);
        FuncX():Func("x"){this->con=1;}
        FuncX(double c):Func("x"),con(c){}
        Func*d();
        double con;
};
//================================================UNARY
class FuncUnary:public Func{
    public:
        virtual bool equ(FuncUnary*oth);
        virtual Func*gx1();
        FuncUnary(string t,Func*v):Func(t),var(v){}
        Func*var;
        string expr();
};
class FuncLog:public FuncUnary{
    public:
        FuncLog(Func*v):FuncUnary("log",v){}
        Func*d();
};
class FuncSin:public FuncUnary{
    public:
        FuncSin(Func*v):FuncUnary("sin",v){}
        Func*d();
};
class FuncCos:public FuncUnary{
    public:
        FuncCos(Func*v):FuncUnary("cos",v){}
        Func*d();
};
class FuncTan:public FuncUnary{
    public:
        FuncTan(Func*v):FuncUnary("tan",v){}
        Func*d();
};
class FuncCot:public FuncUnary{
    public:
        FuncCot(Func*v):FuncUnary("cot",v){}
        Func*d();
};
class FuncSec:public FuncUnary{
    public:
        FuncSec(Func*v):FuncUnary("sec",v){}
        Func*d();
};
class FuncCsc:public FuncUnary{
    public:
        FuncCsc(Func*v):FuncUnary("csc",v){}
        Func*d();
};
//=============================================
class FuncBinary:public Func{
    public:
        virtual bool equ(FuncBinary*oth);
        virtual Func*gx1();
        virtual Func*gx2();
        FuncBinary(string t,Func*a,Func*b):Func(t),var1(a),var2(b){}
        Func*var1;
        Func*var2;
        string expr();
};
class FuncAdd:public FuncBinary{
    public:
        FuncAdd(Func*a,Func*b):FuncBinary("+",a,b){}
        Func*d();
};
class FuncSub:public FuncBinary{
    public:
        FuncSub(Func*a,Func*b):FuncBinary("-",a,b){}
        Func*d();
};
class FuncMul:public FuncBinary{
    public:
        FuncMul(Func*a,Func*b):FuncBinary("*",a,b){}
        Func*d();
};
class FuncDiv:public FuncBinary{
    public:
        FuncDiv(Func*a,Func*b):FuncBinary("/",a,b){}
        Func*d();
};
class FuncPow:public FuncBinary{
    public:
        FuncPow(Func*a,Func*b):FuncBinary("^",a,b){}
        Func*d();
};
#endif
