/*
翻译凯撒密码，所有的大写字母循环左移五位

简单，读入，翻译，输出

关键词：字符串，简单题 
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    char s[200];
    string ss;
    while(cin.getline(s,200))
    {
        ss=s;
        if(ss=="START" || ss=="END")continue;
        if(ss=="ENDOFINPUT")break;
        
        for(int i=0;i<strlen(s);i++)
            if(s[i]>='A' && s[i]<='Z')
                s[i]=((s[i]-'A')+26-5)%26+'A';
        
        cout<<s<<endl;
    }
}
