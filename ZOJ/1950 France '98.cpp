/*
输入16阶的方阵，表示第i国踢赢第j国的概率
求16个国家淘汰赛最后每个国家得冠军的概率

画一个二叉树 
先读入数据。设i-j格式为第i国踢赢第j国的概率，那么16国每国进八强的概率为：
1-2 2-1 3-4 4-3 5-6 6-5 7-8 8-7 9-10 10-9 11-12 12-11 13-14 14-13 15-16 16-15
再看第一个国家进四强的概率：
第一个国家进八强*（第一个国家踢赢第三个国家*第三个国家进八强+第一个国家踢赢第四个国家*第四个国家进八强） 
写出来就是1-2*(1-3*3-4+1-4*4-3)
定义一个数组percentage[4][16]
percentage[0][j]表示第j个国家进八强的概率 
percentage[1][j]表示第j个国家进四强的概率 
percentage[2][j]表示第j个国家进二强的概率 
percentage[3][j]表示第j个国家的冠军的概率 
所以再看第一个国家进四强的概率：
percentage[0][1]*(1-3*percentage[0][3]+1-4*percentage[0][4]) 
第一个国家进二强的概率：
percentage[1][1]*(1-5*percentage[1][5]+1-6*percentage[1][6]+1-7*percentage[1][7]+1-8*percentage[1][8]) 
知道了原理后，用一堆for去算出所有的percentage就行了
实现很需要技巧，我不是说我有技巧。。

还有输出格式考得很多，多看iomanip

关键词：数学题，概率题 
*/
#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    string country[16];
    for(int i=0;i<16;i++)
        cin>>country[i];
        
    double win[16][16];
    for(int i=0;i<16;i++)
        for(int j=0;j<16;j++)
        {
            cin>>win[i][j];
            win[i][j]/=100.0;
        }
    
    double percentage[4][16]={0};
    for(int i=0;i<16;i+=2)
    {
        percentage[0][i]=win[i][i+1];
        percentage[0][i+1]=win[i+1][i];
    }
    
    for(int i=1;i<4;i++)//八强，四强，二强，决赛 
    {
        int group=pow(2.0,i);
        for(int j=0;j<16;j+=2*group)
        {
            for(int k=j;k<j+group;k++)
            {
                for(int l=j+group;l<j+2*group;l++)
                    percentage[i][k]+=win[k][l]*percentage[i-1][l];//k打败l的概率乘以l出线的概率 
                percentage[i][k]*=percentage[i-1][k];//最后再乘以k出线的概率 
            }
            for(int k=j+group;k<j+2*group;k++)
            {
                for(int l=j;l<j+group;l++)
                    percentage[i][k]+=win[k][l]*percentage[i-1][l];
                percentage[i][k]*=percentage[i-1][k];
            }
        }
    }
    
    for(int i=0;i<16;i++)
    {
        double p=int(percentage[3][i]*10000+0.5)/100.0;
        cout.precision(2);
        cout<<left<<setw(10)<<country[i]<<" p="<<fixed<<p<<"%"<<endl;
    } 
    
    //while(1);
}
