/*
直线上有n个小镇，有一条高速路穿过这些镇，方向从1到n
总统为了方便人们从大号的镇返回小号的镇，决定再修两条路，它们是直达的，中间不穿过任何镇
两条路的起点和终点也不能在一个镇 
求这两条路总和的最短长度，以及每条路的起点和终点

例如有10个镇
1 2 3 4 5 6 7 8 9 10
人们可以从小数走向大数
如果修两条路，一条从10到4，一条从5到1，人们就可以从任何一个城市到另一个城市了
总长度为1-10加上4-5
因为1-10是必然的，所以找出距离最近的两个镇作为两条路的起点（或终点）就可以了
注意距离最近的两个镇不能是前两个或后两个，因为那样做不成路 

关键词：图论，有向图 
*/
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int position[50000]={0};
        for(int i=1;i<n;i++)
            cin>>position[i];
            
        
        if(n<=3)cout<<0<<endl;
        else
        {
            int pos,min=position[n-1];
            
            for(int i=2;i<n-1;i++)
               if(min>position[i]-position[i-1])
               {
                   min=position[i]-position[i-1];
                   pos=i;
               }
            
            cout<<position[n-1]+min<<endl;
            cout<<pos+1<<' '<<1<<' '<<n<<' '<<pos<<endl;
        }
        
        if(t!=0)cout<<endl;
    }
} 
