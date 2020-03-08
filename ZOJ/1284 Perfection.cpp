/*
判断一个数的因子和与该数的大小关系，输出格式要注意

直接用最笨的办法求一个数的因子和就行了
也可以用数组的筛法，注意n=1

关键词：数学题，简单题 
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int num;
    cout<<"PERFECTION OUTPUT"<<endl;
    while(cin>>num)
    {
        if(num==0)break;
        
        int result=0;
        for(int i=1;i<=num/2;i++)
            if(num%i==0)result+=i; 

        if(result<num)cout<<setw(5)<<num<<"  DEFICIENT"<<endl;
        else if(result>num)cout<<setw(5)<<num<<"  ABUNDANT"<<endl;
        else if(result==num)cout<<setw(5)<<num<<"  PERFECT"<<endl;
    }
    cout<<"END OF OUTPUT"<<endl;
}
