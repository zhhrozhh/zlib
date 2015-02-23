#include"zTRI.h"

double zMOD(double a,double b){
    return a-(double)((int)(a/b))*b;
}
double fac(int x){
    if(x==0)
        return 1;
    double sum=1;
    for(int i=1;i<=x;i++)
        sum*=i;
    return sum;
}

double pwN(double base,int index){
    if(index<=0)
        return 1;
    if(index==1)
        return base;
    if(index==2)
        return base*base;
    if(index==3)
        return base*base*base;
    if(index==4)
        return base*base*base*base;
    return pwN(pwN(base,4),index/4)*pwN(base,index%4);
}


double pi(int s){
    double sum=0;
    for(int i=0;i<=s;i++)
        sum+=pwN(-1,i)/(2*i-1);
    return sum;
}

double sin(double x,int s){
    double sum = 0;
    for(int i=0;i<s;i++)
        sum+=pwN(x,2*i+1)*pwN(-1,i)/fac(2*i+1);
    return sum;
}
double cos(double x,int s){
    double sum=0;
    for(int i=0;i<=s;i++)
        sum+=pwN(x,2*i)*pwN(-1,i)/fac(2*i);
    return sum;
}
double tan(double x,int s){
    return sin(x,s)/cos(x,s);
}
double cot(double x,int s){
    return 1/tan(x,s);
}
double sec(double x,int s){
    return 1/cos(x,s);
}
double csc(double x,int s){
    return 1/sin(x,s);
}

double exp(double x,int s){
    double sum = 0;
    for(int i=0;i<=s;i++)
        sum+=pwN(x,i)/fac(i);
    return sum;
}

double e(int s){
    return exp(1,s);
}

double ln(double x,int s){
    double sum=0;
    if(x<=0)
        return x/(s-s);
    if(x<2){
        for(int i=1;i<=s;i++)
            sum+=pwN(-1,i)*pwN(-1+x,i)/i;
    return -sum;
    }
    if(x>=2){

        for(int i=1;i<s;i++)
            sum+=pwN(-1,i)/(i*pwN(x-1,i));
        return ln(x-1)-sum;
    }
    return sum;
}



double sinh(double x,int s){
    double sum=0;
    for(int i=0;i!=s;i++)
        sum+=pwN(x,1+2*i)/fac(1+2*i);
    return sum;
}

double cosh(double x,int s){
    double sum=0;
    for(int i=0;i<=s;i++)
        sum+=pwN(x,2*i)/fac(2*i);
    return sum;
}

double tanh(double x,int s){
    return sinh(x,s)/cosh(x,s);
}
double coth(double x,int s){
    return 1/tanh(x,s);
}
double sech(double x,int s){
    return 1/cosh(x,s);
}
double csch(double x,int s){
    return 1/sinh(x,s);
}

