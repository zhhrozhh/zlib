#include"zMath/zMath.h"
int main(){
/*    cout<<(FuncSin(new FuncCos(new FuncConst(2))).d())->expr()<<endl;
    cout<<FuncSin(new FuncSin(new FuncConst(0))).d()->expr()<<endl;
 
    cout<<((fCover(3)+fCover(4))*X())<<endl;
    cout<<((fCover(3)+fCover(4))*X()).simplify()<<endl;
    cout<<DDX(COS(X())*SEC(X()))<<endl;
    cout<<DDX(COS(X())*SEC(X())).simplify().f->expr()<<endl;

    cout<<"=================="<<endl;
    fCover a = COS(X())*X()/(X()+TAN(X()));
    cout<<DDX(a).simplify()<<endl;
    cout<<"F:\t\t\t"<<(TAN(TAN(X())+SIN(X()))*COS(TAN(X())+SIN(X())))<<endl;*/
    Extint a=Extint();
    for(int i = 0;i<20;i++)
        a.set(i,(i+23712)%2731+(i+738234)%9031);
    Extint b=Extint();
    for(int i = 0;i<20;i++)
        b.set(i,(i+51322)%2165+(i+225234)%7045);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<a*b<<endl;


 //   cout<<"simplified F:\t\t"<<(TAN(TAN(X())+SIN(X()))*COS(TAN(X())+SIN(X()))).simplify()<<endl;
  //  cout<<"dF/dx:\t\t\t"<<DDX(TAN(TAN(X())+SIN(X()))*COS(TAN(X())+SIN(X())))<<endl;
    //cout<<"simplified dF/dx:\t"<<DDX(TAN(TAN(X())+SIN(X()))*COS(TAN(X())+SIN(X()))).simplify()<<endl;
/*    
    vector<int>a;
    for(int i=0;i<9;i++)
        a.push_back(((i+31)%7^(i+11)%3)%10);
    MAT<int>x = MAT<int>(3,3,a);
    a.clear(); 
    for(int i=0;i<9;i++)
        a.push_back(((i+29)%5^(i+17)%11)%10);
    MAT<int>y = MAT<int>(3,3,a);
    cout<<x<<y<<x+y<<x*y;
    a.clear();
//=====
    cout<<"||||||||||||||||||||||||||||||"<<endl;
    for(int i=0;i<6;i++)
        a.push_back(((i+31)%7^(i+11)%3)%10);
    MAT<int>z=MAT<int>(2,3,a);
    a.clear();
    for(int i=0;i<6;i++)
        a.push_back(((i+29)%5^(i+17)%11)%10);
    MAT<int>l=MAT<int>(3,2,a);
    cout<<z<<l<<z*l<<(l*z).det()<<endl;

    //=========
    cout<<"|||||||||||||||||||||||||||||||"<<endl;
    cout<<x<<x.trans();
    a.clear();
    a.push_back(1);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(1);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    MAT<int>q=MAT<int>(3,3,a);
    cout<<"|||||||||||||||||||||||||||||||"<<endl;
    cout<<q<<~q<<endl;*/
}

