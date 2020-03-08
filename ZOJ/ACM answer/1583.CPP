//137497 2003-05-01 16:08:17 Wrong Answer 1583 C++ 00:00.30 1364K just for play 
//137516 2003-05-01 16:20:23 Accepted 1583 C++ 00:00.30 1364K just for play 
#include<stdio.h>

int main()
{
//	freopen("in.txt","r",stdin);
	int n;int count=0;
	int b[4][4]={{0,0,0,0},{0,1,2,1},{0,2,4,2},{0,1,2,1}};

	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		count++;
		int num[501][501];
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&num[i][j]);
		printf("Case %d:\n",count);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(i==0||j==0||i==n-1||j==n-1)
				{
					if(j==0){
						printf("%d",num[i][j]);
						if(j==n-1)	printf("\n");
					}
					else{
						printf(" %d",num[i][j]);
						if(j==n-1)	printf("\n");
					}
					continue;
				}
				int t,k;int temp=0;
				for(t=1;t<4;t++)
					for(k=1;k<4;k++)
						temp+=num[i+t-2][j+k-2]*b[t][k];
				temp/=16;
				printf(" %d",temp);
			}
	}
	return 0;
}

		
