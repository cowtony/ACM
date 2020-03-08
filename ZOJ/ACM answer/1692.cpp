//395994 2003-12-12 20:20:01 Accepted 1692 C++ 00:00.01 376K just for play 
#include<stdio.h>
#include<string.h>

int n,c;
bool	visit[11][11];
int state[11][11];
int mov[6][2]={{-1,-1},{-1,0},{0,-1},{0,1},{1,0},{1,1}};


void	search_v(int x,int y,int cur,int& num,bool& ret)
{
	visit[x][y]=true;
	num++;
	int nx,ny;
	int i;
	for(i=0;i<6;i++)
	{
		nx=x+mov[i][0];ny=y+mov[i][1];
		if(nx<0||ny<0||nx>=n||ny>nx)	continue;
		if(visit[nx][ny])	continue;
		if(state[nx][ny]==0){ret=false;continue;}
		if(state[nx][ny]==cur)
		{
			search_v(nx,ny,cur,num,ret);
		}
	}
	
}

	

int cal_get()
{
	
	memset(visit,false,sizeof(visit));			
	int i,j;
	int	getval=0;
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
		{
			if(state[i][j]!=0&&!visit[i][j])
			{
				int num=0;
				
				bool	res=true;
				search_v(i,j,state[i][j],num,res);
				if(res)
				{
					if(state[i][j]==c)	getval-=num;
					else	getval+=num;
				}
				
			}
		}
	return getval;
}
int main()
{
//	freopen("1692.in","r",stdin);
	while(scanf("%d %d",&n,&c)!=EOF)
	{
		if(n==0&&c==0)	break;
		
		int i,j,t;
		for(i=0;i<n;i++)
			for(j=0;j<=i;j++)
				scanf("%d",&state[i][j]);
		int	maxval=-1000;
		for(i=0;i<n;i++)
			for(j=0;j<=i;j++)
			{
				if(state[i][j]==0)
				{
					state[i][j]=c;
					int val=cal_get();
					if(maxval<val)	maxval=val;
					state[i][j]=0;
				}
			}
		printf("%d\n",maxval);
	}
	return 0;
}

