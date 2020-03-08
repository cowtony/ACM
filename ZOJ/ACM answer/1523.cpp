//278106 2003-08-31 15:57:15 Accepted 1523 C++ 00:00.21 2256K just for play 
#include<stdio.h>
#include<string.h>

const int MAX=400;
	int stand[MAX][MAX];
	int scan[MAX][MAX];
	int temp[MAX][MAX];
int main()
{
	int L;
	while(scanf("%d",&L)!=EOF)
	{
		if(L==0)	break;
		int i,j,t,tt;
		for(i=0;i<L;i++)
			for(j=0;j<L;j++)
				scanf("%d",&stand[i][j]);
		for(i=0;i<L;i++)
			for(j=0;j<L;j++)
				scanf("%d",&scan[i][j]);
		int max=-1;
		for(tt=0;tt<2;tt++)
		{
			for(t=0;t<4;t++)
			{
				int cnt=0;
				for(i=0;i<L;i++)
					for(j=0;j<L;j++)
					{
						if((scan[i][j]-stand[i][j]>=0&&scan[i][j]-stand[i][j]<=100)||
							(stand[i][j]-scan[i][j]>=0&&stand[i][j]-scan[i][j]<=100))
								cnt++;
					}
				if(cnt>max)	max=cnt;
				if(t==3)	break;
				for(i=0;i<L;i++)
					for(j=0;j<L;j++)
						temp[i][j]=scan[i][j];
				for(i=0;i<L;i++)
					for(j=0;j<L;j++)
						scan[i][j]=temp[L-1-j][i];
	
			}
			if(tt==1)	break;
			for(i=0;i<L;i++)
				for(j=0;j<L;j++)
					temp[i][j]=scan[i][j];
			for(i=0;i<L;i++)
				for(j=0;j<L;j++)
					scan[i][j]=temp[L-1-i][j];
		}
	


		printf("%.2lf\n",max*100.0/L/L);

	}
	return 0;
}
