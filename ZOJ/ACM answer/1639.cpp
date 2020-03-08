//289054 2003-09-14 00:33:10 Time Limit Exceeded 1639 C++ 00:02.00 1468K just for play 
#include<stdio.h>
#include<string.h>


char name[16][11];
int val[16],n,m;
int line[1025][16][16];
int tcnt[1025][16];
int curset[16];
int maxval;

void tsearch(int lev,int tsum)
{
	if(lev==n)
	{
//		printf("%d\n",tsum);
/*
		int i;
		for(i=0;i<n;i++)
			printf("%d ",curset[i]);
		printf("\n");
*/
		if(tsum>maxval)	maxval=tsum;
		return;
	}
	curset[lev]=0;
	tsearch(lev+1,tsum);
	int i,j;
	for(j=0;j<m;j++)
	{
		if(tcnt[j][lev]==0)	continue;
		for(i=0;i<tcnt[j][lev];i++)
			if(curset[line[j][lev][i]]==0)	break;
		if(i==tcnt[j][lev])	break;
	}
	if(j==m)
	{
		curset[lev]=1;
		tsearch(lev+1,tsum+val[lev]);
		curset[lev]=0;
	}
}
int main()
{
//	freopen("1639.in","r",stdin);
	int count=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		int i,j,t;
		for(i=0;i<n;i++)
			scanf("%s %d",name[i],&val[i]);
		
		char input[500];
		memset(tcnt,false,sizeof(tcnt));
		scanf("%d",&m);
		gets(input);
		for(i=0;i<m;i++)
		{
			gets(input);
			
			char tname[11];
			int contain[16],cnt=0;
			int pt=0;t=0;
			while(1)
			{
				if(t>strlen(input))	break;
				if(input[t]==' '||t==strlen(input))
				{
					if(pt!=0)
					{
						tname[pt]='\0';
						
						for(j=0;j<n;j++)
							if(strcmp(tname,name[j])==0)	break;
						
						contain[cnt++]=j;
					}
					pt=0;
					t++;
				}
				else	tname[pt++]=input[t++];
			}
			
			
			for(j=0;j<cnt;j++)
				for(t=0;t<cnt;t++)
				{
					if(j==t)	continue;
					int tt=contain[j];
					line[i][tt][tcnt[i][tt]++]=contain[t];
					
				}
			
		}
/*
	for(i=0;i<m;i++)
	{
		printf("%d ---- \n",i);
		for(j=0;j<n;j++)
			{
				printf("%d == ",j);
				for(t=0;t<tcnt[i][j];t++)
					printf("%d ",line[i][j][t]);
				printf("\n");
			}
	}
*/
		maxval=0;
		tsearch(0,0);
		printf("System %d: %d\n",++count,maxval);
	}
	return 0;
}





