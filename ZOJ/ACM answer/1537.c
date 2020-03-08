#include <stdio.h>
int main()
{
	int n;
	int i,j;
	int p,t;
	while(1)
	{
		if(scanf("%d",&n)==EOF) break;
		t=0;
		for(i=1;i<10;i++)
		{
			p=0;
			for(j=0;j<n;j++)
			{
				p=(p*10+i)%n;
				if(p==0) {t=1;break;}
			}
			if(t==1) {printf("%d %d\n",i,j+1);break;}
		}
		if(t==0) printf("-1\n");
	}
	return 0;
}