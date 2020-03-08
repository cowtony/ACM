/*
给s和t两个字符串，判断s是否被t包含，s中的字符可间断出现在t中，但顺序不能乱

从s的第一个字母开始，一个个的检查t中是否含有

关键词：字符串 
*/
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string s,t;

    while(cin>>s>>t)
    {
        int m=0;
        for(int i=0;i<s.length();i++)
        {
            for (int j=m;j<t.length();j++)
            {
                if(s[i]==t[j]){m=j+1;break;}
                if(j==t.length()-1){cout<<"No"<<endl;goto end;}
            }
        }
        cout<<"Yes"<<endl;
        end:;
    }
    
    return 0;
}
