/*
一个带（负）权的有向无环图，起初有一个血值，每走一条路血值乘以2再加上路的权
期间及最后都不能让血值为负，求起点时的最小血值

利用逆推的思想，最后一个节点的血值为1
可以得到上一个节点的血值value=ceil((min_HP[i]-map[j][i])/2.0);
最小血值是他的所有下一结点推回来的值中最小的一个
然后利用（逆）拓扑排序最终推回第一项就可以了

关键词：动态规划，图论，拓扑排序 
*/
#include<iostream>
#include<cmath>
#define MAXN 10000000
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    int N;
    cin>>N;
    
    int map[100][100];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>map[i][j];
            
    bool used[100]={0};
    int min_HP[100];
    for(int i=0;i<N;i++)
        min_HP[i]=MAXN;
    min_HP[N-1]=1;
    
    int count=1;
    while(count<N)
    {
        for(int i=0;i<N;i++)if(used[i]==false)
        {
            for(int j=0;j<N;j++)
                if(map[i][j]!=0)goto end;
            
            for(int j=0;j<N;j++)
            {
                if(map[j][i]!=0)
                {
                    int value=ceil((min_HP[i]-map[j][i])/2.0);
                    min_HP[j]=min(min_HP[j],max(value,1));
                }
                map[j][i]=0;
            }
            used[i]=true;count++;
            end:;
        }
    }
    
    cout<<min_HP[0];
    //while(1);
}
