//126114 2003-04-17 18:33:30 Wrong Answer 1161 C++ 00:02.47 444K just for play 
//126150 2003-04-17 18:54:50 Wrong Answer 1161 C++ 00:02.49 444K just for play 
//126153 2003-04-17 19:00:24 Accepted 1161 C++ 00:02.49 444K just for play 
#include<stdio.h>
struct node_type
{
	int val;
	int pre;
	node_type()
	{
		val=-1;
	}
};

void output(node_type tt[][200],int pt,int time[],int curtime)
{
	if(pt==1)
	{
		printf("%d",curtime*5);
		return;
	}
	output(tt,pt-1,time,tt[pt][curtime].pre);
	printf(", %d",(curtime-tt[pt][curtime].pre-time[pt-1])*5);
}



int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int nn;
	scanf("%d",&nn);
	while(nn--)
	{
		int n;int hour;int minute5;
		int output_need=0;
		while(scanf("%d",&n))
		{
			if(n==0)	break;
			if(output_need)	printf("\n");
		
			output_need=1;
			
			scanf("%d",&hour);
			minute5=hour*12;
			int i,j;
			int fish[26],dec[26];int left_fish[26][200];
			int time[26];node_type lake[26][200];
			for(i=1;i<=n;i++)	scanf("%d",&fish[i]);
			for(i=1;i<=n;i++)	scanf("%d",&dec[i]);
			for(i=1;i<n;i++)	scanf("%d",&time[i]);
			lake[1][0].pre=0;lake[1][0].val=0;
			for(i=1;i<=n;i++)
			{	left_fish[i][0]=0;
				for(j=1;j<=minute5;j++)
				{				
					left_fish[i][j]=left_fish[i][j-1]+fish[i];
				//	printf("%d---%d ----> %d\n",i,j,left_fish[i][j]);
					fish[i]=fish[i]-dec[i];
					fish[i]=(fish[i]>0)?fish[i]:0;
				}
				
			}
			for(i=1;i<=minute5;i++)
			{				
				lake[1][i].val=left_fish[1][i];
				lake[1][i].pre=0;
			}
			int beg_time=0;int t;int pre_time;
			for(i=2;i<=n;i++)
			{
				pre_time=beg_time;
				beg_time+=time[i-1];
				for(j=beg_time;j<=minute5;j++)
				{
					
					for(t=pre_time;t<=j-time[i-1];t++)
					{
						int left_time=j-t-time[i-1];
						int temp=lake[i-1][t].val+left_fish[i][left_time];
						if(temp>=lake[i][j].val)
						{
							lake[i][j].val=temp;lake[i][j].pre=t;
						}
					}				
				}
			}
			int pt=1;
			for(i=2;i<=n;i++)			
				if(lake[i][minute5].val>lake[pt][minute5].val)	pt=i;
			output(lake,pt,time,minute5);
			for(i=pt+1;i<=n;i++)
				printf(", 0");
			printf("\n");
			printf("Number of fish expected: %d\n",lake[pt][minute5].val);
		}
		if(nn)	printf("\n");
	}
	return 0;
}

		






			
		


