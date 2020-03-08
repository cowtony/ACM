#include <stdio.h>
#include <math.h>
int main()
{
	float x1,y1,x2,y2,x3,y3,x4,y4;
	int b[500];
	float c[500][2],t,k1,k2,k3;
	int i,m=0;
	int cas;
	scanf("%d",&cas);
	for(i=0;i<cas;i++)
	{
		scanf("%f%f%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		if(fabs(x1-x2)<10e-6||fabs(x3-x4)<10e-6)
		{
			if(fabs(x1-x2)<10e-6&&fabs(x3-x4)<10e-6)
			{
				if(fabs(x1-x3)<10e-6) b[i]=1;
				else b[i]=0;
			}
			else
			{
				if(fabs(x1-x2)<10e-6)
				{
					c[m][0]=x1;
					c[m][1]=y3-(y3-y4)*(x3-x1)/(x3-x4);
					m++;
					b[i]=2;
				}
				else
				{
					c[m][0]=x3;
					c[m][1]=y2-(y2-y1)*(x2-x3)/(x2-x1);
					m++;
					b[i]=2;
				}
			}
		}
		else
		{
			k1=(y1-y2)/(x1-x2);
			k2=(y3-y4)/(x3-x4);
			if(fabs(k1-k2)<10e-6)
			{
				t=x1-x3;
				if(fabs(t)<10e-6)
				{
					k3=(y1-y4)/(x1-x4);
					if(fabs(k3-k2)<10e-6) b[i]=1;
					else b[i]=0;
				}
				else
				{
					k3=(y1-y3)/(x1-x3);
					if(fabs(k3-k2)<10e-6) b[i]=1;
					else b[i]=0;
				}
			}
			else
			{
				b[i]=2;
				c[m][0]=(y4-y2+k1*x2-k2*x4)/(k1-k2);
				c[m][1]=y4+k2*(c[m][0]-x4);
				m++;
			}
		}

	}
	m=0;
	printf("INTERSECTING LINES OUTPUT\n");
	for(i=0;i<cas;i++)
	{
		if(b[i]==0)  printf("NONE\n");
		else if(b[i]==1) printf("LINE\n");
		else {printf("POINT %.2f %.2f\n",c[m][0],c[m][1]);m++;}
	}
	printf("END OF OUTPUT\n");
	return 0;
}

