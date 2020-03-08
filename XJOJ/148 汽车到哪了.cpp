/*
输入站与站之间的距离，再输入路程数，求现在在哪一站或哪两站之间

读入站与站之间的距离，改写成每站与起点的距离
再读入路程数，用二分查找属于哪个位置
不用二分会超时的

关键词：二分查找 
*/ 
#include<iostream>
using namespace std;

int main()
{
    int station[10001];
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,m,ask;
        cin>>n>>m;
        
        station[1]=0;
        for(int i=2;i<=n;i++)
        {
            cin>>station[i];
            station[i]+=station[i-1];
        }

        int start,end,middle;
        while(m--)
        {
            cin>>ask;
            start=1;end=n;
            while(end-start>1)
            {
                middle=(end+start)/2;
                if(station[middle]>=ask)end=middle;
                else if(station[middle]<=ask)start=middle;
            }
            if(station[start]==ask)cout<<start<<endl;
            else if(station[end]==ask)cout<<end<<endl;
            else cout<<start<<' '<<end<<endl;
        }
    }

    return 0;
}
