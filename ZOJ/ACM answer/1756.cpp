#include <stdio.h>
int main()
{
	int a[25][2];
	int i,j,k,h;
	while(1)
	{
		scanf("%d%d",&i,&j);
		if(i==-1&&j==-1) break;
		a[0][0]=i;
		a[0][1]=j;
		k=1;
		while(1)
		{
			scanf("%d%d",&i,&j);
			if(i==0&&j==0) break;
			for(h=0;h<k;h++)
			{
				if(i>=a[h][0]&&j>=a[h][1])
				{
					a[h][0]=i;
					a[h][1]=j;
					break;
				}
				else if(h==k-1)
				{
					a[k][0]=i;
					a[k][1]=j;
					k++;
				}
			}
		}
		printf("%d\n",k);
	}
	return 0;
}
