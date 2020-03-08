/*
输入字典中的单词，再输入一段话，输出这段话中属于字典的单词分别出现的次数以及没在字典的单词数

直接模拟，用map便于实现

关键词：map，STL 
*/
#include<iostream>
#include<map>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int n;
    cin>>n;
    
    map<string,int> m;
    string dictionary[1000];
    for(int i=0;i<n;i++)
    {
        cin>>dictionary[i];
        m[dictionary[i]]=0;
    }
    
    string word;
    int other=0;
    while(cin>>word)
    {
        if(m.find(word)==m.end())
            other++;
        else m[word]++;
    }
    
    for(int i=0;i<n;i++)
        cout<<m[dictionary[i]]<<endl;
    cout<<other<<endl;
    
    //while(1);
}
