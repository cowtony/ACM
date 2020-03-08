/*
给出一个字符串，求出他有多少个回文子串

以给出的字符串每个字母为主线索，作为检索字符串的回文中心
如果是回文的，则向外扩大一位，否则挪向下一个字母作为回文中心
回文中心不仅有是字母的情况，也有两个字母之间的情况
直接枚举各个字母(一个或相邻两个)作为回文中心向外扩展计数。

关键词：字符串，好题 
*/
#include<iostream>
using namespace std;

int main()
{
    char s[5000];
    while(cin>>s)
    {
        int count=0;
        
        for(int i=0;i<strlen(s);i++)
        {
            for(int left=i,right=i;left>=0 && right<strlen(s);left--,right++)
            {
                if(s[left]==s[right])count++;
                else break;
            }
        }
        for(int i=0;i<strlen(s)-1;i++)
        {
            for(int left=i,right=i+1;left>=0 && right<strlen(s);left--,right++)
            {
                if(s[left]==s[right])count++;
                else break;
            }
        }
        cout<<count<<endl;
    }
}
