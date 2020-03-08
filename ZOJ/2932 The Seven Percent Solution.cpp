/*
读入一行字符串，带空格，要求把题中的7个字符转换成相应的代号

读入用cin.getline
然后一个一个字符的找，找到了就用replace函数
输出即可

关键词：字符串，简单题 
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    char c[80];
    
    while(cin.getline(c,80))
    {
        if(c[0]=='#')break;
        
        string s=c;
        for(int i=0;i<s.length();i++)
        {
            switch(s[i])
            {
                case ' ':s.replace(i,1,"%20");break;
                case '!':s.replace(i,1,"%21");break;
                case '$':s.replace(i,1,"%24");break;
                case '%':s.replace(i,1,"%25");break;
                case '(':s.replace(i,1,"%28");break;
                case ')':s.replace(i,1,"%29");break;
                case '*':s.replace(i,1,"%2a");break;
            }
        }
        cout<<s<<endl;
    }
} 
