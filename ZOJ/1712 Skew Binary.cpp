/*
10120(skew)= 1*(2^5-1)+0*(2^4-1)+1*(2^3-1)+2*(2^2-1)+0*(2^1-1)如此例，将给的数据转化为十进制
 
一位一位加起来就可以了
也可以先初始化一个数组：1,3,7,15,31...相乘相加就行了

关键词：简单题，进制转换 
*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    string skew;
    
    while (cin>>skew)
    {
        if(skew=="0")return 0;
        
        long result=0;
        for(int i=0;i<skew.length();i++)
            result+=(skew[i]-'0')*(pow(2.0,double(skew.length()-i))-1);

        cout<<result<<endl;
    }
}
