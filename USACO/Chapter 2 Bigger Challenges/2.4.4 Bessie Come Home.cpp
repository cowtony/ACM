/*
ID:cowtony1
PROG:comehome
LANG:C++

��a-z,A-Z��52���ڵ㣬����һ��ͼ��ע��������п��ܺ��ж����ߣ�Ҳ�����Լ����Լ���·��
Ȼ�������д��ĸ�ڵ㵽Z�ڵ������һ���Լ�����

�����ʱ��Ҫע�⣬��Ϊ�ڵ���٣����Կ�����floyd�㷨�����·

�ؼ��ʣ�ͼ�ۣ����·��
*/
#include<iostream>
#include<fstream>
using namespace std;

const int MAX=1000000000;

int f(char c)
{
    if(c>='a' && c<='z')return c-'a';
    else return c-'A'+26;
}

int main()
{
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);
    
    int P;
    cin>>P;
    
    int map[52][52];
    for(int i=0;i<52;i++)
        for(int j=0;j<52;j++)
        {
            map[i][j]=MAX;
            if(i==j)map[i][j]=0;
        }
    bool used[52]={false};
    
    for(int i=0;i<P;i++)
    {
        char a,b;
        int distance;
        cin>>a>>b>>distance;
        used[f(a)]=true;
        used[f(b)]=true;
        map[f(a)][f(b)]=min(map[f(a)][f(b)],distance);
        map[f(b)][f(a)]=min(map[f(b)][f(a)],distance);
    }
    
    for(int k=0;k<52;k++)
        for(int i=0;i<52;i++)
            for(int j=0;j<52;j++)
                if(map[i][j]>map[i][k]+map[k][j])
                   map[i][j]=map[i][k]+map[k][j];

    int shortest=MAX;
    char No;
    for(int i=26;i<51;i++)//ע�ⲻ�ܰ�'Z'�ӽ�ȥ����Ȼ���·���϶���Z 0 
        if(map[i][f('Z')]<shortest)
        {
            shortest=map[i][f('Z')];
            No=i-26+'A';
        }
    cout<<No<<' '<<shortest<<endl;
}
