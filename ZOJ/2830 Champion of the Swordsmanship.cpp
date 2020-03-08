/*
一种比赛可以3人也可以2人玩，只有一人胜出，输入人数，求最少比赛局数

思路是让三个人比赛，一个人胜出
就是说比一次少两个人
最后要是剩一个人就是结束
剩两个人就再比一局
总结下来正好是n/2
或者去模拟这个过程算出结果也行（超时）

关键词：巧算法，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        cout<<n/2<<endl;
    }
}
