#include"zFUNC.h"
fCover::fCover(const fCover&oth){
    this->f=oth.f;
}
fCover fCover::operator=(const fCover&oth){
    this->f=oth.f;
    return*this;
}
bool fCover::operator==(fCover oth){
    return (this->f->type == oth.f->type)&&this->f->equ(oth.f);
}
ostream&operator<<(ostream&o,fCover oth){
    o<<oth.str();
    return o;
}
#define c0 (this->f->gco())
fCover fCover::simplify(){
    fCover x1 = (this->f->gx1()==nullptr)?fCover(0.0):fCover(this->f->gx1()).simplify();
    fCover x2 = (this->f->gx2()==nullptr)?fCover(0.0):fCover(this->f->gx2()).simplify();
    fCover x0 = x1;
    if(this->f->type=="+"){
        if(x1.f->type=="c"&&x2.f->type=="c")
            return fCover(x1.f->gco()+x2.f->gco());
        if(x1.f->type=="x"&&x2.f->type=="x")
            return fCover(new FuncX(x1.f->gco()+x2.f->gco()));
        return x1+x2;
    }
    if(this->f->type=="-"){
        if(x1.f->type=="c"&&x2.f->type=="c")
            return fCover(x1.f->gco()-x2.f->gco());
        if(x1.f->type=="x"&&x2.f->type=="x")
            return fCover(new FuncX(x1.f->gco()-x2.f->gco()));
        return x1-x2;
    }
    if(this->f->type=="*"){
        if(x1.f->type=="pow"&&x2.f->type=="pow"&&x1.f->gx1()->equ(x2.f->gx1()))
            return fCover(new FuncPow(x1.f->gx1(),new FuncAdd(x1.f->gx2(),x2.f->gx2()))).simplify();
        if(x1.f->equ(x2.f))
            return fCover(new FuncPow(x1.f,new FuncConst(2.0)));
        if(x1.f->type=="c"&&x1.f->gco()==1)
            return fCover(x2.f);
        if(x2.f->type=="c"&&x2.f->gco()==1)
            return fCover(x1.f);
        if((x1.f->type=="c"||x1.f->type=="x")&&(x1.f->gco()==0))
            return fCover(0.0);
        if((x2.f->type=="c"||x2.f->type=="x")&&(x2.f->gco()==0))
            return fCover(0.0);
        if(x1.f->type=="c"&&x2.f->type=="c")
            return fCover(x1.f->gco()*x2.f->gco());
        if(x1.f->type=="x"&&x2.f->type=="x")
            return fCover(new FuncX(x1.f->gco()*x2.f->gco()));
        if(x1.f->type=="x"&&x2.f->type=="c")
            return fCover(new FuncX(x2.f->gco()*x1.f->gco()));
        if(x1.f->type=="c"&&x2.f->type=="x")
            return fCover(new FuncX(x1.f->gco()*x2.f->gco()));
        if((x1.f->type=="tan")&&(x2.f->type=="cos")&&(x1.f->gx1()->equ(x2.f->gx1())))
            return SIN(x2.f->gx1());
        if((x1.f->type=="cos")&&(x2.f->type=="tan")&&(x1.f->gx1()->equ(x2.f->gx1())))
            return SIN(x2.f->gx1());
        if((x1.f->type=="tan")&&(x2.f->type=="cot")&&(x1.f->gx1()->equ(x2.f->gx1())))
            return fCover(1.0);
        if((x1.f->type=="cot")&&(x2.f->type=="tan")&&(x1.f->gx1()->equ(x2.f->gx1())))
            return fCover(1.0);
        return x1*x2;
    }
    if(this->f->type=="/"){
        if(x1.f->equ(x2.f))
            return fCover(1.0);
        if((x1.f->type=="x"||x1.f->type=="c")&&(x1.f->gco()==0))
            return fCover(0.0);
        if(x1.f->type=="c"&&x2.f->type=="c")
            return fCover(x1.f->gco()/x2.f->gco());
        if(x1.f->type=="x"&&x2.f->type=="x")
            return fCover(x1.f->gco()/x2.f->gco());
        if(x1.f->type=="x"&&x2.f->type=="c")
            return fCover(new FuncX(x1.f->gco()/x2.f->gco()));
        if(x2.f->type=="tan")
            return fCover(new FuncMul(x1.f,new FuncCot(x2.f->gx1()))).simplify();
        if(x2.f->type=="cot")
            return fCover(new FuncMul(x1.f,new FuncTan(x2.f->gx1()))).simplify();
        if(x2.f->type=="sin")
            return fCover(new FuncMul(x1.f,new FuncCsc(x2.f->gx1()))).simplify();
        if(x2.f->type=="cos")
            return fCover(new FuncMul(x1.f,new FuncSec(x2.f->gx1()))).simplify();
        if(x2.f->type=="csc")
            return fCover(new FuncMul(x1.f,new FuncSin(x2.f->gx1()))).simplify();
        if(x2.f->type=="sec")
            return fCover(new FuncMul(x1.f,new FuncCos(x2.f->gx1()))).simplify();
        return x1/x2;
    }
    return fCover(this->f);
}
/*if(this->f->type=="^":break;
  if(this->f->type=="sin":break;
  if(this->f->type=="cos":break;
  if(this->f->type=="tan":break;
  if(this->f->type=="cot":break;
  if(this->f->type=="sec":break;
  if(this->f->type=="csc":break;
  if(this->f->type=="log":break;*/

fCover fCover::operator+(fCover oth){
    return fCover(new FuncAdd(this->f,oth.f));
}
fCover fCover::operator-(fCover oth){
    return fCover(new FuncSub(this->f,oth.f));
}
fCover fCover::operator*(fCover oth){
    return fCover(new FuncMul(this->f,oth.f));
}
fCover fCover::operator/(fCover oth){
    return fCover(new FuncDiv(this->f,oth.f));
}
fCover fCover::operator^(fCover oth){
    return fCover(new FuncPow(this->f,oth.f));
}
fCover fCover::operator+(double oth){
    return fCover(new FuncAdd(this->f,new FuncConst(oth)));
}
fCover fCover::operator-(double oth){
    return fCover(new FuncSub(this->f,new FuncConst(oth)));
}
fCover fCover::operator*(double oth){
    return fCover(new FuncMul(this->f,new FuncConst(oth)));
}
fCover fCover::operator/(double oth){
    return fCover(new FuncDiv(this->f,new FuncConst(oth)));
}
fCover fCover::operator^(double oth){
    return fCover(new FuncPow(this->f,new FuncConst(oth)));
}
fCover fCover::operator+(){
    return fCover(this->f);
}
fCover fCover::operator-(){
    return fCover(new FuncSub(new FuncConst(0),this->f));
}
fCover LOG(fCover F){
    return fCover(new FuncLog(F.f));
}
fCover SIN(fCover F){
    return fCover(new FuncSin(F.f)); 
}
fCover COS(fCover F){
    return fCover(new FuncCos(F.f));
}
fCover TAN(fCover F){
    return fCover(new FuncTan(F.f));
}
fCover COT(fCover F){
    return fCover(new FuncCot(F.f));
}
fCover SEC(fCover F){
    return fCover(new FuncSec(F.f));
}
fCover CSC(fCover F){
    return fCover(new FuncCsc(F.f));
}
fCover X(){
    return fCover(new FuncX());
}
fCover X(double d){
    return fCover(new FuncX(d));
}
fCover DDX(fCover F){
    return fCover(F.f->d());
}
