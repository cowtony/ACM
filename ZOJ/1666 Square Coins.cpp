/*
有面值为平方数的17种硬币，从1到289，输入一个数，求有多少种方法可以用硬币凑出这个数

构造一个递归函数search(a,b)
代表用面值不小于b^2的硬币凑出a这个数

关键词：递归之王^10 
*/
#include<iostream> 
using namespace std; 

int r;//统计解的个数 

void search(int x,int num)
{ 
    if(x==0){r++;return;} 
    if(num*num>x)return;
    
    for(int i=num;i*i<=x && i<=17;i++)
        search(x-i*i,i);
} 

int main()
{ 
    int n;
    
    //freopen("aaa.txt","r",stdin);
    
    while (cin>>n)
    { 
        if(n==0)break; 
        
        r=0; 
        search(n,1); 
        cout<<r<<endl; 
    } 
    
    //while(1);
    return 0; 
}
