#ifndef ZSTRING
#define ZSTRING
#include"../zPreq.h"
#include<vector>

vector<string>zSsplit(string str, string flag);
vector<string>zSsplit(string str,char flag);
vector<string>zSsplit(char*str,char flag);
vector<string>zSsplit(char*str,char*flag);
vector<string>zSsplit(char*str,string flag);
vector<string>zSsplit(string str,char*flag);
string zSreduceBlank(string str);
string zSreduceBlank(char*str);
string zSremoveBlank(string str);
string zSremoveBlank(char*str);

#endif
