/*
输入十进制的数，输出该数二进制表示法中1的位置

注意的是每行最后的位置不能跟空格

关键词：简单题，进制转换 
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
        
        int i;
        for(i=0;n>1;i++)
        {
            if(n%2==1)cout<<i<<" ";
            n/=2;
        }
        cout<<i<<endl;
    }
    
    //while(1);
}
