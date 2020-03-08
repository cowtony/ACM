/*
根据公式e=sum(0!+1!+2!+...+n!)求自然对数值，每一行输出n更进一步的精确值，n<10 

常规方法，格式输出很严谨，要注意

关键词：数学题，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    cout<<"n e"<<endl;
    cout<<"- -----------"<<endl;
    cout<<"0 1"<<endl;
    cout<<"1 2"<<endl;
    cout<<"2 2.5"<<endl;
    
    double sum=2.5,temp=0.5;
    
    for(int i=3;i<10;i++)
    {
        sum+=temp/=i;
        printf("%d %.9lf\n",i,sum);
    }
    
    return 0;
}
