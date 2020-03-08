/*
淘汰赛，每次两两分组后淘汰一半，若人数为奇数则随机选一个人直接晋级，输入人数，输出淘汰至一人所需的轮数

取2的对数再向上取整即可

关键词：数学题，简单题 
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long n;
    while(cin>>n)
    {
        if(n==0)return 0;
        cout<<ceil(log10((double)n)/log10(2.0))<<endl;
    }
}  
