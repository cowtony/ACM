/*
替换加密

直接做，用map存对照表方便些，注意密文的结束不仅有'\n'还有'\r'
这个读入数据好烦人呀！！！读原密码的时候要用下面这样才行 

关键词：简单题，字符串 
*/
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() 
{ 
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {  
        string s;
        do 
        { 
            getline(cin,s);
        }while (isalpha(s[0])==false);
        
        map<char,char> m;
        for(char i='A';i<='Z';i++)
            cin>>m[i];
            
        for(int i=0;i<s.length();i++) 
            if(s[i]>='A' && s[i]<='Z')s[i]=m[s[i]];
            
        cout<<t<<' '<<s;
    } 
} 
