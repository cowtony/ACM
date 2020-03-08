/*
定义一个数列为3或5的倍数（含3,5），从小到大排列，输入项数n<=100000求该项值

先用数组存储该数列，再直接输出

关键词：数学题，简单题
*/
#include<iostream>
using namespace std;

int main()
{
    int n=0;
    int niu[100000];
      
    for(int i=3;n<100000;i++)
        if(i%3==0||i%5==0)niu[n++]=i;   //生成数列
        
    //freopen("aaa.txt","r",stdin);
    
    while(cin>>n)
    {
        cout<<niu[n-1]<<endl;
    }
    
    //while(1);
    return 0;
}
