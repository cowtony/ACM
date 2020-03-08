#include <stdio.h>
int main()
{
	int stack[1001];
	int i,si,t;
	int out[1001];
	int n,p;
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		while(1)
		{
			scanf("%d",&out[1]);
			if(out[1]==0) {printf("\n");break;}
			for(i=2;i<=n;i++)
				scanf("%d",&out[i]);
			si=0;
			p=0;
			t=1;
			for(i=1;i<=n;i++)
			{
				while(out[i]>=t)
				{
					stack[++si]=t;
					t++;
				}
				if(out[i]==stack[si])
				{
					si--;
				}
				else {p=1;break;}
			}
			if(p==1) printf("No\n");
			else printf("Yes\n");
		}
	}
	return 0;
}








