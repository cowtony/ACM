#include<stdio.h>

int main()
{
	freopen("1104.in","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		double x[105],y[105];
		double t1,t2,pre=-1;
		int i,j,t=0;
		double tx=0;
		bool flag=false;
		for(i=0;i<n;i++)
		{
			scanf("%lf %lf",&t1,&t2);
			
			if(flag||t1>pre){x[t]=tx;y[t++]=t1;	tx+=t2;}
			else{flag=true;x[t]=tx;y[t++]=pre;tx+=t2;x[t]=tx;y[t++]=t1;}
			
			pre=t1;
		}

	}
	return 0;
}
		
