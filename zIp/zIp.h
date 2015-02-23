#include"../zPreq.h"
#include"../zStr/zSTR.h"
class IP{
    public:
        int a;
        int b;
        int c;
        int d;
        IP(int a,int b,int c,int d);
        IP(string addr);
        string type();
        friend ostream&operator<<(ostream&o,IP x);

}
