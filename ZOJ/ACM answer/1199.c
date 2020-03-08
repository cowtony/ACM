#include <stdio.h>
#include <math.h>
int main()
{
	int cas,i;
	int a[50];
	float b[50][2],t,p1;
	float x1,y1,r1,x2,y2,r2,x3,y3;
	scanf("%d",&cas);
	for(i=0;i<cas;i++)
	{
		scanf("%f%f%f",&x1,&y1,&r1);
		scanf("%f%f%f",&x2,&y2,&r2);
		p1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		if(fabs(r1-r2)<10e-6) a[i]=0;
		else if(p1-fabs(r1-r2)>10e-6)
		{
			a[i]=1;
			if(r1<r2)
			{
				t=x1;x1=x2;x2=t;
				t=y1;y1=y2;y2=t;
				t=r1;r1=r2;r2=t;
			}
				if(fabs(x1-x2)<10e-6)
				{
					
					b[i][0]=x2;
					b[i][1]=r2*(y2-y1)/(r1-r2)+y2;
				}
				else if(x2>x1)
				{
					b[i][0]=fabs((x2-x1)*r2/(r1-r2))+x2;
					b[i][1]=(y2-y1)*(b[i][0]-x2)/(x2-x1)+y2;
				}
				else
				{
					b[i][0]=-fabs((x2-x1)*r2/(r1-r2))+x2;
					b[i][1]=(y2-y1)*(b[i][0]-x2)/(x2-x1)+y2;
				}


		}
		else a[i]=0;
	}
	for(i=0;i<cas;i++)
	{
		if(a[i]==0) printf("Impossible.\n");
		else printf("%.2f %.2f\n",b[i][0],b[i][1]);
	}
	return 0;
}




