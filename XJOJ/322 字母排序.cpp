/*
字典中单词的字母均被调换，但是顺序不变。给出按顺序的一些单词，求字母调换顺序 

基本的拓扑排序问题，题目内容有些麻烦

关键词：图论，拓扑排序，STL 
*/
#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    bool path[256][256]={false};
    set<char> cow,temp;
    map<char,char> result;
    
    int A,K;
    cin>>A>>K;
    
    string s0,s1;
    cin>>s0;
    for(int i=1;i<K;i++)
    {
        cin>>s1;
        for(int j=0;j<s0.length();j++)
            if(s0[j]!=s1[j])
            {
                path[s0[j]][s1[j]]=true;
                cow.insert(s0[j]);
                cow.insert(s1[j]);
                break;
            }
        s0=s1;
    }
    
    temp=cow;
    if(cow.size()!=A){cout<<0<<endl;return 0;}
    
    while(cow.size()>0)
    {
        int count=0;
        int min;
        
        for(set<char>::iterator it1=cow.begin();it1!=cow.end();it1++)
        {
            for(set<char>::iterator it2=cow.begin();it2!=cow.end();it2++)
                if(path[*it2][*it1]==true)goto end;
            count++;
            min=*it1;
            end:;
        }
        
        if(count==1)
        {
            result[min]=*(temp.begin());
            cow.erase(min);
            temp.erase(*(temp.begin()));
        }
        else{cout<<0<<endl;return 0;}
    }
    
    cin>>s0;
    for(int i=0;i<s0.length();i++)
        cout<<result[s0[i]];
    
    //while(1);
}
