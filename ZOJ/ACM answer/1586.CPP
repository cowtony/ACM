//138993 2003-05-02 22:02:34 Accepted 1586 C++ 00:00.17 4308K just for play 
#include<stdio.h>
#include<string.h>

const int max_num=1000000000;
int main()
{
	//freopen("in.txt","r",stdin);
	int cost[1001];
	int val[1001][1001];
	int nn;
	//printf("=============\n");
	scanf("%d",&nn);
	while(nn--)
	{
		int i,j;int n;
		scanf("%d",&n);
		for(i=0;i<n;i++)	scanf("%d",&cost[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&val[i][j]);
				val[i][j]+=cost[i]+cost[j];
			}
		bool visit[1001];int minval[1001];
		memset(visit,0,sizeof(visit));
		
		for(i=0;i<n;i++)	minval[i]=max_num;
		int pt=0;visit[0]=1;
		int total=0;
		for(i=0;i<n-1;i++)
		{
			
			for(j=0;j<n;j++)			
				if(!visit[j]&&minval[j]>val[j][pt])	minval[j]=val[j][pt];
			int min=max_num;
			for(j=0;j<n;j++)
				if(!visit[j]&&minval[j]<min){pt=j;min=minval[j];}
			total+=min;
			visit[pt]=1;
			//printf("%d----%d\n",pt,min);
		}
		printf("%d\n",total);
	}
	return 0;
}

				


			
