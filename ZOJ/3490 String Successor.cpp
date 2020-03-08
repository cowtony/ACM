/*
给字符串进位，规则是从右往左，给字母或数字加1，如果进位了，那么左边的下一个字母或数字也加1
如果字符串中没有字母或数字则只给最右边的加1
如果最左边的进位了则补添一位同类型的字母或数字

按照规则直接做
进位用一个循环，若没有进位则退出

关键词：字符串 
*/
#include<iostream>
#include<string>
using namespace std;

bool alphanumerics(char c)
{
    if(c>='0' && c<='9')return true;
    if(c>='a' && c<='z')return true;
    if(c>='A' && c<='Z')return true;
    return false;
}//判断一个字符是否为字母或数字 

bool nonalphanumerics(string s)
{
    for(int i=0;i<s.length();i++)
        if(alphanumerics(s[i])==true)return true;
    return false;
}//判断字符串中是否含有字母或数字 

int leftmost_alphanumerics(string s)
{
    for(int i=0;i<s.length();i++)
        if(alphanumerics(s[i])==true)return i;
}//返回最左边的字母或数字的位置 

string successor(string s)
{
    if(nonalphanumerics(s)==false)
    {
        s[s.length()-1]++;
        return s;
    }
    
    int leftmost=leftmost_alphanumerics(s);
    
    for(int i=s.length()-1;i>leftmost;i--)
    {
        if(alphanumerics(s[i])==true)
        {
            if((s[i]>='0'&&s[i]<'9')||(s[i]>='a'&&s[i]<'z')||(s[i]>='A'&&s[i]<'Z'))
            {
                s[i]++;return s;
            }
            else if(s[i]=='9')s[i]='0';
            else if(s[i]=='z')s[i]='a';
            else if(s[i]=='Z')s[i]='A';
        }
    }
    
    if(s[leftmost]=='9')
    {
        s[leftmost]='0';
        s.insert(s.begin()+leftmost,'1');
    }
    else if(s[leftmost]=='z')
    {
        s[leftmost]='a';
        s.insert(s.begin()+leftmost,'a');
    }
    else if(s[leftmost]=='Z')
    {
        s[leftmost]='A';
        s.insert(s.begin()+leftmost,'A');
    }
    else s[leftmost]++;
    
    return s;
}//进位函数 

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        string s;
        cin>>s>>n;
        
        for(int i=0;i<n;i++)
        {
            s=successor(s);
            cout<<s<<endl;
        }
        
        cout<<endl;
    }
}
