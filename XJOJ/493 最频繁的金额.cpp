/*
输入N<=1000000个数，其中有一个数至少出现了N/2次，求该数

可以直接读入，再快排，输出中间那个元素
还有线性复杂度算法，因为有一个数出现了一半次以上，所以每次消掉两个不同的，最后剩下的肯定是题目所求数字
代码见下
输出要保留小数点后两位
时间卡的很严 

关键词：有想法，巧算法 
*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int N;
    cin>>N;
    
    double temp;
    int count=0;
    
    for(int i=0;i<N;i++)
    {
        double d;
        scanf("%lf",&d);
        
        if(count==0)
        {
            temp=d;
            count++;
        }
        else
        {
            if(d==temp)count++;
            else count--;
        }
    }
    printf("%.2lf",temp);
}
