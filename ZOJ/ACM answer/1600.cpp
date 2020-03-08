#include<stdio.h>

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		int price[101],BK[101];
		int i,j,t;
		for(i=0;i<N;i++)	scanf("%d",&price[i]);
		for(i=0;i<N;i++)	scanf("%d",&BK[i]);
		int sel,minsel=-1;
		for(i=1;i<N;i++)
		{
			int t_sum=0;
			for(j=i;j<N;j++)	t_sum+=BK[j];
			for(j=N-i;j<N;j++)	t_sum+=BK[j];
			if(t_sum>minsel){minsel=t_sum;sel=i;}
		}
		printf("%d ",sel+1);
		minsel=10000;
		for(i=0;i<N;i++)
			if(minsel>price[i])	minsel=price[i];
		for(i=1;i<N-1;i++)
			if(price[i]==minsel)	break;
		if(i==N-1)	printf("%d\n",minsel);
		else	printf("%d\n",minsel-1);
	}
	return 0;
}

		


