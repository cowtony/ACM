/*
一段连续自然数的和等于所给的值，现在要求从小到大输出所有解

设该段连续的数首项为a，尾项为b，总和为m
则根据求和公式(a+b)(b-a+1)/2=m
即(a+b)(b-a+1)=2m
用for循环对2m分解因数，设有pq=2m且p<q 
则a+b=p
b-a+1=q解此方程组即可

关键词：数论 
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int m;
    int p,q;
    cin>>m;
    
    for(int i=sqrt(2*m);i>1;i--)
    {
        if(2*m%i==0)
        {
            p=2*m/i;
            q=i;
            if((p-q+1)%2==0 && (p+q-1)%2==0)
                cout<<(p-q+1)/2<<' '<<(p+q-1)/2<<endl;
        }
    }

    //while(1);
    return 0; 
}
