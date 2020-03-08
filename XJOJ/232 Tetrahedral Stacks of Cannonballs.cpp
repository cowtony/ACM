/*
头晕，题是英语的看不懂，就是求一个数列a[1]=1,a[2]=1+1+2,a[3]=1+1+2+1+2+3=a[2]+sum(3)

简单，直接预存1000内的结果然后输出

关键词：数学题，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int result[1000]={0};
    int sum=0;
    for(int i=1;i<1000;i++)
    {
        sum+=i;
        result[i]=result[i-1]+sum;
    }
    
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        cout<<i<<": "<<n<<" "<<result[n]<<endl;
    }
    
    //while(1);
}
