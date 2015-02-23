#include"zCX.h"
CX::CX(double re,double im){
    this->re=re;
    this->im=im;
}
CX CX::operator+(CX oth){
    return CX(this->re+oth.re,this->im+oth.im);
}
CX CX::operator+(double oth){
    return CX(this->re+oth,this->im);
}
CX CX::operator*(CX oth){
    return CX(this->re*oth.re-this->im*oth.im,this->re*oth.im+this->im*oth.re);
}
CX CX::operator*(double oth){
    return CX(oth*this->re,oth*this->im);
}
CX CX::operator-(CX oth){
    return CX(this->re-oth.re,this->im-oth.im);
}
CX CX::operator-(double oth){
    return CX(this->re-oth,this->im);
}
CX CX::operator~(){
    return CX(this->re,-this->im);
}
CX CX::operator/(CX oth){
    return (*this)*(~oth)/(oth*(~oth)).re;
}
CX CX::operator/(double oth){
    return CX(this->re/oth,this->im/oth);
}
CX CX::operator-(){
    return CX(-this->re,-this->im);
}

CX operator+(double oth,CX thi){
    return thi+oth;
}
CX operator-(double oth,CX thi){
    return CX(oth-thi.re,thi.im);
}
CX operator*(double oth,CX thi){
    return thi*oth;
}
CX operator/(double oth,CX thi){
    return CX(oth,0)/thi;
}

ostream& operator<<(ostream&o,CX thi){
    if(thi.im>=0)
        o<<thi.re<<"+"<<thi.im<<"i";
    else
        o<<thi.re<<thi.im<<"i";
    return o;
}


