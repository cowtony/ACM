/*
求矩阵中不相交的两个子矩阵，使其价值乘积最大。矩阵价值就是内部所有元素的和 

设想枚举所有的分割线，把矩阵分成两块，再求每块的最大子矩阵
但是这样有许多重复的运算
求最大子矩阵是遍历所有的行组合，再把它们列值加起来求最大子段和
为了避免重复运算，对整个矩阵遍历行组合，然后存到一个分割线数组
这样最后直接遍历一遍数组就可以找到以哪条分割线左右乘积最大
当然还要考虑列分割，所以转置矩阵后再来一次
还需要考虑的因素是负负得正，两个最小的负值相乘也可以得到很大的正数
所以把前面的过程改成取最小也再来一次

关键词：二维动态规划，最大子矩阵 
*/
#include<iostream>
#define INF_MIN -1000000
#define INF_MAX 1000000
using namespace std;

int matrix[100][100];

int max_DP(int array[],int start,int end)
{
    int max=INF_MIN;
    int b=INF_MIN;
    for(int i=start;i<end;i++)
    {
        if(b>0)b+=array[i];
        else b=array[i];
        if(b>max)max=b;
    }
    return max;
}//最大子段和 

int min_DP(int array[],int start,int end)
{
    int min=INF_MAX;
    int b=INF_MAX;
    for(int i=start;i<end;i++)
    {
        if(b<0)b+=array[i];
        else b=array[i];
        if(b<min)min=b;
    }
    return min;
}//最小子段和 

int main()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>matrix[i][j];
            
    long long max=INF_MIN;//存结果的最大值 
    long long max_boundary[99][2];//最大值的分割线 
    long long min_boundary[99][2];//最小值的分割线 
    
    for(int pppp=0;pppp<2;pppp++)
    {
        for(int i=0;i<99;i++)
            for(int j=0;j<2;j++)
            {
                max_boundary[i][j]=INF_MIN;
                min_boundary[i][j]=INF_MAX;
            }//分割线初始化 
            
        for(int i=0;i<n;i++)
        {
            int sum[100]={0};
            for(int ii=i;ii<n;ii++)
            {
                for(int j=0;j<m;j++)
                    sum[j]+=matrix[ii][j];//遍历所有可能的行组合，sum是加一起得值 
                
                int a=max_DP(sum,0,m);
                int b=min_DP(sum,0,m);

                for(int k=ii;k<n-1;k++)
                {
                    if(max_boundary[k][0]<a)max_boundary[k][0]=a;
                    if(min_boundary[k][0]>b)min_boundary[k][0]=b;
                }
                for(int k=0;k<i;k++)
                {
                    if(max_boundary[k][1]<a)max_boundary[k][1]=a;
                    if(min_boundary[k][1]>b)min_boundary[k][1]=b;
                }//存到分隔线里 
            }
        }
        for(int k=0;k<n-1;k++)
        {
            if(max_boundary[k][0]!=INF_MIN && max_boundary[k][1]!=INF_MIN)
            {
                long long t=max_boundary[k][0]*max_boundary[k][1];
                if(t>max)max=t;
            }
            if(min_boundary[k][0]!=INF_MAX && min_boundary[k][1]!=INF_MAX)
            {
                long long t=min_boundary[k][0]*min_boundary[k][1];
                if(t>max)max=t;
            }
        }//找分割线的最大值 
        
        if(pppp==0)
        {
            for(int i=0;i<100;i++)
                for(int j=i+1;j<100;j++)
                    swap(matrix[i][j],matrix[j][i]);
            swap(m,n);
        }//矩阵转置，再按列分割来一次 
    }
    cout<<max;
    //while(1);
}
