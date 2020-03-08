/*
一段4.5公里的路，一个人从出发点骑车，他总要和别人一起骑，如果有另一个人超过他他就加速和那个人一起骑
求到终点需要多长时间

由题意知这个人不可能被别人超过，他肯定是最先到的
贪心，O(n)，枚举所有车子，如果：
1. 开始时间 < 0 的，不予考虑，太快的赶不上，太慢的赶上也没用。
2. 开始时间 > 0 的，Charley 和最早到达的车子一起到达。

关键词：贪心，简单题 
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        
        double speed;
        int start;
        double time;
        double min=1e9;
        for(int i=0;i<n;i++)
        {
            cin>>speed>>start;
            if(start>=0)
            {
                time=4.5/speed*3600+start;
                if(time<min)min=time;
            }
        }
        cout<<ceil(min)<<endl;
    }
}
