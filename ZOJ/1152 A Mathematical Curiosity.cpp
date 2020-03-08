/*
输入n,m，求使(a^2+b^2+m)/(a*b)为整数且0<a<b<n的a,b对数

穷举

关键词：数学，穷举法
*/
#include<iostream>
using namespace std;

int main()
{
    int blocks,count,cases,n,m,a,b;
      
    cin>>blocks;
    while(blocks--)
    {   
        cases=0;
        
        while(cin>>n>>m)
        {
            if(n==0)break;
            
            count=0;
            
            for(b=2;b<n;b++)
                for(a=1;a<b;a++)
                    if((a*a+b*b+m)%(a*b)==0)count++;
                    
            cout<<"Case "<<++cases<<": "<<count<<endl;
        }
        if(blocks>0)cout<<endl;
    }
    
    return 0;
}

