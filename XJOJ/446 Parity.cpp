/*
二进制串中1的个数为奇数则为“odd parity”，否则为“even parity”
输入一个二进制串，最后一位被替换为'e'或'o'，求原串

直接统计，判断，一改，输出

关键词：简单题 
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    while(cin>>s)
    {
        if(s=="#")break;
        
        int count=0;
        for(int i=0;i<s.length();i++)
            if(s[i]=='1')count++;
            
        int last=s.length()-1;
        if(s[last]=='e')
        {
            if(count%2==0)s[last]='0';
            else s[last]='1';
        }
        else
        {
            if(count%2==0)s[last]='1';
            else s[last]='0';
        }
        cout<<s<<endl;
    }
} 
