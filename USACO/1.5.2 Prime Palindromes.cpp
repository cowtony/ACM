/*
ID:cowtony1
PROG:pprime
LANG:C++
输出5<=a<b<=100000000内既是回文数又是素数的数

因为质数比回文数多得多 
所以先用迭代深度优先搜索按升序生成所有的回文数
然后判断是否在[a,b]内以及是否是质数，然后输出

关键词：回文，迭代深度优先搜索 
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

bool isprime(int n)
{
    if(n%2==0)return false;
    for(int i=3;i*i<=n;i+=2)
        if(n%i==0)return false;
    return true;
}

int pow10(int n)
{
    int t=1;
    for(int i=0;i<n;i++)
        t*=10;
    return t;
}

int MAX_layer;
int result[4];
int a,b;

void DFS(int depth)
{
    if(depth==(MAX_layer+1)/2)
    {
        int n=0;
        int t1=1,t2=pow10(MAX_layer-1);
        for(int i=0;i<depth;i++)
        {
            n+=(t1+t2)*result[i];
            t1*=10;t2/=10;
        }
        if(MAX_layer%2==1)n-=(t1/10)*result[depth-1];
        
        if(n>=a && n<=b && isprime(n)==true)cout<<n<<endl;
    }
    else for(int i=0;i<10;i++)
    {
        if(depth==0 && i==0)continue;
        result[depth]=i;
        DFS(depth+1);
    }
}

int main()
{
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
    
    cin>>a>>b;
    for(MAX_layer=1;MAX_layer<=8;MAX_layer++)
        DFS(0);
}
