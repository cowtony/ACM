/*
输入许多颜色（字符串），输出出现次数最多的那个

用map做
熟悉怎么用map查找

关键词：STL，map，简单题 
*/
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        
        string s;
        map<string,int> m;
        while(n--)
        {
            cin>>s;
            m[s]++;
        }
        
        int max=0;
        map<string,int>::iterator it,it2;
        for(it=m.begin();it!=m.end();it++)
            if((*it).second>max)
            {
                max=(*it).second;
                it2=it;
            }
            
        cout<<(*it2).first<<endl;
    }
}
