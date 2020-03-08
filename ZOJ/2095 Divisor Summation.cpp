/*
求n<=500000的因子和

用筛法算出500000内每个数的因子和，再直接输出

关键词：数学题
*/
#include<iostream>
#define SIZE 500000
using namespace std;

int main()
{
    int factor[SIZE+1]={0};
    int x,n;
    
    for(int i=1;i<=SIZE/2;i++)
        for(int j=i*2;j<=SIZE;j+=i)
            factor[j]+=i;              //筛，求各个因子和
    
    //freopen("aaa.txt","r",stdin);
    
    cin>>x;
    while(x--)
    {
        scanf("%d",&n);
        printf("%d\n",factor[n]);   //用cin和cout会超时
    }
    
    //while(1);
    return 0;
}

