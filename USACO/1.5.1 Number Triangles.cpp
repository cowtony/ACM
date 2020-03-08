/*
ID:cowtony1
PROG:numtri
LANG:C++
读入一个数字金字塔，找出一条路线使得和最大，输出最大值

简单的动态规划
状态转移方程：number[i][j]+=max(number[i-1][j-1],number[i-1][j]);
就是说当前格子的最大值是上面两个最大值中较大的一个加上自己
最后在最底下一行找出最大值就行了

关键词：动态规划，简单题 
*/
#include<iostream>
#include<fstream>
using namespace std;

int number[1001][1001]={0};

int main()
{
    ifstream cin("numtri.in");
    ofstream cout("numtri.out");
    
    int R;
    cin>>R;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=i;j++)
            cin>>number[i][j];
    
    for(int i=2;i<=R;i++)
        for(int j=1;j<=i;j++)
            number[i][j]+=max(number[i-1][j-1],number[i-1][j]);
    
    int max_value=0;
    for(int j=1;j<=R;j++)
        max_value=max(max_value,number[R][j]);
    
    cout<<max_value<<endl;
}
