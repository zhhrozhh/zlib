#include"zOFU.h"

int Comb(int r,int n){
    return fac(n)/(fac(r)*fac(n-r));
}
int Perm(int r,int n){
    return fac(n)/fac(n-r);
}

double Ber_H(double pSum,int x){
    return 0;
}

double BernoulliN(int x){
    if(x==0)
        return 1;

    return 0;
}
