/*
已知火鸡的数量，和五位数总价的中间三位，求火鸡有可能最高整数单价

枚举，从最大的数向下枚举
遇到第一个成立的即为所求解

关键词：简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,d1,d2,d3,d4,d5;
        cin>>n;
        cin>>d2>>d3>>d4;
        
        for(d1=9;d1>0;d1--)
            for(d5=9;d5>=0;d5--)
            {
                int money=d1*10000+d2*1000+d3*100+d4*10+d5;
                if(money%n==0)
                {
                    cout<<d1<<' '<<d5<<' '<<money/n<<endl;
                    goto end;
                }
            }
        cout<<0<<endl;
        end:;
    }
}
