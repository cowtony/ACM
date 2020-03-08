/*
求n<=100000的因子和

用筛法算出100000内每个数的因子和，再直接输出
本题将该数本身也算为该数的因数 

关键词：数学题
*/
#include<iostream>
#define SIZE 100000
using namespace std;

int main()
{
    int factor[SIZE+1]={0};
    int t,n;
    
    for(int i=1;i<=SIZE;i++)
        for(int j=i;j<=SIZE;j+=i)
            factor[j]+=i;              //筛，求各个因子和
    
    //freopen("aaa.txt","r",stdin);
    
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",factor[n]);   //用cin和cout会超时
    }
    
    //while(1);
    return 0;
}

