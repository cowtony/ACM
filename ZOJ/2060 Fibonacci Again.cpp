/*
斐波那契数列中F(0)=7,F(1)=11，要求输入项数，输出该项能否被3整除

7,11,18,29,47,76,123,199,322,521,843....
     yes         yes             yes
找规律可以看出从第二项开始每四项出现一个三的倍数

关键词：巧算法，数学题 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    
    while(cin>>n)
    {
        if(n%4==2)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    
    return 0;
}
