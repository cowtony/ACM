//253094 2003-08-12 21:41:09 Accepted 1082 C++ 00:00.00 460K just for play 
#include<stdio.h>
#include<string.h>

const int MAX=10000000;
int main()
{
//	freopen("1082.in","r",stdin);
	int N;
	while(scanf("%d",&N))
	{
		if(N==0)	break;
		int line[101][101];
		int dis[101][101];
		int i,j,t;
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				line[i][j]=MAX;
		for(i=1;i<=N;i++)
		{
			int temp,to,time_use;
			scanf("%d",&temp);
			for(j=0;j<temp;j++)
			{
				scanf("%d %d",&to,&time_use);
				line[i][to]=time_use;
			}
		}
		for(j=1;j<=N;j++)
			for(t=1;t<=N;t++)
				dis[j][t]=line[j][t];
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				for(t=1;t<=N;t++)
					if(dis[j][t]>dis[j][i]+dis[i][t])	
						dis[j][t]=dis[j][i]+dis[i][t];
		int selmin=MAX;
		int selpt=-1;
		for(i=1;i<=N;i++)
		{
			int tmin=0;
			for(j=1;j<=N;j++)
			{

				if(i==j)	continue;
				if(dis[i][j]>tmin)	tmin=dis[i][j];
			}
			if(tmin<selmin){	selmin=tmin;selpt=i;}			
		}
		if(selmin<MAX)	{printf("%d %d\n",selpt,selmin);}
		else	printf("disjoint\n");
	}
	return 0;
}



					


