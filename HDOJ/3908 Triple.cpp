/*
找出一列数中所有三个数都互质或都不互质的数的对数

找出一个数与第二个数互质，与第三个不互质的对数，与总的组合数相减便得到所求
看网上详解去

关键词：数学题 
*/ 
#include<iostream>
using namespace std;

int GCD(int a,int b)
{
    if(b==0)return a;
    return GCD(b,a%b);
}

int main()
{
    //freopen("aaa.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int num[800];
        for(int i=0;i<n;i++)
            cin>>num[i];
            
        int total=n*(n-1)*(n-2)/6;
        for(int i=0;i<n;i++)
        {
            int A=0,B=0;
            for(int j=0;j<n;j++)
                if(i!=j)
                    if(GCD(num[i],num[j])==1)A++;
                    else B++;
            total-=A*B/2;
        }
        
        cout<<total<<endl;
    }
    //while(1);
}
