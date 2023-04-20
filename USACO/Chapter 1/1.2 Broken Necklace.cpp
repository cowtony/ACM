/*
ID: cowtony1
PROG: beads
LANG: C++

��һ����һ���������������ҷֱ�ȡ���ӣ���ÿ��ֻ��ȡһ����ɫ����ɫ���⡣��������ȡ���ٸ�

ö�ٴ�ϵĵ㣬Ȼ��ģ����У��ҵ����ֵ
����򵥣�������������

�ؼ��ʣ�ģ�� 
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream cout("beads.out");
    ifstream cin("beads.in");
    
    int N;
    cin>>N;
    char color[350];
    for(int i=0;i<N;i++)
        cin>>color[i];
    
    int maxn=0;
    for(int i=0;i<N;i++)
    {
        int count=0;
        char c='w';
        for(int j=i;j!=(i-1+N)%N;j=(j+1)%N,count++)
        {
            if(color[j]=='w')continue;
            else if(c=='w'){c=color[j];continue;}
            else if(c!=color[j])break;
        }
        c='w';
        for(int k=(i-1+N)%N;k!=i;k=(k-1+N)%N,count++)
        {
            if(color[k]=='w')continue;
            else if(c=='w'){c=color[k];continue;}
            else if(c!=color[k])break;
        }
        maxn=max(maxn,count);
    }
    cout<<min(maxn,N)<<endl;
    //while(1);
}
