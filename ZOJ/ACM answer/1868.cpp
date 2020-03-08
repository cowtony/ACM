#include <iostream>
#include <cmath>
const double pi=acos(-1);

double a[1000];
double b[1000][2];

double angle(double lng1,double lat1,double lng2,double lat2){
	double dlng=fabs(lng1-lng2)*pi/180;
	while (dlng>=pi+pi)
		dlng-=pi+pi;
	if (dlng>pi)
		dlng=pi+pi-dlng;
	lat1*=pi/180,lat2*=pi/180;
	return acos(cos(lat1)*cos(lat2)*cos(dlng)+sin(lat1)*sin(lat2));
}

int main()
{
	int n;
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&b[i][0],&b[i][1]);
		}
		double haha=180.0;
		int t;
		for(i=0;i<n;i++)
		{
			double temp=0;
            for(j=0;j<n;j++)
			{
				double jiaodu=angle(b[i][1],b[i][0],b[j][1],b[j][0]);
				if(temp<jiaodu)
				{
					temp=jiaodu;
				}
			}
			if(temp<haha)
			{
				haha=temp;
				t=i;
			}
		}
		printf("%.2lf %.2lf\n",b[t][0],b[t][1]);
	}
	return 0;
}
