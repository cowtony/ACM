/*
给出矩形的长和宽及两圆半径，问是否可以把这两个圆不重叠的放入矩形中

最优方法是一个圆顶矩形的左下角，一个圆顶矩形的右上角。便可以由勾股定理得到：
(r1+r2)^2=[a-(r1+r2)]^2+[b-(r1+r2)]^2

关键词：数学题 
*/
#include<iostream>
using namespace std;

int main()
{
    double a,b,r1,r2;

    while(cin>>a>>b>>r1>>r2)
    {
        if((r1+r2)*(r1+r2)<=(a-r1-r2)*(a-r1-r2)+(b-r1-r2)*(b-r1-r2))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
