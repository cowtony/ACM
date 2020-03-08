/*
求(0!+1!+2!+...+n!)%m的值，其中0<=n<10^100，0<m<1000000

当n>=m时，n!%m=0，所以阶乘上限只取到min(n,m-1)就可以了
另外注意n<=1，m=1的特例，要加result%=m这句话

关键词：数学题，字符串 
*/
#include<iostream>
#include<string>
using namespace std;

int find_min(char n[],int m)
{
    int length_m=0;
    for(int i=1;i<=m;i*=10,length_m++);
    
    if(length_m<strlen(n))return m-1;
    else
    {
        int N=0;
        for(int i=0;i<strlen(n);i++)
        {
            N*=10;
            N+=n[i]-'0';
        }
        return min(N,m-1);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char n[102];
        int m;
        cin>>n>>m;
        
        int N=find_min(n,m);
        
        int result=1;
        long long f=1;
        for(int i=1;i<=N;i++)
        {
            f=(f*i)%m;
            result=(result+f)%m;
        }
        result%=m;//当n=0 or 1，m=1时，不会运行for循环，处理特例用的 
        cout<<result<<endl;
    }
} 
