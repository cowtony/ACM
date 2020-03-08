//1893 2003-05-24 16:20:40 Wrong Answer 1002 C++ 00:00:01 380K just for play 
#include<stdio.h>

int minval;
int val[6][6];
int visit[6];
int min[6][6];
int n;
int son[6];
int tval;
int sel_beg;
void search()
{
	int i,j;
/*	for(i=0;i<n;i++)
		printf("%d ",visit[i]);
	printf("\n");
*/	
	for(i=0;i<n;i++)
		if(!visit[i])	break;
	if(i==n)
	{
		int tt=tval;
		for(i=0;i<n;i++)
			if(son[i])	tt+=min[i][sel_beg];
		if(tt<minval)	minval=tt;
		return;
	}
	for(i=0;i<n;i++)
	{
		if(visit[i])
		{
			for(j=0;j<n;j++)
			{
				if(!visit[j])
				{
					son[i]=0;
					visit[j]=1;
					tval+=val[i][j];
					search();
					visit[j]=0;
					son[i]=1;
				}
			}
		}
	}

}
		
int main()
{
	freopen("1002.in","r",stdin);
//	freopen("1002.out","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		minval=100000;
		int i,j,t;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&val[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				min[i][j]=val[i][j];
		for(t=0;t<n;t++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
				{
					if(min[i][j]>min[i][t]+min[t][j])
						min[i][j]=min[i][t]+min[t][j];
				}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%d ",min[i][j]);
			printf("\n");
		}
		for(i=0;i<n;i++)
		{
			tval=0;sel_beg=i;
			for(j=0;j<n;j++){	visit[j]=0;son[j]=1;}
			visit[i]=1;
			search();
			visit[i]=0;
			
		}
		
			
		printf("%d\n",minval);
	}
	return 0;
}