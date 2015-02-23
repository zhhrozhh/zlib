#include"zFI.h"

void zFcompare(ifstream&a,ifstream&b){
    string sa;
    string sb;
    int i=1;
    while(getline(a,sa)&&getline(b,sb)){
        cout<<"l "<<i<<":";
        i++;
        if(sa == sb)
            cout<<"s"<<endl;
        else
            cout<<"d"<<endl;
    }
}
