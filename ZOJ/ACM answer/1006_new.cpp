//1399 2003-06-07 16:10:53 Wrong Answer 1006 C++ 00:00:02 380K just for play 
//1530 2003-06-07 16:33:33 Wrong Answer 1006 C++ 00:00:07 388K just for play 
#include<stdio.h>

int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int line[16][16];
		int preline[16][16];
		int i,j,t;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
				line[i][j]=2;
		}
		
		for(j=0;j<m;j++)
		{
			for(i=1;i<=n;i++)
			{
				for(t=i+1;t<=n;t++)
					preline[i][t]=line[i][t];
			}		
			int min,max;
			scanf("%d %d",&min,&max);
			if(min>max){i=min;min=max;max=i;}
			line[min][max]=1;

			for(i=1;i<min;i++)
				if(preline[i][min]==1)
					line[i][max]=1;

			for(i=max+1;i<=n;i++)
				if(preline[max][i]==1)
					line[min][i]=1;

			for(i=1;i<min;i++)			
				if(preline[i][min]==1&&preline[i][max]==2)
					line[i][min]=2;


			for(i=max+1;i<=n;i++)
				if(preline[max][i]==1&&preline[min][i]==2)
					line[max][i]=2;


		}
		int res=true;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
				if(line[i][j]==2){res=false;break;}
			if(j<=n)	break;
		}
		if(res)	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}

				
					