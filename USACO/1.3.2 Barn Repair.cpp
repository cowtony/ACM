/*
ID:cowtony1
PROG:barn1
LANG:C++

有S个牛棚，有的牛棚里有牛，共有C头牛。现在要拿木板盖上所有的牛，要求木板最多M块，求木板最少多长

肯定是木板M块最好，也就是有M-1个间隙
算出连续空牛棚的长度，排序后最大的M-1个空着最省木板
注意当M>=C时直接输出C就行了 

关键词：贪心
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    
    int M,S,C;
    cin>>M>>S>>C;
    
    bool cow[201]={0};
    for(int i=0;i<C;i++)
    {
        int t;
        cin>>t;
        cow[t]=true;
    }
    
    vector<int> v;
    int c=0;
    for(int i=1;i<=S;i++)
        if(cow[i]==false)c++;
        else
        {
            v.push_back(c);
            c=0;
        }
    v.push_back(c);
    
    int sum=S-v[0]-v[v.size()-1];
    v.erase(v.begin());
    v.erase(v.end()-1);
    sort(v.begin(),v.end(),greater<int>());

    for(int i=0;i<M-1;i++)
        sum-=v[i];
    
    if(M>=C)cout<<C<<endl;
    else cout<<sum<<endl;
}
