#include <stdio.h>
int main()
{
	int k,m,t,c,r;
	int a[100];
	int i,j,l,p,count;
	int course;
	while(1)
	{
		scanf("%d",&k);
		if(k==0) break;
		scanf("%d",&m);
		for(i=0;i<k;i++)
		{
			scanf("%d",&a[i]);
		}
		t=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&c,&r);
			count=0;
			for(j=0;j<c;j++)
			{
				scanf("%d",&course);
				p=0;
				for(l=0;l<k;l++)
				{
					if(a[l]==course) {p=1;break;}
				}
				if(p==1) count++;
			}
			if(count<r) t=1;
		}
		if(t==0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}

