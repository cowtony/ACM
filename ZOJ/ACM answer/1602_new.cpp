//177920 2003-06-23 13:53:16 Accepted 1602 C++ 00:00.00 416K just for play 
#include<stdio.h>

struct matrix{int row,col;};

int main()
{
	int n;
	matrix input[101];
	int val[101][101];
	
	while(scanf("%d",&n)!=EOF)
	{
		int i,j,t;
		scanf("%d",&input[0].row);
		for(i=1;i<n-1;i++)
		{
			scanf("%d",&input[i].row);
			input[i-1].col=input[i].row;
		}
		scanf("%d",&input[n-2].col);
		for(i=0;i<n-1;i++)	val[i][i]=0;
		for(t=1;t<n-1;t++)
		{
			for(i=0;i<n-1-t;i++)
			{
				int min=-1;
				for(j=i;j<i+t;j++)
				{
					int t_val=val[i][j]+val[j+1][i+t]+input[i].row*input[j].col*input[i+t].col;
					if(min<0||t_val<min)	min=t_val;
				}
				val[i][i+t]=min;
			}
		}
		printf("%d\n",val[0][n-2]);
	}
	return 0;
}









		
