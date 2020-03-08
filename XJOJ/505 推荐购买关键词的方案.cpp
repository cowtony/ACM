/*
在N个关键词中选出某几个，使其价值总和尽可能大并且不大于B

深度优先搜索枚举所有组合即可
也可以用动态规划背包，我不会

关键词：DFS 
*/
#include<iostream>
using namespace std;

int total;
int cost[20];
int MAX;
int N,B;

void DFS(int sum,int present)
{
    if(sum>total)return;
    else MAX=max(MAX,sum);
    
    for(int i=present;i<N;i++)
        DFS(sum+cost[i],i+1);
}

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N>>B;
        
        total=0;
        MAX=0;
        for(int i=0;i<N;i++)
        {
            cin>>cost[i];
            total+=cost[i];
        }
        total=total-B;
        DFS(0,0);
        cout<<total-MAX<<endl;
    }
    
    
    //while(1);
}
