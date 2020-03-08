/*
ID:cowtony1
PROG:ariprog
LANG:C++
定义一个集合是所有形如p^2+q^2的数，其中0<=p,q<=M
要求求出集合里所有长度为N的等差数列的首项和公差

枚举，先生成集合中的所有数，并且放入一个筛中便于检验某个数字数不属于这个集合
然后在集合中枚举首项a，以及大于a的k使k-a作为公差
检验输出即可

关键词：枚举 
*/
#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

struct Sequence
{
    int a,b;
    Sequence(int x=0,int y=0):a(x),b(y){}
    bool operator <(const Sequence s)const
    {
        if(b!=s.b)return b>s.b;
        else return a>s.a;
    }
};

int N,M;
bool record[125001]={0};

bool judge(int a,int b)
{
    for(int i=0;i<N;i++)
        if(record[a+i*b]==false)return false;
    return true;
}

int main()
{
    ifstream cin("ariprog.in");
    ofstream cout("ariprog.out");
    
    cin>>N>>M;
    
    for(int i=0;i<=M;i++)
        for(int j=i;j<=M;j++)
            record[i*i+j*j]=true;
    M=2*M*M;
    int num[30000],length=0;
    for(int i=0;i<=M;i++)
        if(record[i])num[length++]=i;
    
    priority_queue<Sequence> pq;
    for(int i=0;i<length;i++)
       for(int j=i+1;j<length;j++)
       {
           int a=num[i],b=num[j]-num[i];
           if(a+(N-1)*b>M)break;
           if(judge(a,b)==true)pq.push(Sequence(a,b));
       }
       
    if(pq.empty()==true)cout<<"NONE"<<endl;
    else while(pq.empty()==false)
    {
        Sequence s=pq.top();
        cout<<s.a<<' '<<s.b<<endl;
        pq.pop();
    }
}
