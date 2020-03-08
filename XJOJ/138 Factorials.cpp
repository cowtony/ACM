/*
输出n!的最后一个非零位

一个数一个数的乘，虽然只用记最后一位，但是要是末尾有零要及时消掉
为了不让存储结果的变量溢出，每次再模一个1000000，这个数要比n大

关键词：简单题，数学题 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int result=1;
    
    for(int i=1;i<=n;i++)
    {
        result*=i;
        while(result%10==0)
            result/=10;
        result%=100000;//不能模十 
    }
    cout<<result%10;
    
    //while(1);
    return 0;
}

