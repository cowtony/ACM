/*
给出a*b的点阵，要求用最短的路线经过格子每一点，可以走斜线，输出最短路程

若a*b为偶数，则至少有一边为偶数，蛇形绕完即可，不需走斜线，易证出所走路程即为a*b
若a*b为奇数，则每一边都有奇数个点，最少走一条斜线，所以最短路程为a*b+sqrt(2)

关键词：巧方法
*/
#include<iostream>
#include<cmath>
#include<iomanip>   //用于控制输出精度
using namespace std;

int main()
{
    int n,i,a,b;

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        cout<<"Scenario #"<<i<<":"<<endl;
        if((a*b)%2==0)
            cout<<fixed<<setprecision(2)<<double(a*b)<<endl;                //四舍五入至小数点后两位
        else
            cout<<fixed<<setprecision(2)<<double(a*b+sqrt(2.0)-1)<<endl;
        cout<<endl; 
    }

    return 0;
}
  
