/*
输入n，输出满足n=a*2^p的a和p，a为奇数 

先列出2^p在数组中
然后一个一个的枚举看是否符合要求
好像是有唯一解，反正只输出一组解

关键词：数学题，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int d;
    cin>>d;
    while(d--)
    {
        int n;
        cin>>n;
        
        int binary[100]={1};
        for(int i=0;binary[i]<=1000000;i++)
            binary[i+1]=2*binary[i];
            
        for(int i=0;binary[i]<=n;i++)
            if(n%binary[i]==0 && (n/binary[i])%2==1)
            {
                cout<<n/binary[i]<<' '<<i<<endl;
                break;
            }
    }
}
