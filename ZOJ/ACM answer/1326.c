#include <stdio.h>
int main()
{
	int n,x;
	int i,j,l,count,k;
	int a[51];
	int b[20],p=1;
	while(scanf("%d%d",&n,&x)!=EOF)
	{
		for(i=0;i<20;i++)
		{
			scanf("%d",&b[i]);
		}
		for(i=1;i<=n;i++)
		{
			a[i]=i;
		}
		l=0;
		k=n;
		while(k>x)
		{
			count=0;
			for(i=1;i<=n;i++)
			{
				if(k==x) break;
				if(a[i]!=0) count++;
				if(count==b[l]) {a[i]=0;k--;count=0;}
			}
			l++;
		}
		printf("Selection #%d\n",p++);
		for(i=1;i<=n;i++)
		{
			if(a[i]!=0) {printf("%d",a[i]);break;}
		}
		for(j=i+1;j<=n;j++)
			if(a[j]!=0) printf(" %d",a[j]);
		printf("\n\n");
	}
	return 0;
}