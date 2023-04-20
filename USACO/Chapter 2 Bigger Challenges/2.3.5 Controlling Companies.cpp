/*
ID:cowtony1
PROG:concom
LANG:C++

输入n组数据，分别是i公司对j公司的控股。当一个公司直接或间接占有另一公司50%以上股票时A公司就控制B公司了，求所有的控制关系

直接深搜，对每一个公司搜出所有能被他控制的公司

关键词：深度优先搜索 
*/
#include<iostream>
#include<fstream>
using namespace std;

bool flag[101],own[101];
int stock[101][101]={0},cnt[101];

void DFS(int x)
{
	if (flag[x]==true)return;
	else flag[x]=true;
	for(int i=100;i>0;i--)
	{
		cnt[i]+=stock[x][i];
		if(cnt[i]>50)
		{
			own[i]=true;
			DFS(i);
		}
	}
}
int main()
{
    freopen("concom.in","r",stdin);
    freopen("concom.out","w",stdout);
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
	{
        int u,v,w;
        cin>>u>>v>>w;
		stock[u][v]+=w;
	}
	
	for(int i=1;i<=100;i++)
	{
		fill_n(cnt+1,100,0);
		fill_n(flag+1,100,0);
		fill_n(own+1,100,0);
		DFS(i);
		for (int j=1;j<=100;j++)
			if (own[j]==true && i!=j)
			    cout<<i<<' '<<j<<endl;
	}
}
