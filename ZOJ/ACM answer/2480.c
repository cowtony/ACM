#include <stdio.h>
int main()
{
	int n,m;
	int i,j;
	int x1[10],y1[10],x2[10],y2[10];
	int x,y,t;
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
		}
		scanf("%d",&m);
		for(j=0;j<m;j++)
		{
			scanf("%d%d",&x,&y);
			t=0;
			for(i=n-1;i>=0;i--)
			{
				if(x>=x1[i]&&x<=x2[i]&&y>=y1[i]&&y<=y2[i])
					{t=1;printf("%d\n",i);break;}
			}
			if(t==0) printf("-1\n");
		}
	}
	return 0;
}
				