#include"zIP.h"
IP::IP(int a,int b,int c,int d){
    this->a=a;
    this->b=b;
    this->c=c;
    this->d=d;
}
IP::IP(string addr){
    vector<string>vec;
    if(addr.size()==15)
        vec=zSsplit(addr,addr[3]);
    else
        vec=zSsplit(zSreduceBlank(addr),zSreduceBlank(addr)[3]);
    this->a=vec[0];
    this->b=vec[1];
    this->c=vec[2];
    this->d=vec[3];
}

ostream&operator<<(ostream&o,IP x){
    o<<x.a<<"."<<x.b<<"."<<x.c<<"."<<x.d<<endl;
}
