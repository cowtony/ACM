#include <stdio.h>
#include <math.h>
int main()
{
	int cas;
	int n;
	int i,j,s,t,k,area;
	float l;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d",&n);
		s=8000;
		l=1.0/3.0;
		t=pow((float)n,l);
		for(i=1;i<=t;i++)
		{
			for(j=1;j<=sqrt(n);j++)
			{
				k=n%(i*j);
				if(k!=0) continue;
				else
				{
					k=n/(i*j);
					area=2*(i*j+j*k+i*k);
				}
				if(area<s) s=area;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}