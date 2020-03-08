/*
根据所给的规则计算误差传递数列

可以读一个数据算一个，没必要开数组

关键词：简单题 
*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        int ai;
        int bi;
        int ri=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ai);
            if(ai+ri<128)
            {
                printf("0");
                ri=ai+ri;
            }
            else
            {
                printf("1");
                ri=ai+ri-255;
            }
        }
        printf("\n");
    }
    
    
    //while(1);
}
