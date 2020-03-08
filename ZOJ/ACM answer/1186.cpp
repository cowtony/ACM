//119118 2003-04-13 17:38:09 Accepted 1186 C++ 00:00.53 4496K just for play 
#include<stdio.h>
#include<vector>

using namespace std;

struct line
{
	int from,to;
	line(int fir,int sec)
	{
		from=fir;to=sec;
	}

	void print()
	{
		printf("%d %d\n",from,to);
	}

};

const int max_num=1001;
vector<int>success[max_num];
int used[max_num][max_num];
int visit[max_num];
int father[max_num];
int low[max_num];
int dfs[max_num];
vector<line>result;
int n,m;

int  search(int head,int lev)
{
	
	int i;
	dfs[head]=lev;
	low[head]=lev;

	for(i=0;i<success[head].size ();i++)
	{
		
		int next=success[head][i];
//		printf("%d-----%d=====\n",head,next);
		if(used[head][next]||used[next][head])	continue;

		line temp(head,next);
		result.push_back (temp);
//		printf("%d-----%d=====>>\n",head,next);
		used[head][next]=1;
		if(visit[next])
		{
			if(dfs[next]<low[head])	low[head]=dfs[next];
			continue;
		}
//		printf("%d-----%d=====>>>>>>>>>>>>\n",head,next);
		father[next]=head;
		visit[next]=1;
		int res=search(next,lev+1);
		if(res<low[head])	low[head]=res;	

	}
	if(head!=1&&low[head]==dfs[head])
	{
		line temp(head,father[head]);
		result.push_back (temp);
	}
//	printf("%d-----%d ----->%d\n",head,lev,low[head]);
	return low[head];
}
		



int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	int nn,t;
	scanf("%d",&nn);
	for(t=0;t<nn;t++)
	{
		if(t)	printf("\n");
		int count=0;
		while(scanf("%d%d",&n,&m))
		{
			if(n==0&&m==0)	break;
			count++;
			printf("%d\n\n",count);
			memset(visit,0,sizeof(visit));
			memset(used,0,sizeof(used));
			memset(father,0,sizeof(father));
			result.clear ();
//			while(!num.empty())	num.pop();
			int i;
			for(i=1;i<=n;i++)	success[i].clear();
			for(i=0;i<m;i++)
			{
				int fir,sec;
				scanf("%d%d",&fir,&sec);
				success[fir].push_back (sec);
				success[sec].push_back (fir);
			}
			father[1]=-1;
			visit[1]=1;
			search(1,1);
			for(i=0;i<result.size();i++)
				result[i].print();
			printf("#\n");

		}
		
	}
	return 0;
}
