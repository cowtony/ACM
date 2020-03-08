#include <stdio.h>
int main()
{
	int p,e,i,d;
	int a[1000];
	int j,l;
	int cas;
	scanf("%d",&cas);
	while(cas--)
	{
		l=0;
		while(1)
		{
			scanf("%d%d%d%d",&p,&e,&i,&d);
			if(p==-1&&e==-1) break;
			for(j=1;j<=21252;j++)
			{
				if((j+d-p)%23==0&&(j+d-e)%28==0&&(j+d-i)%33==0) a[l++]=j;
			}
		}
		for(j=0;j<l;j++)
		{
			printf("Case %d: the next triple peak occurs in %d days.\n",j+1,a[j]);
		}
		if(cas>0) printf("\n");
	}
	return 0;
}
