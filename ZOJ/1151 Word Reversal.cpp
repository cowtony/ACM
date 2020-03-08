/*
输入带空格的几句话，把每句话中的每个单词反转后再输出

格式很麻烦，并且用cin.get这一类读入一句话后总有诡异的事情发生
一个一个字符输入再判断也有些麻烦
所以一个一个的单词读入，再读入一个字符判断是空格还是回车

关键词：字符串 
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
    int n,m;
    string word;

    cin>>n;
    while(n--)
    {
        cin>>m;
        while(m)
        {
            cin>>word;
            for(int i=word.size()-1;i>=0;i--)cout<<word[i];//逆序输出单词 
            
            if(getchar()=='\n'){m--;cout<<endl;}
                else cout<<' ';//判断是换行还是继续输出下一个单词 
        }
        
        if(n>0)cout<<endl;//每做完一个testcase多回车一下，最后一个不回车 
    }
    
    return 0;
}
