/*
ID:cowtony1
PROG:prefix
LANG:C++
有一个字符串集合，和一个字符串，求这个字符串前面最多多少个字符可以表示成集合字符串加起来？

动态规划，bool dp[i]表示第i个字符及以前都可以被表示出来
那么就存在集合中的一个长度为a的元素，满足dp[i-a]=true，并且该字符串与i-a~i这一段相同
全部搜索完了以后找出最大的i使得dp[i]=true即可

关键词：动态规划 
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string set[201];
string m;

bool check(int i,int j)
{
    for(int k=0;k<set[j].length();k++)
        if(set[j][k]!=m[i-set[j].length()+k])return false;
    return true;
}

int main()
{
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    
    int n=0;
    string temp;
    while(cin>>temp && temp!=".")set[n++]=temp;
    while(cin>>temp)m+=temp;

    bool dp[200001]={1};
    for(int i=0;i<=m.length();i++)
        for(int j=0;j<n;j++)
        {
            if(i<set[j].length()-1)continue;
            if(check(i,j)==true)dp[i]=dp[i]||dp[i-set[j].length()];
        }
    
    for(int i=m.length();i>=0;i--)
        if(dp[i]==true){cout<<i<<endl;break;}
}
