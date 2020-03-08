/*
给一堆点的坐标，求这些点可以组成多少个边垂直于坐标轴的矩形

直接枚举，先枚举左下角的点，再枚举右下角的点
然后是右上角的，最后是左上角的，一层一层判断是否可以构成矩形
四个for套一起

关键词：简单题，枚举 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    int point[1000][2];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>point[i][0]>>point[i][1];
        
    int count=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(point[j][1]==point[i][1] && point[j][0]>point[i][0])
                for(int k=0;k<n;k++)
                    if(point[k][0]==point[j][0] && point[k][1]>point[j][1])
                        for(int l=0;l<n;l++)
                            if(point[l][1]==point[k][1] && point[l][0]==point[i][0])
                                count++;
    cout<<count;
    
    //while(1);
}
