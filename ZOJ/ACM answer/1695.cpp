//391883 2003-12-10 17:58:35 Wrong Answer 1695 C++ 00:00.06 3224K just for play 
//391902 2003-12-10 18:09:32 Wrong Answer 1695 C++ 00:00.07 3224K just for play 
//391931 2003-12-10 18:32:11 Accepted 1695 C++ 00:00.07 4632K just for play 
#include<stdio.h>
#include<string.h>

int line[601][601];
int connect[601][601];
int c_cnt[601];
bool	visit[601];
bool	has_visit[601];
int		belong_to[601];

struct TT
{
	int val[2];
};

TT	gp[601];
bool	valid[1201];

int	gcnt;
int occur[2][1001];
int pre[601][601];

void search_nei(int cur,int pt,int t)
{
	has_visit[cur]=true;
	belong_to[cur]=2*t+pt;
	gp[t].val[pt]++;
	int i;
	for(i=0;i<c_cnt[cur];i++)
	{
		int next=connect[cur][i];
		if(has_visit[next])	continue;
		if(line[cur][next]==1)		
			search_nei(next,pt,t);
		else	search_nei(next,1-pt,t);
	}
}



int main()
{
//freopen("1695.in","r",stdin);
//freopen("1695.out","w",stdout);
	int  n,p1,p2;
	while(scanf("%d %d %d",&n,&p1,&p2)!=EOF)
	{
		if(n==0&&p1==0&&p2==0)	break;
		memset(line,0,sizeof(line));
		memset(visit,false,sizeof(visit));
		memset(c_cnt,0,sizeof(c_cnt));
		int t1,t2;char ans[5];
		int i,j,t;
//input
		for(i=0;i<n;i++)
		{
			scanf("%d %d %s",&t1,&t2,ans);
			if(t1==t2)	continue;
			visit[t1]=visit[t2]=true;
			if(strcmp(ans,"yes")==0)
			{
				if(line[t1][t2]==1)	continue;
				line[t1][t2]=line[t2][t1]=1;
				connect[t1][c_cnt[t1]++]=t2;
				connect[t2][c_cnt[t2]++]=t1;
			}
			else
			{
				if(line[t1][t2]==-1)	continue;
				line[t1][t2]=line[t2][t1]=-1;
				connect[t1][c_cnt[t1]++]=t2;
				connect[t2][c_cnt[t2]++]=t1;
			}

		}
		if(p1==p2)
		{
			printf("no\n");
			continue;
		}
		gcnt=0;		
//divide the person to each group ,one group with oposite sites
		memset(has_visit,false,sizeof(has_visit));
		for(i=1;i<=(p1+p2);i++)
		{
			if(visit[i]&&!has_visit[i])
			{
				gp[gcnt].val[0]=gp[gcnt].val[1]=0;
				search_nei(i,0,gcnt);
				gcnt++;
			}			
		}
//calculate the extra person and describe them to be one group
		int	temp=0;
		for(i=1;i<=(p1+p2);i++)
		{
			if(!visit[i]){
				temp++;
				belong_to[i]=gcnt*2;
			}
		}
		if(temp!=0)
		{
			gp[gcnt].val[0]=temp;
			gp[gcnt++].val[1]=0;
		}

//determine	the sequence of unipue num
		for(j=0;j<=p1+p2;j++)	occur[0][j]=0;
		occur[0][0]=1;int pt=0;
		for(i=0;i<gcnt;i++)
		{
			pt=1-pt;
			for(j=0;j<=p1+p2;j++)	occur[pt][j]=0;
			for(j=0;j<=p1+p2;j++)
			{
				if(occur[1-pt][j]>0)
				{
					
					occur[pt][j+gp[i].val[0]]+=occur[1-pt][j];
					pre[i][j+gp[i].val[0]]=2*i;
					
					occur[pt][j+gp[i].val[1]]+=occur[1-pt][j];
					pre[i][j+gp[i].val[1]]=2*i+1;
					
				}
			}
		}
		
		if(occur[pt][p1]==1)		
		{
			memset(valid,false,sizeof(valid));
//determine which group is in the unique group
			int tsum=p1,t_pt=gcnt-1;
			while(tsum>0)
			{
				int tt=pre[t_pt][tsum];
				valid[tt]=true;
				tsum-=gp[tt/2].val[tt%2];
				t_pt--;
			}
//output
			for(i=1;i<=p1+p2;i++)
			{
				if(valid[belong_to[i]])
					printf("%d\n",i);
				
			}
			printf("end\n");
		}
		else	printf("no\n");
	}
	return 0;
}

		

		