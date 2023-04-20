/*
ID:cowtony1
PROG:sprime
LANG:C++
找出所有的N位质数，删掉后面若干位后仍为质数的数

深度优先搜索生成所有的数
第一位只能是2,3,5,7
后面位只能是1,3,7,9
生成的同时就进行检验，满足是质数才进下一深度

关键词：深度优先搜索 
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int N;

bool isprime(int n)
{
    if(n%2==0)return false;
    for(int i=3;i*i<=n;i+=2)
        if(n%i==0)return false;
    return true;
}

void DFS(int n,int depth)
{
    if(depth==N)cout<<n<<endl;
    else
    {
        if(isprime(n*10+1)==true)DFS(n*10+1,depth+1);
        if(isprime(n*10+3)==true)DFS(n*10+3,depth+1);
        if(isprime(n*10+7)==true)DFS(n*10+7,depth+1);
        if(isprime(n*10+9)==true)DFS(n*10+9,depth+1);
    }
} 

int main()
{
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    
    cin>>N;
    DFS(2,1);
    DFS(3,1);
    DFS(5,1);
    DFS(7,1);
}
