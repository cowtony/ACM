#include<stdio.h>

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int nn;
	scanf("%d",&nn);
	while(nn--)
	{
				
		int k,n;
		scanf("%d%d",&k,&n);
		int len[5001];
		int val[2][5001];
		int last[2][5001];
		int need[2][5001];
		int i,j,t;
		for(i=0;i<n;i++)	scanf("%d",&len[i]);
		int min=50000;int beg;
		for(j=0;j<n;j++)	val[0][j]=-1;
		for(i=0;i<n-2;i++)
		{
			if(len[i+1]-len[i]<min){	min=len[i+1]-len[i];beg=i+2;}
			val[0][i+2]=min*min;
			last[0][i+2]=beg;
			need[0][i+2]=1;
		}
/*
		for(t=0;t<n;t++)
			{
				printf("%d ",val[0][t]);
				if(t%10==0)	printf("\n");
			}
			printf("\n\n");
*/
		int pt=1;int t_val;	
		for(i=1;i<k+8;i++)
		{
			for(j=0;j<n;j++)	val[pt][j]=-1;
			int min=50000;int beg;
			for(j=last[1-pt][3*i-1];j<n-2-need[1-pt][3*i-1];j++)
			{
				if(val[1-pt][3*i-1]<0)	continue;
				if(len[j+1]-len[j]<min){	min=len[j+1]-len[j];beg=j+2;}
				int end_pt=j+2+need[1-pt][3*i-1];
				val[pt][end_pt]=val[1-pt][3*i-1]+min*min;
				last[pt][end_pt]=beg;
				if(beg-last[1-pt][3*i-1]>=need[1-pt][3*i-1]+2)
					need[pt][end_pt]=1;
				else	need[pt][end_pt]=1+need[1-pt][3*i-1]-(beg-last[1-pt][3*i-1]-2);
			}
			
			for(t=3*i;t<n-2-1;t++)
			{
				
				int min=50000;int beg;
				for(j=last[1-pt][t];j<n-2-need[1-pt][t];j++)
				{
					if(val[1-pt][t]<0)	continue;
					if(len[j+1]-len[j]<min){	min=len[j+1]-len[j];beg=j+2;}
					t_val=val[1-pt][t]+min*min;
					int end_pt=j+2+need[1-pt][t];
					if(val[pt][end_pt]>t_val)	
					{
						val[pt][end_pt]=t_val;
						last[pt][end_pt]=beg;
						if(beg-last[1-pt][t]>=need[1-pt][t]+2)
							need[pt][end_pt]=1;
						else	need[pt][end_pt]=1+need[1-pt][t]-(beg-last[1-pt][t]-2);
					}

				}
				
			}

			for(t=0;t<n;t++)
			{
				printf("%d ",val[pt][t]);
				if(t%10==0)	printf("\n");
			}
			printf("\n\n");

		}

		pt=1-pt;min=val[pt][3*i-1];
		for(j=3*i;j<n;j++)
			if(min<0||val[pt][j]<min)	min=val[pt][j];

		printf("%d\n",min);
	}
	return 0;
}