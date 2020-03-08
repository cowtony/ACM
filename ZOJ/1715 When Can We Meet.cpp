/*
输入N个人有空的日期，以及最少有Q个人参加会议，要求定一个有空人最多的会议日期

用数组date[100]存下有空日期的人数，即每输入一个日期，在该角标上加一。
然后找出有空人数最多的那一天，如果人数小于Q输出0，否则输出那一天的日期

关键词：简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int N,Q;
    while(cin>>N>>Q)
    {
        if(N==0 && Q==0)break;
        
        int date[100]={0};
        for(int i=0;i<N;i++)
        {
            int m;
            cin>>m;
            for(int j=0;j<m;j++)
            {
                int day;
                cin>>day;
                date[day]++;
            }
        }
        
        int max=0,max_date=0;
        for(int i=1;i<100;i++)
        {
            if(date[i]>max)
            {
                max=date[i];
                max_date=i;
            }
        }
        if(max<Q)cout<<0<<endl;
        else cout<<max_date<<endl;
    }
}
