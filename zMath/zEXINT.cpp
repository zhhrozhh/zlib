#include"zEXINT.h"
Extint::Extint(){
    this->val=(unsigned long*)malloc(sizeof(unsigned long)*(MAXL+1));
    for(int i=0;i<=MAXL;i++)
        *(this->val+i)=0;
    this->inf=false;
    this->NumOfSegments=0;
}
Extint::Extint(const Extint&oth){
    this->val=(unsigned long*)malloc(sizeof(unsigned long)*(MAXL+1));
    for(int i=0;i<=MAXL;i++)
        *(this->val+i)=*(oth.val+i);
    this->inf=oth.inf;
    
}
void Extint::set(int pos,unsigned long data){
    *(this->val+pos)=data;
}
Extint&Extint::sinf(){
    this->inf=true;
    return*this;
}
void Extint::rerange(unsigned long scale){
    for(int i=0;i<MAXL;i++)
        if(*(this->val+i)>scale){
            *(this->val+i+1)+=(*(this->val+i))/(scale+1);
            *(this->val+i)%=(scale+1);
        }
    if(*(this->val+MAXL)!=0)
        this->inf=true;
}
bool Extint::operator>(Extint oth){
    if(this->inf)
        return true;
    if(oth.inf)
        return false;
    for(int i =MAXL-1;i>=0;i--){
        if(*(this->val+i)>*(oth.val+i))
            return true;
        if(*(this->val+i)<*(oth.val+i))
            return false;
    }
    return false;
}
bool Extint::operator<(Extint oth){
    return oth>(*this);
}
bool Extint::operator==(Extint oth){
    if(this->inf||oth.inf)
        return false;
    for(int i=0;i<MAXL;i++)
        if(*(this->val+i)!=*(oth.val+i))
            return false;
    return true;
}
Extint Extint::operator+(Extint oth){
    Extint res = Extint();
    if(!(this->inf || oth.inf))
        for(int i=0;i<MAXL;i++){
            *(res.val+i)=*(this->val+i)+*(oth.val+i);
            if(*(res.val+i)>MAXM){
                *(res.val+i+1)= *(res.val+i)/(MAXM+1);
                *(res.val+i)%=(MAXM+1);
            }
        }
    if(this->inf||oth.inf||(*(res.val+MAXL)!=0UL))
        res.inf=true;
    return res;
}
Extint Extint::operator-(Extint oth){
    Extint res = Extint();
    if(this->inf||oth.inf)
        return res.sinf();
    if((*this)<oth)
        return res;
    for(int i =MAXL-1;i>=0;i--){
        if(*(this->val+i)>=*(oth.val+i))
            *(res.val+i)=*(this->val+i)-*(oth.val+i);
        else{
            *(res.val+i)=MAXM+1+*(this->val+i)-*(oth.val+i);
            int j = i+1;
            while(*(res.val+j)==0)
                j++;
            *(res.val+j)-=1;
        }
    }
    return res;
}
Extint Extint::operator*(Extint oth){
    Extint res=Extint();
    if(this->inf||oth.inf)
        return res.sinf();
    else{
        for(int i =0;i<=MAXL;i++)
            for(int j=0;j<=MAXL;j++){
                if(i+j<=MAXL)
                    res.val[i+j]=(*(this->val+i))*(*(oth.val+j));
                else if((*(this->val+i))*(*(oth.val+j))>0){
                    res.inf=true;
                    return res;
                }
            }
    }
    res.rerange(MAXM);
    return res;
}
Extint Extint::operator/(Extint oth){
    Extint res=Extint();
    if(this->inf||oth==res)
        return res.sinf();
    else if(oth.inf||(*this)==res)
        return res;
    if(*this<oth)
        return res;
    else{
        int i;
        int j=i=MAXL-1;//since this >= other, i>=j
        while(*(this->val+i)==0)
            i--;
        while(*(oth.val+j)==0)
            j--;
        for(int k=j;k<=i;k++)
            res.set(j-k,*(this->val+k)/(*(oth.val+j)));
    }
    return res;
}

ostream&operator<<(ostream&o,Extint oth){
    if(oth.inf)
        o<<"inf";
    else{
        Extint coth = Extint(oth);
        unsigned long m=1;
        while((m*10)<MAXM)
            m*=10;
        coth.rerange(m-1);
        int x = MAXL-1;
        while(*(coth.val+x)==0)
            x--;
        string res = "";
        for(int i=0;i<=x;i++){
            res = to_string(*(coth.val+i)) + res;
            *(coth.val+i)=((*(coth.val+i)==0)?1:*(coth.val+i));
            while(*(coth.val+i)<m){
                *(coth.val+i)*=10;
                res = "0"+res;
            }
        }
        o<<res;
    }
    return o;
}
