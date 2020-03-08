/*
找出数列中的最长降序子串，并且还要输出有多少个不同解

动态规划的经典题，第一问好做
设以第i个元素结尾的子串最大长度为m[i]
那么状态转移方程就是：m[i]=max(m[j])+1  j<i且price[j]>price[i]

但是还得做另外一个动态规划就是解的个数
count[i]表示以第i个元素结尾的解的个数（设当前长度为l）
那么状态转移方程count[i]就是i前面m[j]长度为l-1的和
但是注意如果有m[a]=m[b]=l-1，price[a]=price[b]，那么只加最后面的一个数
具体原因不说了
 
为了方便，在数据最后加了一个-1元素，保证最长的肯定是以最后一个元素结尾的了

关键词：动态规划  
*/
#include<iostream>
#include<set>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int n;
    cin>>n;
    
    int price[5001];
    for(int i=0;i<n;i++)
        cin>>price[i];
    price[n]=-1;
        
    int count[5001];
    int m[5001]={0};
    for(int i=0;i<=n;i++)
    {
        int max=0;
        for(int j=0;j<i;j++)
            if(price[j]>price[i] && max<m[j])
                max=m[j];
        m[i]=max+1;
        
        set<int> s;
        for(int j=i-1;j>=0;j--)
            if(price[j]>price[i] && m[j]==max)
                if(s.find(price[j])==s.end())
                {
                    count[i]+=count[j];
                    s.insert(price[j]);
                }
        if(count[i]==0)count[i]=1;
    }
    
    cout<<m[n]-1<<' '<<count[n];
    //while(1);
}
