#ifndef ZMATRIX
#define ZMATRIX
#include"../zPreq.h"
#include<stdio.h>
#include<stdlib.h>
#include<vector>
void MErr(string a);
template<class T>
class MAT{
    public:
        T*mat;
        int r;
        int l;
        MAT(int a,int b):r(a),l(b){
            this->mat=(T*)malloc(sizeof(T)*a*b);
        }
        MAT(int a,int b,vector<T>m):r(a),l(b){
            if(a*b!=m.size())
                MErr("Me01");
            this->mat=(T*)malloc(sizeof(T)*a*b);
            for(int i=0;i<a*b;i++)
            *(this->mat+i) = m[i];
        }
        MAT(int a,int b,T*m):r(a),l(b){
            this->mat=(T*)malloc(sizeof(T)*a*b);
            for(int i=0;i<a*b;i++)
                *(this->mat+i)=*(m+i);
        }
        T*getEw(int a,int b){
            return this->mat+((a-1)*this->l)+b-1;
        }
        T getEr(int a,int b){
            return *getEw(a,b);
        }
        T trace(){
            if(this->r!=this->l)
                MErr("Me01");
            T res=this->getEr(1,1);
            for(int i=2;i<=this->r;i++)
                res = res+getEr(i,i);
            return res;
        }
        T det(){
            if(this->r!=this->l)
                MErr("Me02");
            if(this->r==1)
                return *(this->mat);
            if(this->r==2)
                return this->getEr(1,1)*this->getEr(2,2)-this->getEr(1,2)*this->getEr(2,1);
            T sum = this->getEr(1,1)*(this->minor(1,1).det());
            for(int i=2;i<r;i++)
                sum = sum+ (i%2?(this->getEr(1,i)*(this->minor(1,i).det())):-(this->getEr(1,i)*(this->minor(1,i).det())));
            return sum;
        }
        MAT minor(int a,int b){
            if(this->r!=this->l)
                MErr("Me02");
            if(this->r==1)
                MErr("Me03");
            vector<T> r;
            for(int i=1;i<=this->r*this->r;i++)
                if(((i%this->l!=0?(i%this->l):(this->l))!=a)&&(((i-1)/(this->l)+1)!= b))
                    r.push_back(this->mat[i-1]);
            return MAT(this->r-1,this->r-1,r);
        }
        MAT trans(){
            vector<T> a;
            for(int i=0;i<this->r*this->l;i++)
                a.push_back(*(this->mat+((((i+1)%this->r==0)?(this->r):((i+1)%this->r))-1)*this->l+i/this->l));
            return MAT(this->l,this->r,a);
        }
        MAT operator+(MAT oth){
            if(this->r!=oth.r || this->l!=oth.l)
                MErr("Me04");
            MAT res=MAT(this->r,this->l);
                for(int i=0;i<this->r*this->l;i++)
                    *(res.mat+i)=*(this->mat+i)+*(oth.mat+i);
            return res;
        }
        MAT operator-(MAT oth){
            if(this->r!=oth.r || this->l!=oth.l)
                MErr("Me04");
            MAT res=MAT(this->r,this->l);
                for(int i=0;i<this->r*this->l;i++)
                    *(res.mat+i)=*(this->mat+i)-*(oth.mat+i);
            return res;
        }
        MAT operator*(MAT oth){
            if(this->l!=oth.r)
                MErr("Me05");
            vector<T>v;
            for(int i=1;i<=this->r*oth.l;i++){
                int a = (i%oth.l==0)?(this->r):(i%other.l);
                int b = (i-1)/oth.l+1;
                T sum = this->getEr(b,1)*oth.getEr(1,a);
                for(int j=2;j<=oth.r;j++)
                    sum = sum + this->getEr(b,j)*oth.getEr(j,a);
                v.push_back(sum);
            }
            return MAT(this->r,oth.l,v);
        }
        MAT operator/(MAT oth){
            MAT t = MAT(this->r,this->l,this->mat);
            return t*~oth;
        }
        MAT operator*(T oth){
            vector<T>m;
            for(int i=0;i<this->r*this->l;i++)
                m.push_back(*(this->mat+i)*oth);
            return MAT(this->r,this->l,m);
        }
        MAT operator/(T oth){
            vector<T>m;
            for(int i=0;i<this->r*this->l;i++)
                m.push_back(*(this->mat+i)/oth);
            return MAT(this->r,this->l,m);
        }
        MAT operator~(){
            if(this->r!=this->l)
                MErr("Me02");
            T de = this->det();
            vector<T> a;
            for(int i=0;i<this->r*this->l;i++)
                a.push_back((this->minor(i/this->l+1,(i+1)%this->r?((i+1)%this->r):this->r)).det()/(i%2?-de:de));
            return MAT(this->l,this->r,a);
        }
        MAT operator+(){
            return MAT(this->r,this->l,this->mat);
        }
        MAT operator-(){
            vector<T>a;
            for(int i=0;i<this->l*this*r;i++)
                a.push_back(-*(this->mat+i));
            return MAT(this->r,this->l,a);
        }
        MAT EntrywiseP(MAT oth){
            if(this->r!=oth.r || this->l!=oth.l)
                MErr("Me04");
            MAT res=MAT(this->r,this->l);
                for(int i=0;i<this->r*this->l;i++)
                    *(res.mat+i)=*(this->mat+i)* *(oth.mat+i);
            return res;
        }
        MAT KroneckerP(MAT oth);

};
template<class T>
ostream&operator<<(ostream&o,MAT<T>m){
    o<<endl;
    for(int i=1;i<=m.r;i++){
        for(int k=1;k<=m.l;k++)
            o<<m.getEr(i,k)<<"\t\t";
        o<<endl;
    }
    return o;
}

#endif
