#include <stdio.h>
int main()
{
	int a[4097];
	int stick;
	int i,j;
	int cas,n,t;
	int max;
	scanf("%d",&cas);
	while(cas--)
	{
		t=max=0;
		for(i=1;i<4097;i++)
		{
			a[i]=1;
		}
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&stick);
			if(a[stick]==1) 
			{
				t=1;
				for(j=stick-1;j>=1;j--)
				{
					if(a[j]==0) t++;
					else break;
				}
				for(j=stick+1;j<4097;j++)
				{
					if(a[j]==0) t++;
					else break;
				}
				a[stick]=0;
				if(t>max) max=t;
			}
			else   a[stick]=1;
		}
		printf("%d\n",max);
	}
	return 0;
}