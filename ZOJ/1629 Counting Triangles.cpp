/*
数n阶正三角形共包含多少个三角形

先数正的，从上往下一层一层加。第一层1个，第二层1+2个，第三层1+2+3个。。。
再数倒的，思路一样只不过要多考虑大三角不够的情况，如n=6时： 
第一层1个
第二层2+1个
第三层3+2+1个
第四层4+3+2个
第五层5+4个
第六层6个，相当于比正的少了1+(3+2+1)+(5+4+3+2+1)个 

关键词：数学题 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==1){cout<<1<<endl;continue;}
        
        int result=0;

        //计算正三角
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)result+=j;
   
        //计算倒三角
        for(int i=1;i<=n-1;i++)
            for(int j=1;j<=i;j++)result+=j;
        for(int i=n-2;i>0;i-=2)
            for(int j=1;j<=i;j++)result-=j;
    
        cout<<result<<endl;
    }
}
