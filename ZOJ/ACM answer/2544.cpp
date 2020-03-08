#include <stdio.h>
#include <math.h>
#define pi 3.141592654
int main()
{
	double a[100][3];
	double b[100],di;
	int k,m,count;
	int i,j;
	double r2=(20000/pi)*(20000/pi);
	double x,y,z;
	while(scanf("%d%d",&k,&m))
	{
		if(!k&&!m) break;
		for(i=0;i<k;i++)
		{
			scanf("%lf%lf%lf",&a[i][0],&a[i][1],&a[i][2]);
			b[i]=a[i][0]*a[i][0]+a[i][1]*a[i][1]+a[i][2]*a[i][2]-r2;
		}
		count=0;
		for(i=0;i<m;i++)
		{
			scanf("%lf%lf%lf",&x,&y,&z);
			for(j=0;j<k;j++)
			{
				di=(a[j][0]-x)*(a[j][0]-x)+(a[j][1]-y)*(a[j][1]-y)+(a[j][2]-z)*(a[j][2]-z);
				if(b[j]>di) {count++;break;}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
