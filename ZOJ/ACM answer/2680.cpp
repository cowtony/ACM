#include <stdio.h>
#include <math.h>
#define pi 3.1415926
void change1(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void change2(double &a,double &b)
{
	double temp;
	temp=a;
	a=b;
	b=temp;
}
int main()
{
	int cas,i,j;
	int a[5][2];
	double b[5],p1,p2;
	scanf("%d",&cas);
	while(cas--)
	{
		for(i=0;i<5;i++)
		{
			scanf("%d:%d",&a[i][0],&a[i][1]);
			p1=(double)(a[i][0]%12);
			p2=(double)a[i][1];
			b[i]=fabs(p2*6.0-p1*30.0-p2/2.0);
			if(b[i]>180.0) b[i]=360.0-b[i];
		}
		for(i=0;i<4;i++)
		{
			for(j=i+1;j<5;j++)
			{
				if(b[i]>b[j]) 
				{
					change2(b[i],b[j]);
					change1(a[i][0],a[j][0]);
					change1(a[i][1],a[j][1]);
				}
				else if(fabs(b[i]-b[j])<10e-6)
				{
					if((double)(a[i][0])+(double)(a[i][1])/60.0>double(a[j][0])+(double)(a[j][1])/60.0)
					{
						change2(b[i],b[j]);
						change1(a[i][0],a[j][0]);
						change1(a[i][1],a[j][1]);
					}
				}
			}
		}
		printf("%02d:%02d\n",a[2][0],a[2][1]);
	}
	return 0;
}