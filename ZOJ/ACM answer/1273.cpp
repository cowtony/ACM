#include<stdio.h>

int n,from,to;
int val[31][31];
int node[31][31];
int cost[31][31];
int node_cnt[31];
bool	visit[31];

void cal_val(int cur,int node_set[],int set_cnt)
{
	visit[cur]=true;
	int i,j,t;
	for(i=0;i<node_cnt[cur];i++)
	{
		int next=node[cur][i];
		if(visit[next])
		{
			int pt;
			for(pt=0;pt<set_cnt;pt++)
				if(node_set[pt]==next)	break;
			for(j=set_cnt-1;j>pt;j++)
											

int main()
{
	while(scanf("%d %d %d",&n,&from,&to)!=EOF)
	{
		if(n==0&&from==0&&to==0)	break;
		int i,j,t;
		int tform,tto,tval;
		memset(val,0xff,sizeof(val));
		memset(node_cnt,0,sizeof(node_cnt));
		memset(visit,false,sizeof(visit));
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&tfrom,tto,tval);			
			cost[tfrom][node_cnt[tfrom]]=tval;
			node[tfrom][node_cnt[tfrom]++]=tto;
			cost[tto][node_cnt[tto]]=tval;
			node[tto][node_cnt[tto++]=tfrom;
		}
		int node_set[31];
		int	set_cnt=1;node_set[0]=from;
		cal_val(from,node_set,set_cnt);		
	}

		
