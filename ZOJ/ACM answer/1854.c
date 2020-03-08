#include <stdio.h>
#include <string.h>
int main()
{
	char a[20][81];
	char b[20][81];
	char c[81];
	int d[20],max,max2,t;
	int i,j,peo,vot;
	while(1)
	{
		if(scanf("%d\n",&peo)==EOF) break;
		for(i=0;i<peo;i++)
		{
			d[i]=0;
			gets(a[i]);
			gets(b[i]);
		}
		scanf("%d\n",&vot);
		for(i=0;i<vot;i++)
		{
			gets(c);
			for(j=0;j<peo;j++)
			{
				if(strcmp(c,a[j])==0) {d[j]++;break;}
			}
		}
		max=-1;t=0;
		for(i=0;i<peo;i++)
		{
			if(d[i]>max) {max=d[i];t=i;}
		}
		d[t]=-1;
		max2=-1;
		for(i=0;i<peo;i++)
		{
			if(d[i]>max2) max2=d[i];
		}
		if(max2<max) puts(b[t]);
		else printf("tie\n");

	}
	return 0;
}
