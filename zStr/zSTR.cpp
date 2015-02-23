#include"zSTR.h"

vector<string>zSsplit(string str,string flag){
    vector<string> res;
    string a=str;
    while(a.size()>0){
        res.push_back(a.substr(0,a.find(flag)));
        a=a.substr(a.find(flag)+flag.size(),a.size());
        if(a.find(flag)==a.npos){
            res.push_back(a);
            break;
        }
    }
    return res;
}

vector<string>zSsplit(string str,char flag){
    string f="";
    f+=flag;
    return zSsplit(str,f);
}

vector<string>zSsplit(char*str,char flag){
    string st = str;
    string f="";
    f+=flag;
    return zSsplit(st,f);
}

vector<string>zSsplit(char*str,char*flag){
    string st=str;
    string f=flag;
    return zSsplit(st,f);
}
vector<string>zSsplit(char*str,string flag){
    string st = str;
    return zSsplit(st,flag);
}

vector<string>zSsplit(string str,char* flag){
    string f = flag;
    return zSsplit(str,f);
}

bool isblank(char a){
    return (a==' ')||(a=='\n')||(a=='\t');
}

string zSreduceBlank(string str){
    string res;
    for(int i=0;i<=str.size();i++){
        if(!isblank(str[i]))
            res.push_back(str[i]);
        else
            if(!isblank(str[i+1]))
                res.push_back(' ');
    }
    return res;
}

string zSremoveBlank(string str){
    string res;
    for(int i=0;i<=str.size();i++)
        if(!isblank(str[i]))
            res.push_back(str[i]);
    return res;
}


string zSreduceBlank(char*str){
    string st = str;
    return zSreduceBlank(st);
}

string zSremoveBlank(char*str){
    string st=str;
    return zSremoveBlank(st);
}


