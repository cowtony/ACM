/*
n个国家外交关系为一个环，依次输入他们的坐标，要求开会时两国走的路程一样，求开会的坐标

读入一堆点，把相邻两点的中点输出即可
注意最后一个点和第一个点也要算

关键词：简单题 
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        double x[1000];
        double y[1000];
        for(int i=0;i<n;i++)
            cin>>x[i]>>y[i];
            
        double xx,yy;
        cout<<n<<" ";
        cout.precision(6);
        for(int i=0;i<n-1;i++)
        {
            xx=(x[i]+x[i+1])/2;
            yy=(y[i]+y[i+1])/2;
            cout<<fixed<<xx<<" "<<fixed<<yy<<" ";
        }
        xx=(x[n-1]+x[0])/2;
        yy=(y[n-1]+y[0])/2;
        cout<<fixed<<xx<<" "<<fixed<<yy<<endl;
    }
}
