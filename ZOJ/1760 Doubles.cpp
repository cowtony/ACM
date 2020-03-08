/*
求给出的一列整数中有几对整数(a,b)，其中a是b的二倍

穷举，测试n^2对整数

关键词：穷举法
*/
#include <iostream> 
using namespace std; 

int main()
{ 
    int x,t,count,data[15]; 
    
    while(cin>>x)
    { 
        if(x==-1)break;

        data[0]=x;
        t=1;
        count=0; 
        
        while(cin>>x&&x!=0) 
            data[t++]=x;          //将一列数存入数组中
        
        for(int i=0;i<t;i++) 
            for(int j=0;j<t;j++)
                if(data[j]==data[i]*2)count++; 
                
        cout<<count<<endl; 
    } 
    return 0; 
} 
