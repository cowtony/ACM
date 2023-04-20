/*
ID:cowtony1
PROG:ariprog
LANG:C++
����һ����������������p^2+q^2����������0<=p,q<=M
Ҫ��������������г���ΪN�ĵȲ����е�����͹���

ö�٣������ɼ����е������������ҷ���һ��ɸ�б��ڼ���ĳ���������������������
Ȼ���ڼ�����ö������a���Լ�����a��kʹk-a��Ϊ����
�����������

�ؼ��ʣ�ö�� 
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
