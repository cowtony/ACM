/*
输入一些单词对应的老鼠语言，再输入一些老鼠单词，输出他们的翻译

map映照容器题
读入数据有些需要技巧
sscanf 

关键词：STL，map，搜索 
*/
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string,string> m;
    map<string,string>::iterator p;
    char word[100];
    
    while(gets(word))
    {
        if(strlen(word)==0)break;
        
        char w[100],mouse[100];
        sscanf(word,"%s %s",w,mouse);
        m[mouse]=w;
    }
    
    while(cin>>word)
    {
        p=m.find(word);
        if(p!=m.end())cout<<m[word]<<endl;
        else cout<<"eh"<<endl;
    }
}
