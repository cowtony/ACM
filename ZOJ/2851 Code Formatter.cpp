/*
输入一段代码，要求把所有的'\t'替换为四个空格，并且删除每行末尾多余的空格
输出替换了几个'\t'，删除了几个空格

先一行一行的读，每读一行算一行
找出该行字符串所有的'\t'并用replace成员函数替换即可
再从字符串末尾开始找出有多少个空格

关键词：字符串，简单题 
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        int tab=0,space=0;
        while(getline(cin,s))
        {
            if(s=="##")break;
            
            for(int i=0;i<s.length();i++)
                if(s[i]=='\t')
                {
                    tab++;
                    s.replace(i,1,"    ");
                }
                
            for(int i=s.length()-1;i>=0;i--)
            {
                if(s[i]==' ')space++;
                else break;
            }
        }
        cout<<tab<<" tab(s) replaced"<<endl;
        cout<<space<<" trailing space(s) removed"<<endl;
    }
    
    //while(1);
} 
