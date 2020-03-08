#include <stdio.h>
int main()
{
	long dis;
	double money;
	long k;
	long temp;
	while(scanf("%ld",&dis))
	{
		
		if(dis==0) break;
		if(dis<=4) {printf("10\n");continue;}
		k=dis/8;
		money=(double)(k)*18.0;
		dis=dis%8;
		switch(dis)
		{
		case 1:money+=2.4;break;
		case 2:money+=4.8;break;
		case 3:money+=7.2;break;
		case 4:money+=9.6;break;
		case 5:money+=12.0;break;
		case 6:money+=14.0;break;
		case 7:money+=16.0;break;
		default: break;
		}
		temp=(long)money;
		if(money-(double)temp>10e-5) printf("%.1lf\n",money);
		else printf("%.lf\n",money);
	}
	return 0;
}
		
