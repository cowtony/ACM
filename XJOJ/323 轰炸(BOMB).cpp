/*
输入1<n<700个整数点，输出最多有几个点在一条直线上

暴力搜索，先用i,j确定两个点(j>i)
再搜索还有多少个点在ij这条线上

关键词：简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int n,point[700][2];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>point[i][0]>>point[i][1];
        
    int max=2;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            int count=2;
            for(int k=j+1;k<n;k++)
                if((point[k][0]-point[j][0])*(point[j][1]-point[i][1])==(point[k][1]-point[j][1])*(point[j][0]-point[i][0]))
                    count++;
            if(count>max)max=count;
        }
    cout<<max;
    
    //while(1);
}
