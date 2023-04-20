/*
ID: cowtony1
PROG: milk2
LANG: C++
输入N个工人挤奶的时间段，求至少有一人工作的最长持续时间和没有人工作的最长持续时间

读入数据，按开始工作的时间排序，然后模拟记录下最大值即可

关键词：模拟 
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

struct Time
{
    int start,end;
    bool operator <(const Time t)const
    {
        return start<t.start;
    }
};
int main()
{
    ofstream cout("milk2.out");
    ifstream cin("milk2.in");
    int N;
    cin>>N;
    Time time[5000];
    for(int i=0;i<N;i++)
        cin>>time[i].start>>time[i].end;
    sort(time,time+N);
    
    int left=time[0].start,right=time[0].end;
    int max_y=0,max_n=0;
    
    for(int i=0;i<N;i++)
    {
        if(time[i].start>right)
        {
            left=time[i].start;
            max_n=max(max_n,time[i].start-right);
        }
        right=max(right,time[i].end);
        max_y=max(max_y,right-left);
    }
    cout<<max_y<<' '<<max_n<<endl;
    //while(1);
}
