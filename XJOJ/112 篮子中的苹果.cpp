/*
有n个篮子，里面装有不同个数的苹果，先拿出一些，再去掉一些篮子（包括篮子里的水果）
保证每个篮子里的水果个数相同，求最后最多可以有多少个苹果 

将苹果个数按大小排好
横轴为篮子编号1到n
纵轴为该篮子里的苹果数
此时图形为单调递减
取图线上一点，去掉纵轴大于它的部分，表示题意中第一次操作
再去掉横轴大于它的部分，表示第二次操作
最后剩下的矩形就是剩余的苹果个数，每篮都相等
遍历横轴找到最大就行了

关键词：巧算法，简单题 
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    int apple[50];
    cin>>n;
    
    for(int i=0;i<n;i++)
        cin>>apple[i];
    
    sort(apple,apple+n);
    
    int max=0,count;
    for(int i=0;i<n;i++)
    {
        count=apple[i]*(n-i);
        if(count>max)max=count;
    }
    
    cout<<max;
    
    //while(1);
    return 0;
}
