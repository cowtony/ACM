/*
输入正N边形的边数，输出里面有多少对平行线（算上所有对角线）

找规律，边数分奇偶两种情况
奇数对每一条边而言有int(n/2)-1条对角线和他平行
所以这个方向的平行线对数为C(n/2,2)
乘以n就是总数
偶数情况稍微复杂一些，但原理和上面一样

关键词：巧算法，数学题
*/
#include<iostream>
using namespace std;

int c(int a,int b=2)
{
    return a*(a-1)/2;
}

int main()
{
    int n;
    cin>>n;
    
    if(n%2==1)
        cout<<n*c(n/2,2);
    else
        cout<<n/2*(c(n/2,2)+c(n/2-1,2));

    //while(1);
    return 0;
}
