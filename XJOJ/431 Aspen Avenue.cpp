/*
路的左侧有n<=2000棵树，已知位置，现在要把树摆在路两边，树要成对出现，并且间隔一致
求最少需要挪动的距离

如果没有间隔一致这个条件就可以贪心了，现在用动态规划
dp[i][j]表示摆好了i棵树，左边有j棵
其他的自己想吧，这题做得真烦

关键词：动态规划 
*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

double dp[2001][2001];

double distance(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    //freopen("aaa.txt","r",stdin);
    int n,l,w;
    cin>>n>>l>>w;
    double base=l/double(n/2-1);
    
    double point[2001];
    for(int i=1;i<=n;i++)
        cin>>point[i];
    sort(point+1,point+1+n);
    
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        double x1=0,y1=point[i];
        double x2=0,y2=(i-1)*base;
        dp[i][i]=dp[i-1][i-1]+distance(x1,y1,x2,y2);
        x2=w,y2=(i-1)*base;
        dp[i][0]=dp[i-1][0]+distance(x1,y1,x2,y2);
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {//注意，这里记得j不能等于i，因为下面有i-j-1不然就变成-1了
            double x1=0,y1=point[i];
            double x2=0,y2=(j-1)*base;
            double dist1=dp[i-1][j-1]+distance(x1,y1,x2,y2);
            x2=w;y2=(i-j-1)*base;
            double dist2=dp[i-1][j]+distance(x1,y1,x2,y2);
            dp[i][j]=min(dist1,dist2);
        }
    }
    cout.precision(10);
    cout<<fixed<<dp[n][n/2];
    
    //while(1);
}
