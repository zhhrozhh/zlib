#include"zFUN.h"
//========================================FUNC
bool Func::equ(Func*oth){
    return this->type == oth->type;
}
double Func::gco(){
    return 0;
}
Func*Func::gx1(){
    return nullptr;
}
Func*Func::gx2(){
    return nullptr;
}
//========================================Const
bool FuncConst::equ(FuncConst*oth){
    return (this->type == oth->type)&&(this->con==oth->con);
}
double FuncConst::gco(){
    return this->con;
}
//========================================Unary
bool FuncUnary::equ(FuncUnary*oth){
    return (this->type==oth->type)&&(x0->equ(oth->var));
}
Func*FuncUnary::gx1(){
    return this->var;
}
//========================================Binary
bool FuncBinary::equ(FuncBinary*oth){
    return (this->type==oth->type)&&(x1->equ(oth->var1))&&(x2->equ(oth->var2));
}
Func*FuncBinary::gx1(){
    return this->var1;
}
Func*FuncBinary::gx2(){
    return this->var2;
}
//========================================X
string FuncX::expr(){
    ostringstream o;
    o<<this->con;
    return (this->con==1?"":o.str())+"x";
}
bool FuncX::equ(FuncX*oth){
    return this->con == oth->con;
}
double FuncX::gco(){
    return this->con;
}
//========================================
string FuncConst::expr(){
    ostringstream x;
    x<<this->con;
    return x.str();
}
string FuncUnary::expr(){
    return this->type+"("+x0->expr()+")";
}
string FuncBinary::expr(){
    bool Aq = (this->type=="^"||x1->type=="+"||x1->type=="-");
    bool Bq = (this->type=="^"||x2->type=="+"||x2->type=="-"||this->type=="/");
    return (Aq?"(":"")+x1->expr()+(Aq?")":"")+((this->type=="*")?"":this->type)+(Bq?"(":"")+x2->expr()+(Bq?")":"");
}
//=========================================
Func*FuncConst::d(){
    return new FuncConst(0);
}
Func*FuncAdd::d(){
    return Add(dd(x1),dd(x2));
}
Func*FuncSub::d(){
    return Sub(dd(x1),dd(x2));
}
Func*FuncMul::d(){
    return Add(Mul(dd(x1),x2),Mul(x1,dd(x2)));
}
Func*FuncDiv::d(){
    return Div(Sub(Mul(dd(x1),x2),Mul(x1,dd(x2))),Mul(x2,x2));
}
Func*FuncPow::d(){
    return Mul(Mul(x2,Pow(x1,Sub(x2,new FuncConst(1)))),Add(Mul(x2,dd(x1)),Mul(x1,Mul(Log(x1),dd(x2)))));
}
//===================================================
Func*FuncX::d(){
    return new FuncConst(this->con);
}
//===================================================
Func*FuncLog::d(){
    return Div(dd(x0),x0);
}
Func*FuncSin::d(){
    return Mul(new FuncCos(x0),dd(x0));
}
Func*FuncCos::d(){
    return Sub(new FuncConst(0),Mul(new FuncSin(x0),dd(x0)));
}
Func*FuncTan::d(){
    return Mul(new FuncSec(x0),new FuncSec(x0));
}
Func*FuncCot::d(){
    return Sub(new FuncConst(0),Mul(new FuncCsc(x0),new FuncCsc(x0)));
}
Func*FuncSec::d(){
    return Mul(new FuncTan(x0),new FuncSec(x0));
}
Func*FuncCsc::d(){
    return Sub(new FuncConst(0),Mul(new FuncCot(x0),new FuncCsc(x0)));
}
//==================================================
