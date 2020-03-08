/*
ID:cowtony1
PROG:namenum
LANG:C++

读入一个字典，再读入一个数字串表示在手机上的按键，输出字典中能按出来的单词，没有则输出NONE

可以先建立字母对应数字的匹配
然后每读一条单词就把它转换成数字串，看是否和读入的一样

关键词：直接做，简单题 
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    
    char trans[26]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};
    
    string num;
    cin>>num;
    
    ifstream infile("dict.txt");
    string word;
    bool flag=false;
    while(infile>>word)
    {
        string temp=word;
        for(int i=0;i<temp.length();i++)
            temp[i]=trans[temp[i]-'A'];
        if(num==temp){cout<<word<<endl;flag=true;}
    }
    if(flag==false)cout<<"NONE"<<endl;
}
