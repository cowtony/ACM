/*
输入一个体积，输出他的一组长宽高，使表面积最小

表面积最小时变长为体积开立方，所以从0到体积的立方遍历一条边
再循环内遍历另一条边，记下表面积最小的一组解即可

关键词：枚举，简单题
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a,b,c,v,min=1000000000;
    cin>>v;
    int t=(pow(v,1/3.0))+1;
    
    for(int i=t;i>0;i--)
    {
        if(v%i==0)
        {
            int j;
            for(j=sqrt(v/i);j>0;j--)
                if((v/i)%j==0)break;

            if(i*j+v/i+v/j<min)
            {
                min=i*j+v/i+v/j;
                a=i;b=j;c=v/i/j;
            }
        }
    }
    cout<<a<<' '<<b<<' '<<c;
    
    //while(1);
    return 0;
}
