/*
用同样正方体堆一堆高度不等的柱子，问最少挪几次可以使它们高度都相等

先求出总数，除以柱子数就是最终高度，再将原数据中所有高出最终高度的部分加起来就是结果

关键词：简单题
*/
#include<iostream>
using namespace std;

int main()
{
    int n,t,sum,result,count=1;
    int hi[50];
   
    //freopen("aaa.txt","r",stdin);
    
    while(cin>>n,n!=0)   //读取方块柱子的个数
    {
        result=0;
        sum=0;t=n;
        
        while(t--)      //读取每个柱子的高度
        {
            cin>>hi[t];
            sum+=hi[t];
        }
        
        sum/=n;       //算出平均高度
        for(int i=0;i<n;i++)
        {
            if(hi[i]>sum)result+=hi[i]-sum;
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",count++,result);
    }
    
    //while(1);
    return 0;
}

